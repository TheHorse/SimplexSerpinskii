#include <QtGui/QApplication>
#include <QVector>
#include <QVector3D>
#include <QFile>
#include <QTextStream>
#include "view.h"
#include "simplex.h"
#include "povray.h"


int n = 4; // Dimensionals count
int maxRecursionDepth = 4;

void rec(QVector<Simplex>& storage, const Simplex& current, int recursionDepth)
{
    if (recursionDepth == maxRecursionDepth)
        storage.append(current);
    else
    {
        for (int i = 0; i <= n; i++)
        {
            Simplex newTriangle(current.dimensionsCount());
            for (int k = 0; k <= n; k++)
            {
                if (i == k)
                    newTriangle[k] = current[i];
                else
                    newTriangle[k] = (current[i] + current[k]) / 2.0;
            }
            rec(storage, newTriangle, recursionDepth + 1);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<Simplex> triangles;
    rec(triangles, Simplex(n, true), 0);

    /*  PovRay output;
   for (int c = 0; c < 2000; c++)
   {
       output.generatePovFile("/home/horse/horse/r" + QString::number(c) + ".pov", triangles, c / 195.0f);
       qDebug() << c;
   }*/

    View view;
    view.setSimplexes(triangles);
    view.show();
    return a.exec();
}
