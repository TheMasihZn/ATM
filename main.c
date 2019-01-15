#include <stdio.h>
#include <time.h>

char Language = 'F';

int Masih(int a[4], int b[4]);

void out(int);

void adminMenu();

void language(char*);

main() {

    int choice, tempPass[5], password[5];



    language('E');

    for (int j = 0; j < 4; ++j) {
        scanf("%1d", &password[j]);
    }

    out(2);             //choice
    scanf("%d", &choice);

    if (choice == 1) {
        int bool = 1;
        while (bool) {
            printf("\n Ramze feli ra vared konid:   ");
            for (int i = 0; i < 4; i++) {
                scanf("%1d", &tempPass[i]);
            }

            if (Masih(tempPass, password)) {
                bool = 0;
                printf("Ramze jadid ra vared konid:   ");
                for (int j = 0; j < 4; ++j) {
                    scanf("%1d", &password[j]);
                }
                printf("Ramze shoma taghir peida kar.");

            } else {
                printf("Ramz eshtebah ast.\n");
            }
        }
    }
}

void language(char* l) {
    l='F';
    out(1);             //language
//    scanf("%d")
}

int Masih(int a[4], int b[4]) {
    for (int i = 0; i < 4; ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void out(int code) {
    switch (Language) {
        case 'E':
            switch (code) {
                case 1:
                    printf("Please Enter your language: ");
                    printf("");
                    break;
                case 2:
                    printf("\n\nPlease choose:   ");

                default:
                    printf("Undefined!");
            }
            break;


        case 'D':
            switch (code) {
                case 1:

                default:
                    printf("Undefined!");
            }
            break;


        default:
            switch (code) {
                case 1:
                    printf("Lotfan zaban khod ra entekhab konid...\n");
                    printf("\n 1.Farsi\n 2.English\n 3.Deutsch\n hiiiiiiiiii\n");
                    break;
                case 2:
                    printf("\n\nGozineh ra vared konid:   ");
                    break;
                default:
                    printf("Undefined!");
            }
            break;
    }
}

void adminMenu() {

}



