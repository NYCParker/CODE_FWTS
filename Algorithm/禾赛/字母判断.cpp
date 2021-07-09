#include<stdio.h>
#include<string.h>

int Judge_char(char su)
{
    if ((su <= 'z' && su >= 'a') || (su <= 'Z' && su >= 'A')) {
        return 1;
    }
    return 0;
}

int main()
{
    char Arr[1024] = { 0 };
    char Src[1024] = { 0 };
    int i, j, k;
    while (gets(Arr) > 0) 
	{
        char A = 'A', Z = 'Z', a = 'a', z = 'z';
        k = 0;
        int len = strlen(Arr);
        for (; A <= 'Z', a <= 'z'; A++, a++) {
            for (i = 0; i < len; i++) {
                if (Arr[i] == A || Arr[i] == a) {
                    Src[k] = Arr[i];
                    k++;
                }
            }
        }

        k = 0;
        for (j = 0; j < len; j++) {
            if (Judge_char(Arr[j]) == 1) {
                printf("%c", Src[k]);
                k++;
            } else {
                printf("%c", Arr[j]);
            }
        }
        printf("\n");
    }
    return 0;
}