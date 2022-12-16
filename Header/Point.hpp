#if !defined(POINT_HPP)
#define POINT_HPP

class Point
{
private:
public:
    int x = 0;
    int y = 0;
    Point(int x, int y);
    int distFromOrigin() const;
    ~Point();
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::distFromOrigin() const
{
    // Ignoring sqrt
    return (x*x) + (y*y);
}

Point::~Point()
{
}

#endif // POINT_HPP
