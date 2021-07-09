//先跳1 f(n-1)  2 f(n-2) 3f(n-3) 4 f(n-4)

class Solution
{
public:
    int jumpFloorII(int number)
    {
        int first = 1;
        int second = 2;
        int last = 4;
        int sum = 7;

        if (number == 1) //f1
        {
            return 1;
        }

        else if (number == 2) //f2
        {
            return 2;
        }

        //求f3 f(3) = 1+f(2)+f(1)
        //f4 f(4) = 1+f(1)+f(2)+f(3)
        else
        {
            for (int i = 0; i < number - 3; i++)
            {
                last = sum + 1;
                sum = sum + last;
            }

            return last;
        }
    }
};