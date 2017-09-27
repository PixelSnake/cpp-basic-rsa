class RSAKey
{
  int a, b;

public:
  RSAKey(int a, int b);
  ~RSAKey();

  int getA() const;
  int getB() const;
};
