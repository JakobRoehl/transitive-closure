#include <string>
#include <iostream>
using namespace std;
#define X 36
#define Y 2

      string t = "MYSTRING1234567890";

const string cSHORT = ".";
const string ccLONG = "-";
      string combs[X][Y] = {{"A", cSHORT + ccLONG},
                            {"B", ccLONG + cSHORT + cSHORT + cSHORT},
                            {"C", ccLONG + cSHORT + ccLONG + cSHORT},
                            {"D", ccLONG + cSHORT + cSHORT},
                            {"E", cSHORT},
                            {"F", cSHORT + cSHORT + ccLONG + cSHORT},
                            {"G", ccLONG + ccLONG + cSHORT},
                            {"H", cSHORT + cSHORT + cSHORT + cSHORT},
                            {"I", cSHORT + cSHORT},
                            {"J", cSHORT + ccLONG + ccLONG + ccLONG},
                            {"K", ccLONG + cSHORT + ccLONG},
                            {"L", cSHORT + ccLONG + cSHORT + cSHORT},
                            {"M", ccLONG + ccLONG},
                            {"N", ccLONG + cSHORT},
                            {"O", ccLONG + ccLONG + ccLONG},
                            {"P", cSHORT + ccLONG + ccLONG + cSHORT},
                            {"Q", ccLONG + ccLONG + cSHORT + ccLONG},
                            {"R", cSHORT + ccLONG + cSHORT},
                            {"S", cSHORT + cSHORT + cSHORT},
                            {"T", ccLONG},
                            {"U", cSHORT + cSHORT + ccLONG},
                            {"V", cSHORT + cSHORT + cSHORT + ccLONG},
                            {"W", cSHORT + ccLONG + ccLONG},
                            {"X", ccLONG + cSHORT + cSHORT + ccLONG},
                            {"Y", ccLONG + cSHORT + ccLONG + ccLONG},
                            {"Z", ccLONG + ccLONG + cSHORT + cSHORT},
                            {"1", cSHORT + ccLONG + ccLONG + ccLONG + ccLONG},
                            {"2", cSHORT + cSHORT + ccLONG + ccLONG + ccLONG},
                            {"3", cSHORT + cSHORT + cSHORT + ccLONG + ccLONG},
                            {"4", cSHORT + cSHORT + cSHORT + cSHORT + ccLONG},
                            {"5", cSHORT + cSHORT + cSHORT + cSHORT + cSHORT},
                            {"6", ccLONG + cSHORT + cSHORT + cSHORT + cSHORT},
                            {"7", ccLONG + ccLONG + cSHORT + cSHORT + cSHORT},
                            {"8", ccLONG + ccLONG + ccLONG + cSHORT + cSHORT},
                            {"9", ccLONG + ccLONG + ccLONG + ccLONG + cSHORT},
                            {"0", ccLONG + ccLONG + ccLONG + ccLONG + ccLONG}};

int index(string combs[X][Y], string value) {
  for (int i = 0; i < X; i++) {
    if (combs[i][0]== value)
      return i;
  }
  return 0;
}
string mors(string combs[X][Y], string value) {
  return combs[index(combs, value)][1];
}
string cts(char* a) {
    string s = "";
    s += a[0];
    return s;
}
int main(void) {

  for(char& c : t) {
    if(c == ' ')
      cout << ' ';
    else
      cout << mors(combs, cts(&c));
    cout << ' ';
  }
  cout << '\n';
  return 0;
}
