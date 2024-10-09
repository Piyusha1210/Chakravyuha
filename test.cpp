#include <iostream>
#include <vector>
#include "main.cpp"

using namespace std;

void runTests()
{

    // Test Case Set 1
    cout << "\nRunning Test Case Set 1:" << endl;
    int power1 = 100, skips1 = 1, recharges1 = 0;
    vector<int> enemies1 = {20, 30, 40, 10, 15, 25, 35, 5, 10, 15, 20};
    cout << (solve(0, power1, skips1, recharges1, power1, 0, enemies1) ? "Abhimanyu will Succeed!" : "Abhimanyu will Lose!") << endl;

    // Test Case Set 2
    cout << "\nRunning Test Case Set 2:" << endl;
    int power2 = 150, skips2 = 1, recharges2 = 1;
    vector<int> enemies2 = {20, 25, 35, 45, 30, 20, 50, 10, 15, 20, 40};
    cout << (solve(0, power2, skips2, recharges2, power2, 0, enemies2) ? "Abhimanyu will Succeed!" : "Abhimanyu will Lose!") << endl;

    cout << endl;
}

int main()
{
    runTests();
    return 0;
}