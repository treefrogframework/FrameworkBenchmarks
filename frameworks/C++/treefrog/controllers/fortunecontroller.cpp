#include "fortunecontroller.h"
#include "fortune.h"
#include "mngfortune.h"

static bool caseSensitiveLessThan(const Fortune &f1, const Fortune &f2)
{
    return f1.message() < f2.message();
}

static bool caseSensitiveMngFortuneLessThan(const MngFortune &f1, const MngFortune &f2)
{
    return f1.message() < f2.message();
}


void FortuneController::index()
{
    QList<Fortune> fortuneList = Fortune::getAll();
    Fortune fortune;
    fortune.setMessage(QStringLiteral("Additional fortune added at request time."));
    fortuneList << fortune;
    // Sort
    std::sort(fortuneList.begin(), fortuneList.end(), caseSensitiveLessThan);
    texport(fortuneList);
    render();
}

void FortuneController::mindex()
{
    QList<MngFortune> fortuneList = MngFortune::getAll();
    MngFortune fortune;
    fortune.setMessage(QStringLiteral("Additional fortune added at request time."));
    fortuneList << fortune;
    // Sort
    std::sort(fortuneList.begin(), fortuneList.end(), caseSensitiveMngFortuneLessThan);
    texport(fortuneList);
    render("mindex");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(FortuneController)
