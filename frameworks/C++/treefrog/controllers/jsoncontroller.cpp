#include "jsoncontroller.h"


void JsonController::json()
{
    static QVariantMap obj = {{QStringLiteral("message"), QStringLiteral("Hello, World!")}};
    renderJson(obj);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(JsonController)
