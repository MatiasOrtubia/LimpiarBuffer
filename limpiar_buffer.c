/* Ejemplo de limpieza de buffer para fgets  */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nombre[10];

    for(int i = 0; i <= 10; i++)
    {
        printf("Como te llamas?\t");
        if(fgets(nombre, 10, stdin) != NULL)
        {
            if(!strchr(nombre, '\n')) // Chequea si existe un '\n'
            {
                int c;
                while(((c = getchar()) != EOF) && (c != '\n')); // Consume el resto de char hasta \n. fgets NO leyo el \n, pero al ingresar el input ingrese un \n que se guardo en el buffer.

                if(c == EOF)
                {
                    fprintf(stderr, "Error\n");
                    return 1;
                }
                printf("Mucho gusto, %s.\n", nombre);
            }
        
            else // En este caso, fgets pudo leer todo, por lo que guardo el \n al final.
            {
                nombre[strlen(nombre) - 1] = '\0'; // Se elimina el ENTER (solo para poner el '.' despues, sino queda abajo)
                printf("Mucho gusto, %s.\n", nombre); // En este caso, no se incluye el \n porque fgets pudo leerlo
            }
        }
    }

    printf("Mucho gusto, %s.\n", nombre);
    return 0;
}
