#include "include.h"

std::string getMessage()
{
  std::string ret;
  std::getline(std::cin, ret);
  return ret;
}

int main(int argc, char * argv[])
{
  Participant client1("client21"), client2("client2");

  client1.setKeys(29, 31);

  std::cout << "Type a message: ";
  std::string msg = getMessage();

  auto enc = client2.encryptMessage(msg, *client1.getPublicKey());
  std::cout << "Encrypted message: ";
  for (int& i : enc)
    std::cout << i;
  std::cout << std::endl;

  std::string dec = client1.decryptMessage(enc);
  std::cout << "Decrypted message: " << dec << std::endl;

  return 1;
}
