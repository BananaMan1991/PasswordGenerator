#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAXLEN 100


int main() {
    FILE *fp;
    int dontSave = 0;
    fp = fopen("password.txt", "w+");
    if (fp == NULL) { printf("cannot access file password.txt, will not save to file.\n"); dontSave = 1; }
    char alphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char Alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char nums[10] = {"0123456789"};
    char syms[34] = {"!\"#$%%&'()*+,-./:;<=>?@[\\]^_`{|}~"};

    char chars[100];
    char final[MAXLEN] = "";
    char input;

    int i,n,l;

    for(i=0;i<26;i++) {
        chars[i] = alphabet[i];
    }
    l=i;

    printf("\nCapital letters? (Y/N) ");
    input = getch();
    printf("%c", input);
    if (input == 'y' || input == 'Y') {
        for(i=0;i<26;i++) {
            chars[l] = Alphabet[i];
            l++;
        }
    }

    printf("\nNumbers? (Y/N) ");
    input = getch();
    printf("%c", input);
    if (input == 'y' || input == 'Y') {
        for(i=0;i<10;i++) {
            chars[l] = nums[i];
            l++;
        }
    }

    printf("\nSymbols? (Y/N) ");
    input = getch();
    printf("%c", input);
    if (input == 'y' || input == 'Y') {
        for(i=0;i<32;i++) {
            chars[l] = syms[i];
            l++;
        }
    }

    printf("\nHow many characters? ");
    scanf("%d", &n);
    if (n>MAXLEN) n = MAXLEN;
    else if (n<1) { printf("\n password cannot be less than one character"); return 1; }

    srand(time(0));
    for(i=0;i<n;i++) {
        int random = rand() % l;
        final[i] = chars[random];
    }

    printf("\n Your Password Is: %s \n", final);
    if(!dontSave) {
        fprintf(fp, final);
        printf("Password saved to file password.txt");
    }
    fclose(fp);

    printf("Press any key to exit. ");
    getch();
    return 0;
}
