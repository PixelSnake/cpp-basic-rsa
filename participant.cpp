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

std::vector<int> Participant::encryptMessage(std::string message, const RSAKey& otherPublicKey)
{
  std::vector<int> ret;

  for (char& c : message)
    ret.push_back(encryptMessage((int)c, otherPublicKey));

  return ret;
}
int Participant::encryptMessage(int message, const RSAKey& otherPublicKey)
{
  return Math::modExp(message, otherPublicKey.getB(), otherPublicKey.getA());
}

std::string Participant::decryptMessage(const std::vector<int>& message)
{
  std::string ret;

  for (auto c : message)
    ret += (char)decryptMessage(c);

  return ret;
}
int Participant::decryptMessage(int message)
{
  return Math::modExp(message, this->privateKey->getB(), this->privateKey->getA());
}
