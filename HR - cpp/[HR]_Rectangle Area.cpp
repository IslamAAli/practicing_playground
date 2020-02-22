#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle{

    private: 
        int width;
        int height;
    
    public:
        void read_input()
        {
            cin >> width >> height; 
        }

        void display()
        {
            cout << width << " " << height<<endl;
        }

        int getWidth()
        {
            return width;
        }

        int getHeight()
        {
            return height;
        }
};

class RectangleArea : public Rectangle{
    public: 
        void display()
        {
            cout << this->getWidth() * this->getHeight()<<endl;
        }
};

