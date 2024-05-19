#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GraphicPrimitive
{
protected:
    string rgb;
    int x, y;

public:
    virtual void printProperties() const = 0;
    GraphicPrimitive(string color, int x, int y) : x(x), y(y)
    {
        rgb = color;   //конструктор 
    }

    string getRGB() const
    {
        return rgb;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    void setX(int newX)
    {
        x = newX;
    }

    void setY(int newY)
    {
        y = newY;
    }
};

class Rectangle : public GraphicPrimitive
{
    int width, height;

public:
    Rectangle(string color, int x, int y, int width, int height) : GraphicPrimitive(color, x, y), width(width), height(height) {}

    void printProperties() const override
    {
        cout << "Rectangle:\n"
            << "Color: " << getRGB() << "\n"
            << "Coordinates: (" << getX() << ", " << getY() << ")\n"
            << "Width: " << width << ", Height: " << height << "\n";
        cout << endl;
    }
};

class Circle : public GraphicPrimitive
{
    int radius;

public:
    Circle(string color, int x, int y, int radius) : GraphicPrimitive(color, x, y), radius(radius) {}

    void printProperties() const override
    {
        cout << "Circle:\n"
            << "Color: " << getRGB() << "\n"
            << "Coordinates: (" << getX() << ", " << getY() << ")\n"
            << "Radius: " << radius << "\n";
        cout << endl;
    }
};

class Polygon : public GraphicPrimitive
{
    int radius, n;

public:
    Polygon(string color, int x, int y, int radius, int n) : GraphicPrimitive(color, x, y), radius(radius), n(n) {}

    void printProperties() const override
    {
        cout << "Polygon:\n"
            << "Color: " << getRGB() << "\n"
            << "Coordinates: (" << getX() << ", " << getY() << ")\n"
            << "Radius: " << radius << "\n"
            << "Circle radius length: " << n << "\n";
        cout << endl;
    }
};

class Text : public GraphicPrimitive
{
    int size;
    string text;

public:
    Text(string color, int x, int y, int size, string text) : GraphicPrimitive(color, x, y), size(size), text(text) {}

    void printProperties() const override
    {
        cout << "Text:\n"
            << "Color: " << getRGB() << "\n"
            << "Coordinates: (" << getX() << ", " << getY() << ")\n"
            << "Font size: " << size << "\n"
            << "Text: " << text << "\n";
        cout << endl;
    }
};


int main()
{
    vector<GraphicPrimitive*> primitives;
    primitives.push_back(new Rectangle("15, 144, 5", 0, 0, 10, 20));
    primitives.push_back(new Circle("11, 34, 210", 1, 2, 8));
    primitives.push_back(new Polygon("221, 32, 9", 0, 4, 2, 3));
    primitives.push_back(new Text("208, 145, 91", 3, 5, 2, "qwerty"));

    for (const auto& primitive : primitives)
    {
        primitive->printProperties();
    }

    for (const auto& primitive : primitives)
    {
        delete primitive;
    }

    return 0;
}
