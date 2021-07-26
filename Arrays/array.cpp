//A Simple Array Program
#include<bits/stdc++.h>

using namespace std;

void print(int* arr, int size) {
   cout<<"Array: ";
   for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
   cout<<endl;
}

void modify(const int location, const int value, int* arr) {
   //updating value at entered location
   arr[location-1]=value;
}

void deleteElement(const int location, int* arr, int* size_addr) {
   int i=location-1;
   while(i<*size_addr) {
      arr[i]=arr[i+1];
      i+=1;
   }
   //reduce the size by one
   int temp=*size_addr-1;
   *size_addr=temp;
}

int main() {
   //size of array
   int n{};
   cout<<"Enter the Size of Array: ";
   cin>>n;

   //creating array with size as n
   int array[n];

   //accepting the array elements
   cout<<"Enter the Array Elements: ";
   for(int i=0;i<n;i++) 
      cin>>array[i];

   //Printing the entered array
   print(array,n);

   //modify value at entered position
   modify(3,100,array);
  
   //printing array after modification
   print(array,n);

   //deleting an element from an array
   deleteElement(4,array,&n);

   //printing array after delete operation
   print(array,n);
}

/*
Program Flow
Accept the size of the Array
Print the array
Modify the array element at the mentioned position.
Printing the modified array
Deleting an element from array from specified position.
Printing the array after deletion operation.
*/
