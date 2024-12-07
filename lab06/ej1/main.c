/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
  /*  abb_dump(tree);
    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } else {
        printf("\nÁrbol vacío\n");
    }*/
    
    int select, length;
    bool result=true;
    bool existe; 
    abb_elem elem;
    while(result) {
    printf("\nIngrese un valor entre 1 y 7: ");
    scanf("%d",&select);
     switch (select) {
      case 1: 
             abb_dump(tree);
             break;
      case 2:
             printf("Ingrese el elemento que desea agregar:\n ");
             scanf("%d",&elem);
             tree = abb_add(tree, elem);
             abb_dump(tree);
             break;
      case 3:
             printf("Ingrese el elemento que desea borrar:\n ");
             scanf("%d",&elem);
             tree = abb_remove(tree,elem);
             abb_dump(tree);
             break;
      case 4: 
             printf("Ingrese el elemento que desea ver si existe:\n ");
             scanf("%d",&elem);
             existe = abb_exists(tree, elem); 
             if (existe) {
              printf("El elemento sí existe en árbol\n");
             } else {
              printf("El elemento no existe en el árbol\n");
             }
             break;
      case 5: 
             length = abb_length(tree);
             printf("La longitud del árbol es: %d", length);
             break;
      case 6: 
             printf("El máximo es: %d, el mínimo es: %d, la raíz es: %d", abb_min(tree),abb_max(tree),abb_root(tree));
             break;
      case 7: 
             result = false;
      
     }
    }
    
    tree = abb_destroy(tree);
    
    /*
     * Modificar e implementar con un ciclo una interfaz que permita al usuario
     * realizar una de las siguientes operaciones en cada iteración:
     *
     * 1 ........ Mostrar árbol por pantalla
     * 2 ........ Agregar un elemento
     * 3 ........ Eliminar un elemento
     * 4 ........ Chequear existencia de elemento
     * 5 ........ Mostrar longitud del árbol
     * 6 ........ Mostrar raiz, máximo y mínimo del árbol
     * 7 ........ Salir
     *
     * Se debe solicitar un número de entrada para realizar una de las acciones.
     *
     * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
     * elemento a agregar, eliminar o chequear respectivamente.
     *
     * Al salir debe liberarse toda la memoria utilizada.
     *
     */
    return (EXIT_SUCCESS);
}
