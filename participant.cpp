#include "include.h"

Participant::Participant(std::string name)
{
  this->name = name;
}

Participant::~Participant()
{
  delete this->privateKey;
  delete this->publicKey;
}

void Participant::setKeys(int p, int q)
{
  int n = p * q;
  int t = (p - 1) * (q - 1);
  int e = 11;
  int d = 611;

  this->publicKey = new RSAKey(n, e);
  this->privateKey = new RSAKey(n, d);
}

RSAKey* Participant::getPublicKey() const
{
  return this->publicKey;
}

int Participant::encryptMessage(int message, const RSAKey& otherPublicKey)
{
  return Math::modExp(message, otherPublicKey.getB(), otherPublicKey.getA());
}

int Participant::decryptMessage(int message)
{
  return Math::modExp(message, this->privateKey->getB(), this->privateKey->getA());
}
