
//看一下大佬们怎么写的
// 1 直接排序 排完之后 数组中间那个数肯定是的    时间复杂度并非最优
//2 候选法（最优解）在遍历数组时保存两个值：一是数组中一个数字，一是次数。 
//遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1； 减到0则忽略前面所有 重新从新的地方定候选人 
//若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可
//3 然后遍历这个array，hashmap的key是array里的不同数字，value是这些数字出现在array里的次数
//我们遍历hashmap，检测value（即当前数字出现的次数）是否大于数组array长度的一半， hashmap不会啊= =
//如果有这个数字，我们return回key（即当前遍历到的数字），
//如果我们走完了整个hashmap还没有发现这样一个数字，我们需要return 0

#include <bits/stdc++.h>
using namespace std;

//解法1  注意sort的用法
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        return numbers[numbers.size() / 2];
    }
};

//解法2
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int cand = numbers[0];
        int count = 1;

        for (int i = 1; i < numbers.size(); i++)
        {
            if (count == 0) //如果厮杀打平，则抛弃前面所有的数，初始化，继续厮杀
            {
                count = 1;
                cand = numbers[i];
            }

            if (cand == numbers[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return cand;
    }
};

//解法3 类似于原来的解法，但是用map实现
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {

    }
};