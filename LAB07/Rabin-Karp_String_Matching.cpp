

#include <bits/stdc++.h> 
using namespace std; 

#define d 256 

void rabinKarp(string pat, string txt, int q) 
{ 
	int M = pat.length();
	int N = txt.length();
	int i, j; 
	int p = 0;  
	int t = 0;  
	int h = 1; 
	bool found = 0;
	int hits = 0;

	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	for (i = 0; i <= N - M; i++) 
	{ 
		if ( p == t ) 
		{ 
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			if (j == M) 
			{
				cout<<"Pattern found at index "<< i<<endl; 
				found = 1;
			}
			hits++;
		} 
 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 
			if (t < 0) 
			t = (t + q); 
		} 
	} 

	if(!found)
		cout << "Pattern not found" << endl;

	cout << "Total number of hits when the hash values were same : " << hits << endl;
} 

int main() 
{ 
	string text, pattern;
	int q; //  this is the mode value we will be using in the rabinkarpt algo
	cout << "Enter Your TEXT : ";
	cin >> text;
	cout << "Enter pattern to search : ";
	cin >> pattern;
	cout << "Enter the value of q : ";
	cin >> q;


	rabinKarp(pattern, text, q);
	return 0; 
} 
