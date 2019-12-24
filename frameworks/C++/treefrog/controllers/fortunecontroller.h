#ifndef FORTUNECONTROLLER_H
#define FORTUNECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT FortuneController : public ApplicationController
{
    Q_OBJECT
public:
    FortuneController() { }
    bool sessionEnabled() const { return false; }
    bool transactionEnabled() const { return false; }

public slots:
    void index();   // SQL
    void mindex();  // MongoDB
};

#endif // FORTUNECONTROLLER_H
