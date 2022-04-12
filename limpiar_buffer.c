/* Ejemplo de limpieza de buffer para fgets, podria servir para getchar tambien,  */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nombre[10];

    for(int i = 0; i <= 10; i++)
    {
        printf("Como te llamas?\t");/*
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
*/

        /* Otra forma que estuve probando */
        if(fgets(nombre, 10, stdin) != NULL) {
            size_t n = strlen(nombre);
            int c;

            if(feof(stdin)) { // Si el buffer esta vacio, entonces se intento leer mas alla de EOF, por lo que feof(stdin) es != 0)
                if(nombre[n - 1] == '\n')
                    nombre[n -1] = '\0';
            }

            else if((c = getchar()) != EOF) // Si el buffer NO esta vacio, c tuvo que obtener algo distinto a EOF
                while(((c = getchar()) != EOF) && (c != '\n')); // Limpia lo que queda
            /*
            if(feof(stdin)) { // Si el buffer esta vacio....
                int c;
                while(((c = getchar()) != EOF) && (c != '\n'));
            }

            else { // Si el buffer sigue teniendo cosas
                printf("n = %zd\n", n);
                if(nombre[n - 1] == '\n')
                    nombre[n - 1] = '\0';
                }
            */

            printf("Mucho gusto, %s.\n", nombre);
        }
    }
    return 0;
}

/*
 
    fgets etc
    int c;
    while(((c = getchar()) != EOF) && (c != '\n')); // Primero limpia todo el buffer.
    --Se saca

*/


