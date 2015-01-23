#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <string>

#include "Math/Vec2.h"

class AbstractObject
{
 public:
  virtual void Update(float dt);
  
 private:
  Math::Vec2 position;
  Math::Vec2 speed;
};

#endif
