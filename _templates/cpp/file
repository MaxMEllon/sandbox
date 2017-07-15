#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <queue>
#include <deque>
#include <stack>

typedef long l;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef double D;

using namespace std;

ll gcd(ll a, ll b);
ll gcd3(ll a, ll b, ll c);
ll lcm(ll a, ll b);
void safe_sort(vector<ll> *arr);
void unsafe_sort(vector<ll> *arr);
bool is_prime(ll num);
vector<ll> generate_prime(ll num);

int main() {
  return 0;
}

// ２数の最大公約数
ll gcd(ll a, ll b) {
  ll t; while (b != 0) { t = b; b = a % b; a = t; } return a;
}

// ３数の最大公約数
ll gcd3(ll a, ll b, ll c) {
  ll s, t; s = gcd(a, b); t = gcd(c, s); return t;
}

// 最大公倍数
ll lcm(ll a, ll b) {
  if (a * b == 0) return 0; return (a * b / gcd(a, b));
}

/** {{{
 * 安全なソート
 * 使い方
 * vector<ll> arr; // データ列を vectorで用意
 * safe_sort(&arr);     // アドレスを渡す
 }}} */
void safe_sort(vector<ll> *arr) {
  // 逆順にするとき
  // return stable_sort(arr->begin(), arr->end(), greater<ll>());
  return stable_sort(arr->begin(), arr->end());
}

/** {{{
 * 高速なソート
 * 使い方
 * vector<ll> arr; // データ列を vectorで用意
 * unsafe_sort(&arr);     // アドレスを渡す
 }}} */
void unsafe_sort(vector<ll> *arr) {
  // 逆順にするとき
  // return sort(arr->begin(), arr->end(), greater<ll>());
  return sort(arr->begin(), arr->end());
}

// 素数判定
bool is_prime(ll num) {
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
}

/** {{{
 *  素数列を生成
 *  使い方
 *  vector<ll> arr = generate_prime(n);
 }}} */
vector<ll> generate_prime(ll num) {
  vector<ll> arr;
  for (int i = 2; i < num; i++) {
    if (is_prime(i)) arr.push_back(i);
  }
  return arr;
}
