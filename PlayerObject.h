#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <string>
#include <stack>

#include "AbstractObject.h"
#include "Math/Math.h"

class PlayerObject : public AbstractObject
{
 public:
  PlayerObject(float newX, float newY);

  void Update(float dt);

  void SendImpulse(std::string impulse);

 //private:
  std::stack<std::string> impulseStack;

};

#endif
