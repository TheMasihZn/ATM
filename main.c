#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define ADMIN_PASSWORD 1377


char LANGUAGE = 'F';
int mablagh, choice, tempPass[5], hesab[5][3],
        count = 0, shomareh = 0, pass = 1, mojoodi = 2, masdoodi = 3,
        halghehUser = 1, halgheVorood = 1, halgheh = 1, gozineh, userCount = 10;
int Daryaftiha[10], variziha[10];

void mojoodiHesab();

int adminMenu();

void out(int);

void daryaft();

void ChangePassword();

void adminEftetahHesab();

void enteghaleVajh();

void adminKolehesab();

void daryaftVajh();

void adminEftetahHesab();

void adminMojoodiKol();

void RafeMasdoodi();

void hazfehHesab();

void userMenu();

void sepordehGozari();

void variz();

void sooratHesab();

int main() {
        int u, j = 0, passEshtebah = 0, k = 1;
    for (int i = 0; i < 10; ++i) {
        Daryaftiha[i]=0;
        variziha[i]=0;
    }
    out(1);             //zaban
    scanf("%d", &gozineh);
    system("cls");
    if (gozineh == 2) {
        LANGUAGE = 'E';
    }

    do {
        int k = 1;
        out(19);
        printf("1.Admin\n");
        for (k=1; k < 6; ++k) {
            if (hesab[k - 1][shomareh] != 0) {
                printf("%d.%d%d\n", k + 1, hesab[k - 1][shomareh], hesab[k - 1][shomareh] / 10000);
            }
        }

        scanf("%d", &gozineh);
        system("cls");
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
                    system("cls");
                    adminMenu();
                    break;
                }


            } else {
                if (u == hesab[userCount][pass]) {
                    system("cls");
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

void userMenu() {
    do {
        out(9);
        out(2);             //choice
        scanf("%d", &choice);
        system("cls");
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
                halghehUser = 0;
                break;
            case 6:
                sepordehGozari();
                break;
            case 7:
                sooratHesab();
                break;
            default:
                break;
        }


    } while (halghehUser == 1);

}

void sooratHesab() {
    out(25);
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        if (Daryaftiha[i]!=0) {
            printf("+%d\n",Daryaftiha[i]);
        }
    }

    out(26);
    for (int i = 0; i < 10; ++i) {
        if (variziha[i]!=0) {
            printf("+%d\n",variziha[i]);
        }
    }
   getch();
   out(14);
   scanf("%d",&halghehUser);
   system("cls");
}

void sepordehGozari() {
    out(10);
    mablagh = 0;
    scanf("%d", &mablagh);
    system("cls");
    hesab[userCount][mojoodi] += mablagh;
    variz();
}

void variz() {
    for (int i = 0; i < 10; ++i) {
        if (variziha[i] == 0) {
            variziha[i] = mablagh;
            mablagh=0;
        }

    }


    }

void daryaftVajh() {
    out(10);
    mablagh = 0;
    int gozineh;
    scanf("%d", &mablagh);
    system("cls");
    if (mablagh > hesab[userCount][mojoodi]){
        out(11);
    getch();
    system("cls");
     }else
        out(12);
    hesab[userCount][mojoodi] -= mablagh;
    Daryaftiha[10];
    out(13);
    scanf("%d", &gozineh);
    if (gozineh == 1) {
        out(21);
    }
    daryaft();
    getch();
    system("cls");

    out(14);                    ///tasmim edameh
    scanf("%d", &halghehUser);
    system("cls");


}

void adminMojoodiKol() {
    long sum = 0;
    for (int i = 0; i <= count; ++i) {
        sum += hesab[i][mojoodi];
    }
    printf("Mojoodi kol hesab ha :  %d", (int) sum);
    getch();
    out(14);
    scanf("%d", &halgheh);
    system("cls");
}

void adminEftetahHesab() {

    int tmppassword[4];
    hesab[count][shomareh] = (rand()*pow(10,10))+(rand()*pow(10,8))+(rand()*pow(10,6))+(rand()*pow(10,4))+(rand()*100)+rand();
    printf("Ramze kart ra vared konid :   ");
    for (int j = 0; j < 4; ++j) {
        scanf("%1d", &tmppassword[j]);
    }
    system("cls");
    hesab[count][pass] = tmppassword[0] * 1000 + tmppassword[1] * 100 + tmppassword[2] * 10 + tmppassword[3];
    hesab[count][mojoodi] = 10000000;
    printf("Shomare hesabe moshtari : %d%d\n", hesab[count][shomareh], hesab[count][shomareh] / 10000);
    printf("ramze hesab :   %d\n", hesab[count][pass]);
    printf("mojoodi :   %d\n", hesab[count][mojoodi]);
    count++;
    getch();
    system("cls");
    out(14);
    scanf("%d", &halgheh);
    system("cls");
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
                case 9:
                    printf("\n\n 1.Receiving mony\t\t2.Receiving inventory\n\n3.Mony transfer\t\t4.change password\n\n5.Quit\t\t6.Deposit\n\n7.account");
                case 10:
                    printf("\n How much do you want ?");
                    break;
                case 11:
                    printf("\n your balance isn't enough.");
                    break;
                case 12:
                    printf("\n please get your cash.");
                    break;
                case 13:
                    printf("\n 1.Yes\t\t2.No\n do you want receipt?");
                    break;
                    case 14:
                    printf("\nDo you want to continio:\n 1.yes\t\t2.No");
                    break;
                    case 15:
                    printf("Enter the target card number: ");
                    break;
                case 16:
                    printf("Cash transfer was successful.");
                    break;
                case 17:
                    printf("\nFrom card number: %d%d",hesab[userCount][shomareh],hesab[userCount][shomareh]/10000);
                    break;
                case 18:
                    printf("\n please take out your card.\nThank you for choosing our bank.");
                    break;
                case 19:
                    printf("accounts: \n");
                    break;
                case 20:
                    printf("This account has been blocked.");
                    break;
                case 21:
                    printf("\n\n Card number :  %d\n Requested amount :  %d Rial(s) \n Remaining :  %d Rial(s)",
                           hesab[userCount][shomareh], mablagh, hesab[userCount][mojoodi]);
                    break;
                case 22:
                    printf("\t\t\tPASARGAD BANK\n\t\t\tcode branch:3921\ndate:1397/10/30\ntime:10:00:00\n cash move:%d\ntarget card:", mablagh);
                    break;

                case 23:
                    printf("\nRemaining : %d", hesab[userCount][mojoodi]);
                    break;
                case 24:
                    printf("\n Card number :%d%d", hesab[userCount][shomareh], hesab[userCount][shomareh] / 10000);
                    break;
                case 25:
                    printf("Taken in cash:\n\n");
                    break;
                case 26:
                    printf("Added to this account:\n\n");
                    break;
                case 27:
                    printf("Cash deposited.");
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
                    printf("\nKarte mabda:%d%d",hesab[userCount][shomareh],hesab[userCount][shomareh]/10000);
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
                    break;
                case 25:
                    printf("Mabaleghe daryafti be sharhe zir ast:\n\n");
                    break;
                case 26:
                    printf("Mabaleghe varizi be sharhe zir ast:\n\n");
                    break;
                case 27:
                    printf("\n Sepordeh gozari anjam shod.");
                    break;
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
    system("cls");

}

void enteghaleVajh() {
    int i, kartmaghsad1, kartmaghsad2;
    out(15);
    scanf("%8d%8d", &kartmaghsad1, &kartmaghsad2);
    system("cls");
    out(10);
    scanf("%d", &mablagh);
    system("cls");
    if (mablagh > hesab[userCount][mojoodi])
        out(11);
    else {

        hesab[userCount][mojoodi] -= mablagh;
        out(16);
        out(13);
        scanf("%d", &gozineh);
        system("cls");
    }
    if (gozineh == 1)
        out(22);

    printf("%8d%8d", kartmaghsad1, kartmaghsad2);
    daryaft();
    out(17);
    out(23);
    out(14);
    scanf("%d", &halghehUser);
    system("cls");
}

void adminKolehesab() {
    printf("kole hesab ha:");
    int j = 1;
    for (int i = 0; i <= count; i++) {
        printf("\n hesabe %d:\n %d%d", i+1, hesab[i][shomareh], hesab[count][shomareh] / 10000);

    }
    out(14);
    scanf("%d", &halgheh);
    system("cls");


}

int adminMenu() {
    do {
        printf("\n1.Ejade hesab\t\t2.Hazfe hesab\n\n3.Rafe masdoodi\t\t4.Neshane hame hesabha\n\n5.Neshan kol mojoodi ha\t\t6.Khorooj");
        out(2);
        scanf("%d", &gozineh);
        system("cls");
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
    system("cls");
    if (gozineh > 0 && gozineh < 6) {
        hesab[gozineh - 1][masdoodi] = 0;
        printf("hesab azad shod.");
        getch();
    }
    system("cls");

}

void hazfehHesab() {
    for (int i = 0; i <= count; ++i) {
        if (hesab[i][shomareh] != 0) {
            printf("hesab %d:%d%d", i + 1, hesab[i][shomareh], hesab[i][shomareh] / 10000);
        }

    }
    out(2);
    scanf("%d", &gozineh);
    system("cls");
    hesab[gozineh - 1][shomareh] = 0;
    hesab[gozineh - 1][pass] = 0;
    hesab[gozineh - 1][mojoodi] = 0;
    printf("\nHesab mored nazar hazf shod.");


}

void mojoodiHesab() {
    out(24);
    out(23);
getch();
    system("cls");
}

void daryaft() {
    for (int i = 0; i < 10; ++i) {
        if (Daryaftiha[i] == 0) {
            Daryaftiha[i] = mablagh;
            mablagh=0;
        }

    }

}





