// {{{
// {{{
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
// }}}

// {{{
#define int long long
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define FOR(i,s,e) for (int i=(s);i<(e);i++)
#define RFOR(i,s,e) for (int i=(s-1);i>=(e);i--)
#define ll long long
#define MAIN signed main(void)
// }}}

int LL_MAX = 9223372036854775807;
int LL_MIN = -9223372036854775808;

using namespace std;
// }}}
int gcd(int a, int b)                       // ２数の最大公約数 {{{
{
  int t; while (b != 0) { t = b; b = a % b; a = t; } return a;
} // }}}
int gcd3(int a, int b, int c)               // ３数の最大公約数 {{{
{
  int s, t; s = gcd(a, b); t = gcd(c, s); return t;
} // }}}
int lcm(int a, int b)                       // 最大公約数 {{{
{
  if (a * b == 0) return 0; return (a * b / gcd(a, b));
} // }}}
vector<int> in_arr(int size)                // 配列入力 {{{
{
  vector<int> arr;
  REP(i, size) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  return arr;
} // }}}
void out_arr(vector<int> arr)               // 配列出力 {{{
{
  REP(i, arr.size()) {
    cout << arr[i] << " ";
  }
  cout << endl;
} // }}}
bool is_prime(int num)                      // 素数判定 {{{
{
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  else if (num % 3 == 0) return false;
  else if (num % 5 == 0) return false;
  else if (num % 7 == 0) return false;
  else if (num % 11 == 0) return false;
  double root = sqrt(num);
  for (int i = 3; i <= root; i += 2) { if (num % i == 0) return false; }
  return true;
} // }}}
vector<int> gen_prime(int num)              // n以下の素数生成 {{{
{
  vector<int> arr;
  for (int i = 2; i < num; i++) {
    if (is_prime(i)) arr.push_back(i);
  }
  return arr;
} // }}}

MAIN {
  int n;
  cin >> n;
  vector<int> arr = in_arr(n);

  vector<int> left;
  vector<int> right;
  left.push_back(arr[0]);
  right.push_back(arr[arr.size() - 1]);

  FOR(i, 1, arr.size() - 1) {
    left.push_back(left[i - 1] + arr[i]);
  }
  RFOR(i, arr.size() - 1, 1) {
    int j = right.size();
    right.push_back(right[j - 1] + arr[i]);
  }

  int min = LL_MAX;
  FOR(i, 0, right.size()) {
    int tmp = abs(left[i] - right[right.size() - 1 - i]);
    if (tmp < min) { min = tmp; }
  }

  cout << min << endl;

  return 0;
}

// vim: ft=cpp ts=2 sts=2 sw=2 tw=0
