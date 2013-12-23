#include "povray.h"
#include "point.h"
#include <QMessageBox>

PovRay::PovRay()
{
    QFile file(":/pov/template.pov");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    templatePov = QString(file.readAll());
    file.close();


}

void PovRay::generatePovFile(const QString& path, const QVector<Simplex>& triangles, const double angel)
{
     int n = triangles.first().dimensionsCount();

     QString out = QString(templatePov);
     QString count = QString::number(triangles.count() * (n + 1) * n * (n -1) / 6 * 3 );
     QString array;

     QFile file(path);
     file.open(QIODevice::WriteOnly | QIODevice::Text);

     QVector3D v;
     foreach(const Simplex& triangle, triangles)
     {
         for (int i = 0; i < n + 1; i++)
             for (int k = i + 1; k < n + 1; k++)
                 for (int j = k + 1; j < n + 1; j++)
                 {
                     v = triangle[i].to3D(focus, angel);
                     array += "  <" + QString::number(v.x()) + "," + QString::number(v.y()) + "," + QString::number(v.z()) + ">,";
                     v = triangle[k].to3D(focus, angel);
                     array += "  <" + QString::number(v.x()) + "," + QString::number(v.y()) + "," + QString::number(v.z()) + ">,";
                     v = triangle[j].to3D(focus, angel);
                     array += "  <" + QString::number(v.x()) + "," + QString::number(v.y()) + "," + QString::number(v.z()) + ((j == n + 1 && k == n && i == n -1) ? ">\n" : ">,\n");
                 }
     }

     out = out.replace("<<!!--count of points--!!>>", count);
     out = out.replace("<<!!--Main Array of points--!!>>", array);

     file.write(out.toUtf8());

     file.close();
}
