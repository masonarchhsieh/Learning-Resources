/*
 * =====================================================================================
 *
 *       Filename:  kernel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2019 02:36:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include "keyboard_map.h"

/* there are 25 lines each of 80 columns; each element takes 2 bytes */
#define LINES 25
#define COLUMN_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMN_IN_LINE * LINES

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMEN_OFFSET 0x08

#define ENTER_KEY_CODE 0x1c

extern unsigned char keyboard_map[128];
extern void keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);
extern void load_idt(unsigned long *idt_ptr);

// current cursor location
unsigned int current_loc = 0;
// video memory begins at address 0xb8000
char *vidptr = (char*) 0xb8000;

// Setting up the IDT(Interrupt Descriptor Table
struct IDT_entry
{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

struct IDT_entry IDT[IDT_SIZE];

void idt_init(void)
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    /* populate IDT entry of keyboard's interrupt */
    keyboard_address = (unsigned long) keyboard_handler;
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08;      // KERNEL_CODE_SEGMEN_OFFSET
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e;     // INTERRUPT_GATE
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    /* Ports
     *          PIC1      PIC2
     *Command   0x20      0xA0
     *Data      0x21      0XA1 
     */

    /* ICW1 - begin initialisation */
    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);

    /* ICW2 - remap offset address of IDT */
    /* In x86 protected mode, we have to remap the PICs(Programmable Interrupt Controller)
     * beyond 0x20 because Intel have designated the first 32 interrupts as "reserved" for cpu execeptions
     */
    write_port(0x21, 0x20);
    write_port(0xA1, 0x28);


    /* ICW3 - setup cascading */
    write_port(0x21, 0x00);
    write_port(0xA1, 0x00);

    /* ICW4 - environment info */
    write_port(0x21, 0x01);
    write_port(0xA1, 0x01);
    /* Intialisation finished */

    /* mask interrupts */
    write_port(0x21, 0xff);
    write_port(0xA1, 0xff);

    /* fill the IDT descriptor */
    idt_address = (unsigned long) IDT;
    idt_ptr[0] = (sizeof(struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16;

    load_idt(idt_ptr);
}

/* Turn on keyboard's IRQ line using the interrupt mask */
void kb_init(void)
{
    /* 0xFD is 11111101 - enables only IRQ1 (keyboard) */
    write_port(0x21, 0xFD);
}

void kprint(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

void kprint_newline(void)
{
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMN_IN_LINE;
    current_loc += (line_size - current_loc & (line_size));
}

void clear_screen(void)
{
    unsigned int i = 0;
    while (i < SCREENSIZE) {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x07;
    }
}

void keyboard_handler_main(void)
{
    unsigned char status;
    char keycode;

    /* write EOI */
    write_port(0x20, 0x20);

    status = read_port(KEYBOARD_STATUS_PORT);
    /* Lowest bit of status will be set if buffer is not empty */
    if (status & 0x01) {
        keycode = read_port(KEYBOARD_DATA_PORT);
        if (keycode < 0)
            return;
        
        if (keycode == ENTER_KEY_CODE) {
            kprint_newline();
            return;
        }

        vidptr[current_loc++] = keyboard_map[(unsigned char) keycode];
        vidptr[current_loc++] = 0x07;
    }
}

  
// void kmain(void)
// {
//     const char *str = "my first kernel with keyboard support";
//     char *vidptr = (char*) 0xb8000;     //video mem begins here
//     unsigned int i = 0;
//     unsigned int j = 0;
// 
//     /* The following code clears the screen
//      * There are 25 lines each of 80 columns: each element takes 2 bytes *
//      */
//     while (j < 80 * 25 * 2) {
//         /* blank character */
//         vidptr[j] = ' ';
//         /* attribute-byte - light grey on black screen */
//         vidptr[j+1] = 0x07;
//         j = j + 2;
//     }
// 
//     j = 0;
// 
//     /* this loop writes the string to video memory */
//     while(str[j] != '\0') {
//         /* the character's acii */
//         vidptr[i] = str[j];
//         /*  attribute-byte: give character black bg and light grey fg */
//         vidptr[i+1] = 0x07;
//         ++j;
//         i = i + 2;
//     }
//     return;
// }

/* A complete version of kmain: */
void kmain(void)
{
    const char *str = "my first kernel with keyboard support";
    clear_screen();
    kprint(str);
    kprint_newline();
    kprint_newline();

    idt_init();
    kb_init();

    while(1);
}
