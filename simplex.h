#ifndef NTRIANGLE_H
#define NTRIANGLE_H

#include <QObject>
#include <point.h>

class Simplex
{

public:
    Simplex(const int dimensionsCount = 3, const bool calculateTrueSimplex = false);

    int dimensionsCount() const
    {
        return n;
    }

    Point& operator[] (int index)
    {
        Q_ASSERT(index >= 0 && index <= n);
        return  points[index];
    }

    const Point& operator[] (int index) const
    {
        Q_ASSERT(index >= 0 && index <= n);
        return points[index];
    }

    static const double r;

private:
    QVector<Point> points;
    int n; //dimensionals count

};

#endif // NTRIANGLE_H
