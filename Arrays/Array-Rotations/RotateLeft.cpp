/*
Left Rotation of Array
-We use the Juggling ALgorithm to do the left array rotation
-This is also know as in place rotation
-Time Complexity: O(n)
-Space Complexity: O(1)
*/
#include<bits/stdc++.h>

using namespace std;

void print(int *arr, const int n) {
  for(int i=0;i<n;i++) 
     cout<<arr[i]<<" ";
  cout<<endl;
}

//Using Eucledian Method to find GCD
int gcd(const int a, const int b) {
  if(b==0)
     return a;
  else
     return gcd(b, a%b);
}

void leftRotate(int *arr, const int n, const int k) {
  int d=-1,i{},temp{},j{};
  for(int i=0;i<gcd(n,k);i++) {
     j=i;
     temp=arr[i];
     while(1) {
        d=(j+k)%n;
        if(d==i)
           break;
        arr[j]=arr[d];
        j=d;
     }
     arr[j]=temp;
  }
}

int main() {
  int k{}, n{};
  cout<<"Enter the Size of Array: ";
  cin>>n;
  int arr[n]{};
  cout<<"Enter the degree of Left Rotation: ";
  cin>>k;
  cout<<"GCD: "<<gcd(n,k)<<endl;
  cout<<"Enter the Array elements: ";
  for(int i=0;i<n;i++) 
     cin>>arr[i];
  leftRotate(arr,n,k);
  cout<<"Array after left rotation: ";
  print(arr,n); 
}
