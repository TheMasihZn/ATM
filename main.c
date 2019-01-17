#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <curses.h>
char LANGUAGE = 'F', tmp = ' ';
int choice, moj = 10000000, tempPass[5], password[5], hesab[5][3], count = 0, number = 0, pass = 1, remain = 2, halgheh ,gozineh;


int moghayeseh(int *a, int *b);
void out(int);
void language(char *);

void ChangePassword();


void adminMenu();

void adminEftetahHesab();

void enteghaleVajh();


void daryaftVajh();
void adminMojoodiKol();


int main() {
//    clock_t before = clock();
//    while (clock()-before<=5000) {
//    }
    language(&LANGUAGE);
//    system("cls");
     out(3);
    system ("clear");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            hesab[i][j] = 0;
        }
    }

    adminMojoodiKol();

    for (int j = 0; j < 4; ++j) {
        scanf("%1d", &password[j]);
    }
    do{
    out(9);
    out(2);             //choice
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                daryaftVajh();
                break;
            case 2:
                break;
            case 3:
                enteghaleVajh();
                break;
            case 4:
                ChangePassword();
                break;
            case 5:
                out(18);
                break;




            default:
                break;
        }



        }while(halgheh==1);}

void daryaftVajh() {
    out(10);
    int temp, gozineh, halgheh;
    scanf("%d", &temp);
    // system("@cls||clear");
    if (temp > moj)
        out(11);
    else
        out(12);
    //getch();
    //system("cls");
    moj = moj - temp;
    out(13);
    scanf("%d", &gozineh);
    //system("cls");
    if (gozineh == 1) {
        if (LANGUAGE == 'F')
            printf("\n\n shomareh kart: 6104 3378 **** 4260\n mablagh daryafti:%d rial \n mojoodi:%d rial", temp, moj);
        else if (LANGUAGE == 'E')
            printf("\n\n kart number: 6104 3378 **** 4260\n:%d rial\n mojoodi:%d rial", temp, moj);
        // getch();
    }
        out(14);                    ///tasmim edameh
        scanf("%d", &halgheh);
        //system("cls");



}

void adminMojoodiKol() {
    long sum = 0;
    for (int i = 0; i <= count; ++i) {
        sum += hesab[i][remain];
    }
    printf("Mojoodi kol hesab ha :  %d", (int) sum);
}

void adminEftetahHesab() {
    int tmppassword[4];
    printf("aya motmaenid?  \n");
    printf("1.Bale\n2.Kheir\n");
    int i;
    scanf("%1d", &i);
    if (i == 1) {
        hesab[count][number] = rand();
        printf("Shomare hesabe moshtari : %d%d\n", hesab[count][0], hesab[count][number] / 10000);
        scanf("Ramze kart ra vared konid");

        for (int j = 0; j < 4; ++j) {
            scanf("%1d", &tmppassword[j]);
        }
        hesab[count][pass] = tmppassword[0] * 1000 + tmppassword[1] * 100 + tmppassword[2] * 10 + tmppassword[3];
        hesab[count][remain] = 10000000;

        count++;

    }
}

void language(char *l) {
    int i;
    out(1);             //language
    scanf("%d", &i);
    if (i == 2) {
        l = 'E';

    }
}

int moghayeseh(int *a, int *b) {
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
                case 3:
                    printf("Please enter your password:   ");

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
                case 3:
                    printf("ramze vorud ra vared konid:");
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
                case 9:
                    printf("\n\n 1.daryaafte Vajh\t\t2.Daryafte Mojoodi\n\n3.Enteghale Vajh\t\t4.Tghire ramz\n\n5.Sarfe nazar az anjame amaleiyat\n\n6.Sepordeh gozari\t\t7.Gereftane soorat hesab\n\ngozineh morede nazar ra vared konid:  ");
                    break;
                case 10:
                    printf("mablaghe morede nazar be rial:    ");
                    break;
                case 11:
                    printf("\n mojoodi kafi nist. ");
                    break;
                case 12:
                    printf("lotfan vajh khod ra daryaft konid");
                    break;
                case 13:
                    printf("\n\n 1.Bale \n 2.Kheir\n aya resid mikhahid?  ");
                    break;
                case 14:
                    printf("\n\n 1. Bale \n 2. Kheir \n aya mikhahid edameh bedaheid؟ ");
                    break;
                case 15:
                    printf("Shomare Kart Maghsad Ra Vared Konid: ");
                    break;
                case 16:
                    printf("Mablagh Morede nazar Ba Movaffaghiyat enteghal yaft.");
                    break;
                case 17:
                    printf("\nKarte mabda:");
                    break;
                case 18:
                    printf("\n Lotfan kart khod ra bardarid.\nsepas gozarim baraye entekhab in aberbank.");


                    break;
                default:
                    printf("Undefined!");
            }
            break;
    }
}

void ChangePassword(){

    int bool = 1;
    while (bool) {
        out(5);
        for (int i = 0; i < 4; i++) {
            scanf("%1d", &tempPass[i]);
        }

        if (moghayeseh(tempPass, password)) {
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
    out(14);                    ///tasmim edameh
    scanf("%d", &halgheh);

}

void enteghaleVajh() {
    int i, kartmaghsad[16];
    out(15);
    for (i = 0; i < 16; i++)
        scanf("%1d", &kartmaghsad[i]);
    //system("cls");
    out(10);
    int temp;
    scanf("%d", &temp);
    moj -= temp;
    //system("cls");
    if (temp > moj)
        out(11);
    else {
        out(16);
        //getch();
        //system("cls");
        out(13);
        scanf("%d", &gozineh);
    }
    if (gozineh == 1)
        if (LANGUAGE == 'F')
            printf("\t\t\tBANK PASARGAD\n\t\t\tKode Shobeh:3921\nTarikh:1397/10/30\nZaman:10:00:00\nVajhe enteghali:%d\nKarte maghsad:",
                   temp);
        else if (LANGUAGE == 'E')
            printf("\t\t\tBANK PASARGAD\n\t\t\tcode branch:3921\ndate:1397/10/30\ntime:10:00:00\n cash move:%d\ntarget card:",
                   temp);
    for (i = 0; i < 16; i++)
        printf("%1d", kartmaghsad[i]);
    out(17);
    if (LANGUAGE == 'F')
        printf("\nMojodi:%d", moj);
    else if (LANGUAGE == 'E')
        printf("");
    //getch();
    // system("cls");
    out(14);
    scanf("%d", &halgheh);
    //system("cls");
                }



