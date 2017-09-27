#pragma once

class Participant
{
  std::string name;
  RSAKey* privateKey;
  RSAKey* publicKey;

public:
  Participant(std::string name);
  ~Participant();

  void setKeys(int p, int q);
  RSAKey* getPublicKey() const;
  int encryptMessage(int message, const RSAKey& otherPublicKey);
  int decryptMessage(int message);
};
