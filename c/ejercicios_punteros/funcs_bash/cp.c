#include <stdio.h>

int main(void)
{
    FILE* ptr_file1 = fopen("file1.txt", "r");
    FILE* ptr_file2 = fopen("file2.txt", "a");
    char ch;
    while ((ch = fgetc(ptr_file1)) != EOF)
    {
        fputc(ch, ptr_file2);
    }
    fclose(ptr_file1);
    fclose(ptr_file2);
}