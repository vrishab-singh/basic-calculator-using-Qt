#ifndef WIDGET_H
#define WIDGET_H
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *ans;
    QLineEdit *firstNumberLineEdit;  // Declare these lines
    QLineEdit *secondNumberLineEdit;

public slots:
    void changeAdd();
    void changeSub();
    void changeMul();
    void changeDiv();
    void clearAll();
};
#endif // WIDGET_H
