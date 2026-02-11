#include<bits/stdc++.h>
using namespace std;
int main()
{
	int isum = 0;
	int i,j,iFirstTerm, iNumTerms, iConstantRatio;
	cout << "please enter the constant ratio : " << "\n";
	cin >> iConstantRatio;
	cout << "please enter the number of terms; " << "\n";
	cin >> iNumTerms;
	for(i = 0; i <= iNumTerms; i++){
		iFirstTerm = 1;
		for(j = 0; j < i; j++){
			iFirstTerm *= iConstantRatio;
			cout << iFirstTerm << " ";
		}
		isum += iFirstTerm;
		cout << "[" << isum << "]" << "\n";
	}
	cout << "\n" << "Sum = " << isum << "\n";
	return 0;

}
