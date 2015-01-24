#include "BasicEnemyObject.h"

BasicEnemyObject::BasicEnemyObject(float newX, float newY, AbstractObject* newObjectToFollow) :
  AbstractObject("basicenemy", newX, newY),
  objectToFollow(newObjectToFollow)
{
  SetSpeed(50);
}

void BasicEnemyObject::Update(float dt)
{
  float directionToObject = Math::atan2(objectToFollow->y, objectToFollow->x);
  SetDirection(directionToObject);
  UpdatePositions(dt);
}
