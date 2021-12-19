//Assignment 1  - RSA implementation

#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

// find gcd
double gcd(int n, int m) {
	while(true) {
		int temp = n % m;
		if (temp == 0)
			return m;
		n = m;
		m = temp;
	}
}

int main() {
	// two primes
	double p = 5, q = 11;

	// calc n, phi
    double n = p * q, phi = ((p - 1) * (q - 1));
    // n is max value that can be unambiguously encrypted

	// calculation for e
    double e = 3;
	while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

	double msg;
	cout << "Integer to encrypt: ";
	cin >> msg;

	cout << "Original message: " << msg << endl;

	// get d
	double d =  fmod((1/e), phi);
	// enc = m^e mod n && dec = enc^d mod n
	double enc = pow(msg, e);
	double dec = pow(enc, d);
	enc = fmod(enc, n);
	dec = fmod(dec, n);

	cout << "Encrypted: " << enc << endl;

	cout << "Decrypted: " << dec << endl;
}
