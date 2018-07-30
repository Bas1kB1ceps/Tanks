#include "World.h"
#include <cassert>

World::World(QObject* parent) : QObject(parent)
{

}

void World::onGameObjectDestroyed(QObject* gameObject)
{
    GameObject* temp = qobject_cast<GameObject*>(gameObject);
    assert(temp != nullptr);

    m_gameObjects.removeOne(temp);
}
