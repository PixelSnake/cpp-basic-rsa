#include "include.h"

int mode = CRYPTMODE_ENCRYPT;

std::string getMessage()
{
  std::string ret;
  std::getline(std::cin, ret);
  return ret;
}

std::string getParam(int argc, char * argv[])
{
  if (argc < 2) return std::string();

  for (int i = 1; i < argc; ++i)
  {
    std::string p(argv[i]);
    std::ifstream s(p.c_str());

    if (!s.good())
    {
      if (p == "-d") mode = CRYPTMODE_DECRYPT;
      else return p;
    }
    else
    {
      std::string ret;
      s.seekg(0, std::ios::end);
      ret.reserve(s.tellg());
      s.seekg(0, std::ios::beg);
      ret.assign((std::istreambuf_iterator<char>(s)),
        std::istreambuf_iterator<char>());
      return ret;
    }
  }

  return std::string();
}

int main(int argc, char * argv[])
{
  Participant client1("client21"), client2("client2");

  client1.setKeys(29, 31);

  auto msg = getParam(argc, argv);
  if (msg.empty())
  {
    std::cout << "Not input." << std::endl;
    return 0;
  }

  if (mode == CRYPTMODE_ENCRYPT)
  {
    auto enc = client2.encryptMessage(msg, *client1.getPublicKey());
    for (int& i : enc)
      std::cout << i << " ";
    std::cout << std::endl;
  }
  else
  {
    std::string str;
    std::vector<int> nums;
    std::stringstream ssin(msg);
    while (ssin >> str)
      nums.push_back(std::stoi(str));

    std::string dec = client1.decryptMessage(nums);
    std::cout << dec << std::endl;
  }

  return 1;
}
