#include <iostream>         // std::cout
#include <memory>           // for smart_pointer

using namespace std;

class Rectangle
{
    int Length;
    int Breadth;

    public:
        Rectangle(int l, int b)
        {
            Length = l;
            Breadth = b;
        }
        int Area()
        {
            return Length * Breadth;
        }
};

int Fun(int l, int b)
{
    Rectangle *p = new Rectangle(l, b);
    int area = p->Area();
    delete p;
    return area;
}

// when the function ends and it's going out of the scope
// and then the unique pointer p will be deleted and automatically it will also
// delete the Rectangle object from the heap memory.

// !!! we cannot share the unique pointer object with another pointer. But we can
//     transfer the control from one pointer to another pointer by removing p1.
//    => unique_ptr means upon an object at a time only one pointer will be pointing.
int Fun_unique_ptr(int l, int b)
{
    unique_ptr<Rectangle> p (new Rectangle(l, b));
    int area = p->Area();
    return area;
}

int main ()
{
    int i = 0;
    while (i++ < 10) {
        // int result = Fun(i, i * i);
        int result = Fun_unique_ptr(i, i * i);
        cout << "i is " << i << ", Fun returns " << result << endl;
    }
 
    return 0;
}
