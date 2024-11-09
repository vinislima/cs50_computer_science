
#include <stdio.h>

int main(void)
{
	int num;
	int result;

	while (1)
	{
		printf("Height: ");
        result = scanf("%d", &num);

        while (getchar() != '\n')
            ;

        if (result == 1 && num > 0)
        {
            for (int i = 1; i <= num; i++)
            {
                for (int j = 1; j <= num - i; j++)
                {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++)
                {
                    printf("#");
                }
                printf("\n");
            }
            break;
        }
        else
        {
            continue;
        }
    }
}