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