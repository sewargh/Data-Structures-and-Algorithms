#include <iostream>
using namespace std;

// Given a number N return the index value of the Fibonacci sequence, where the sequence is:

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...
// the pattern of the sequence is that each value is the sum of the 2 previous values, that means that for N=5 → 2+3

//For example: fibonacciRecursive(6) should return 8

int fibonacciIterative(int n){
  int num1 = 0;
  int num2 = 1;
  int ans = 0;
  if(n == 0)return num1; else if (n==1) return num2;
  for(int i = 2; i <= n; i++){
    ans=num1+num2;
    num1=num2;
    num2=ans;
  }
  return ans;
}
int fibonacciRecursive(int n){
  if(n==0) return 0;
  else if (n==1) return 1; // or write=>  if(n<2) return n;
  else return (fibonacciRecursive(n-1)+fibonacciRecursive(n-2));
}
int main() {
  cout << fibonacciRecursive(12) << endl;
  cout << fibonacciIterative(12) << endl;

}
