#include <iostream>
#include <cmath>
#include "nomer_1.h"

using namespace std;

double nomer_1() {
    int n;
    cout<<"vvedite chislo 'n'"<<endl;
    cin>>n;

    double result = 0;
    double result1 = 0;
    double result2 = 0;
    double result3 = 0;

    for (int i=1; i<=n; i++) {
        result1 += 2;
        result1 = sqrt(result1);
    }

    int i = 1;
    while (i<=n) {
        result2 += 2;
        result2 = sqrt(result2);
        i++;
    }

    i = 1;
    do {
        result3 += 2;
        result3 = sqrt(result3);
        i++;
    } while(i<=n);

    result = (result1 + result2 + result3) / 3;
    return result;
}
