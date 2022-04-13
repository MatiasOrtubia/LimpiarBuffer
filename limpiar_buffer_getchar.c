/* Limpiar el buffer de stdin cuando uso getchar, para admitir un unico caracter y que no quede guardado el \n. */

#include <stdio.h>

int main(void)
{

    int c;

    do {
        printf("Ingresar caracter:\t");
        c = getchar();
        
        if(c == '\n') { /* En caso de que ponga solo ENTER. Es necesario para que no se quede esperando en el getchar. AL FINAL DEL BUFFER, NO HAY EOF (a menos que este enviando la informacion desde un archivo), SI SOLO INGRESO ENTER, EL BUFFER QUEDA VACIO SIN EOF NI NADA */
            continue;
        }

        printf("%c\n", c); /* Se imprime el caracter. */

        /* Se limpia el buffer hasta el \n, o EOF en caso de que se este ingresando un archivo. */
        while(((c = getchar()) != EOF) && (c != '\n'));

    } while(c != EOF);

    putchar('\n');

    return 0;
}


