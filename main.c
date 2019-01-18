#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ADMIN_PASSWORD 1377

//todo wtf is 10 in 3
//todo cls kon
//todo zaban engelisi ra kamel kon
//todo soorat hesab

char LANGUAGE = 'F';
int mablagh, choice, moj = 10000000, tempPass[5], hesab[5][3],
        count = 0, shomareh = 0, pass = 1, mojoodi = 2, masdoodi = 3,
        halghehUser = 1, halgheVorood = 1, halgheh = 1, gozineh, userCount = 10;

void mojoodiHesab();

int adminMenu();

void out(int);

void ChangePassword();

void adminEftetahHesab();

void enteghaleVajh();

void adminKolehesab();

void daryaftVajh();

void adminEftetahHesab();

void adminMojoodiKol();

void RafeMasdoodi();

void voroodeKarbar();

void hazfehHesab();

void userMenu();

int main() {

    out(1);             //language
    scanf("%d", &gozineh);
    if (gozineh == 2) {
        LANGUAGE = 'E';
    }

    voroodeKarbar();

}

void userMenu() {
    do {
        out(9);
        out(2);             //choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                daryaftVajh();
                break;
            case 2:
                mojoodiHesab();
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


    } while (halghehUser == 1);

}

void voroodeKarbar() {
    int u, j = 0, passEshtebah = 0, k = 1;
    do {
        int k = 1;
        out(19);
        printf("1.Admin\n");
        for (; k < 6; ++k) {
            if (hesab[k - 1][shomareh] != 0) {
                printf("%d.%d%d\n", k + 1, hesab[k - 1][shomareh], hesab[k - 1][shomareh] / 10000);
            }
        }

        scanf("%d", &gozineh);
        if (gozineh == 1) {
            userCount = 6;
        } else if (gozineh > 1 && gozineh < 7) {
            userCount = gozineh - 2;
            if (hesab[userCount][masdoodi] == 1) {
                out(20);
                continue;
            }
            passEshtebah = 0;
        }


        while (1) {
            out(3);
            for (j = 0; j < 4; ++j) {
                scanf("%1d", &tempPass[j]);

            }

            u = (tempPass[0] * 1000) + (tempPass[1] * 100) + (tempPass[2] * 10) + tempPass[3];

            if (userCount == 6) {

                if (u == ADMIN_PASSWORD) {
                    adminMenu();
                    break;
                }


            } else {
                if (u == hesab[userCount][pass]) {
                    userMenu();
                    break;
                } else {
                    passEshtebah++;
                    if (passEshtebah > 2) {
                        hesab[userCount][masdoodi] = 1;
                        out(20);
                        break;
                    } else {
                        out(8);
                    }
                }
            }
        }


    } while (halgheVorood);
}

void daryaftVajh() {
    out(10);
    mablagh = 0;
    int gozineh;
    scanf("%d", &mablagh);
    if (mablagh > hesab[userCount][mojoodi])
        out(11);
    else
        out(12);
    hesab[userCount][mojoodi] -= mablagh;
    out(13);
    scanf("%d", &gozineh);
    if (gozineh == 1) {
        out(21);


    }
    out(14);                    ///tasmim edameh
    scanf("%d", &halghehUser);


}

void adminMojoodiKol() {
    long sum = 0;
    for (int i = 0; i <= count; ++i) {
        sum += hesab[i][mojoodi];
    }
    printf("Mojoodi kol hesab ha :  %d", (int) sum);
    out(14);
    scanf("%d", &halgheh);
}

void adminEftetahHesab() {
    int tmppassword[4];
    hesab[count][shomareh] = rand();
    printf("Ramze kart ra vared konid :   ");
    for (int j = 0; j < 4; ++j) {
        scanf("%1d", &tmppassword[j]);
    }
    hesab[count][pass] = tmppassword[0] * 1000 + tmppassword[1] * 100 + tmppassword[2] * 10 + tmppassword[3];
    hesab[count][mojoodi] = 10000000;

    printf("Shomare hesabe moshtari : %d%d\n", hesab[count][shomareh], hesab[count][shomareh] / 10000);
    printf("ramze hesab :   %d\n", hesab[count][pass]);
    printf("mojoodi :   %d\n", hesab[count][mojoodi]);

    count++;
    out(14);
    scanf("%d", &halgheh);
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
                    break;
                case 4:
                    printf("What account do you want to enter??");
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
                case 21:
                    printf("\n\n Card number :  %d\n Requested amount :  %d Rial(s) \n Remaining :  %d Rial(s)",
                           hesab[userCount][shomareh], mablagh, hesab[userCount][mojoodi]);
                    break;
                case 22:
                    printf("\t\t\tBANK PASARGAD\n\t\t\tcode branch:3921\ndate:1397/10/30\ntime:10:00:00\n cash move:%d\ntarget card:",
                           mablagh);
                    break;

                case 23:
                    printf("\nRemaining : %d", hesab[userCount][mojoodi]);
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
                case 4:

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
                    printf("\n\n 1.daryaafte Vajh\t\t2.Daryafte Mojoodi\n\n3.Enteghale Vajh\t\t4.Tghire ramz\n\n5.Enseraf\t\t6.Sepordeh gozari\n\n7.Gereftane soorat hesab");
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
                    printf("\n\n aya mikhahid edameh bedahei?\n 1. Bale \n 2. Kheir  ");
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
                case 19:
                    printf("Hesab Ha:\n");
                    break;
                case 20:
                    printf("Hesab Masdood shod.\n");
                    break;
                case 21:
                    printf("\n\n shomareh kart:  %d%d\n mablagh daryafti:%d rial \n mojoodi:%d Rial",
                           hesab[userCount][shomareh], hesab[userCount][shomareh] / 10000, mablagh,
                           hesab[userCount][mojoodi]);
                    break;
                case 22:
                    printf("\t\t\tBANK PASARGAD\n\t\t\tKode Shobeh:3921\nTarikh:1397/10/30\nZaman:10:00:00\nVajhe enteghali:%d\nKarte maghsad:",
                           mablagh);
                    break;
                case 23:
                    printf("\nMojodi:%d", hesab[userCount][mojoodi]);
                    break;
                case 24:
                    printf("\nShomareh kart :%d%d", hesab[userCount][shomareh], hesab[userCount][shomareh] / 10000);
                default:
                    printf("Undefined!");
            }
            break;
    }
}

void ChangePassword() {

    int halgheh = 1, u;
    while (halgheh) {
        out(5);
        for (int i = 0; i < 4; i++) {
            scanf("%1d", &tempPass[i]);
        }

        u = (tempPass[0] * 1000) + (tempPass[1] * 100) + (tempPass[2] * 10) + tempPass[3];

        if (u == hesab[userCount][pass]) {
            halgheh = 0;
            out(6);
            for (int i = 0; i < 4; i++) {
                scanf("%1d", &tempPass[i]);
            }
            hesab[userCount][pass] = (tempPass[0] * 1000) + (tempPass[1] * 100) + (tempPass[2] * 10) + tempPass[3];

            out(7);
        } else {
            out(8);
        }


    }
    out(14);                    ///tasmim edameh
    scanf("%d", &halghehUser);

}

void enteghaleVajh() {
    int i, kartmaghsad1, kartmaghsad2;
    out(15);
    scanf("%8d%8d", &kartmaghsad1, &kartmaghsad2);
    out(10);
    int mabagh;
    scanf("%d", &mabagh);
    if (mabagh > hesab[userCount][mojoodi])
        out(11);
    else {

        hesab[userCount][mojoodi] -= mabagh;
        out(16);
        out(13);
        scanf("%d", &gozineh);
    }
    if (gozineh == 1)
        out(22);

    printf("%8d%8d", kartmaghsad1, kartmaghsad2);
    out(17);
    out(23);
    out(14);
    scanf("%d", &halghehUser);
    //system("cls");
}

void adminKolehesab() {
    printf("kole hesab ha:");
    int j = 1;
    for (int i = 0; i <= count; i++) {
        printf("\n hesabe %d:\n %d%d", j, hesab[i][shomareh], hesab[count][shomareh] / 10000);
        j++;
    }
    out(14);
    scanf("%d", &halgheh);


}

int adminMenu() {
    do {
        printf("\n1.Ejade hesab\t\t2.Hazfe hesab\n\n3.Rafe masdoodi\t\t4.Neshane hame hesabha\n\n5.Neshan kol mojoodi ha\t\t6.Khorooj");
        out(2);
        scanf("%d", &gozineh);
        switch (gozineh) {
            case 1:
                adminEftetahHesab();
                break;
            case 2 :
                hazfehHesab();
                break;
            case 3:
                RafeMasdoodi();
                break;
            case 4:
                adminKolehesab();
                break;
            case 5:
                adminMojoodiKol();
                break;
            case 6:
                return 0;
            default:
                break;

        }
    } while (halgheh == 1);
}

void RafeMasdoodi() {
    for (int k = 0; k < 5; ++k) {
        if (hesab[k][masdoodi] != 0) {
            printf("%d.%d%d\n", k + 1, hesab[k][shomareh], hesab[k][shomareh] / 10000);
        }
    }

    scanf("%d", &gozineh);
    if (gozineh > 0 && gozineh < 6) {
        hesab[gozineh-1][masdoodi] = 0;
        printf("hesab azad shod.");
    }


}

void hazfehHesab() {
    for (int i = 0; i <= count; ++i) {
        if (hesab[i][shomareh] != 0) {
            printf("hesab %d:%d%d", i + 1, hesab[i][shomareh], hesab[i][shomareh] / 10000);

        }
    }
    out(2);
    scanf("%d", &gozineh);
    gozineh--;
    hesab[gozineh][shomareh] = 0;
    hesab[gozineh][pass] = 0;
    hesab[gozineh][mojoodi] = 0;


}

void mojoodiHesab() {
    out(24);
    out(23);

}



