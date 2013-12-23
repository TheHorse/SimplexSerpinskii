#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <simplex.h>
#include <QVector>

namespace Ui {
    class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    void setSimplexes(const QVector<Simplex>& simplexes);
    ~View();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Ui::View *ui;
    QVector<Simplex> simplexes;
    static const double focus = 500.0;

    double angle;
};

#endif // VIEW_H
