#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <string>

#include "Math/Math.h"

class AbstractObject
{
 public:
  AbstractObject(std::string newIdentifier);

  virtual void Update(float dt) {};
  
  void SetDirection(float newDirection);
  void SetPosition(float newX, float newY);
  void SetSpeed(float newSpeed);

  void UpdatePositions(float dt);
  
  //private:
  float direction;
  float height;
  float width;
  float x;
  float xSpeed;
  float y;
  float ySpeed;

  std::string identifier;
};

#endif
