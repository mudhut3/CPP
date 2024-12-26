/*
    Harrison Groves
    CS 2 - Hernandez
    October 23, 2024
    Rectangle MiniLab
*/
#include <iostream>
using namespace std;

// Implement a structure named Rectangle with a height and a width.
struct Rectangle {
    int height;
    int width;
};

/* Implement four functions:
- isSquare: Returns if the rectangle is a square (height and width are the same)
- add: Adds a provided height and width to the rectangle's height/width.
- set: Sets a rectangle's height and width to a provided height and width.
- draw: uses height as the vertical dimension (outer loop) and width as the 
  horizontal dimension (inner loop) to draw the rectangle with '*' characters.
*/

bool isSquare(const Rectangle &rect) 
{
    return rect.height == rect.width;
}

void add(Rectangle &rect, int addHeight, int addWidth) 
{
    rect.width += addWidth;
    rect.height += addHeight;
}

void set(Rectangle &rect, int newHeight, int newWidth) 
{
    rect.width = newWidth;
    rect.height = newHeight;
}

void draw(const Rectangle &rect) 
{
    for (int i = 0; i < rect.height; ++i) {  // outer loop for height
        for (int j = 0; j < rect.width; ++j) { // inner loop for width
            cout << "*";
        }
        cout << endl;
    }
}

int main() 
{
  Rectangle r1, r2;
  set(r1, 1, 1);
  
  // Draw the unit rectangle
  cout << "unit rectangle" << endl;
  draw(r1);
  
  // Set, print dimensions and draw
  set(r1, 4, 3);
  cout << "r1 is " << r1.height << " x " << r1.width << endl;
  draw(r1);
  
  // Assign, increment, print dimensions and draw
  r2 = r1;
  add(r2, 3, 4);
  cout << "r2 is " << r2.height << " x " << r2.width << endl;
  draw(r2);
  
  if (isSquare(r2))
    cout << "r2 is a square" << endl;
  else
    cout << "r2 is not a square" << endl;
  return 0;
}