#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double d = -0.0;

    if (d == 0 && signbit(d))
    {
        cout << "-" << endl;
    }

    return 0;
}