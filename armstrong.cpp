#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int n = 0;

    // Calculate the number of digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    // Calculate the sum of digits raised to the power n
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    return sum == originalNum;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
