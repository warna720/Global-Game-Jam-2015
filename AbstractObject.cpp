#include "AbstractObject.h"

AbstractObject::AbstractObject(std::string newIdentifier, float newX, float newY) :
  direction(0.0f),
  height(0.0f),
  width(0.0f),
  storedSpeed(0.0f),
  x(newX),
  xSpeed(0.0f),
  y(newY),
  ySpeed(0.0f),
  id(0),
  identifier(newIdentifier)
{
}

void AbstractObject::SetDirection(float newDirection)
{
  direction = newDirection;
  SetSpeed(storedSpeed);
}

void AbstractObject::SetPosition(float newX, float newY)
{
  x = newX;
  y = newY;
}

void AbstractObject::SetSpeed(float newSpeed)
{
  storedSpeed = newSpeed;
  xSpeed = newSpeed * Math::cos(direction);
  ySpeed = newSpeed * Math::sin(direction);
}

void AbstractObject::UpdatePositions(float dt)
{
  x += xSpeed * dt;
  y += ySpeed * dt;
}
