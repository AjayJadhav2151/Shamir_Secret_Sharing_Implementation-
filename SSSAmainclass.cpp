#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric> 
#include "SecretShamir.h"
//using namespace std;

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

    int m;
        cout << "how many keys you have to reconstruct the secret: ";
        cin >> m;
        while (m < k)
        {
            cout << "Number of shares must be at least " << k << "Please enter again: ";
			cin >> m;   
        }

    vector<pair<int, int>> shares(m);
    cout << "Enter the shares (x and y values) one by one:\n";
    for (int i = 0; i < m; i++) {
        int x_val, y_val;
        cout << "Share " << (i + 1) << ": ";
        cin >> x_val >> y_val;
        shares[i] = make_pair(x_val, y_val);
    }


    cout << "Recovered secret is: " << sss.reconstructSecret(shares) << endl;

    return 0;
}