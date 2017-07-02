#include <iostream>

using namespace std;

bool my_swap(int arr[], int p1, int p2);
bool my_order(int arr[], int p1, int p2);

int main()
{
  int n = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int j = 0; j < n; j++) {
    for (int k = 0; k < j; k++) {
      if (j + k < 2 * n - 3) {
        (my_order(arr, j, k)) && (my_swap(arr, j, k));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

bool my_order(int arr[], int p1, int p2) {
  return arr[p1] < arr[p2];
}

bool my_swap(int arr[], int p1, int p2) {
  int tmp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = tmp;
  return true;
}

