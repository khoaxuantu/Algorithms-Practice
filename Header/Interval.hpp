#ifndef INTERVAL_HPP
#define INTERVAL_HPP

class Interval
{
private:

public:
    int start = 0;
    int end = 0;
    Interval();
    Interval(int start, int end);
    ~Interval();
};

Interval::Interval(int start, int end)
{
    this->start = start;
    this->end = end;
}

Interval::~Interval()
{
}

#endif