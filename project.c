#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include<stdlib.h>
#include<string.h>

char global_mother[100][100];


void type_of_file(){
    int counter = 0 ;
    char type_of_file[100];
    while(1){
        char c = getchar();
        if(c != ' '){
            type_of_file[counter] = c ;
            counter ++ ;
        }else{
            break ;
        }
    }
    type_of_file[counter] = '\0';

}
int* counter_of_char_int_wich_line(char* address){
    int* number_char = (int*)malloc(200*sizeof(int));
    FILE* my_file = fopen(address,"r");
    int i = 0 ;
    while(1){
       // printf("-");
        int counter = 0 ;
        char c = fgetc(my_file);
        if(c != EOF){
            while(1){
                //printf("*");
                if(c == '\n' || c == EOF){
                   // printf("*");
                    number_char[i] = counter ;
                    i++ ;
                    break;
                }else{
                    counter++ ;
                    c = fgetc(my_file);
                }
            }
        }else{
            break;
        }
    }
    return number_char ;
}
void ctreate_file(){


        char address[200];
        int flag = 0 ;

       // scanf("%s",address);
       int i = 0 ;
       while(1){
        char c =   getchar();
        if(c == '"'){

        }else{
            if(c == '\n'){
                break;
            }else{
                address[i] = c;
                i++ ;
            }
        }
       }
       address[i] = '\0';




        char address_of_dir[100];
        int size = strlen(address);

        int j = 0 ;
        for(int i = size - 1 ; i >= 0 ; i --){
            char c = address[i];
            if(c == '/'){

                break ;

            }else{
                j ++ ;

            }
        }
        for(int i = 0 ; i < size-j ; i++){
            address_of_dir[i] = address[i];
        }
        address_of_dir[size-j] = '\0';
        //printf("%s",address_of_dir);


    int size_2 = strlen(address_of_dir);
    char temp_address[size_2];

    for(int i = 0 ; i < size_2 ; i ++){
        char c = address_of_dir[i];

        if(c != '/'){
            temp_address[i] = c;
        }else{
            temp_address[i] = '\0' ;
            mkdir(temp_address);
            temp_address[i] = c ;
           }
    }
    FILE* my_file = fopen(address,"w");
    fclose(my_file);
}
////////////////

char* inserter(){
    char* address;
    address = (char*)malloc(200*sizeof(char));
    int flag = 0 ;
    int num_cot = 0 ;

       int i = 0 ;
       while(1){
        char c =   getchar();
        if(c == '"'){
            flag = 1 ;
            num_cot ++ ;
        }else{
            if( (c == ' ' && flag == 0)|| (num_cot == 2) ){
                break;
            }
            else{
                address[i] = c;
                i++ ;
            }
        }
       }
        address[i] = '\0';
        //printf("\n%s\n",address);
    FILE* read_for_exist = fopen(address,"r");
    if(read_for_exist == NULL){
        printf("The file that you choosed is not exist!\n");
        exit(0);
    }
    fclose(read_for_exist);
   // printf("%s",address);
   // printf("--%c--",*address);
    return address ;
}
char* get_string(){

    //static char str[200];
    char * str ;
    int flag = 0 ;
    str = (char*)malloc(200 * sizeof(char));
       int i = 0 ;
       while(1){
        char c =   getchar();
        if(c == '"'){
            flag ++ ;
        }else{
            if(c == '\n' || (c == ' ' && flag == 0) || flag == 2){
                break;
            }else{
                str[i] = c;
                i++ ;
            }
        }
       }
       str[i] = '\0';

      // printf("%s",address);

    return str ;



}
void get_position(char address[],char string_to_position[]){
    FILE* origin_2 = fopen(address,"r");
    int line_num , char_num ;
    type_of_file();
    scanf("%d",&line_num);
    getchar();
    scanf("%d",&char_num);
  //  printf("line: %d char : %d",line_num,char_num);
      char t[100];
    for(int i = 0 ; i < line_num - 1 ; i ++){
        if(fgets(t,100,origin_2) == NULL){
            printf("Error!");
            return ;
        }
    }
    for(int i = 0 ; i < char_num ; i ++){
        char c = fgetc(origin_2);
        if(c == EOF){
            printf("Error!");
            return ;
        }
    }
    fclose(origin_2);
    char srting_to_read[100];
    FILE* my_file = fopen(address,"r");
    //char df[100] = "root\\new\\name.txt";
    FILE* temping_file = fopen("root\\h.txt","w");
    for(int i = 1 ; i < line_num - 1 ; i ++){
    fgets(srting_to_read,100,my_file);

    fputs(srting_to_read,temping_file);
    }

    char c ;

    for(int i = 0 ; i < char_num ; i ++){
        c = fgetc(my_file);
        fputc(c,temping_file);
    }

    //fputs(string_to_position,temping_file);

    //
    int size = strlen(string_to_position);
    for(int i = 0 ; i < size ;  i ++){
        if(string_to_position[i] == '\\'){
            if(string_to_position[i+1] == 'n'){
                fputc('\n',temping_file);
                i ++ ;
            }else{
                fputc('\\',temping_file);
                i++ ;
            }
        }else{
            fputc(string_to_position[i],temping_file);
        }
    }
    //

    while(1){
        c = fgetc(my_file);
        if(c == EOF){
            //fputc(c,temping_file);
            break;
        }else{
            fputc(c,temping_file);
        }
   }




   fclose(temping_file);
   fclose(my_file);

   FILE* org = fopen(address,"w");
   FILE* temp = fopen("root\\h.txt","r");

   while(1){
    if(fgets(srting_to_read,100,temp) == NULL){
        break ;
    }

    fputs(srting_to_read,org);
   }
   fclose(org);
   fclose(temp);
   remove("root\\h.txt");

}
char* get_address(){
    char* address ;

    address = (char*) malloc(200 * sizeof(char));
    int i = 0 ;
    while(1){
        char c =   getchar();
        if(c == '"'){

        }else{



            if(c == '\n'){
                break;
            }else{
                address[i] = c;
                i++ ;
            }
        }
       }
       address[i] = '\0';
       return address ;
}


void cat(){
    char * address = inserter();
    char show_text[100] ;
    FILE* org = fopen(address,"r");
    while(1){
    if(fgets(show_text,100,org) == NULL){
        break ;
    }
    printf("%s",show_text);
    printf("\n");
    }


}

void removestr_func(char address[],int num_of_line,int num_of_char,int amount_of_char_delete,char type_of_delete,int* list){

    FILE* origin_2 = fopen(address,"r");
    FILE* temp = fopen("temp.txt","w");
    char t[100];
    for(int i = 0 ; i < num_of_line - 1 ; i ++){
        if(fgets(t,100,origin_2) == NULL){
            printf("Error!");
            return ;
        }
    }
    for(int i = 0 ; i < num_of_char ; i ++){
        char c = fgetc(origin_2);
        if(c == EOF){
            printf("Error!");
            return ;
        }
    }
    fclose(origin_2);
    FILE* origin = fopen(address,"r");
    char str[100];
    if(type_of_delete == 'b'){
        int place_curser = (num_of_char) - amount_of_char_delete ;
        int sum = place_curser ;
       // printf("1: %d\n",sum);
        while(sum < 0){
            num_of_line -= 1 ;
            if(num_of_line == 0){
                printf("Error!");
                return ;
            }
            sum += (list[num_of_line - 1] + 1 );
           // printf("2 : %d",sum);
        }
        num_of_char = sum ;
    }


        for(int i = 1 ; i < num_of_line - 1; i ++){
            fgets(str,100,origin);
            //printf("--%s--\n",str);
            fputs(str,temp);
        }
       // printf("*-%d-*",num_of_line);
        //printf("--%s--",str);
        for(int i = 0 ; i < num_of_char ; i ++){
            char c = fgetc(origin);
            fputc(c,temp);
        }

        for(int i = 0 ; i < amount_of_char_delete ; i ++){
            char c = fgetc(origin);
           // printf("\n%c-",c);
        }
       // printf("b%db",amount_of_char_delete);
        while(1){
           char c = fgetc(origin);
           if(c != '\n'){
            if(c == EOF){
                break;
            }else{
            fputc(c,temp);
            }
           }else{
            fputc(c,temp);
            break;
           }
          // printf(" * ");
        }
        while(1){
            if(fgets(str,100,origin) != NULL){
                fputs(str,temp);
            }else{
                break ;
            }
        }


    fclose(temp);
   fclose(origin);

   FILE* org = fopen(address,"w");
   FILE* tem = fopen("temp.txt","r");

   while(1){
    if(fgets(str,100,tem) == NULL){
        break ;
    }

    fputs(str,org);
   }
   fclose(org);
   fclose(tem);
   remove("temp.txt");
   printf("removing characters is successfully Done!\n");
}
void pastestr(char address[],int line_num , int char_num){

        FILE* origin_2 = fopen(address,"r");
    char t[100];
    for(int i = 0 ; i < line_num - 1 ; i ++){
        if(fgets(t,100,origin_2) == NULL){
            printf("Error!");
            return ;
        }
    }
    for(int i = 0 ; i < char_num ; i ++){
        char c = fgetc(origin_2);
        if(c == EOF){
            printf("Error!");
            return ;
        }
    }
    fclose(origin_2);
    char srting_to_read[100];
    FILE* my_file = fopen(address,"r");
    FILE* only_for_paste = fopen("temp2.txt","r");
    //char df[100] = "root\\new\\name.txt";
    FILE* temping_file = fopen("temp.txt","w");
    for(int i = 1 ; i < line_num - 1  ; i ++){
    fgets(srting_to_read,100,my_file);

    fputs(srting_to_read,temping_file);
    }

    char c ;

    for(int i = 0 ; i < char_num ; i ++){
        c = fgetc(my_file);
        fputc(c,temping_file);
    }

    while(1){
        c = fgetc(only_for_paste);

        if(c == EOF){
            break ;
        }
        fputc(c,temping_file);
    }

    while(1){
        c = fgetc(my_file);
        if(c == EOF){
           // fputc(c,temping_file);
            break;
        }else{
            fputc(c,temping_file);
        }
   }


   fclose(temping_file);
   fclose(only_for_paste);
   fclose(my_file);

   FILE* org = fopen(address,"w");
   FILE* temp = fopen("temp.txt","r");

   while(1){
    if(fgets(srting_to_read,100,temp) == NULL){
        break ;
    }

    fputs(srting_to_read,org);
   }
   fclose(org);
   fclose(temp);
   remove("temp.txt");
   remove("temp2.txt");
   printf("paste is Done!");
}

void cutstr(char address[],int num_of_line,int num_of_char,int amount_of_char_delete,char type_of_delete,int* list){
    FILE* origin_2 = fopen(address,"r");
    char t[100];
    for(int i = 0 ; i < num_of_line - 1 ; i ++){
        if(fgets(t,100,origin_2) == NULL){
            printf("Error!");
            return ;
        }
    }
    for(int i = 0 ; i < num_of_char ; i ++){
        char c = fgetc(origin_2);
        if(c == EOF){
            printf("Error!");
            return ;
        }
    }
    fclose(origin_2);


    FILE* origin = fopen(address,"r");
    FILE* temp = fopen("temp.txt","w");
    FILE* temp_for_paste = fopen("temp2.txt","w");
    char str[100];
    if(type_of_delete == 'b'){
        int place_curser = (num_of_char) - amount_of_char_delete ;
        int sum = place_curser ;
       // printf("1: %d\n",sum);
        while(sum < 0){
            num_of_line -= 1 ;
            if(num_of_line == 0){
                printf("Error!");
                return ;
            }
            sum += (list[num_of_line - 1] + 1 );
           // printf("2 : %d",sum);
        }
        num_of_char = sum ;
    }


        for(int i = 1 ; i < num_of_line ; i ++){
            fgets(str,100,origin);
            //printf("--%s--\n",str);
            fputs(str,temp);
        }
       // printf("*-%d-*",num_of_line);
        //printf("--%s--",str);
        for(int i = 0 ; i < num_of_char ; i ++){
            char c = fgetc(origin);
            fputc(c,temp);
        }

        for(int i = 0 ; i < amount_of_char_delete ; i ++){
            char c = fgetc(origin);
            fputc(c,temp_for_paste);
           // printf("\n%c-",c);
        }
       // printf("b%db",amount_of_char_delete);
        while(1){
           char c = fgetc(origin);
           if(c != '\n'){
            if(c == EOF){
                break;
            }else{
            fputc(c,temp);
            }
           }else{
            fputc(c,temp);
            break;
           }
        }
        while(1){
            if(fgets(str,100,origin) != NULL){
                fputs(str,temp);
            }else{
                break ;
            }
        }


    fclose(temp);
    fclose(temp_for_paste);
   fclose(origin);

   FILE* org = fopen(address,"w");
   FILE* tem = fopen("temp.txt","r");

   while(1){
    if(fgets(str,100,tem) == NULL){
        break ;
    }

    fputs(str,org);
   }
   fclose(org);
   fclose(tem);
   remove("temp.txt");
   printf("Cut Done!\n");


}


void copystr(char address[],int num_of_line,int num_of_char,int amount_of_char_copy,char type_of_copy,int* list){


        FILE* origin_2 = fopen(address,"r");
    char t[100];
    for(int i = 0 ; i < num_of_line - 1 ; i ++){
        if(fgets(t,100,origin_2) == NULL){
            printf("Error!");
            return ;
        }
    }
    for(int i = 0 ; i < num_of_char ; i ++){
        char c = fgetc(origin_2);
        if(c == EOF){
            printf("Error!");
            return ;
        }
    }
    fclose(origin_2);

    FILE* origin = fopen(address,"r");
    FILE* temp = fopen("temp2.txt","w");
    char str[100];
        if(type_of_copy == 'b'){
        int place_curser = (num_of_char) - amount_of_char_copy ;
        int sum = place_curser ;
       // printf("1: %d\n",sum);
        while(sum < 0){
            num_of_line -= 1 ;
            //printf("\n---%d----\n",num_of_line);
            if(num_of_line == 0){
                printf("Error!");
                return ;
            }
            sum += (list[num_of_line - 1] + 1 );
           // printf("2 : %d",sum);
        }
        num_of_char = sum ;
    }

    for(int i = 1 ; i < num_of_line - 1; i ++){
            fgets(str,100,origin);
            //printf("--%s--\n",str);

    }
    for(int i = 0 ; i < num_of_char ; i ++){
            char c = fgetc(origin);
    }
    for(int i = 0 ; i < amount_of_char_copy; i ++){
            char c = fgetc(origin);
            if(c == EOF){
                printf("Error!");
                return ;
            }
           fputc(c,temp);
    }
    fclose(temp);
    fclose(origin);
    printf("copy is Done!\n");





}

char* converting_textfile_into_string(char* address){

    char* whole_str ;
    whole_str = (char*) malloc(500*sizeof(char));
    whole_str[0] = '\0';
    char temp[100];
    FILE* read = fopen(address,"r");
    while(1){
        if(fgets(temp,100,read) == NULL){
            break ;
        }else{
            strcat(whole_str,temp);
            //printf("%s",whole_str);
        }
    }
    fclose(read);
    return whole_str ;

}

int line_of_file_counter(char* address){
    FILE* my_file = fopen(address,"r");
    int i = 0 ;
    char string_to_read[100];
    while(1){
        if(fgets(string_to_read,100,my_file) == NULL){

            break ;
        }
        i ++ ;
    }
     fclose(my_file);
    return i ;

}
int  counter_char(char* address,char pattern){
    int i = 0 ;
    int counter = 0 ;
    while(1){
        if(address[i] == '\0'){
            break ;
        }
        else if(address[i] == pattern){
            counter ++ ;
        }
        i ++ ;
    }
    return counter ;
}

char* changing_name (char* address){
    char* changed_name ;
    changed_name = (char*) malloc(200* sizeof(char));
    changed_name[0] = '\0' ;
    int size_of_back = counter_char(address,'\\');
    changed_name = strstr(address,"\\");
    for(int i = 0 ; i < size_of_back - 1  ; i ++){
        changed_name ++ ;
        changed_name = strstr(changed_name,"\\");
    }
    changed_name ++ ;


    // int size = strlen(address);
    // for(int i = 0 ; i < size - 4 ; i ++){
    //     changed_name[i] = address[i];
    // }
    // strcat(changed_name,"_TEST_.txt");
    return changed_name ;
}

void backup_file(char* address_read,char* address_write){
    FILE* for_read = fopen(address_read,"r");
    FILE* backup_file = fopen(address_write,"w");

    char string_to_read[100];
    while(1){
        if(fgets(string_to_read,100,for_read) == NULL){
            break ;
        }else{
            fputs(string_to_read,backup_file);
        }
    }

    fclose(for_read);
    fclose(backup_file);

}



/**
 * Lists all files and sub-directories recursively
 * considering path as base path.
 */

void listFilesRecursively(char *basePath,int depth)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "\\");

            strcat(path, dp->d_name);
           int size = counter_char(path,'\\');
           if(depth == -1){
                listFilesRecursively(path,depth);
           }else if(size <= depth + 5){
                listFilesRecursively(path,depth);
           }


        }
    }

    closedir(dir);
}
char* add_extra_char(char* string , char* patt,char* patt_2){
    strcat(patt,string);
    strcat(patt,patt_2);
    printf("*");
    return patt ;
}
//removestr --file root\new\name.txt --pos 2:1 -size 3 -b

void word_by_word(char* string_1 , char* string_2){
    if(counter_char(string_1,' ') != counter_char(string_2,' ')){
        printf("%s",string_1);
        printf("%s",string_2);
        return ;
    }
    int count_word_1 = counter_char(string_1,' ') + 1 ;
    int count_word_2 = counter_char(string_2,' ') + 1 ;
    int size_for_1 = 0;
    int size_for_2 = 0;
    char temp_string_1[100];
    char temp_string_2[100];
    for(int i = 0 ; i < count_word_1 ; i ++){

        char* word_1 = strtok(string_1+size_for_1," ");
        char* word_2 = strtok(string_2+size_for_2," ");
        if(strcmp(word_1,word_2) == 0){
            strcat(word_1," ");
            strcat(word_2," ");
            size_for_1 = strlen(word_1);
            size_for_2 = strlen(word_2);
            strcat(temp_string_1,word_1);
            strcat(temp_string_2,word_2);
            printf("------");
        }else{
            strcat(temp_string_1,add_extra_char(word_1,"<<",">> "));
            strcat(temp_string_2,add_extra_char(word_2,"<<",">> "));

            size_for_1 = strlen(word_1) + 1;
            size_for_2 = strlen(word_2) + 1;
        }

    }
    printf("%s\n",temp_string_1);
    printf("%s\n",temp_string_2);
}
int main(){
    char c ;

    char want_of_user[100];
    int counter = 0 ;
    while(1){
        c = getchar();
        if(c != ' '){
            want_of_user[counter] = c ;
            counter ++ ;
        }else{
            break ;
        }
    }
    want_of_user[counter] = '\0';
    counter = 0 ;

    //for creating file :

    if(strcmp(want_of_user,"createfile") == 0){
            type_of_file();
            ctreate_file();
            printf("Your file is created succsessfully!\n");
    }
   // printf("k");
    //end for creating file

    //for inserter

    else if(strcmp(want_of_user,"inserter") == 0){

        type_of_file();

        char * address = inserter();
        char* changed_name = changing_name(address);
        backup_file(address,changed_name);

        type_of_file();

        char* str = get_string();

        get_position(address,str);

        printf("Your file is edited successfuly\n");
    }
    //printf("\n");
    //for cat
    else if(strcmp(want_of_user,"cat") == 0){
        type_of_file();
        cat();
        printf("Done!\n");
    }
   // printf(" \n");
    //end for cat

    //for removestr
    else if(strcmp(want_of_user,"removestr") == 0){
        type_of_file();
        char* address = inserter();
        char* changed_name = changing_name(address);
        backup_file(address,changed_name);

        type_of_file();
       // getchar();
        int line_num ;
        scanf("%d",&line_num);
        getchar();
        int char_num ;
        scanf("%d",&char_num);
        getchar();
        type_of_file();

        int num_of_char_to_delete ;
        scanf("%d",&num_of_char_to_delete);
        getchar();
        getchar();
        char c = getchar();
       // printf("address : %s \n line_num = %d \n char_num : %d \n delete_char : %d\n c : %c",address,line_num,char_num,num_of_char_to_delete,c);

        int * list = counter_of_char_int_wich_line(address);
        removestr_func(address,line_num,char_num,num_of_char_to_delete,c,list);
        printf("Done!\n");
    }
    //printf("\n");
    //end for remove str

    //for copy
    else if(strcmp(want_of_user,"copystr") == 0){
        type_of_file();
        char* address = inserter();

        type_of_file();
       // getchar();
        int line_num ;
        scanf("%d",&line_num);
        getchar();
        int char_num ;
        scanf("%d",&char_num);
        getchar();
        type_of_file();

        int num_of_char_to_copy ;
        scanf("%d",&num_of_char_to_copy);
        getchar();
        getchar();
        char f_or_b_copy = getchar();
        int * list = counter_of_char_int_wich_line(address);
        //printf("address : %s , line : %d , char : %d , copy : %d , type : %c ",address,line_num,char_num,num_of_char_to_copy,f_or_b_copy);
        copystr(address,line_num,char_num,num_of_char_to_copy,f_or_b_copy,list);
        printf("Done!\n");
    }
    //printf("\n");
    //end for copy

    //for cut

        else if(strcmp(want_of_user,"cutstr") == 0){
        type_of_file();
        char* address = inserter();
        char* changed_name = changing_name(address);
        backup_file(address,changed_name);

        type_of_file();
       // getchar();
        int line_num ;
        scanf("%d",&line_num);
        getchar();
        int char_num ;
        scanf("%d",&char_num);
        getchar();
        type_of_file();
        //cutstr --file root\new\h.txt --pos 1:3 -aize 4 -f

        int num_of_char_to_cut ;
        scanf("%d",&num_of_char_to_cut);
        getchar();
        getchar();
        char f_or_b_cut = getchar();
        int * list = counter_of_char_int_wich_line(address);
        //printf("address : %s , line_num : %d , char_num : %d , num_cut : %d , f_or_b : %c \n",address,line_num,char_num,num_of_char_to_cut,f_or_b_cut,list);
        cutstr(address,line_num,char_num,num_of_char_to_cut,f_or_b_cut,list);
        printf("Done\n");
    }
    //printf("\n");
    //end for cut

    //for paste
    else if ((strcmp(want_of_user,"pastestr") == 0)){
        type_of_file();
        char* address = inserter();
        char* changed_name = changing_name(address);
        backup_file(address,changed_name);
        type_of_file();
        int num_line ;
        scanf("%d",&num_line);
        getchar();
        int char_num ;
        scanf("%d",&char_num);
        //printf("%d %d",num_line,char_num);
        pastestr(address,num_line,char_num);
        printf("Done!\n");


    }
   // printf("\n");
    //end paste
    //find --str armin --file root\new\name.txt -byword -at 2
//find --str d --file root\new\name.txt blank
    //for find
    else if ((strcmp(want_of_user,"find") == 0)){

          type_of_file();
          char* serach_string = get_string();
          type_of_file();
          char* address = inserter();
          char* whole_string = converting_textfile_into_string(address);

        char type_of_find[20];
        scanf("%s",type_of_find);

        //printf("search string: %s , address : %s , type_of_file : %s\n",serach_string,address,type_of_find);


        if(strcmp(type_of_find,"-bychar") == 0){
            char bychar_1[20];
            int flag = 0 ;
            scanf("%s",bychar_1);
            char* temp = strstr(whole_string,serach_string);
            if(strcmp(bychar_1,"-def") == 0){
                if(temp){
                    printf("%d",strlen(whole_string) - strlen(temp));
                }else{
                    printf("not find!\n");
                }
            }else if(strcmp(bychar_1,"-at") == 0){
                int number ;
                scanf("%d",&number);
                char* temp = strstr(whole_string,serach_string);

                //number -- ;
                if(temp){
                for(int i = 1 ; i < number ; i ++){
                    temp +=1 ;
                    temp = strstr(temp,serach_string);
                    if(!temp){
                        printf("Error!\n");
                        flag = 1 ;
                        break;
                    }
                }
                }else{
                   // printf("Not Find!");
                }
                printf("%d",flag);
                if(temp){
                    printf("%d",strlen(whole_string) - strlen(temp));
                }else{
                    if(flag == 0)
                        printf("not find!\n");
                }
            }else if(strcmp(bychar_1,"-all") == 0){
                char* temp = strstr(whole_string,serach_string);
                if(temp){
                while(temp = strstr(temp,serach_string)){
                        int size = strlen(whole_string) - strlen(temp);
                        printf("%d\n",size);
                        temp += 1 ;
                }
                }else{
                    printf("Not Find!\n");
                }
            }else{
                printf("Error!\n");
            }
        }


        //for byword

        else if(strcmp(type_of_find,"-byword") == 0){
            char byword_1[20];
            scanf("%s",byword_1);

            if(strcmp(byword_1,"-def") == 0){
                char* temp = strstr(whole_string,serach_string);
                if(temp){
                    int size = strlen(whole_string) - strlen(temp);
                    int counter = 0 ;
                    for(int i = 0 ; i < size ; i ++){
                        if(whole_string[i] == ' ' || whole_string[i] == '\n'){
                            counter ++ ;
                        }
                    }
                    printf("%d",counter);
                }else{
                    printf("not find!\n");
                }
            }else if(strcmp(byword_1,"-at") == 0){
                int flag = 0 ;
                int number ;
                scanf("%d",&number);
                char* temp = strstr(whole_string,serach_string);
                //number -- ;
                if(temp){
                for(int i = 1 ; i < number ; i ++){
                    temp +=1 ;
                    temp = strstr(temp,serach_string);
                    if(!temp){
                        flag = 1 ;
                        printf("Error!\n");
                        break;
                    }
                }
                }else{
                    //printf("Not find!");
                }

                //printf("%d",flag);
                if(temp){
                   // printf("00000--0000");
                    int size = strlen(whole_string) - strlen(temp);
                    int counter = 0 ;
                    for(int i = 0 ; i < size ; i ++){
                        if(whole_string[i] == ' ' || whole_string[i] == '\n'){
                            counter ++ ;
                        }
                    }
                    printf("%d",counter);
                }else{
                    if(flag == 0)
                        printf("not find!\n");
                }
            }else if(strcmp(byword_1,"-all") == 0){
            char* temp = strstr(whole_string,serach_string);
            if(temp){
            while(temp = strstr(temp,serach_string)){
                int counter  = 0 ;
                int size = strlen(whole_string) - strlen(temp);
                for(int i = 0 ; i < size ; i ++){
                    if(whole_string[i] == ' ' || whole_string[i] == '\n'){
                        counter ++ ;
                    }
                }
                printf(" %d,",counter);
                temp += 1 ;

            }
            }else{
                printf("Not find!\n");
            }
        }else{
                printf("Error!\n");
            }
    }
        //for count
        else if(strcmp(type_of_find,"-count") == 0){
            char* temp = strstr(whole_string,serach_string);
            int counter = 0 ;
            if(temp){
                while(temp = strstr(temp,serach_string)){
                    counter  ++ ;
                    temp += 1;

                }
                printf("%d",counter);
            }else{
                printf("not find!\n");
            }
        }else if(strcmp(type_of_find,"-all") == 0){
            char byall_1[20];
            scanf("%s",byall_1);

            if(strcmp(byall_1,"-byword") == 0){
                char* temp = strstr(whole_string,serach_string);

                if(temp){
                while(temp = strstr(temp,serach_string)){
                    int counter  = 0 ;
                    int size = strlen(whole_string) - strlen(temp);
                    for(int i = 0 ; i < size ; i ++){
                        if(whole_string[i] == ' ' || whole_string[i] == '\n'){
                            counter ++ ;
                        }
                    }
                    printf(" %d,",counter);
                    temp += 1 ;
                }
                }else{
                    printf("Not find!\n");
                }
            }else if(strcmp(byall_1,"-bychar") == 0){
                char* temp = strstr(whole_string,serach_string);
                if(temp){
                while(temp = strstr(temp,serach_string)){
                        int size = strlen(whole_string) - strlen(temp);
                        printf("%d\n",size);
                        temp += 1 ;
                }
                }else{
                    printf("Not find\n");
                                    }
            }else{
                printf("Error!\n");
            }


        }


    }
    //end find
    //printf("\n");
    else if(strcmp(want_of_user,"replace") == 0){
        type_of_file();
        char* serach_string = get_string();
        type_of_file();
        char* replace_string = get_string();
        type_of_file();
        char* address = inserter();
        char* changed_name = changing_name(address);
        backup_file(address,changed_name);


        char* whole_string = converting_textfile_into_string(address);
        char c = getchar();
        if(c == '\n'){
            char* temp = strstr(whole_string,serach_string);
            if(temp){
            int size = strlen(whole_string) - strlen(temp);
            FILE* org_file = fopen(address,"r");
            FILE* temp_file = fopen("read.txt","w");
            for(int i = 0 ; i < size ; i ++){
                char c = fgetc(org_file);
                fputc(c,temp_file);
            }
            fputs(replace_string,temp_file);
            for(int i = 0 ; i < strlen(serach_string); i ++){
                fgetc(org_file);
            }
            while(1){
                char c = fgetc(org_file);
                if(c == EOF){
                    break;
                }else{
                    fputc(c,temp_file);
                }
            }
            fclose(temp_file);
            fclose(org_file);
            FILE* org = fopen(address,"w");
            FILE* temp_q = fopen("read.txt","r");
            char string_to_read[100];
            while(1){
                if(fgets(string_to_read,100,temp_q) == NULL){
                    break;
                }else{
                    fputs(string_to_read,org);
                }


            }
            fclose(org);
                fclose(temp_q);
                remove("read.txt");
                printf("replace Done!\n");
            }else{
                printf("Error!\n");
            }

        }else{
            char type_of_replace[20];
            int flag = 1 ;
            scanf("%s",type_of_replace);
            if(strcmp(type_of_replace,"at") == 0){
                //printf("-----");
                int number ;
                scanf("%d",&number);
                char* temp = strstr(whole_string,serach_string);
                if(temp){
                for(int i = 1 ; i < number ; i ++){
                    temp +=1 ;
                    temp = strstr(temp,serach_string);
                    if(!temp){
                        printf("Error!\n");
                        flag = 0 ;
                        break;
                    }
                }
                }else{
                    flag = 0 ;
                    printf("Error!\n");
                }
            if(flag){
            int size = strlen(whole_string) - strlen(temp);
            FILE* org_file = fopen(address,"r");
            FILE* temp_file = fopen("read.txt","w");
            for(int i = 0 ; i < size ; i ++){
                char c = fgetc(org_file);
                fputc(c,temp_file);
            }
            fputs(replace_string,temp_file);
            for(int i = 0 ; i < strlen(serach_string); i ++){
                fgetc(org_file);
            }
            while(1){
                char c = fgetc(org_file);
                if(c == EOF){
                    break;
                }else{
                    fputc(c,temp_file);
                }
            }
            fclose(temp_file);
            fclose(org_file);
            FILE* temp0 = fopen("read.txt","r");
            FILE* org = fopen(address,"w");
            char string_to_read[100];
            while(1){
                if(fgets(string_to_read,100,temp0) == NULL){
                    break;
                }else{
                    fputs(string_to_read,org);
                }


            }
             fclose(org);
            fclose(temp0);
            backup_file("read.txt",address);
            remove("read.txt");
            printf("replace Done!\n");
            }



            }else if(strcmp(type_of_replace,"all") == 0){
                int flag = 0 ;
            while(1){

                char* whole_string2 = converting_textfile_into_string(address);
                char* temp = strstr(whole_string2,serach_string);
                if(temp == 0){
                    if(flag == 0){
                        printf("Error!\n");
                    }else{
                        printf("success\n");
                    }
                    break ;
                }else{
                    flag = 1 ;
                }
                int size = strlen(whole_string2) - strlen(temp);
                FILE* org_file = fopen(address,"r");
                FILE* temp_file = fopen("read.txt","w");
                for(int i = 0 ; i < size ; i ++){
                    char c = fgetc(org_file);
                    fputc(c,temp_file);
                }
                fputs(replace_string,temp_file);
                for(int i = 0 ; i < strlen(serach_string); i ++){
                    fgetc(org_file);
                }
                while(1){
                    char c = fgetc(org_file);
                    if(c == EOF){
                        break;
                    }else{
                        fputc(c,temp_file);
                    }
                }
                fclose(temp_file);
                fclose(org_file);
                FILE* org = fopen(address,"w");
                FILE* temp0 = fopen("read.txt","r");
                char string_to_read[100];
                while(1){
                    if(fgets(string_to_read,100,temp0) == NULL){
                        break;
                    }else{
                        fputs(string_to_read,org);
                    }
                }
                    fclose(org);
                    fclose(temp0);
                    printf("replace Done!\n");
            }

        }

    }
//replace --str armin --str <> --file root\new\name.txt -all
    }
    //printf("\n");
    //end replace
    else if(strcmp(want_of_user,"grep") == 0){
        char type_of_grep[10];
        scanf("%s",type_of_grep);
        getchar();
        //printf("**%s**",type_of_grep);
        type_of_file();
        char* pattern = get_string();
        //getchar();
       // printf("pattern: %s\n",pattern);
        type_of_file();
        while(1){
            char* address = inserter();
            //printf("\n%s\n",address);
            //printf("\n--%s--\n",address);
            c = getchar();
            FILE* my_file = fopen(address,"r");
            char cmp_read[100];
            int counter = 0 ;
            int i = 0 ;
            while(1){
            if(fgets(cmp_read,100,my_file) == NULL){
                break ;
            }

            if(strstr(cmp_read,pattern)){

                    if(strcmp(type_of_grep,"-def") == 0){
                        printf("%s : %s\n",address,cmp_read);
                    }else if(strcmp(type_of_grep,"-C") == 0){
                        counter ++ ;
                    }else if(strcmp(type_of_grep,"-I") == 0){
                        i ++ ;
                        if(i == 1){
                            printf("%s\n",address);
                        }
                    }
                }
            }
            if(strcmp(type_of_grep,"-C") == 0){
                printf("%s : %d\n",address,counter);
            }
            fclose(my_file);

            if(c == '\n'){
                break;
            }
           // getchar();
        }
        printf("\n");

    }else if(strcmp(want_of_user,"auto-indent") == 0){
        char* address = inserter();


      //  char* changed_name = changing_name(address);
      //  backup_file(address,changed_name);

        FILE* my_file_2 = fopen(address,"r");


        //
        FILE* fir = fopen("fir.txt","w");
        while(1){
            char c = fgetc(my_file_2);
            if(c == EOF){
                break ;
            }else{
                if(c != '\n'){
                    fputc(c,fir);
                }
            }
        }
        fclose(fir);
        fclose(my_file_2);
        backup_file("fir.txt",address);
        remove("fir.txt");
         //
        FILE* my_file = fopen(address,"r");
        FILE* temp = fopen("temp.txt","w");
        int counter_of_aculad = 0 ;
        int counter_of_close_aculad = 0 ;
        int flag = 0 ;


        while(1){
            c = fgetc(my_file);
            if(c == EOF){
                break ;
            }
            if(c == '{'){
                if(flag == 0){
                    fputc(' ',temp);
                }
                counter_of_aculad ++ ;
                fputc(c,temp);
                fputc('\n',temp);
                for(int i = 0 ; i < counter_of_aculad ; i ++){
                    fputc('\t',temp);
                }
            }else if(c == '}'){
                counter_of_close_aculad ++ ;
                fputc('\n',temp);
                for(int i = 0 ; i < counter_of_aculad - counter_of_close_aculad; i ++){
                    fputc('\t',temp);
                }
                fputc(c,temp);
            }else{
                if(c == ' '){
                    flag  = 1 ;
                }else{
                    flag = 0 ;
                }
                fputc(c,temp);

            }
        }
        fclose(my_file);
        fclose(temp);
        FILE* org = fopen(address,"w");
        FILE* fake = fopen("temp.txt","r");
        char string_to_read[100];
        while(1){
            if(fgets(string_to_read,100,fake) == NULL){
                break ;
            }else{
                fputs(string_to_read,org);
            }
        }
        fclose(org);
        fclose(fake);
        remove("temp.txt");


    }

    else if(strcmp(want_of_user,"compare") == 0){
        char* address_file_1 = inserter();
        char* address_file_2 = inserter();
        FILE* read_file_1 = fopen(address_file_1,"r");
        FILE* read_file_2 = fopen(address_file_2,"r");
        char string_to_read_1[100];
        char string_to_read_2[100];
        int i = 0 ;
        int size_file_1 = line_of_file_counter(address_file_1);
        int size_file_2 = line_of_file_counter(address_file_2);

        while(1){
            if(fgets(string_to_read_1,100,read_file_1) == NULL){
                break ;
            }
             if(fgets(string_to_read_2,100,read_file_2) == NULL){
                break ;
            }
            i ++ ;
            if(strcmp(string_to_read_2,string_to_read_1) != 0){
                printf("============ #%d ============\n",i);
                printf("%s\n",string_to_read_1);
                printf("%s\n",string_to_read_2);
            }
        }
        fclose(read_file_1);
        fclose(read_file_2);

        FILE* final_1 = fopen(address_file_1,"r");
        FILE* final_2 = fopen(address_file_2,"r");
        if(size_file_1 > size_file_2){
            printf("============ start: #%d   end: #%d ============\n",size_file_2 + 1 , size_file_1);
            for(int i = 0 ; i < size_file_1 ; i ++){
                fgets(string_to_read_1,100,final_1);
                if(i >= size_file_1){
                    printf("%s\n",string_to_read_1);
                }
            }
        }
        if(size_file_2 > size_file_1){
            printf("============ start: #%d   end: #%d ============\n",size_file_1 + 1 , size_file_2);
            for(int i = 0 ; i < size_file_2 ; i ++){
                fgets(string_to_read_2,100,final_2);
                if(i >= size_file_1){
                    printf("%s\n",string_to_read_2);
                }
            }
        }
        fclose(final_1);
        fclose(final_2);




    }
   // printf("\n");

    else if(strcmp(want_of_user,"undo") == 0){
        char* address = inserter();
        type_of_file();
        char* changed_file = changing_name(address);
        //printf("\n%s\n",changed_file);
        backup_file(changed_file,"temp.txt");
        backup_file(address,changed_file);
        backup_file("temp.txt",address);
        remove("temp.txt");
        printf("Done!\n");



    } else if(strcmp(want_of_user,"tree") == 0){
            char path[100];

    // Input path from user
    //printf("Enter path to list files: ");
    int depth ;
    scanf("%d",&depth);
    strcpy(path,"C:\\Users\\ModernSystem\\Desktop\\project\\root");
    //printf("%d",depth);
    listFilesRecursively(path,depth);


    return 0;

    }else{
        printf("Invalid Command!\n");
    }

}


