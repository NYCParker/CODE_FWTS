//first second third 迭代

class Solution
{
public:
    int Fibonacci(int n)
    {
        int first = 0;
        int second = 1;
        int third = 1;  //n 项

        if (n == 0)
        {
            return 0;
        }

        else if (n == 1)
        {
            return 1;
        }

        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                first = second;
                second = third;
                third = first + second;
            }
            return third;
        }
    }
};