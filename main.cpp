#include "include.h"

int main(int argc, char * argv[])
{
  Participant client1("client21"), client2("client2");

  client1.setKeys(29, 31);

  printf("Type any character: ");
  char c = getchar();

  int enc = client2.encryptMessage((int)c, *client1.getPublicKey());
  printf("Encrypted message: %c\n", (char)enc);

  int dec = client1.decryptMessage(enc);
  printf("Decrypted message: %c\n", (char)dec);

  return 1;
}
