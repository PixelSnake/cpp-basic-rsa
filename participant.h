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
  std::vector<int> encryptMessage(const std::string message, const RSAKey& otherPublicKey);
  int encryptMessage(int message, const RSAKey& otherPublicKey);
  std::string decryptMessage(const std::vector<int>& message);
  int decryptMessage(int message);
};
