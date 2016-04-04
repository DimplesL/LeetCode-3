#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>


using namespace std;


#define __tmain main

class Solution
{
public:

    int threeSumClosest(vector<int>& nums, int target)
    {
        int size = nums.size( );
        int min = INT_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());

        for(int index = 0; index < size - 2; index++)
        {

            for(int start = index + 1, end = size - 1;
                start < end;)
            {
                //  ���� a + b + c
                int sum = nums[index] + nums[start] + nums[end];

                //  ����ӽ���
                int dis = fabs(sum - target);

                //  ������С�Ľӽ���
                if(dis < min)
                {
                    min = dis;
                    res = sum;
                }

                if(sum == target)
                {
                    res = sum;
                    break;
                }
                else if(sum > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }

            }
        }

        return res;
    }
};


int __tmain( )
{
    int a[] = { 1, 1, 1, 0, };
    vector<int> vec(a, a + 4);

    Solution solu;
    cout <<solu.threeSumClosest(vec, 100) <<endl;

    return 0;
}
