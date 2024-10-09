#include <iostream>
#include <vector>
using namespace std;

bool solve(int idx, int power, int skip, int recharge, int totalPower, int backEnemy, vector<int> &enemy)
{
    if (idx > 11)
        return true;

    bool ans = false;

    if (skip)
    {
        ans = ans || solve(idx + 1, power, skip - 1, recharge, totalPower, 0, enemy);
    }

    if(power < enemy[idx] && recharge)
    {
        power = totalPower;
        recharge--;
    }

    if (power >= enemy[idx])
    {
        power -= enemy[idx];

        if ((idx == 4 || idx == 8) && backEnemy > 0)
        {
            if (power >= backEnemy)
            {
                power -= backEnemy;
                backEnemy = 0;
            }
            else if (recharge > 0)
            {
                recharge--;
                power = totalPower;
                power -= backEnemy;
                backEnemy = 0;
            }
            else
            {
                return false;
            }
        }

        if (idx == 3 || idx == 7)
        {
            backEnemy = enemy[idx] / 2;
        }
        else
        {
            backEnemy = 0;
        }
        
        ans = ans || solve(idx + 1, power, skip, recharge, totalPower, backEnemy, enemy);
    }
    return ans;
}

int main()
{
    int power, skip, recharge;
    cin >> power >> skip >> recharge;

    vector<int> enemy(12);
    for (int i = 1; i <= 11; i++)
    {
        cin >> enemy[i];
    }

    bool ans = solve(1, power, skip, recharge, power, 0, enemy);

    if (ans)
        cout << "Yes, Abhimanyu will Succed!" << endl;
    else
        cout << "No, Abhimanyu will Loose!" << endl;

    return 0;
}


/*

Test case - 1
12 1 0
1 2 3 1 2 3 4 1 2 3 5
No, Abhimanyu will Loose!


Test case - 2
20 1 1
4 2 3 6 2 7 4 4 5 3 5
No, Abhimanyu will Loose!


Test case - 3
20 2 1
4 2 3 6 2 7 4 4 5 3 5
Yes, Abhimanyu will Succed!


Test case - 4
50 2 3
10 20 30 15 25 35 40 10 20 30 50
No, Abhimanyu will Loose!


Test case - 5
50 2 1
10 20 30 15 25 35 40 10 20 30 50
No, Abhimanyu will Loose!

Test case - 6
200 1 1
50 30 40 20 10 25 15 5 20 30 60
Yes, Abhimanyu will Succed!

*/