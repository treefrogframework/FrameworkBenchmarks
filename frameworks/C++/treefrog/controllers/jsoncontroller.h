#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT JsonController : public ApplicationController
{
    Q_OBJECT
public:
    JsonController() { }
    bool sessionEnabled() const override { return false; }
    bool transactionEnabled() const override { return false; }

public slots:
    void json();
};

#endif // JSONCONTROLLER_H
