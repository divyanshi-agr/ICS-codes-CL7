#include<iostream>
 
using namespace std; 

int findMinX(int num[], int rem[], int k) { 
    int x = 1, j;
    // this loop will always break.
    while (true) {
        // Check if remainder of x % num[j] is
        // rem[j] or not (for all j from 0 to k-1)
        for (j = 0;j < k;j++)
            if (x % num[j] != rem[j])
               break;
        // If all remainders matched, we found x
        if (j == k) 
            return x;
        // Else try next number
        x++; 
    }
} 

int main(void) { 
	int n;
	cout << "\nEnter n : ";
	cin >> n;
	int num[n], rem[n]; // [5, 7] [1, 3]
	// x % num[i] = rem[i]
	cout << "\nEnter num: ";
	for(int i = 0;i < n;i++)
		cin >> num[i];
    // Assumption: Numbers in num[] are pairwise co-prime
    // (gcd for every pair is 1)
	cout<<"\nEnter rem: ";
	for(int i = 0;i < n;i++)
		cin >> rem[i];
	
    // int num[n] = {3, 4, 5, 7};
    // int rem[] = {2, 3, 1, 2};
    
    int k = sizeof(num) / sizeof(num[0]);
    cout << "\nx is " << findMinX(num, rem, k); 
   
    return 0; 
} 
