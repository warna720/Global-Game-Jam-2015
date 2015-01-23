#include "AbstractObject.h"

AbstractObject::AbstractObject(std::string newIdentifier) :
  direction(0.0f),
  height(0.0f),
  width(0.0f),
  x(0.0f),
  xSpeed(0.0f),
  y(0.0f),
  ySpeed(0.0f),
  identifier(newIdentifier)
{
}

void AbstractObject::SetDirection(float newDirection)
{
  direction = newDirection;
}

void AbstractObject::SetPosition(float newX, float newY)
{
  x = newX;
  y = newY;
}

void AbstractObject::SetSpeed(float newSpeed)
{
  xSpeed = newSpeed * Math::cos(direction);
  ySpeed = newSpeed * Math::sin(direction);
}

void AbstractObject::UpdatePositions(float dt)
{
  x += xSpeed * dt;
  y += ySpeed * dt;
}
