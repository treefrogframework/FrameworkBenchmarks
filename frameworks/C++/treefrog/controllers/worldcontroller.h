#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WorldController : public ApplicationController
{
    Q_OBJECT
public:
    WorldController() { }
    bool sessionEnabled() const override { return false; }
    bool transactionEnabled() const override { return false; }

public slots:
    void plain();
    void queries();
    void queries(const QString &num);
    void random();
    void updates(const QString &num);
    void updates();

    // MongoDB
    void mqueries();
    void mqueries(const QString &num);
    void mrandom();
    void mupdates(const QString &num);
    void mupdates();
};

#endif // WORLDCONTROLLER_H
