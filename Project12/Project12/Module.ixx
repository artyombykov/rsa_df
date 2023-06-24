#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int main() {
    int p = 3;
    int q = 5;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e, d;
    for (int i = 2; i < phi; i++) {
        if (gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }
    for (int i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }
    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    int msg;
    cout << "Enter a message to encrypt: ";
    cin >> msg;

    int c = pow(msg, e);
    c = c % n;

    int decrypted_msg = pow(c, d);
    decrypted_msg = decrypted_msg % n;

    cout << "Encrypted message: " << c << endl;
    cout << "Decrypted message: " << decrypted_msg << endl;

    return 0;
}