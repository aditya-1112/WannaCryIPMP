//program for in-place matrix transpose 
#include <bits/stdc++.h> 
#define HASH_SIZE 128 
using namespace std; 

void Print2DArray(int *A, int nr, int nc) { 
	for(int r = 0; r < nr; r++){ 
		for(int c = 0; c < nc; c++) 
		    cout<<setw(4)<<*(A + r*nc + c); 
		cout<<endl; 
	}
    cout<<endl; 
} 

void MatrixInplaceTranspose(int *A, int r, int c){ 
	int size = r*c - 1; 
	int t; 
	int next; 
	int cycleBegin; 
	int i; 
	bitset<HASH_SIZE> b; 
    b.reset(); 
	b[0] = b[size] = 1; 
	i = 1; 
	while (i < size) { 
		cycleBegin = i; 
		t = A[i]; 
		do{ 
			next = (i*r)%size; 
			swap(A[next], t); 
			b[i] = 1; 
			i = next; 
		} 
		while (i != cycleBegin); 
        for (i = 1; i < size && b[i]; i++) 
			; 
		cout << endl; 
	} 
} 


int main() { 
	int r = 5, c = 6; 
	int size = r*c; 
	int *A = new int[size]; 
    for(int i = 0; i < size; i++) 
		A[i] = i+1; 
    Print2DArray(A, r, c); 
	MatrixInplaceTranspose(A, r, c); 
	Print2DArray(A, c, r); 
    delete[] A; 
    return 0; 
} 

