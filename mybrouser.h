#ifndef MYBROUSER_H
#define MYBROUSER_H

#include <QWidget>
#include <QUrl>

namespace Ui {
class MyBrouser;
}

class MyBrouser : public QWidget
{
    Q_OBJECT

public:
    explicit MyBrouser(QWidget *parent = nullptr);
    ~MyBrouser();

signals:
    void showMainWindow();

private slots:
    void on_search_clicked();

    void on_next_clicked();

    void on_prev_clicked();

    void on_stop_clicked();

    void on_exit_clicked();

private:
    Ui::MyBrouser *ui;
    QUrl url;
};

#endif // MYBROUSER_H
