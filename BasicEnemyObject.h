#ifndef BASICENEMYOBJECT_H
#define BASICENEMYOBJECT_H

#include "AbstractObject.h"
#include "Math/Math.h"

class BasicEnemyObject : public AbstractObject
{
 public:
  BasicEnemyObject(float newX, float newY, AbstractObject* newObjectToFollow);

  void Update(float dt);

 //private:
  AbstractObject* objectToFollow;

};

#endif
