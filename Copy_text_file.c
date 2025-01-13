#include <stdio.h>

int main() {
    FILE *fp_read , *fp_write;
    if ((fp_read = fopen("Input.txt" , "r")) == NULL){
        printf("error opening file1 \n");
        return 1 ;
    }
    if ((fp_write = fopen("Output.txt" , "w")) == NULL){
        printf("error opening file2\n");
        return 2 ;
    }


    char letter;
    while (!feof(fp_read)){
        letter = fgetc(fp_read);
        //printf("%c",letter);
        if(!feof(fp_read)){
            fputc(letter,fp_write);
        }
    }
    rewind(fp_read);
    fputs("\n\n" , fp_write);


    char string[100+1];
    while(!feof(fp_read)){
        fgets(string , 20 , fp_read);
        fputs("\n" , fp_write);
        fflush(fp_write);
        fputs(string , fp_write);
        fflush(fp_write);
    }
    rewind(fp_read);
    fputs("\n\n\n" , fp_write);
    fflush(fp_write);

//
    while(!feof(fp_read)){
        fscanf(fp_read, "%s" ,string);
        if (!feof(fp_read)){
            fprintf(fp_write,string);
        }
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
    
}
