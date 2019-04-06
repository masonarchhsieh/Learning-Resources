/*
 * =====================================================================================
 *
 *       Filename:  rect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/22/2019 04:56:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yi-Ting, Hsieh (a1691807), a1691807@student.adelaide.edu.au
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
    int width, height;
    public:
        Rectangle(){}
        void display(){
            cout << width << " " << height;
        }
};

class RectangleArea::Rectangle
{
    public:
        RectangleArea(){}
        void read_input(){
            cin >> width >> height;       
        }

        void display(){
            cout << width * height;
        }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
