
#include <stdio.h>

int main(void)
{
    int num, num_cont;
    int result;
    int vinte_cinco, dez, cinco, um;
    int cont_vinte_cinco, cont_dez, cont_cinco, cont_um;
    int a, b, c, d, soma;

    while (1)
    {
        printf("Change owed: ");
        result = scanf("%d", &num);

        while (getchar() != '\n')
            ;

        if (result == 1 && num > 0)
        {
            num_cont = num;
            vinte_cinco = 25;
            dez = 10;
            cinco = 5;
            um = 1;

            cont_vinte_cinco = 0;
            cont_dez = 0;
            cont_cinco = 0;
            cont_um = 0;

            a = 0;
            b = 0;
            c = 0;
            d = 0;

            while (num_cont >= vinte_cinco)
            {
                a = num_cont - 25;
                num_cont = a;
                cont_vinte_cinco = cont_vinte_cinco + 1;
            }

            while (num_cont >= dez)
            {
                b = num_cont - 10;
                num_cont = b;
                cont_dez = cont_dez + 1;
            }

            while (num_cont >= cinco)
            {
                c = num_cont - 5;
                num_cont = c;
                cont_cinco = cont_cinco + 1;
            }

            while (num_cont >= um)
            {
                d = num_cont - 1;
                num_cont = d;
                cont_um = cont_um + 1;
            }

            soma = cont_vinte_cinco + cont_dez + cont_cinco + cont_um;
            printf("%d\n", soma);
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}