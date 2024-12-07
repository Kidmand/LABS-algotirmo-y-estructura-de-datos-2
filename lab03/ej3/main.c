#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}




unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
bool res  = true;
  FILE *file = NULL; 
   file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
 unsigned int length = 0;
 unsigned int i = 0u;
// max_size=max_size;
  while (!feof (file) && i<max_size)
  {
   res = fscanf (file, "%u -> *%c*\n", &indexes[i], &letters[i]);
   
   if (res != 1) {
    fprintf(stderr, "Invalid array.\n");
    exit(EXIT_FAILURE);
   }
    i++;
    length++;
  }
  
  fclose(file);

 
  return length;
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
       // print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}



void reconstruccion (unsigned int indexes[], char letters[],  char sorted[], unsigned int length) {

 for (unsigned int i=0u; i<length; i++) {
  if (indexes[i]>length-1) {
   fprintf (stderr,"Error en el indice del fichero\n");
   exit(EXIT_FAILURE);
  } else {
  sorted[indexes[i]]=letters[i];
  }
 }
}

int main(int argc, char *argv[]) {
   // FILE *file;
   char *filepath = NULL;
   filepath = parse_filepath(argc, argv);
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0u; 
    length = data_from_file (filepath, indexes , letters, MAX_SIZE);
    reconstruccion(indexes, letters, sorted, length);
   
    dump(sorted, length);

    return EXIT_SUCCESS;
}

