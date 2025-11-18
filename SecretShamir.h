#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric> 
#include "Fraction.h"
using namespace std;

class ShamirSecret{
private:
    int secret;
    int n;
    int threshold;
    //vector<int> poly;
    vector<pair<int, int>> points;

    /*int calculateY(int x) {
        int y = secret;
        int power = 1;
        for (auto coeff : poly) {
            y += coeff * power;
            power *= x;
        }
        return y;
    }*/

    /*void generatePolynomial() {
        poly.resize(threshold);
        for (int i = 1; i < threshold; ++i) {
            int p = 0;
            while (p == 0) {
                p = rand() % 997;
            }
            poly[i] = p;
        }
    }*/

    int getrandom(int j) {
        srand(j * 12345 + 999); 
        return (rand()%997);
	}
public:
    ShamirSecret(int secret, int n, int threshold) {
		this->secret = secret;
		this->n = n;
		this->threshold = threshold;
    }

 /*   void createShares() {
        generatePolynomial();
        points.resize(n);
        for (int i = 1; i <= n; ++i) {
            points[i - 1] = { i, calculateY(i) };
        }
    }*/
    void createShares() {
        points.resize(n);
        for (int i = 1; i <= n; ++i) {
            int y = secret;
            int power = i;
            for (int j = 1; j < threshold; j++) {
                int coeff = getrandom(j);
                y += coeff * power; 
                power *= i;
            }
            points[i - 1] = { i, (int)y };
        }
    }

    void displayShares() {
        cout << "Secret is divided into " << n << " parts:\n";
        for (auto& p : points) {
            cout << p.first << " " << p.second << "\n";
        }
       /* cout << "generate secret from any of " << threshold << " parts.\n";*/
    }

    int reconstructSecret(vector<pair<int, int>>& shares) {
        int M = shares.size();
        Fraction result(0, 1);

        for (int i = 0; i < M; ++i) {
            Fraction term(shares[i].second, 1);
            for (int j = 0; j < M; ++j) {
                if (i != j) {
                    Fraction frac(-shares[j].first, shares[i].first - shares[j].first);
                    term = term * frac;
                }
            }
            result = result + term;
        }
        return result.num;  
    }
};