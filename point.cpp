#include "point.h"
#include <qmath.h>
#include <QTime>

Point::Point(int dimensionsCount)
{ 
    coordinates.resize(dimensionsCount);
    for (int i = 0; i < dimensionsCount; i++)
        coordinates[i] = 0;
}

double Point::distanceTo(const Point& point)
{
    double distance = 0;
    for (int i = 0; i < coordinates.count(); i++)
        distance += (coordinates[i] - point[i]) * (coordinates[i] - point[i]);
    return sqrt(distance);
}

double Point::distanceToCenter()
{
    double distance = 0;
    for (int i = 0; i < coordinates.count(); i++)
        distance += coordinates[i] * coordinates[i];
    return sqrt(distance);
}

QPoint Point::to2D(double focus, double angle) const {
   QVector3D temp = to3D(focus, angle);
   return QPoint(temp.x() * focus / (focus + temp.z()), temp.y() * focus / (focus + temp.z()));
}

QVector3D Point::to3D(double focus, double angle) const {
    double p1, p2, p3;
    double ratio;

    double* temp = new double[coordinates.count()];
    for (int i = 0; i < coordinates.count(); i++)
        temp[i] = coordinates[i];

    //rotation
    for (int i = 0; i < coordinates.count(); i++)
        for (int k = i + 1; k < coordinates.count(); k++)
            {
                ratio = sqrt(2 + i * coordinates.count() + k);
                p1 = temp[i] * cos(angle * ratio) - temp[k] * sin(angle * ratio);
                p2 = temp[k] * cos(angle * ratio) + temp[i] * sin(angle * ratio);
                temp[i] = p1;
                temp[k] = p2;
            }

    //projection
    for (int i = coordinates.count() - 1; i > 3; i--)
        for (int k = 0; k < i; k++)
            temp[k] *= focus  / (focus + temp[i]);

    p1 = temp[0];
    p2 = temp[1];
    p3 = temp[2];

    delete [] temp;
    return QVector3D(p1, p2, p3);
}
