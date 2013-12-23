#include "simplex.h"
#include <qmath.h>
#include <QDebug>

const double Simplex::r = 300.0;

Simplex::Simplex(const int dimensionalCount, const bool calculateTrueSimplex)
    : n(dimensionalCount)
{
    for (int i = 0; i < dimensionalCount + 1; i++)
        points.push_back(Point(dimensionalCount));

    if (!calculateTrueSimplex)
        return;

    double c = r * sqrt(3) / 2;  
    double l = c * 2;    //distance between points
    points[0][0] = + 0; points[0][1] = + r;      //first point
    points[1][0] = + c; points[1][1] = - r / 2;  //second point
    points[2][0] = - c; points[2][1] = - r / 2;  //3th point    

    for (int i = 3; i <= dimensionalCount; i++)
    {
        double d =  points[0].distanceToCenter();

        double q2 = (l * l - 2 * d * d) / (2 * sqrt(l * l - d * d));
        double q1 = sqrt(d * d + q2 * q2);

        for (int k = 0; k < i; k++)
        {
            points[k][i-1] = -q2;   //set i-th dimension for all created points
            points[i][k] = 0;       //set all calculated dimension for new point
        }
        points[i][i-1] = q1;
    }

}


