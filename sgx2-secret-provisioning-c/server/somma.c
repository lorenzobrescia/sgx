#include <stdio.h>
#include <dirent.h>
#include <string.h>

/*#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"
void show_dir_content(char * path)
{
  DIR * d = opendir(path); // open the path
  if(d==NULL) return; // if was not able, return
  struct dirent * dir; // for the directory entries
  while ((dir = readdir(d)) != NULL) // if we were able to read somehting from the directory
    {
      if(dir-> d_type != DT_DIR) // if the type is not directory just print it with blue color
        printf("%s%s\n",BLUE, dir->d_name);
      else
      if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
        printf("%s%s\n",GREEN, dir->d_name); // print its name in green
        char d_path[255]; // here I am using sprintf which is safer than strcat
        sprintf(d_path, "%s/%s", path, dir->d_name);
        show_dir_content(d_path); // recall with the new path
      }
    }
    closedir(d); // finally close the directory
}*/

void main(int argc, char *argv[], char * envp[]){
	printf("INIZIO C\n\n");
	float primo, secondo;
	FILE* uno = fopen("/input/1.txt", "r");
	FILE* due = fopen("/input/2.txt", "r");
	
	FILE* ris = fopen("/output/ris.txt", "w");
	fscanf(uno, "%f", &primo);
	fscanf(due, "%f", &secondo);
	fclose(uno);
	fclose(due);
	printf("Il risultato e': %f\n", primo + secondo);
	fprintf(ris, "%f", primo + secondo);
	fclose(ris);
	/*
	printf("VARIABILI D'AMBIENTE\n");
	for (int i = 0; envp[i] != NULL; i++){    
        	printf("%s\n", envp[i]);
	}
	*/
	/*
	printf("\n");
	show_dir_content(".");
	printf("\n");*/
	
	printf("FINE C\n");
}
