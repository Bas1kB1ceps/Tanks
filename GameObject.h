#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QList>
#include <type_traits>

class Component;

class GameObject : public QObject
{
    Q_OBJECT
public:  
    explicit GameObject(QObject *parent = nullptr);

    virtual void tick(float deltaTime);

    template<class T>
    T* createComponent();

private:
    QList<Component*> m_components;

    void updateComponents(float deltaTime);
};

template<class T>
T* GameObject::createComponent()
{
  static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");

  T* temp = new Component(this);
  m_components << temp;
  return temp;
}

#endif // GAMEOBJECT_H
