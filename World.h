#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <QList>
#include <type_traits>

class GameObject;

class World : public QObject
{
public:
    explicit World(QObject* parent = nullptr);

    void create();

signals:
    void gameObjectCreated(GameObject* gameObject);

protected:
    template<class T>
    T* createObject();

private slots:
    void onGameObjectDestroyed(QObject* gameObject);

private:
    QList<GameObject*> m_gameObjects;

};

template<class T>
T* World::createObject()
{
    static_assert(std::is_base_of<GameObject, T>::value, "T must be derived from GameObject");

    T* temp = new T(this);
    connect(temp, &QObject::destroyed, this, &World::onGameObjectDestroyed);
    m_gameObjects << temp;
    return temp;
}

#endif // WORLD_H
