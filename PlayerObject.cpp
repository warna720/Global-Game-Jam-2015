#include "PlayerObject.h"

PlayerObject::PlayerObject(float newX, float newY) :
  AbstractObject("player", newX, newY)
{
}

void PlayerObject::Update(float dt)
{
  std::string impulse;
  SetSpeed(0);
  while (!impulseStack.empty())
  {
    impulse = impulseStack.top();
    if (impulse == "UP")
    {
      SetDirection(Math::PI / 2);
      SetSpeed(100);
    }
    else if (impulse == "DOWN")
    {
      SetDirection(-Math::PI / 2);
      SetSpeed(100);
    }
    else if (impulse == "LEFT")
    {
      SetDirection(Math::PI);
      SetSpeed(100);
    }
    else if (impulse == "RIGHT")
    {
      SetDirection(0);
      SetSpeed(100);
    }
    impulseStack.pop();
  }
  UpdatePositions(dt);
}

void PlayerObject::SendImpulse(std::string impulse)
{
  impulseStack.push(impulse);
}
