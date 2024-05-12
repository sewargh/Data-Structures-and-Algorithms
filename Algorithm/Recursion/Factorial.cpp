#include <iostream>
using namespace std;

int findFactorialRecursive(int number){
  if(number == 1) // or 2 becaue 1*1 = 1 then 2*1 = 2;
    return 1;
  else return findFactorialRecursive(number-1)*number; //number-1 => we want to go lower and lower until we get to the base case;
}
int findFactorialIterative(int number){
  int ans  = 1;
  for (int i=1; i<=number; i++)
    ans*=i;
  return ans;
}
int main() {
  cout << findFactorialRecursive(2) << endl;
  cout << findFactorialIterative(1) << endl;

}
