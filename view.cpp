#include "view.h"
#include "ui_view.h"
#include <QPainter>
#include <QVector3D>
#include <point.h>
#include <qmath.h>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    angle = 0;
}

void View::setSimplexes(const QVector<Simplex>& simplexes)
{
    this->simplexes = simplexes;
} 

View::~View()
{
    delete ui;
}

void View::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
   
    QPoint center(this->width() / 2, this->height() / 2);

    foreach(const Simplex& simplex, simplexes)
        for (int i = 0; i < simplex.dimensionsCount() + 1; i++)
            for (int k = i+1; k < simplex.dimensionsCount() + 1; k++)
                p.drawLine(simplex[i].to2D(focus, angle) + center, simplex[k].to2D(focus, angle) + center);

    angle += 0.01;
    this->update();
}
