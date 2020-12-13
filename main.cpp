#include "game.h"
#include "players.h"
#include "aliens.h"
#include "bullet.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

/*void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    int WIDTH = 300;
    int HEIGHT = 500;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}
*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene(); // creating a scene
    Player * rect = new Player();
    rect -> setRect(0,0,100,100); // 38 en 39 -> create an item to put into the scene
    scene->addItem(rect);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    QGraphicsView * view = new QGraphicsView(scene); // add a view
    view->show();

    //Game window;
    //window.setWindowTitle("Space Invaders");
    //window.show();
    //center(window);

    return app.exec();
}
