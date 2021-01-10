#include "game.h"
#include <QApplication>
using namespace SpaceInvaderz;
Game * game;

int main(int argc, char *argv[]) //1.Clean main? 48. correct and useful usage of cmnd line parameters
{
    QApplication app(argc, argv);
    game = new Game();
    game->show();
    return app.exec();
}
