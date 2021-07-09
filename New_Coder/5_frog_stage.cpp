//先跳1 f(n-1)  2 f(n-2) 

class Solution
{
public:
    int jumpFloor(int number)
    {
        int first = 1;
        int second = 2;
        int third = 3;

        if (number == 1)
        {
            return 1;
        }

        else if (number == 2)
        {
            return 2;
        }
        else
        {
            for (int i = 0; i < number - 3; i++)
            {
                first = second;
                second = third;
                third = first + second;
            }
            return third;
        }
    }
};