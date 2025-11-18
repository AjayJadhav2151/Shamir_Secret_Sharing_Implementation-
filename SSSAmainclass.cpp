#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric> 
#include "SecretShamir.h"
using namespace std;

int main() {
    cout << "Enter the Secret : ";
    int secret;
	cin >> secret;
	cout << "Enter number of shares n : ";
    int n;
	cin >> n;
	cout << "Enter threshold k : ";
    int k;
	cin >> k;

    ShamirSecret sss(secret, n, k);
    sss.createShares();
    sss.displayShares();
    cout << "Recovered secret is: " << sss.reconstructSecret() << endl;

    return 0;
}