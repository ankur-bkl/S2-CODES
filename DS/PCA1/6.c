#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and cols of A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and cols of B: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Multiplication not possible");
        return 0;
    }

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }

    printf("Result:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}