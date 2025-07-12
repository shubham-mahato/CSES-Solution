#include<iostream>
using namespace std;

int main() {
    long long num, sum = 0;
    cin >> num;

    for(long long i = 0; i < num - 1; i++) {
        long long temp;
        cin >> temp;
        sum += temp;
    }

    long long exp = (num * (num + 1)) / 2;
    cout << (exp - sum);

    return 0;
}
