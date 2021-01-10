#include "game.h"
#include "vriend.h"
#include "enemy.h"
#include "QImage"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include "windows.h"
using namespace SpaceInvaderz;
extern Game * game;

Game::Game(){
    // create the scene
    scene = new QGraphicsScene(); //32. Dynamic memory allocation(new)
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/Background.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    //player->setPos(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score(); //32. Dynamic memory allocation(new)
    scene->addItem(score);
    health = new Health(); //32. Dynamic memory allocation(new)
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    // spawn enemies
    QTimer * timerE = new QTimer(); //32. Dynamic memory allocation(new)
    QObject::connect(timerE,SIGNAL(timeout()),player,SLOT(spawnE()));
    timerE->start(2000);

    // spawn vriend
    QTimer * timerF = new QTimer(); //32. Dynamic memory allocation(new)
    QObject::connect(timerF,SIGNAL(timeout()),player,SLOT(spawnF()));
    timerF->start(30000);

    //play background music
    QMediaPlayer * music = new QMediaPlayer(); //32. Dynamic memory allocation(new)
    music->setMedia(QUrl("qrc:/sounds/sounds/background.mp3"));//47.useful (modern) usage of file I/O
    music->play();
    bool startgame = true;
    if(startgame == true){
        qDebug() << "\n!!!INSTRUCTIONS!!!\nUse your left and right arrow keys to move with your spaceship.\nUse space to shoot.\nKilling an enemy will increase your score while missing an enemy will decrease your health.\nKilling a friend will increase your health with one, while missing him will decrease it with 2.\nSucces player!\n ";
    };

    Sleep(10000);
    show();

}

Game::~Game()
{
    delete bullet;
    delete enemy;
}
