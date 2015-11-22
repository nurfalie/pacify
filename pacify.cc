extern "C"
{
#include <stdlib.h>
}

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>

double char_class(const char c)
{
  int _c_ = static_cast<int> (c);

  if(static_cast<int> ('0') <= _c_ && _c_ <= static_cast<int> ('9'))
    return 1;
  else if(static_cast<int> ('a') <= _c_ && _c_ <= static_cast<int> ('z'))
    return 2;
  else if(static_cast<int> ('A') <= _c_ && _c_ <= static_cast<int> ('Z'))
    return 2.5;
  else if(_c_ < (1 << 7))
    return 3;
  else if(_c_ < (1 << 8))
    return 3.5;
  else if(_c_ < (1 << 10))
    return 4;
  else if(_c_ < (1 << 14))
    return 5;
  else if(_c_ < (1 << 16))
    return 6;
  else if(_c_ < (1 << 18))
    return 7;
  else if(_c_ < (1 << 22))
    return 8;
  else if(_c_ < (1 << 26))
    return 9;
  else
    return 10;
}

double distance(const char a, const char b)
{
  std::string _a_;
  std::string _b_;

  _a_.append(1, a);
  _b_.append(1, b);
  std::transform(_a_.begin(), _a_.end(), _a_.begin(), ::tolower);
  std::transform(_b_.begin(), _b_.end(), _b_.begin(), ::tolower);

  if(_a_ == _b_)
    return 0;

  std::map<char, std::pair<double, double> > keys;
  std::string L1("1234567890");
  std::string L2("qwertyuiop");
  std::string L3("asdfghjkl");
  std::string L4("zxcvbnm");
  std::string _a_b_(_a_ + _b_);

  for(size_t i = 0; i < L1.length(); i++)
    keys[L1[i]] = std::pair<double, double> (static_cast<double> (i), 0);

  for(size_t i = 0; i < L2.length(); i++)
    keys[L2[i]] = std::pair<double, double> (static_cast<double> (i) + 0.5,
					     1);

  for(size_t i = 0; i < L3.length(); i++)
    keys[L3[i]] = std::pair<double, double> (static_cast<double> (i) + 0.75,
					     2);

  for(size_t i = 0; i < L4.length(); i++)
    keys[L4[i]] = std::pair<double, double> (static_cast<double> (i) + 1, 3);

  for(size_t i = 0; i < (_a_b_).length(); i++)
    if(keys.find(_a_b_[i]) == keys.end())
      return 15;

  return 0;
}

int main(void)
{
  return EXIT_SUCCESS;
}
