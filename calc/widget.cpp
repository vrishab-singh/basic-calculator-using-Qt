#include "widget.h"
#include "./ui_widget.h"
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setWindowTitle("Calculator");
    resize(500,400);

    QLabel *a = new QLabel(this);
    a->setText("Enter first number");
    QLineEdit *ai = new QLineEdit(this);

    QLabel *b = new QLabel(this);
    b->setText("Enter second number");
    QLineEdit *bi = new QLineEdit(this);



    QLabel *op = new QLabel(this);
    op->setText("which operation do you want to perform: ?");

    QPushButton *add = new QPushButton(this);
    add->setText("Addition");
    connect(add, SIGNAL(clicked()), this, SLOT(changeAdd()));

    QPushButton *sub = new QPushButton(this);
    sub->setText("Subtraction");
    connect(sub, SIGNAL(clicked()), this, SLOT(changeSub()));
    QPushButton *mul = new QPushButton(this);
    mul->setText("Multiplication");
    connect(mul, SIGNAL(clicked()), this, SLOT(changeMul()));
    QPushButton *div = new QPushButton(this);
    div->setText("Division");
    connect(div, SIGNAL(clicked()), this, SLOT(changeDiv()));

    QPushButton *calc = new QPushButton(this);
    calc->setText("Answer:");

    ans = new QLabel(this);
    ans->setText("0");

    QPushButton *clr = new QPushButton(this);
    clr->setText("Clear");
    connect(clr, SIGNAL(clicked()), this, SLOT(clearAll()));

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(a,0,0);
    grid->addWidget(ai,0,3);
    grid->addWidget(b,1,0);
    grid->addWidget(bi,1,3);
    grid->addWidget(op,2,0);
    grid->addWidget(add,3,1);
    grid->addWidget(sub,3,2);
    grid->addWidget(mul,3,3);
    grid->addWidget(div,3,4);
    grid->addWidget(calc,4,1);
    grid->addWidget(ans,4,3);
    grid->addWidget(clr,5,3);
    firstNumberLineEdit = ai;
    secondNumberLineEdit = bi;
}
void Widget::clearAll(){
    ans->setText("0");
    firstNumberLineEdit->clear();
    secondNumberLineEdit->clear();
}
void Widget::changeAdd()
{
    // Retrieve text from line edits
    QString xStr = firstNumberLineEdit->text();
    QString yStr = secondNumberLineEdit->text();

    // Convert text to numbers
    bool conversionX, conversionY;
    double x = xStr.toDouble(&conversionX);
    double y = yStr.toDouble(&conversionY);
    double result = x + y;

    // Display result
    ans->setText(QString::number(result));
}
void Widget::changeSub()
{
    // Retrieve text from line edits
    QString xStr = firstNumberLineEdit->text();
    QString yStr = secondNumberLineEdit->text();

    // Convert text to numbers
    bool conversionX, conversionY;
    double x = xStr.toDouble(&conversionX);
    double y = yStr.toDouble(&conversionY);
    double result = x - y;

    // Display result
    ans->setText(QString::number(result));
}
void Widget::changeMul()
{
    // Retrieve text from line edits
    QString xStr = firstNumberLineEdit->text();
    QString yStr = secondNumberLineEdit->text();

    // Convert text to numbers
    bool conversionX, conversionY;
    double x = xStr.toDouble(&conversionX);
    double y = yStr.toDouble(&conversionY);
    double result = x * y;

    // Display result
    ans->setText(QString::number(result));
}
void Widget::changeDiv()
{
    // Retrieve text from line edits
    QString xStr = firstNumberLineEdit->text();
    QString yStr = secondNumberLineEdit->text();

    // Convert text to numbers
    bool conversionX, conversionY;
    double x = xStr.toDouble(&conversionX);
    double y = yStr.toDouble(&conversionY);
    double result = x / y;

    // Display result
    ans->setText(QString::number(result));
}

Widget::~Widget()
{
    delete ui;
}
