#ifndef GAME_H
#define GAME_H

#include <QObject>

class World;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject* parent = nullptr);

    void init();
    void update();
    void pause();
    void stop();

private:
    World* m_currentWorld = nullptr;

};

#endif // GAME_H
