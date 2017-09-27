#include "include.h"

RSAKey::RSAKey(int a, int b)
{
  this->a = a;
  this->b = b;
}

RSAKey::~RSAKey() {}

int RSAKey::getA() const
{
  return this->a;
}

int RSAKey::getB() const
{
  return this->b;
}
