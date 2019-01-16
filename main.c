#include <stdio.h>
#include <time.h>

char LANGUAGE = 'F';
int choice, tempPass[5], password[5];

int stringCMP(int *a, int *b);
void out(int);
void language(char *);

void userChangePassword();


void adminMenu();


main() {

    language(&LANGUAGE);

    for (int j = 0; j < 4; ++j) {
        scanf("%1d", &password[j]);
    }

    out(2);             //choice
    scanf("%d", &choice);


}

void language(char *l) {
    int i;
    l = 'F';
    out(1);             //language
    scanf("%d", &i);
    if (i == 2) {
        l = 'E';
    }
}

int stringCMP(int *a, int *b) {
    for (int i = 0; i < 4; ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void out(int code) {
    switch (LANGUAGE) {
        case 'E':
            switch (code) {
                case 1:
                    printf("Please Enter your language: ");
                    printf("\n 1.Farsi\n 2.English\n");
                    break;
                case 2:
                    printf("\n\nPlease choose:   ");
                    break;
                case 5:
                    printf("\n Enter the current password:   ");
                    break;
                case 6:
                    printf("Enter the new password:   ");
                    break;
                case 7:
                    printf("Your password has changed.");
                    printf("\n\n\n\npress any key to  continue...");
                    break;
                case 8:
                    printf("Wrong password.\n");
                    break;

                default:
                    printf("Undefined!");
            }
            break;


        default:
            switch (code) {
                case 1:
                    printf("Lotfan zaban khod ra entekhab konid...\n");
                    printf("\n 1.Farsi\n 2.English\n");
                    break;
                case 2:
                    printf("\n\nGozineh ra vared konid:   ");
                    break;
                case 5:
                    printf("\n Ramze feli ra vared konid:   ");
                    break;
                case 6:
                    printf("Ramze jadid ra vared konid:   ");
                    break;
                case 7:
                    printf("Ramze shoma taghir peida kar.");
                    break;
                case 8:
                    printf("Ramz eshtebah ast.\n");
                    break;
                default:
                    printf("Undefined!");
            }
            break;
    }
}

void adminMenu() {

}

void userChangePassword() {

    int bool = 1;
    while (bool) {
        out(5);
        for (int i = 0; i < 4; i++) {
            scanf("%1d", &tempPass[i]);
        }

        if (stringCMP(tempPass, password)) {
            bool = 0;
            out(6);
            for (int j = 0; j < 4; ++j) {
                scanf("%1d", &password[j]);
            }
            out(7);
        } else {
            out(8);
        }

    }

}



