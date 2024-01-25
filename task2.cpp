#include <iostream>
#include <cmath>
using namespace std;

class Point 
{
private:
    double x;
    double y;

public:

    Point(double Xcoo, double Ycoo) : x(Xcoo), y(Ycoo) {}
    double getX() const 
    {
        return x;
    }
    double getY() const 
    {
        return y;
    }
    void setX(double newX) 
    {
        x = newX;
    }
    void setY(double newY) 
    {
        y = newY;
    }
    double distance(const Point& otherPoint) const
    {
        double dX = x - otherPoint.getX();
        double dY = y - otherPoint.getY();
        return sqrt(dX * dX + dY * dY);
    }
};

int main() 
{
    double x1, y1;
    cout << "Enter x coordinate for Point 1: ";
    cin >> x1;

    cout << "Enter y coordinate for Point 1: ";
    cin >> y1;

    Point point1(x1, y1);

    double x2, y2;
    cout << "Enter x coordinate for Point 2: ";
    cin >> x2;

    cout << "Enter y coordinate for Point 2: ";
    cin >> y2;

    Point point2(x2, y2);

    cout << "Point 1 coordinates: (" << point1.getX() << ", " << point1.getY() << ")" << endl;
    cout << "Point 2 coordinates: (" << point2.getX() << ", " << point2.getY() << ")" << endl;
    cout << "Distance between points: " << point1.distance(point2) << endl;

    return 0;
}

