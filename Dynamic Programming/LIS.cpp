#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> lis;

    for (int num : nums)
    {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end())
            lis.push_back(num);
        else
            *it = num;
    }

    cout << "Length of LIS: " << lis.size() << endl;
    return 0;
}
