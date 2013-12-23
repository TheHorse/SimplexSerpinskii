#ifndef POINT_H
#define POINT_H

#include <QDebug>
#include <QPoint>
#include <QVector>
#include <QVector3D>

class Point
{
private:
    QVector<double> coordinates;

public:
    Point() {}
    Point(const int dimensionsCount);

    double distanceTo(const Point& point);
    double distanceToCenter();
    QPoint to2D(double focus, double angle) const;
    QVector3D to3D(double focus, double angle) const;

    double& operator[](int index)
    {
        Q_ASSERT(index >= 0 && index < coordinates.count());
        return coordinates[index];
    }

    const double& operator[](int index) const
    {
        Q_ASSERT(index >= 0 && index < coordinates.count());
        return coordinates[index];
    }

    Point operator/ (double right) const
    {
        Point p(this->coordinates.count());
        for (int i = 0; i < coordinates.count(); i++)
            p[i] = coordinates[i] / right;
        return p;
    }

    Point operator+ (const Point& right) const
    {
        Point p(this->coordinates.count());
        for (int i = 0; i < coordinates.count(); i++)
            p[i] = coordinates[i] + right[i];
        return p;
    }
};

#endif // POINT_H
