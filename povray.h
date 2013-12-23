#ifndef POVRAY_H
#define POVRAY_H
#include <QString>
#include <QFile>
#include <QVector>
#include "simplex.h"

class PovRay
{
private:
    QString templatePov;
    QFile output;
    static const double focus = 500.0;

public:
    PovRay();
    void generatePovFile(const QString& path, const QVector<Simplex>& triangles, const double angle);
};

#endif // POVRAY_H
