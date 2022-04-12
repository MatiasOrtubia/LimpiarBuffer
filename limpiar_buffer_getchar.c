#include <stdio.h>

int main(void)
{
    int c;

    printf("Ingresar caracter:\t");
    while((c = getchar()) != EOF)
    {
        /* En caso de que ponga solo ENTER. Es necesario para que no se quede esperando en el getchar. AL FINAL DEL BUFFER NO HAY EOF, SI SOLO INGRESO ENTER, EL BUFFER QUEDA VACIO SIN EOF NI NADA */
        if(c == '\n')
        {
            printf("Ingresar caracter:\t");
            continue;
        }

        printf("%c\n", c);

        /* Limpieza del buffer */
        while(((c = getchar()) != EOF) && (c != '\n'));
        
        printf("Ingresar caracter:\t");
    }
    putchar('\n');

    return 0;
}
