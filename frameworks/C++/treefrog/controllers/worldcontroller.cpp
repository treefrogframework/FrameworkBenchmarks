#include "worldcontroller.h"
#include "world.h"
#include "mngworld.h"


void WorldController::plain()
{
    setContentType(QByteArrayLiteral("text/plain"));
    renderText(QStringLiteral("Hello, World!"));
}

void WorldController::queries()
{
    queries("1");
}

void WorldController::queries(const QString &num)
{
    QVariantList worlds;
    int d = qMin(qMax(num.toInt(), 1), 500);

    for (int i = 0; i < d; ++i) {
        int id = Tf::random(1, 10000);
        worlds << World::get(id).toVariantMap();
    }
    renderJson(worlds);
}

void WorldController::random()
{
    int id = Tf::random(1, 10000);
    World world = World::get(id);
    renderJson(world.toVariantMap());
}

void WorldController::updates()
{
    updates("1");
}

void WorldController::updates(const QString &num)
{
    QVariantList worlds;
    int d = qMin(qMax(num.toInt(), 1), 500);
    World world;

    for (int i = 0; i < d; ++i) {
        int id = Tf::random(1, 10000);
        world = World::get(id);
        world.setRandomNumber( Tf::random(1, 10000) );
        world.update();
        worlds << world.toVariantMap();
    }
    renderJson(worlds);
}

/*
  MongoDB
 */
void WorldController::mqueries()
{
    mqueries("1");
}

void WorldController::mqueries(const QString &num)
{
    QVariantList worlds;
    int d = qMin(qMax(num.toInt(), 1), 500);

    for (int i = 0; i < d; ++i) {
        QString id = QString::number(Tf::random(1, 10000));
        worlds << MngWorld::get(id).toVariantMap();
    }
    renderJson(worlds);
}

void WorldController::mrandom()
{
    QString id = QString::number(Tf::random(1, 10000));
    auto world = MngWorld::get(id);
    renderJson(world.toVariantMap());
}

void WorldController::mupdates()
{
    mupdates("1");
}

void WorldController::mupdates(const QString &num)
{
    QVariantList worlds;
    int d = qMin(qMax(num.toInt(), 1), 500);
    MngWorld world;

    for (int i = 0; i < d; ++i) {
        QString id = QString::number(Tf::random(1, 10000));
        world = MngWorld::get(id);
        world.setRandomNumber( Tf::random(1, 10000) );
        world.update();
        worlds << world.toVariantMap();
    }
    renderJson(worlds);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(WorldController)
