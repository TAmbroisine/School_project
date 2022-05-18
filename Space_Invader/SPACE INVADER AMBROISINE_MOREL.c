/***************************************************************************************************************
	ROLE : Le programme réalise le jeu du Space Invader
	AUTEUR : Morel Thibault et Ambroisine Tyron
	DATE : 05/12/2021 au 19/01/2021
*****************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define TAILLE_MAX 1000

//system("mode con lines=52 cols=197");
//Zone de jeu:Xmax = 150 / Ymax = 52

/**************************************************************************
Variables utilisées:


    Variables vaisseau:

        NOM          |      Tableau   |        Numéro

        Vaisseau     |      tabcoord  |          1
Position depart      |      tabcompt  |          19

    Variables tirs:

        NOM          |      Tableau   |        Numéro

          tir1       |    tabcoord    |        2
          tir2       |    tabcoord    |        3
          tir3       |    tabcoord    |        4

    Variables Ennemis:

        NOM                          |           Tableau    |         Numéro

        ennemi 1                     |        tabccoord     |          8
        ennemi 2                     |        tabccoord     |          9
        ennemi 3                     |        tabccoord     |          10
        ennemi 4                     |        tabccoord     |          11
        ennemi 5                     |        tabccoord     |          12
        ennemi 6                     |        tabccoord     |          13
        ennemi 7                     |        tabccoord     |          14
        ennemi 8                     |        tabccoord     |          15
        ennemi 9                     |        tabccoord     |          16
        delai ennemi                 |        tabtime       |          2
        temps ennemi                 |        tabtime       |          4
        apparition ennemis           |        tabcompt      |          3
        ennemis mort                 |        tabcompt      |          7
        ennemis mort (réapparition)  |        tabcompt      |          10
        indicateur ennemis disparus  |        tabcompt      |          13
        ennemis tués par le joueur   |        tabcompt      |          30



    Variables Boss:

        NOM                         |      Tableau   |         Numéro

        Boss                        |     tabcoord   |        17
        tir Boss 1                  |     tabcoord   |        18
        tir Boss 2                  |     tabcoord   |        19
        tir Boss 3                  |     tabcoord   |        20
        tir Boss 4                  |     tabcoord   |        21
        tir Boss 5                  |     tabcoord   |        22
        Nombre de boss vaincus      |     tabcompt   |        8
        Boss Hit                    |     tabcompt   |        9
        Boss apparu                 |     tabcompt   |        20
        Nombre tirs Boss            |     tabcompt   |        21
        Tir du boss disparu         |     tabcompt   |        23
        vaisseau touché par le Boss |     tabcompt   |        24
        Vie du Boss                 |     tabcompt   |        26


    Variables vitamines:

        NOM                             |       Tableau  |          Numéro

       vitamine 1                       |      tabcoord  |          18
       délai vitamine                   |      tabtime   |          3
       temps vitamines                  |      tabtime   |          5
       vitamine                         |      tabcompt  |          2
       vitamine disparu                 |      tabcompt  |          28
       vitamine récupérer par le joueur |      tabcompt  |          31

**************************************************************************/


/***********************************************************
            PROTOTYPES FONCTIONS
***********************************************************/
void gotoxy(int x, int y);
//Menu du Jeu avec le choix de poursuite de l'utilisateur
int Menu();
//Choix du vaisseau par l'utilisateur
int ChoixAvatar(char vaiso1[2][6],char vaiso2[2][8],char vaiso3[4][16]);
//Choix de la couleur du vaisseau
int ChoixCouleur(int chx,char vaiso1[2][6],char vaiso2[2][8],char vaiso3[4][16]);
//Permet de définir la couleur de la console
void color(int cT,int cF);
//Permet à l'utiliateur de choisir le mode qu'il veut
int ChoixMode();
//Gestion du déplacement des vaisseaux en fonction des touches du claviers saisies
void deplacement(int chx,int tabxy[50][2],int tabcom[40],int couleur,double score[2]);
//Gestion des tirs en fonction des différents vaisseaux et des sorties d'écran
void tir(int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2]);
// Permet à l'utilisateur de jouer, en fonction de ce qu'il a choisi
int Jouer(int mode,int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2]);
// Gestion du déplacement des ennemis et de leur apparition dans le jeu
void Ennemie(int chx,int mode,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur);
// Gestion du déplacement des boss et leur apparition
void Boss(int chx,int mode,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2]);
// Gestion des vitamines pour la vie et la bombe
void vitamine(int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur);
// Permet d'afficher le score du joueur
void AffichageScore(int chx,int mode,int tabtime[9],double score[2],int tabcom[40],int couleur);
// Cette fonction sert à mettre fin à la partie que l'utilisateur perde ou gagne
void GameOver(int tabcom[40],int mode);
// Permet d'afficher le score dans un fichier texte pour avoir les scores des précédentes parties
void EnregistrementScore (double score[2],int tabcom[40],int mode,int tabxy[50][2]);
// Permet de détecter la touche de clavier saisie par l'utilisateur
int kbhit(void);
int getch(void);
// Fonction lié à l'affichage du score dans un fichier texte qui permet d'ouvrir le fichier
FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
// Lié à l'affichage du score et qui permet de choisir le fichier
int fclose(FILE* pointeurSurFichier);
size_t strlen(const char* chaine);
// Affichage des règles du jeu
void afficherRegle(void);

/***********************************************************
     RAPPORT DE TESTS:
     ----------------

A)Saisie du menu:

Choix Menu               Nom               Résultat
-----------------------------------------------------
1                       Jouer                  OK
2                       Règles du jeu          OK
3                       Quitter                OK


B)Choix du vaisseau

Choix                     Nom                Résultat
------------------------------------------------------
2                          Moyen               OK
1                          Facile              OK
3                          Difficile           OK
4                          Erreur             ERREUR
-5                         Erreur             ERREUR

C)Choix couleur du vaisseau

Choix                        Couleur                     Resulat
----------------------------------------------------------------
12                             Blanc                       OK
6                              Bleu                        OK
9                              Rouge                       Ok
3                              Kaki                        Ok
13                             Erreur                     Erreur
-6                             Erreur                     Erreur

D)Choix Mode

Mode                    NOM                             Resulat
-----------------------------------------------------------------
2                      BOSS                               OK
1                      Survie                             OK
-2                     Erreur                             Erreur
3                      Erreur                             Erreur


E)Touches actionnés dans le menu

Touches actionnées             Fonction                       Resultat
---------------------------------------------------------------------
2                             Affiche les Règles                OK
1                             Jouer                             Ok
3                             Fermeture du programme            OK
espace                        Validation du choix               OK

F)Touches actionnées en jeu

Touches actionées           Mode              Type vitamines                Fonction                                            Résultat
-----------------------------------------------------------------------------------------------------------------------------------------
z                            1 ou 2                   /                         Monter                                             OK
q                            1 ou 2                   /                      Aller vers la gauche                                  OK
s                            1 ou 2                   /                         Descendre                                          OK
d                            1 ou 2                   /                      Aller vers la droite                                  OK
f                            1 ou 2                   V                      Récupère une vie                                      OK
f                            1 ou 2                   P                      Déclenche une Bombe                                   OK
echap                        1 ou 2                   /                      Met le jeu en Pause                                   OK
espace                       1 ou 2                   /        Lance un ou plusieurs missiles (en fonction du vaisseau)            OK

G) Enregistrement du score

Pseudo                       Résultat
--------------------------------------
Thibault                         OK
Tyron                            OK
Etudiant1                      Erreur

BILAN:OK!!!!!!
______________

************************************************************/

int main()
{   int choix=4,chxavatar,couleur,mode,tabcoord[50][2],tabcompt[40],i,u; //choix menu,choix de l'avatar, choix de poursuite, choix de la couleur du vaisseau et du mode, tableau de coordonnées et tableau de compteur
    int tabtemps[9]; //Tableau de temps
    double score[2];
    char vaisseau1[2][6]={"  |", //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};
    char ennemie[1][6]={"|-o-|"}; //Dessin du vaisseau ennemi

    srand(time(NULL));
    while (choix !=3) // Condition de fermeture du programme
    {
        choix=Menu();
        if (choix==1)  // Lorsque l'utilisateur choisi l'option 1, le jeu se lance
        {
            for (i=1;i<=50;i=i+1)
            {
                for (u=1;u<=2;u=u+1)
                {
                    tabcoord[i][u]=0;
                }
            }
            for (i=1;i<=9;i=i+1)
            {
                    tabtemps[i]=0;
            }
            for (i=1;i<=40;i=i+1)
            {
                tabcompt[i]=0;
            }
            score[1]=0;
            chxavatar=ChoixAvatar(vaisseau1,vaisseau2,vaisseau3); // Appel de la fonction du choix de l'avatar
            couleur=ChoixCouleur(chxavatar,vaisseau1,vaisseau2,vaisseau3); // Appel de la fonction du choix de la couleur du vaisseau
            mode=ChoixMode(); // Appel de la fonction du choix du mode
            Jouer(mode,chxavatar,tabtemps,tabcoord,tabcompt,couleur,score); // Appel de la fonction pour jouer
            system("CLS"); // L'écran s'efface pour pouvoir afficher le score des différentes parties
            EnregistrementScore(score,tabcompt,mode,tabcoord); // Appel de la fonction de l'enregistrement du score et son affichage

        }
        else if (choix==2) // Si l'utilisateur choisi l'option 2 dans le menu il y a l'affichage des règles du jeu
        {
            afficherRegle();
        }
    }
}
void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

void color(int cT,int cF)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cF*16+cT);
}
/****************************************************************
 rôle : Menu du Jeu avec le choix de poursuite de l'utilisateur
 Entrée : Rien
 Sortie : Choix de poursuite
*****************************************************************/
int Menu()
{
    int x=95,y=29,i=0,touche,chx,ligne=0; //Choix de poursuite et indication de la ligne
    char imgacceuilTerre[16][67] ={" o               .        ___---___                    .",  //Dessin d'acceuil
                           "       .              .--\\        --.     .     .         .   ",
                           "                    ./.;_.\\     __/~ \\.                       ",
                           "                   /;  / `-'  __\\    . \\                      ",
                           " .        .       / ,--'     / .   .;   \\        |            ",
                           "                 | .|       /       __   |      -O-       .   ",
                           "                |__/    __ |  . ;   \\ | . |      |            ",
                           "                |      /  \\\\_    . ;| \\___|                   ",
                           "   .    o       |      \\\\  .~\\\\___,--'    |           .       ",
                           "                 |     | . ; ~~~~\\_    __|                    ",
                           "    |             \\    \\   .  .  ; \\  /_/   .                 ",
                           "   -O-        .    \\   /         . |  ~/                  .   ",
                           "    |    .          ~\\ \\   .      /  /~          o            ",
                           "  .                   ~--___ ; ___--~                         ",
                           "                 .          ---         .                     "};

    char imgacceuilTitre[14][59] ={"  _____ ______   ___   _____  _____",  //Dessin d'accueil du titre du jeu
                                " /  ___|| ___ \\ / _ \\ /  __ \\|  ___|",
                                " \\ `--. | |_/ // /_\\ \\| /  \\/| |__",
                                "  `--. \\|  __/ |  _  || |    |  __|",
                                " /\\__/ /| |    | | | || \\__/\\| |___",
                                " \\____/ \\_|    \\_| |_/ \\____/\\____/",
                                "                                     ",
                                "                                     ",
                                "  _____  _   _  _   _   ___  ______  _____ ______ ",
                                " |_   _|| \\ | || | | | / _ \\ |  _  \\|  ___|| ___ \\",
                                "   | |  |  \\| || | | |/ /_\\ \\| | | || |__  | |_/ /",
                                "   | |  | . ` || | | ||  _  || | | ||  __| |    / ",
                                "  _| |_ | |\\  |\\ \\_/ /| | | || |/ / | |___ | |\\ \\",
                                "  \\___/ \\_| \\_/ \\___/ \\_| |_/|___/  \\____/ \\_| \\_|"};

    char imgmenu[6][33]={"___  ___  _____   _   _   _   _ ",   //Image du menu
                 "|  \\/  | |  ___| | \\ | | | | | |",
                 "| .  . | | |__   |  \\| | | | | |",
                 "| |\\/| | |  __|  | . ` | | | | |",
                 "| |  | | | |___  | |\\  | | |_| |",
                 "\\_|  |_/ \\____/  \\_| \\_/  \\___/ ",};




    system("mode con lines=52 cols=197");
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    system("title SpaceInvader...");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tJeu Space Invader\n\n\n");
    system ("color 02");
    for(ligne=0;ligne<16;ligne++)
    {   gotoxy(75,22+ligne);
        printf("%s",imgacceuilTerre[ligne]);
    }
    Sleep(1250);
    system("CLS");
    system ("color 0D");
    for(ligne=0;ligne<14;ligne++)
    {   gotoxy(75,22+ligne);
        printf("%s",imgacceuilTitre[ligne]);
    }
    Sleep(625);
    system ("CLS");
    for(ligne=0;ligne<6;ligne++)
    {   gotoxy(75,20+ligne);
        printf("%s",imgmenu[ligne]);
    }
    gotoxy(96,29);
    printf("1-JOUER ");
    gotoxy(96,30);
    printf("2-REGLES DU JEU ");
    gotoxy(96,31);
    printf("3-QUITTER ");
    gotoxy(75,35);
    printf("Appuyer sur ESPACE pour valider votre choix et déplacer vous avec Z et S");
    gotoxy(x,y);
    printf(">");
    while (i!=1)
    {
        if(kbhit() == 1)
            {
                touche = getch();
                if(touche==122) // Si l'utilisateur appuie sur la touche z le curseur monte
                {
                    if (y>29)
                    {
                        gotoxy(x,y);
                        printf(" ");
                        y=y-1;
                        gotoxy(x,y);
                        printf(">");
                    }
                }
                if(touche==115) // Si l'utilisateur appuie sur la touche s le curseur descend
                {
                    if (y<31)
                    {
                        gotoxy(x,y);
                        printf(" ");
                        y=y+1;
                        gotoxy(x,y);
                        printf(">");
                    }
                }
                if(touche==32) // Lorsque l'utilisateur appuie sur la touche espace il valide son choix
                {
                    i=1;
                    switch (y)
                    {
                        case 29:
                            chx=1;
                            break;
                        case 30:
                            chx=2;
                            break;
                        case 31:
                            chx=3;
                            break;
                    }
                }
            }
    }
    return chx;
}
/****************************************************************
 rôle : Choix du vaisseau par l'utilisateur
 Entrée : vaisseau1, vaisseau2 et vaisseau3
 Sortie : Choix du vaisseau
*****************************************************************/
int ChoixAvatar(char vaiso1[2][6],char vaiso2[2][8],char vaiso3[4][16])
{
    int chxavatar,ligne=0;  //Choix de l'avatar et indication de la ligne
    char imgvaisseau[6][88]={" _____  _             _                       _", //Dessin de choix vaisseau
                             "/  __ \\| |           (_)                     (_)                              ",
                             "| /  \\/| |__    ___   _ __  __ __   __  __ _  _  ___  ___   ___   __ _  _   _ ",
                             "| |    | '_ \\  / _ \\ | |\\ \\/ / \\ \\ / / / _` || |/ __|/ __| / _ \\ / _` || | | |",
                             "| \\__/\\| | | || (_) || | >  <   \\ V / | (_| || |\\__ \\\\__ \\|  __/| (_| || |_| |",
                             " \\____/|_| |_| \\___/ |_|/_/\\_\\   \\_/   \\__,_||_||___/|___/ \\___| \\__,_| \\__,_|"};

    system("CLS"); // Effacement de l'écran
    for(ligne=0;ligne<6;ligne++)
        {   gotoxy(47,5+ligne);
        printf("%s",imgvaisseau[ligne]);
        }
    for(ligne=0;ligne<2;ligne++)
    {   gotoxy(37,25+ligne);
        printf("%s",vaiso1[ligne]);
    }
    gotoxy(37,30);
    printf("1-Facile");
        for(ligne=0;ligne<2;ligne++)
    {   gotoxy(75,25+ligne);
        printf("%s",vaiso2[ligne]);
    }
    gotoxy(75,30);
    printf("2-Moyen") ;
    for(ligne=0;ligne<4;ligne++)
    {   gotoxy(112,25+ligne);
        printf("%s",vaiso3[ligne]);
    }
    gotoxy(112,30);
    printf("3-Difficile");
    gotoxy(75,32);
    printf("Choix : ");
    scanf("%d",&chxavatar);
    while (chxavatar<1 || chxavatar>3) // Saisie validée du choix du vaisseau
    {
       printf("Erreur ! Veuillez rentré un chiffre valide");
       printf("Choix : ");
       scanf("%d",&chxavatar);
    }
    return chxavatar;
}
/****************************************************************
 rôle : Choix de la couleur du vaisseau
 Entrée : vaisseau1, vaisseau2 et vaisseau3 et le choix du vaisseau
 Sortie : Choix de la couleur du  vaisseau
*****************************************************************/
int ChoixCouleur(int chx,char vaiso1[2][6],char vaiso2[2][8],char vaiso3[4][16])
{
    int ligne;  //Ligne du programme
    char imgchxcolor[6][80]={" _____  _             _                             _", //Dessin du choix de la couleur
                             "/  __ \\| |           (_)                           | |                  ",
                             "| /  \\/| |__    ___   _ __  __   ___   ___   _   _ | |  ___  _   _  _ __",
                             "| |    | '_ \\  / _ \\ | |\\ \\/ /  / __| / _ \\ | | | || | / _ \\| | | || '__|",
                             "| \\__/\\| | | || (_) || | >  <  | (__ | (_) || |_| || ||  __/| |_| || |",
                             " \\____/|_| |_| \\___/ |_|/_/\\_\\  \\___| \\___/  \\__,_||_| \\___| \\__,_||_|"};
    system("CLS");
    for(ligne=0;ligne<6;ligne++)
        {   gotoxy(47,5+ligne);
        printf("%s",imgchxcolor[ligne]);
        }
    if (chx==1) // Affichage des différentes couleurs pour le vaisseau facile
    {
        color(3,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,20+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(37,23);
        printf("1-Bleu_Gris");
        color(5,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,20+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(75,23);
        printf("2-Pourpre");
        color(6,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,20+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(112,23);
        printf("3-Kaki");
        color(7,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,25+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(37,28);
        printf("4-Gris_clair");
        color(8,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,25+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(75,28);
        printf("5-Gris");
        color(9,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,25+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(112,28);
        printf("6-Bleu");
        color(10,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,30+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(37,33);
        printf("7-Vert_Fluo");
        color(11,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,30+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(75,33);
        printf("8-Turquoise");
        color(12,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,30+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(112,33);
        printf("9-Rouge");
        color(13,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,35+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(37,38);
        printf("10-Rose_Fluo");
        color(14,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,35+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(75,38);
        printf("11-Jaune_Fluo");
        color(15,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,35+ligne);
        printf("%s",vaiso1[ligne]);
        }
        gotoxy(112,38);
        printf("12-Blanc");
        gotoxy(75,40);
        color(13,0);
    }
    else if (chx==2) // Affichage des différentes couleurs pour le vaisseau moyen
    {
        color(3,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,20+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(37,23);
        printf("1-Bleu_Gris");
        color(5,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,20+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(75,23);
        printf("2-Pourpre");
        color(6,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,20+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(112,23);
        printf("3-Kaki");
        color(7,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,25+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(37,28);
        printf("4-Gris_clair");
        color(8,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,25+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(75,28);
        printf("5-Gris");
        color(9,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,25+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(112,28);
        printf("6-Bleu");
        color(10,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,30+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(37,33);
        printf("7-Vert_Fluo");
        color(11,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,30+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(75,33);
        printf("8-Turquoise");
        color(12,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,30+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(112,33);
        printf("9-Rouge");
        color(13,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(37,35+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(37,38);
        printf("10-Rose_Fluo");
        color(14,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(75,35+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(75,38);
        printf("11-Jaune_Fluo");
        color(15,0);
        for(ligne=0;ligne<2;ligne++)
        {   gotoxy(112,35+ligne);
        printf("%s",vaiso2[ligne]);
        }
        gotoxy(112,38);
        printf("12-Blanc");
        gotoxy(75,40);
        color(13,0);
    }
    else // Affichage des différentes couleurs pour le vaisseau difficile
    {
        color(3,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(37,15+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(37,23-3);
        printf("1-Bleu_Gris");
        color(5,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(75,15+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(75,23-3);
        printf("2-Pourpre");
        color(6,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(112,15+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(112,23-3);
        printf("3-Kaki");
        color(7,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(37,25-3+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(37,28-1);
        printf("4-Gris_clair");
        color(8,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(75,25-3+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(75,28-1);
        printf("5-Gris");
        color(9,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(112,25-3+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(112,28-1);
        printf("6-Bleu");
        color(10,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(37,30+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(37,33+2);
        printf("7-Vert_Fluo");
        color(11,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(75,30+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(75,33+2);
        printf("8-Turquoise");
        color(12,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(112,30+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(112,33+2);
        printf("9-Rouge");
        color(13,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(37,35+2+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(37,38+4);
        printf("10-Rose_Fluo");
        color(14,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(75,35+2+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(75,38+4);
        printf("11-Jaune_Fluo");
        color(15,0);
        for(ligne=0;ligne<4;ligne++)
        {   gotoxy(112,35+2+ligne);
        printf("%s",vaiso3[ligne]);
        }
        gotoxy(112,38+4);
        printf("12-Blanc");
        gotoxy(75,40+5);
        color(13,0);
    }
    printf("Choix : ");
    scanf("%d",&chx);
    while (chx<1 || chx>12) // Saisie validée du choix de la couleur du vaisseau
    {
        printf("Erreur !Veuillez tapez un chiffre entre 1 et 12 pour choisir une couleur");
        printf("Choix : ");
        scanf("%d",&chx);
    }
    if (chx==1)
    {
        chx=3;
    }
    else
    {
        chx=chx+3;
    }
    return chx;
}

/****************************************************************
 rôle : Permet à l'utiliateur de choisir le mode qu'il veut
 Entrée : Rien
 Sortie : Choix du mode soit Boss, soit survie
*****************************************************************/
int ChoixMode()
{
    int chx,ligne;  //Choix du mode et la ligne choisi
    char iconesurvie[6][10]={" _______ ", //Dessin de l'icone de survie
                             "/       \\",
                             "| 0   0 |",
                             "\\   +   /",
                             " |_____|",
                             "  ''''' "};
    char iconeboss[11][43]={"  //                                \\\\", //Dessin de l'icone du boss
                             " //                                  \\\\",
                             "//                |==|                \\\\",
                             "||             |==|  |==|             ||",
                             "||         |===|   __   |===|         ||",
                             "||=========|      /  \\      |=========||",
                             "||    |    |===|  \\__/  |===|    |    ||",
                             "||         |   |==|  |==|   |         ||",
                             "\\\\             |  |==|  |             //",
                             " \\\\               |  |               //",
                             "  \\\\                                //"};
    char imgchxmode[6][69]={" _____  _             _         ___  ___            _ ", //Dessin du choix mode
                            "/  __ \\| |           (_)        |  \\/  |           | |",
                            "| /  \\/| |__    ___   _ __  __  | .  . |  ___    __| |  ___",
                            "| |    | '_ \\  / _ \\ | |\\ \\/ /  | |\\/| | / _ \\  / _` | / _ \\",
                            "| \\__/\\| | | || (_) || | >  <   | |  | || (_) || (_| ||  __/",
                            " \\____/|_| |_| \\___/ |_|/_/\\_\\  \\_|  |_/ \\___/  \\__,_| \\___|"};

    system("CLS");
    for(ligne=0;ligne<6;ligne++)
        {   gotoxy(40,5+ligne);
        printf("%s",imgchxmode[ligne]);
        }
    for(ligne=0;ligne<6;ligne++)
        {   gotoxy(50,20+ligne);
        printf("%s",iconesurvie[ligne]);
        }
    gotoxy(50,28);
    printf("1-Mode Survie");
    for(ligne=0;ligne<11;ligne++)
        {   gotoxy(100,16+ligne);
        printf("%s",iconeboss[ligne]);
        }
    gotoxy(114,28);
    printf("2-Mode Boss");
    gotoxy(75,31);
    printf("Choix : ");
    scanf("%d",&chx);
    while (chx<1 || chx>2) // Saisie validée du choix du mode
    {
        printf("Erreur ! Choisissez un des 2 modes a l'ecran");
        printf("Choix : ");
        scanf("%d",&chx);
    }
    return chx;
}
/****************************************************************
 rôle : Gestion du déplacement des vaisseaux en fonction des touches du claviers saisies
 Entrée : Choix du vaisseau, choix de la couleur,tableau de compteur avec 20 cases maximum, tableau de coordonnées et de score
 Sortie : Déplacement du vaisseau
*****************************************************************/
void deplacement(int chx,int tabxy[50][2],int tabcom[40],int couleur,double score[2])
{
    char vaisseau1[2][7]={"  |",  //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};
    char clear3[4][13]={"            ", //Espace du vaisseau 3 pour l'effacer
                        "            ",
                        "            ",
                        "            "};
    char clear2[2][7]={"      ", //Espace du vaisseau 2 pour l'effacer
                       "      "};
    char clear1[2][6]={"     ", //Espace du vaisseau 1 pour l'effacer
                       "     "};
    int touche;  //Touche du clavier
    int ligne; //Ligne du programme
    int i;

    if (tabcom[19]==0)
    {
        tabxy[1][1]=75;
        tabxy[1][2]=47;
        tabcom[19]=1;
    }
    if (chx==1) // Si l'utilisateur choisit le vaisseau 1
    {
        if(kbhit() == 1)
        {
            touche = getch();
            if(touche==27) // touche ESCAPE pour arrêter le programme
            {
                tabcom[11]=1;
            }
            if(touche==122) // touche z pour monter
            {
                if(tabxy[1][2]>12)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear1[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]-1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau1[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==113) // touche q pour aller à gauche
            {
                if (tabxy[1][1]>3)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear1[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]-1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                    color(couleur,0);
                    printf("%s",vaisseau1[ligne]);
                    color(5,0);
                    }
                }
            }
            if(touche==115) //touche s pour descendre
            {
                if (tabxy[1][2]<50)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear1[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]+1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau1[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==100) //touche d pour aller à droite
            {
                if (tabxy[1][1]<142)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear1[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]+1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau1[ligne]);
                        color(5,0);
                    }
                }
            }
            if (touche==32) //touche espace pour tirer un missile
            {
                if (tabcom[1]==0)
                {
                    gotoxy(tabxy[1][1]+2,tabxy[1][2]-1);
                    printf("|");
                    tabxy[2][1]=tabxy[1][1]+2;
                    tabxy[2][2]=tabxy[1][2]-1;
                }
            }
            if (touche==102) //touche f pour actionner la bombe qui permet d'éliminer tous les ennemis à l'écran
            {
                if (tabcom[5]>=1)
                {
                    tabcom[5]=tabcom[5]-1;
                    for (i=8;i<=16;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf("     ");
                            tabxy[i][2]=0;
                            tabcom[10]=0;
                            tabcom[3]=0;
                            score[1]=score[1]+500;
                        }
                    }
                }
            }
        }
    }
    if (chx==2)  // Si l'utilisateur choisit le vaisseau 2
    {
        if(kbhit() == 1)
        {
            touche = getch();
            if(touche==27) // touche ESCAPE pour arrêter le programme
            {
                tabcom[11]=1;
            }
            if(touche==122) // touche z pour monter
            {
                if(tabxy[1][2]>12)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear2[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]-1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau2[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==113) // touche q pour aller à gauche
            {
                if (tabxy[1][1]>3)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear2[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]-1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                    color(couleur,0);
                    printf("%s",vaisseau2[ligne]);
                    color(5,0);
                    }
                }
            }
            if(touche==115) //touche s pour descendre
            {
                if (tabxy[1][2]<50)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear2[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]+1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau2[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==100) //touche d pour aller à droite
            {
                if (tabxy[1][1]<142)
                {
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear2[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]+1;
                    for(ligne=0;ligne<2;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau2[ligne]);
                        color(5,0);
                    }
                }
            }
            if (touche==32) //touche espace pour tirer un missile
            {
                if (tabcom[1]==0)
                {
                    //missile 1
                    gotoxy(tabxy[1][1]+5,tabxy[1][2]-1);
                    printf("|");
                    tabxy[2][1]=tabxy[1][1]+5;
                    tabxy[2][2]=tabxy[1][2]-2;
                    //missile 2
                    gotoxy(tabxy[1][1],tabxy[1][2]-1);
                    printf("|");
                    tabxy[3][1]=tabxy[1][1];
                    tabxy[3][2]=tabxy[1][2]-2;
                    gotoxy(tabxy[1][1],tabxy[1][2]-1);
                    printf("      ");
                }
            }
            if (touche==102) //touche f pour actionner la bombe qui permet d'éliminer tous les ennemis à l'écran
            {
                if (tabcom[5]>=1)
                {
                    tabcom[5]=tabcom[5]-1;
                    for (i=8;i<=16;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf("     ");
                            tabxy[i][2]=0;
                            tabcom[10]=0;
                            tabcom[3]=0;
                            score[1]=score[1]+500;
                        }
                    }
                }
            }
        }
    }
    if (chx==3) // Si l'utilisateur choisit le vaisseau 3
    {
        if(kbhit() == 1)
        {
            touche = getch();
            if(touche==27)  // touche ESCAPE pour arrêter le programme
            {
                tabcom[11]=1;
            }// touche ESCAPE pour arrêter le programme
            if(touche==122) // touche z pour monter
            {
                if(tabxy[1][2]>12)
                {
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear3[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]-1;
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau3[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==113) // touche q pour aller à gauche
            {
                if (tabxy[1][1]>3)
                {
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear3[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]-1;
                    for(ligne=0;ligne<4;ligne++)
                    {
                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                    color(couleur,0);
                    printf("%s",vaisseau3[ligne]);
                    color(5,0);
                    }
                }
            }
            if(touche==115) //touche s pour descendre
            {
                if (tabxy[1][2]<48)
                {
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear3[ligne]);
                    }
                    tabxy[1][2]=tabxy[1][2]+1;
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau3[ligne]);
                        color(5,0);
                    }
                }
            }
            if(touche==100) //touche d pour aller à droite
            {
                if (tabxy[1][1]<136)
                {
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        printf("%s",clear3[ligne]);
                    }
                    tabxy[1][1]=tabxy[1][1]+1;
                    for(ligne=0;ligne<4;ligne++)
                    {
                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                        color(couleur,0);
                        printf("%s",vaisseau3[ligne]);
                        color(5,0);
                    }
                }
            }
            if (touche==32) //touche espace pour tirer un missile
            {
                if (tabcom[1]==0)
                {
                    //missile 1
                    gotoxy(tabxy[1][1],tabxy[1][2]-2);
                    printf("|");
                    tabxy[2][1]=tabxy[1][1];
                    tabxy[2][2]=tabxy[1][2]-2;
                    //missile 2
                    gotoxy(tabxy[1][1]+4,tabxy[1][2]-2);
                    printf("|");
                    tabxy[3][1]=tabxy[1][1]+4;
                    tabxy[3][2]=tabxy[1][2]-2;
                    //missile 3
                    gotoxy(tabxy[1][1]+10,tabxy[1][2]-2);
                    printf("|");
                    tabxy[4][1]=tabxy[1][1]+10;
                    tabxy[4][2]=tabxy[1][2]-2;
                }
            }
            if (touche==102) //touche f pour actionner la bombe qui permet d'éliminer tous les ennemis à l'écran
            {
                if (tabcom[5]>=1)
                {
                    tabcom[5]=tabcom[5]-1;
                    for (i=8;i<=16;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf("     ");
                            tabxy[i][2]=0;
                            tabcom[10]=0;
                            tabcom[3]=0;
                            score[1]=score[1]+500;
                        }
                    }
                }
            }
        }
    }

    if (tabcom[1]==0 && touche==32)
    {
        tabcom[1]=1;
    }
    color(14,0);
}
/****************************************************************
 rôle : Gestion des tirs en fonction des différents vaisseaux et des sorties d'écran
 Entrée : choix du vaisseau,de la couleur, tableau de temps, de coordonnées, de compteur et de score
 Sortie : Rien
*****************************************************************/
void tir(int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2])
{
    char boss1[11][43]={"  //                                \\\\",
                        " //                                  \\\\",
                        "//                |==|                \\\\",
                        "||             |==|  |==|             ||",
                        "||         |===|   __   |===|         ||",
                        "||=========|      /  \\      |=========||",
                        "||    |    |===|  \\__/  |===|    |    ||",
                        "||         |   |==|  |==|   |         ||",
                        "\\\\             |  |==|  |             //",
                        " \\\\               |  |               //",
                        "  \\\\                                //"};
    char boss2[10][42]={"               ==========",
                        "           ====          ====",
                        "      =====  /============\\  =====",
                        " =====       |  |------|  |        =====",
                        "||           |==|      |==|            ||",
                        " =====       |  |------|  |        =====",
                        "   |  =====  \\============/  =====  |",
                        "        |  ====          ====  |",
                        "            |  ==========  |",
                        "                  |  |"};
    char boss3[9][42]={"       \\   _.-'~~~~'-._   /",
                       ".       .-~ \\__/  \\__/ ~-.",
                       "      .-~   (oo)  (oo)    ~-.",
                       "     (_____//~~\\\\//~~\\\\______)",
                       " _.-~`                           `~-._",
                       "/O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O\\",
                       "\\_____________________________________/",
                       "    |    \\x x x x x x x/       |",
                       "          \\x_x_x_x_x_x/"};
    char boss4[9][44]={"                   _",
                       "                 _/ \\_",
                       "             ___/     \\___",
                       "         ___/      /\\     \\___",
                       "     ___/         /--\\         \\___",
                       " ___/            /____\\             \\___",
                       "/                                         \\",
                       "-------------------------------------------"
                       " |    |    |    |    |    |    |    |    |"};
    char boss5[11][44]={"            __________________ ",
                        "           /                  \\",
                        "          |      _        _    |",
                        "| | | | | |     | |      | |   | | | | | |",
                        "==========|      -        -    |==========",
                        "| | | | |  \\         _         / | | | | |",
                        "            \\       /+\\       /",
                        "             |     /---\\     |",
                        "             |               |",
                        "             |_______________|",
                        "              ||||||||||||||| "};
    int u,i,o; // increments de boucles For
    int touche; //Touche du clavier saisie
    int ligne; //Ligne du programme

    color(couleur,0);
    if (tabcom[1]==1) //déplacement missile
    {
        if (chx==1)
        {
            if (tabxy[2][1]!=0)
            {
                gotoxy(tabxy[2][1],tabxy[2][2]);
                printf(" ");
                tabxy[2][2]=tabxy[2][2]-1;
                gotoxy(tabxy[2][1],tabxy[2][2]);
                printf("|");
            }
        }
        else if (chx==2)
        {
            for(i=2;i<=3;i=i+1)
            {
                if (tabxy[i][1]!=0)
                {
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf(" ");
                    tabxy[i][2]=tabxy[i][2]-1;
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|");
                }
            }
        }
        else if (chx==3)
        {
            for(i=2;i<=4;i=i+1)
            {
                if (tabxy[i][1]!=0)
                {
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf(" ");
                    tabxy[i][2]=tabxy[i][2]-1;
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|");
                }
            }
        }

    }
    if (tabcom[1]==1) //collisions ennemis
    {
        if (chx==1)
        {
            for (o=8;o<=16;o=o+1)//position ennemis
            {
                    for (i=0;i<=5;i=i+1)//espace de contact possible
                    {
                        if ((tabxy[2][1]==tabxy[o][1]+i)&&(tabxy[2][2]==tabxy[o][2]))
                        {
                            gotoxy(tabxy[o][1],tabxy[o][2]);
                            printf("          ");
                            if (tabxy[2][1]!=0)
                            {
                                tabcom[7]=tabcom[7]+1;
                                tabcom[10]=tabcom[10]+1;
                                score[1]=score[1]+500;
                            }
                            tabcom[4]=1;
                            tabxy[2][1]=0;
                            tabxy[o][2]=0;
                            tabcom[30]=tabcom[30]+1;
                        }
                    }
            }
        }
        else if (chx==2)
        {
            for (u=2;u<=3;u=u+1)//position tirs
            {
                for (o=8;o<=16;o=o+1) //position ennemis
                {
                    for (i=0;i<=5;i=i+1) //espace de contact possible
                    {
                        if ((tabxy[u][1]==tabxy[o][1]+i)&&(tabxy[u][2]==tabxy[o][2]))
                        {
                            gotoxy(tabxy[o][1],tabxy[o][2]);
                            printf("          ");
                            if (tabxy[u][1]!=0)
                            {
                                tabcom[7]=tabcom[7]+1;
                                tabcom[10]=tabcom[10]+1;
                                score[1]=score[1]+500;
                            }
                            tabcom[4]=tabcom[4]+u;
                            tabxy[o][2]=0;
                            tabxy[u][1]=0;
                            tabcom[30]=tabcom[30]+1;
                        }
                    }
                }
            }
        }
        else if (chx==3)
        {
            for (u=2;u<=4;u=u+1)//coord tir
            {
                for (o=8;o<=16;o=o+1)//coord ennemie
                {
                    for (i=0;i<=5;i=i+1)//espace de contact possible
                    {
                        if ((tabxy[u][1]==tabxy[o][1]+i)&&(tabxy[u][2]==tabxy[o][2]))
                        {
                            gotoxy(tabxy[o][1],tabxy[o][2]);
                            printf("          ");
                            if (tabxy[u][1]!=0)
                            {
                                tabcom[7]=tabcom[7]+1;
                                tabcom[10]=tabcom[10]+1;
                                score[1]=score[1]+500;
                            }
                            tabcom[4]=tabcom[4]+u;
                            tabxy[o][2]=0;
                            tabxy[u][1]=0;
                            tabcom[30]=tabcom[30]+1;
                        }
                    }
                }
            }
        }
    }
    if (tabcom[20]==1)//collision boss
    {
        if (chx==1)
        {
            for (i=0;i<=44;i=i+1)//espace de contact possible
            {
                if (((tabxy[2][1]==tabxy[17][1]+i)&&(tabxy[2][2]==tabxy[17][2]+11)))
                {
                    tabcom[9]=tabcom[9]+1;
                    tabcom[4]=1;
                    gotoxy(tabxy[2][1],tabxy[2][2]);
                    printf(" ");
                    tabxy[2][1]=0;
                }
            }
        }
        else if (chx==2)
        {
            for (u=2;u<=3;u=u+1)//coord tir
            {
                for (i=0;i<=44;i=i+1)//espace de contact possible
                {
                    if (((tabxy[u][1]==tabxy[17][1]+i)&&(tabxy[u][2]==tabxy[17][2]+11)))
                    {
                        tabcom[9]=tabcom[9]+1;
                        tabcom[4]=tabcom[4]+u;
                        gotoxy(tabxy[u][1],tabxy[u][2]);
                        printf(" ");
                        tabxy[u][1]=0;
                    }
                }
            }
        }
        else if (chx==3)
        {
            for (u=2;u<=4;u=u+1)//coord tir
            {
                for (i=0;i<=43;i=i+1)//espace de contact possible
                {
                    if (((tabxy[u][1]==tabxy[17][1]+i)&&(tabxy[u][2]==tabxy[17][2]+11)))
                    {
                        tabcom[9]=tabcom[9]+1;
                        tabcom[4]=tabcom[4]+u;
                        gotoxy(tabxy[u][1],tabxy[u][2]);
                        printf(" ");
                        tabxy[u][1]=0;
                    }
                }
            }
        }
        if (tabcom[8]==0||tabcom[8]==5)
        {
            for(ligne=0;ligne<11;ligne++)
            {
                gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                color(12,0);
                printf("%s",boss1[ligne]);
                color(5,0);
            }
        }
        else if (tabcom[8]==1||tabcom[8]==6)
        {
            for(ligne=0;ligne<10;ligne++)
            {
                gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                color(12,0);
                printf("%s",boss2[ligne]);
                color(5,0);
            }
        }
        else if (tabcom[8]==2||tabcom[8]==7)
        {
            for(ligne=0;ligne<9;ligne++)
            {
                gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                color(12,0);
                printf("%s",boss3[ligne]);
                color(5,0);
            }
        }
        else if (tabcom[8]==3||tabcom[8]==8)
        {
            for(ligne=0;ligne<9;ligne++)
            {
                gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                color(12,0);
                printf("%s",boss4[ligne]);
                color(5,0);
            }
        }
        else if (tabcom[8]==4||tabcom[8]==9)
        {
            for(ligne=0;ligne<11;ligne++)
            {
                gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                color(12,0);
                printf("%s",boss5[ligne]);
                color(5,0);
            }
        }
    }
    if (tabcom[1]==1) //missiles sort de l'écran
    {
        if (chx==1)
        {
            if (tabxy[2][2]==1)
            {
               gotoxy(tabxy[2][1],tabxy[2][2]);
               printf(" ");
               tabcom[4]=1;
               tabxy[2][2]=60;
               tabxy[2][1]=0;
            }
        }
        if (chx==2)
        {
           for (u=2;u<=3;u=u+1)
           {
                if (tabxy[u][2]==1)
                {
                    gotoxy(tabxy[u][1],tabxy[u][2]);
                    printf(" ");
                    tabxy[u][2]=60;
                    tabxy[u][1]=0;
                    tabcom[4]=tabcom[4]+u;
                }
            }
        }
        if (chx==3)
        {
           for (u=2;u<=4;u=u+1)
           {
                if (tabxy[u][2]==2)
                {
                    gotoxy(tabxy[u][1],tabxy[u][2]);
                    printf(" ");
                    tabxy[u][2]=60;
                    tabxy[u][1]=0;
                    tabcom[4]=tabcom[4]+u;
                }
            }
        }
    }
    if (tabcom[1]==1)
    {
        if (chx==1)
        {
            if (tabxy[2][1]==0)
            {
                tabcom[1]=0;
                tabcom[4]=0;
            }
        }
        if (chx==2)
        {
            if ((tabxy[2][1]==0) && (tabxy[3][1]==0))
            {
                tabcom[1]=0;
                tabcom[4]=0;
            }
        }
        if (chx==3)
        {
            if ((tabxy[2][1]==0) && (tabxy[3][1]==0) && (tabxy[4][1]==0))
            {
                tabcom[1]=0;
                tabcom[4]=0;
            }
        }
    }
    color(14,0);
}
/****************************************************************
 rôle : Permet à l'utilisateur de jouer, en fonction de ce qu'il a choisi
 Entrée : choix du mode, choix du vaisseau, choix de la couleur, tableau de temps, de coordonnées, de compteur et de score
 Sortie : Bon fonctionnement du jeu
 *****************************************************************/
int Jouer(int mode,int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2])
{
    int i,u,ligne,MAX, MIN,touche;
    char vaisseau1[2][7]={"  |",   //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};
    char Pause[6][40]={"______   ___   _   _  _____  _____ ",
                       "| ___ \\ / _ \\ | | | |/  ___||  ___|",
                       "| |_/ // /_\\ \\| | | |\\ `--. | |__ ",
                       "|  __/ |  _  || | | | `--. \\|  __|",
                       "| |    | | | || |_| |/\\__/ /| |___",
                       "\\_|    \\_| |_/ \\___/ \\____/ \\____/" };
    char clearPause[6][36]={"                                   ",
                            "                                   ",
                            "                                   ",
                            "                                   ",
                            "                                   ",
                            "                                   "};
    system("CLS");
    for (i=1;i<=51;i=i+1)
    {
        gotoxy(1,i);
        printf("||");
        gotoxy(148,i);
        printf("||");
    }
    tabxy[1][1]=75;
    tabxy[1][2]=47;
    tabcom[6]=10;
    switch (chx) // Affichage du vaisseau
    {
        case 1: // Si choix 1
            for(ligne=0;ligne<2;ligne++)
            {
                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                color(couleur,0);
                printf("%s",vaisseau1[ligne]);
                color(5,0);
            }
            break;
        case 2: // Si choix 2
            for(ligne=0;ligne<2;ligne++)
            {
                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                color(couleur,0);
                printf("%s",vaisseau2[ligne]);
                color(5,0);
            }
            break;
        case 3:  // Si choix 3
            for(ligne=0;ligne<4;ligne++)
            {
                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                color(couleur,0);
                printf("%s",vaisseau3[ligne]);
                color(5,0);
            }
            break;
    }
    while (tabcom[25]==0) // Condition fin de partie
    {
        while (tabcom[11]==0 && tabcom[25]==0)
        {
            deplacement(chx,tabxy,tabcom,couleur,score);
            tir(chx,tabtime,tabxy,tabcom,couleur,score);
            srand(time(NULL));
            if (tabtime[2]==0)
            {
                if (chx==1) // Délai d'apparition des ennemis
                {
                    if (tabcom[7]<48)
                    {
                        MAX = 7000;
                        MIN = 3500;
                    }
                    if (tabcom[7]>=48 && tabcom[7]<123)
                    {
                        MAX = 6000;
                        MIN = 3000;
                    }
                    if (tabcom[7]>=123)
                    {
                        MAX = 5000;
                        MIN = 2500;
                    }
                }
                if (chx==2) // Délai d'aparition des ennemis
                {
                    if (tabcom[7]<48)
                    {
                        MAX = 5000;
                        MIN = 2500;
                    }
                    if (tabcom[7]>=48 && tabcom[7]<123)
                    {
                        MAX = 4000;
                        MIN = 1500;
                    }
                    if (tabcom[7]>=123)
                    {
                        MAX = 3000;
                        MIN = 1000;
                    }
                }
                if (chx==3) // Délai d'apparition des ennemis
                {
                    if (tabcom[7]<48)
                    {
                        MAX = 4000;
                        MIN = 2000;
                    }
                    if (tabcom[7]>=48 && tabcom[7]<123)
                    {
                        MAX = 3000;
                        MIN = 1500;
                    }
                    if (tabcom[7]>=123)
                    {
                        MAX = 2000;
                        MIN = 500;
                    }
                }
                tabtime[2]= (rand() % (MAX - MIN+1)) + MIN; // Apparition aléatoire des ennemis
            }
            Ennemie(chx,mode,tabtime,tabxy,tabcom,couleur); // Appel de la fonction ennemie
            if (mode==2) // Appel de la fonction Boss si l'utilisateur a choisi le mode Boss
            {
                Boss(chx,mode,tabtime,tabxy,tabcom,couleur,score); //apppel de la fonction Boss
            }
            if (tabtime[1]==25000000)
            {
                tabtime[1]=0;
            }
            AffichageScore(chx,mode,tabtime,score,tabcom,couleur); // Appel de la fonction affichage du score
            GameOver(tabcom,mode); // Appel de la fonction Game Over
            if (tabtime[3]==0) // Délai d'apparition des vitamines
            {
                MAX = 45000;
                MIN = 25000;
                tabtime[3]= (rand() % (MAX - MIN+1)) + MIN; // Apparition aléatoire des vitamines
            }
            vitamine(chx,tabtime,tabxy,tabcom,couleur); //Appel de la fonction Vitamine
            Sleep(25); // Temps de Pause de 25 ms
            tabtime[1]=tabtime[1]+25;
            switch (chx)
            {
                case 1:
                  score[1]=score[1]+25*0.5;
                  break;
                case 2:
                  score[1]=score[1]+25*1;
                  break;
                case 3:
                  score[1]=score[1]+25*2.5;
                    break;
            }
        }
        if (tabcom[11]==1) // Si l'utilisateur met Pause alors apparition d'un message et partie qui se stop
        {
            for(ligne=0;ligne<6;ligne++)
            {
                gotoxy(58,23+ligne);
                color(5,0);
                printf("%s",Pause[ligne]);
            }
        }
        while (tabcom[11]==1)
        {
            if(kbhit() == 1)
            {
                touche = getch();
                if(touche==27) // Lorsque l'utilisateur tape la touche escape le jeu se met en pause
                {
                    tabcom[11]=0;
                    for(ligne=0;ligne<6;ligne++)
                    {
                        gotoxy(58,23+ligne);
                        color(5,0);
                        printf("%s",clearPause[ligne]);
                    }
                }// touche ESCAPE pour arrêter la pause
            }
        }
        getchar();
    }
}
/****************************************************************
 rôle : Gestion du déplacement des ennemis et de leur apparition dans le jeu
 Entrée : choix du vaisseau, du mode et tableau de temps, de coordonnées, de compteur et de score
 Sortie : Rien
 *****************************************************************/
void Ennemie(int chx,int mode,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur)
{
    int i,u,ligne,x; // Increment et ligne du programme
    int mvt; // Mouvement ennemis
    int MAX = 0, MIN = 0;
    char vaisseau1[2][6]={"  |", //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};
    char ennemie[1][6]={"|-o-|"}; //Dessin du vaisseau ennemi
    char clear[1][6]={"     "}; //Effacement du vaisseau ennemi avec des espaces

    tabtime[4]=tabtime[4]+25;
    color(5,0);

    switch(tabcom[3]) //collision sol
    {
        case 1:
                for (i=8;i<=10;i=i+1)
                {
                   if (tabxy[i][2]==51)
                   {
                       gotoxy(tabxy[i][1],tabxy[i][2]);
                       printf("     ");
                       tabcom[10]=tabcom[10]+1;
                       tabcom[7]=tabcom[7]+1;
                       tabxy[i][2]=0;
                   }
                }
                break;
        case 2:
                for (i=8;i<=13;i=i+1)
                {
                    if (tabxy[i][2]==51)
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabxy[i][2]=0;
                    }
                }
                break;
        case 3:
                for (i=8;i<=16;i=i+1)
                {
                    if (tabxy[i][2]==51)
                   {
                       gotoxy(tabxy[i][1],tabxy[i][2]);
                       printf("     ");
                       tabcom[10]=tabcom[10]+1;
                       tabcom[7]=tabcom[7]+1;
                       tabxy[i][2]=0;
                   }
                }
                break;
    }
    if (tabtime[4]>=tabtime[2]) //apparition ennemis
    {
        switch (tabcom[3])
        {
            case 0:
                for (i=8;i<=10;i=i+1)
                {
                    if (tabcom[22]==0)
                    {
                        tabxy[i][2]=3;
                    }
                    else
                    {
                        tabxy[i][2]=12;
                    }
                    if (i==8)
                    {
                        tabxy[i][1]= (rand() %  (136 - 91 + 1)) + 91;
                    }
                    else if (i==9)
                    {
                        tabxy[i][1]= (rand() %  (86 - 45 + 1)) + 45;
                    }
                    else if (i==10)
                    {
                        tabxy[i][1]= (rand() %  (40 - 3 + 1)) + 3;
                    }
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");

                }
                break;
            case 1:
                for (i=11;i<=13;i=i+1)
                {
                    if (tabcom[22]==0)
                    {
                        tabxy[i][2]=3;
                    }
                    else
                    {
                        tabxy[i][2]=12;
                    }
                    if (i==11)
                    {
                        tabxy[i][1]= (rand() %  (136 - 91 + 1)) + 91;
                    }
                    else if (i==12)
                    {
                        tabxy[i][1]= (rand() %  (86 - 45 + 1)) + 45;
                    }
                    else if (i==13)
                    {
                        tabxy[i][1]= (rand() %  (40 - 3 + 1)) + 3;
                    }
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");
                }
                break;
            case 2:
                for (i=14;i<=16;i=i+1)
                {
                    if (tabcom[22]==0)
                    {
                        tabxy[i][2]=3;
                    }
                    else
                    {
                        tabxy[i][2]=12;
                    }
                    if (i==14)
                    {
                        tabxy[i][1]= (rand() %  (136 - 91 + 1)) + 91;
                    }
                    else if (i==15)
                    {
                        tabxy[i][1]= (rand() %  (86 - 45 + 1)) + 45;
                    }
                    else if (i==16)
                    {
                        tabxy[i][1]= (rand() %  (40 - 3 + 1)) + 3;
                    }
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");
                }
                break;
        }
        if (tabcom[3]<3)
        {
            tabcom[3]=tabcom[3]+1;
        }
        tabtime[4]=0;
        tabtime[2]=0;
    }
    if ((tabtime[1]%150)==0) //deplacement ennemis
    {
        if (tabcom[3]==1)
        {
            for (i=8;i<=10;i=i+1)
            {
                if (tabxy[i][2]!=0)
                {
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("     ");
                    mvt=(rand() % (2 - 1 + 1)) + 1;
                    if (mvt==1)
                    {
                        mvt=-1;
                    }
                    if (mvt==2)
                    {
                        mvt=1;
                    }
                    tabxy[i][1]=tabxy[i][1]+mvt;
                    for (u=8;u<=10;u=u+1)
                    {
                        if (u!=i && ((tabxy[i][1]+6==tabxy[u][1])||(tabxy[i][1]==tabxy[u][1]+6)))
                        {
                            tabxy[i][1]=tabxy[i][1]-mvt;
                        }
                    }
                    if (tabxy[i][1]<=3)
                    {
                        tabxy[i][1]=tabxy[i][1]+1;
                    }
                    else if (tabxy[i][1]>=136)
                    {
                        tabxy[i][1]=tabxy[i][1]-1;
                    }
                    tabxy[i][2]=tabxy[i][2]+1;
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");
                    gotoxy(tabxy[i][1],tabxy[i][2]-1);
                    printf("     ");
                }
            }
        }
        if (tabcom[3]==2)
        {
            for (i=8;i<=13;i=i+1)
            {
                if (tabxy[i][2]!=0)
                {
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("     ");
                    mvt = (rand() % (2 - 1 + 1)) + 1;
                    if (mvt==1)
                    {
                        mvt=-1;
                    }
                    if (mvt==2)
                    {
                        mvt=1;
                    }
                    tabxy[i][1]=tabxy[i][1]+mvt;
                    for (u=8;u<=13;u=u+1)
                    {
                        if (u!=i && ((tabxy[i][1]+6)==tabxy[u][1])||(tabxy[i][1]==(tabxy[u][1]+6)))
                        {
                            tabxy[i][1]=tabxy[i][1]-mvt;
                        }
                    }
                    if (tabxy[i][1]<=3)
                    {
                        tabxy[i][1]=tabxy[i][1]+1;
                    }
                    else if (tabxy[i][1]>=136)
                    {
                        tabxy[i][1]=tabxy[i][1]-1;
                    }
                    tabxy[i][2]=tabxy[i][2]+1;
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");
                    gotoxy(tabxy[i][1],tabxy[i][2]-1);
                    printf("     ");
                }
            }
        }
        if (tabcom[3]==3)
        {
            for (i=8;i<=16;i=i+1)
            {
                if (tabxy[i][2]!=0)
                {
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("     ");
                    mvt= (rand() % (2 - 1 + 1)) + 1;
                    if (mvt==1)
                    {
                        mvt=-1;
                    }
                    if (mvt==2)
                    {
                        mvt=1;
                    }
                    tabxy[i][1]=tabxy[i][1]+mvt;
                    for (u=8;u<=16;u=u+1)
                    {
                        if (u!=i && ((tabxy[i][1]+6)==tabxy[u][1])||(tabxy[i][1]==(tabxy[u][1]+6)))
                        {
                            tabxy[i][1]=tabxy[i][1]-mvt;
                        }
                    }
                    if (tabxy[i][1]<=3)
                    {
                        tabxy[i][1]=tabxy[i][1]+1;
                    }
                    else if (tabxy[i][1]>=136)
                    {
                        tabxy[i][1]=tabxy[i][1]-1;
                    }
                    tabxy[i][2]=tabxy[i][2]+1;
                    gotoxy(tabxy[i][1],tabxy[i][2]);
                    printf("|-o-|");
                    gotoxy(tabxy[i][1],tabxy[i][2]-1);
                    printf("     ");
                }
            }
        }
    }
    if(chx==1)  // collision vaisseau
    {
        if (tabcom[3]==1)
        {
            for (i=8;i<=10;i=i+1)
            {
                for (u=0;u<=3;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-4;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==2)
        {
            for (i=8;i<=13;i=i+1)
            {
                for (u=0;u<=3;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==3)
        {
            for (i=8;i<=16;i=i+1)
            {
                for (u=0;u<=3;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau1[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
    }
    else if (chx==2)
    {
        if (tabcom[3]==1)
        {
            for (i=8;i<=10;i=i+1)
            {
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==2)
        {
            for (i=8;i<=13;i=i+1)
            {
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==3)
        {
            for (i=8;i<=16;i=i+1)
            {
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-5;u<=5;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<2;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau2[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
    }
    else if (chx==3)
    {
        if (tabcom[3]==1)
        {
            for (i=8;i<=10;i=i+1)
            {
                for (u=0;u<=6;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-3;u<=10;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-4;u<=11;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+2)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-1;u<=8;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+3)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==2)
        {
            for (i=8;i<=13;i=i+1)
            {
                for (u=0;u<=6;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-3;u<=10;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-4;u<=11;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+2)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-1;u<=8;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+3)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
        if (tabcom[3]==3)
        {
            for (i=8;i<=16;i=i+1)
            {
                for (u=0;u<=6;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-3;u<=10;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-4;u<=11;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+2)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
                for (u=-1;u<=8;u=u+1)
                {
                    if ((tabxy[i][2]==tabxy[1][2]+3)&&(tabxy[i][1]==tabxy[1][1]+u))
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf("     ");
                        for(ligne=0;ligne<4;ligne++)
                        {
                            gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                            color(couleur,0);
                            printf("%s",vaisseau3[ligne]);
                            color(5,0);
                        }
                        tabcom[10]=tabcom[10]+1;
                        tabcom[7]=tabcom[7]+1;
                        tabcom[6]=tabcom[6]-1;
                        tabxy[i][2]=0;
                    }
                }
            }
        }
    }
    if ((tabcom[3]>=3) &&(tabcom[10]==9))
    {
        tabcom[3]=0;
        tabcom[10]=0;
    }
}

/****************************************************************
 rôle : Gestion du déplacement des boss et leur apparition
 Entrée : choix du vaisseau, du mode, de la couleur du vaisseau et tableau du temps, de compteur, de position et de score
 Sortie : Rien
*****************************************************************/
void Boss(int chx,int mode,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur,double score[2])
{
    char boss1[11][43]={"  //                                \\\\",  // Dessin boss 1
                        " //                                  \\\\",
                        "//                |==|                \\\\",
                        "||             |==|  |==|             ||",
                        "||         |===|   __   |===|         ||",
                        "||=========|      /  \\      |=========||",
                        "||    |    |===|  \\__/  |===|    |    ||",
                        "||         |   |==|  |==|   |         ||",
                        "\\\\             |  |==|  |             //",
                        " \\\\               |  |               //",
                        "  \\\\                                //"};
    char boss2[10][42]={"               ==========", // Dessin boss 2
                        "           ====          ====",
                        "      =====  /============\\  =====",
                        " =====       |  |------|  |        =====",
                        "||           |==|      |==|            ||",
                        " =====       |  |------|  |        =====",
                        "   |  =====  \\============/  =====  |",
                        "        |  ====          ====  |",
                        "            |  ==========  |",
                        "                  |  |"};
    char boss3[9][42]={"       \\   _.-'~~~~'-._   /", // Dessin boss 3
                       ".       .-~ \\__/  \\__/ ~-.",
                       "      .-~   (oo)  (oo)    ~-.",
                       "     (_____//~~\\\\//~~\\\\______)",
                       " _.-~`                           `~-._",
                       "/O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O\\",
                       "\\_____________________________________/",
                       "    |    \\x x x x x x x/       |",
                       "          \\x_x_x_x_x_x/"};
    char boss4[9][44]={"                   _",    // Dessin boss 4
                       "                 _/ \\_",
                       "             ___/     \\___",
                       "         ___/      /\\     \\___",
                       "     ___/         /--\\         \\___",
                       " ___/            /____\\             \\___",
                       "/                                         \\",
                       "-------------------------------------------"
                       " |    |    |    |    |    |    |    |    |"};
    char boss5[11][44]={"            __________________ ",   // Dessin boss 5
                        "           /                  \\",
                        "          |      _        _    |",
                        "| | | | | |     | |      | |   | | | | | |",
                        "==========|      -        -    |==========",
                        "| | | | |  \\         _         / | | | | |",
                        "            \\       /+\\       /",
                        "             |     /---\\     |",
                        "             |               |",
                        "             |_______________|",
                        "              ||||||||||||||| "};
    char clearboss[11][44]={"                                           ",  // Effacement du boss
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",
                            "                                           ",};
    char vaisseau1[2][6]={"  |", //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};
    int emplcmnttir,ligne,i,u,mvt; // Emplacement tir, ligne du programme, increment et mouvement du boss

    if (tabcom[7]>=54 && tabcom[3]==0)
    {
        tabcom[7]=0;
        if (tabcom[22]==0)
        {
            tabcom[22]=tabcom[22]+1;
        }
    }
    if (tabcom[22]==1)
    {
        if (tabcom[20]==0)//apparition Boss
        {
            if (tabxy[17][1]==0)
            {
                tabxy[17][1]=53;
                tabxy[17][2]=1;
                if (tabcom[8]==0||tabcom[8]==5)
                {
                    for(ligne=0;ligne<11;ligne++) // Apparition Boss 1
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        color(12,0);
                        printf("%s",boss1[ligne]);
                        color(5,0);
                    }
                }
                else if (tabcom[8]==1||tabcom[8]==6) // Apparition Boss 2
                {
                    for(ligne=0;ligne<10;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        color(12,0);
                        printf("%s",boss2[ligne]);
                        color(5,0);
                    }
                }
                else if (tabcom[8]==2||tabcom[8]==7)
                {
                    for(ligne=0;ligne<9;ligne++) // Apparition Boss 3
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        color(12,0);
                        printf("%s",boss3[ligne]);
                        color(5,0);
                    }
                }
                else if (tabcom[8]==3||tabcom[8]==8)
                {
                    for(ligne=0;ligne<9;ligne++) // Apparition Boss 4
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        color(12,0);
                        printf("%s",boss4[ligne]);
                        color(5,0);
                    }
                }
                else if (tabcom[8]==4||tabcom[8]==9)
                {
                    for(ligne=0;ligne<11;ligne++) // Apparition Boss 5
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        color(12,0);
                        printf("%s",boss5[ligne]);
                        color(5,0);
                    }
                }
                tabcom[20]=1;
            }
        }
        if (tabtime[1]%75==0) //déplacement boss
        {
            if (tabcom[20]==1)
            {
                if (tabxy[17][1]!=0)
                {
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    mvt=(rand() % (2 - 1 + 1)) + 1;
                    if (mvt==1)
                    {
                        mvt=-1;
                    }
                    if (mvt==2)
                    {
                        mvt=1;
                    }
                    tabxy[17][1]=tabxy[17][1]+mvt;
                    if (tabxy[17][1]<=3)
                    {
                        tabxy[17][1]=tabxy[17][1]+1;
                    }
                    else if (tabxy[17][1]>=103)
                    {
                        tabxy[17][1]=tabxy[17][1]-1;
                    }
                    if (tabcom[8]==0||tabcom[8]==5)
                    {
                        for(ligne=0;ligne<11;ligne++)
                        {
                            gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                            color(12,0);
                            printf("%s",boss1[ligne]);
                            color(5,0);
                        }
                    }
                    else if (tabcom[8]==1||tabcom[8]==6)
                    {
                        for(ligne=0;ligne<10;ligne++)
                        {
                            gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                            color(12,0);
                            printf("%s",boss2[ligne]);
                            color(5,0);
                        }
                    }
                    else if (tabcom[8]==2||tabcom[8]==7)
                    {
                        for(ligne=0;ligne<9;ligne++)
                        {
                            gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                            color(12,0);
                            printf("%s",boss3[ligne]);
                            color(5,0);
                        }
                    }
                    else if (tabcom[8]==3||tabcom[8]==8)
                    {
                        for(ligne=0;ligne<9;ligne++)
                        {
                            gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                            color(12,0);
                            printf("%s",boss4[ligne]);
                            color(5,0);
                        }
                    }
                    else if (tabcom[8]==4||tabcom[8]==9)
                    {
                        for(ligne=0;ligne<11;ligne++)
                        {
                            gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                            color(12,0);
                            printf("%s",boss5[ligne]);
                            color(5,0);
                        }
                    }
                }
            }
        }
        if (tabxy[17][1]!=0) //apparition Tirs Boss
        {
            if (tabcom[8]==0 || tabcom[8]==5) // Apparition des tirs à des endroits du vaisseau boss 1 aléatoire
            {
                if (tabcom[21]==0)
                {
                    for (i=20;i<=22;i=i+1)
                    {
                        if (i==20)
                        {
                            emplcmnttir=(rand() % (3 - 1 + 1)) + 1;
                        }
                        else if (i==21)
                        {
                            emplcmnttir=(rand() % (5 - 4 + 1)) + 4;
                        }
                        else if (i==22)
                        {
                            emplcmnttir=(rand() % (8 - 6 + 1)) + 6;
                        }
                        switch (emplcmnttir)
                        {
                            case 1:
                                tabxy[i][1]=tabxy[17][1]+6;
                                tabxy[i][2]=tabxy[17][2]+7;
                                break;
                            case 2:
                                tabxy[i][1]=tabxy[17][1]+12;
                                tabxy[i][2]=tabxy[17][2]+8;
                                break;
                            case 3:
                                tabxy[i][1]=tabxy[17][1]+15;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 4:
                                tabxy[i][1]=tabxy[17][1]+18;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 5:
                                tabxy[i][1]=tabxy[17][1]+21;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 6:
                                tabxy[i][1]=tabxy[17][1]+24;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 7:
                                tabxy[i][1]=tabxy[17][1]+28;
                                tabxy[i][2]=tabxy[17][2]+8;
                                break;
                            case 8:
                                tabxy[i][1]=tabxy[17][1]+33;
                                tabxy[i][2]=tabxy[17][2]+7;
                                break;
                        }
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        color(12,0);
                        printf("|");
                        color(5,0);
                    }
                    tabcom[21]=1;
                }
            }
            if (tabcom[8]==1 || tabcom[8]==6) // Apparition des tirs à des endroits du vaisseau boss 2 aléatoire
            {
                if (tabcom[21]==0)
                {
                    for (i=20;i<=22;i=i+1)
                    {
                        if (i==20)
                        {
                            emplcmnttir=(rand() % (3 - 1 + 1)) + 1;
                        }
                        else if (i==21)
                        {
                            emplcmnttir=(rand() % (5 - 4 + 1)) + 4;
                        }
                        else if (i==22)
                        {
                            emplcmnttir=(rand() % (8 - 6 + 1)) + 6;
                        }
                        switch (emplcmnttir)
                        {
                            case 1:
                                tabxy[i][1]=tabxy[17][1]+3;
                                tabxy[i][2]=tabxy[17][2]+7;
                                break;
                            case 2:
                                tabxy[i][1]=tabxy[17][1]+8;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 3:
                                tabxy[i][1]=tabxy[17][1]+12;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 4:
                                tabxy[i][1]=tabxy[17][1]+18;
                                tabxy[i][2]=tabxy[17][2]+10;
                                break;
                            case 5:
                                tabxy[i][1]=tabxy[17][1]+21;
                                tabxy[i][2]=tabxy[17][2]+10;
                                break;
                            case 6:
                                tabxy[i][1]=tabxy[17][1]+27;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 7:
                                tabxy[i][1]=tabxy[17][1]+31;
                                tabxy[i][2]=tabxy[17][2]+8;
                                break;
                            case 8:
                                tabxy[i][1]=tabxy[17][1]+37;
                                tabxy[i][2]=tabxy[17][2]+7;
                                break;
                        }
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        color(12,0);
                        printf("|");
                        color(5,0);
                    }
                    tabcom[21]=1;
                }
            }
            if (tabcom[8]==2 || tabcom[8]==7) // Apparition des tirs à des endroits du vaisseau boss 3 aléatoire
            {
                if (tabcom[21]==0)
                {
                    for (i=20;i<=22;i=i+1)
                    {
                        if (i==20)
                        {
                            emplcmnttir=(rand() % (3 - 1 + 1)) + 1;
                        }
                        else if (i==21)
                        {
                            emplcmnttir=(rand() % (5 - 4 + 1)) + 4;
                        }
                        else if (i==22)
                        {
                            emplcmnttir=(rand() % (8 - 6 + 1)) + 6;
                        }
                        switch (emplcmnttir)
                        {
                            case 1:
                                tabxy[i][1]=tabxy[17][1]+4;
                                tabxy[i][2]=tabxy[17][2]+8;
                                break;
                            case 2:
                                tabxy[i][1]=tabxy[17][1]+11;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 3:
                                tabxy[i][1]=tabxy[17][1]+13;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 4:
                                tabxy[i][1]=tabxy[17][1]+15;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 5:
                                tabxy[i][1]=tabxy[17][1]+17;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 6:
                                tabxy[i][1]=tabxy[17][1]+19;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 7:
                                tabxy[i][1]=tabxy[17][1]+21;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 8:
                                tabxy[i][1]=tabxy[17][1]+31;
                                tabxy[i][2]=tabxy[17][2]+8;
                                break;
                        }
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        color(12,0);
                        printf("|");
                        color(5,0);
                    }
                    tabcom[21]=1;
                }
            }
            if (tabcom[8]==3 || tabcom[8]==8) // Apparition des tirs à des endroits du vaisseau boss 4 aléatoire
            {
                if (tabcom[21]==0)
                {
                    for (i=20;i<=22;i=i+1)
                    {
                        if (i==20)
                        {
                            emplcmnttir=(rand() % (4 - 1 + 1)) + 1;
                        }
                        else if (i==21)
                        {
                            emplcmnttir=(rand() % (6 - 5 + 1)) + 5;
                        }
                        else if (i==22)
                        {
                            emplcmnttir=(rand() % (9 - 7 + 1)) + 7;
                        }
                        switch (emplcmnttir)
                        {
                            case 1:
                                tabxy[i][1]=tabxy[17][1]+1;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 2:
                                tabxy[i][1]=tabxy[17][1]+6;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 3:
                                tabxy[i][1]=tabxy[17][1]+11;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 4:
                                tabxy[i][1]=tabxy[17][1]+16;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 5:
                                tabxy[i][1]=tabxy[17][1]+21;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 6:
                                tabxy[i][1]=tabxy[17][1]+26;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 7:
                                tabxy[i][1]=tabxy[17][1]+31;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 8:
                                tabxy[i][1]=tabxy[17][1]+36;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                            case 9:
                                tabxy[i][1]=tabxy[17][1]+41;
                                tabxy[i][2]=tabxy[17][2]+9;
                                break;
                        }
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        color(12,0);
                        printf("|");
                        color(5,0);
                    }
                    tabcom[21]=1;
                }
            }
            if (tabcom[8]==4 || tabcom[8]==9) // Apparition des tirs à des endroits du vaisseau boss 5 aléatoire
            {
                if (tabcom[21]==0)
                {
                    for (i=20;i<24;i=i+1)
                    {
                        if (i==20)
                        {
                            emplcmnttir=(rand() % (4 - 1 + 1)) + 1;
                        }
                        else if (i==21)
                        {
                            emplcmnttir=(rand() % (8 - 5 + 1)) + 5;
                        }
                        else if (i==22)
                        {
                            emplcmnttir=(rand() % (14 - 9 + 1)) + 9;
                        }
                        else if (i==23)
                        {
                            emplcmnttir=(rand() % (19 - 15 + 1)) + 15;
                        }
                        else if (i==24)
                        {
                            emplcmnttir=(rand() % (25 - 20 + 1)) + 20;
                        }
                        switch (emplcmnttir)
                        {
                            case 1:
                                tabxy[i][1]=tabxy[17][1];
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 2:
                                tabxy[i][1]=tabxy[17][1]+2;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 3:
                                tabxy[i][1]=tabxy[17][1]+4;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 4:
                                tabxy[i][1]=tabxy[17][1]+6;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 5:
                                tabxy[i][1]=tabxy[17][1]+8;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 6:
                                tabxy[i][1]=tabxy[17][1]+14;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 7:
                                tabxy[i][1]=tabxy[17][1]+15;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 8:
                                tabxy[i][1]=tabxy[17][1]+16;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 9:
                                tabxy[i][1]=tabxy[17][1]+17;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 10:
                                tabxy[i][1]=tabxy[17][1]+18;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 11:
                                tabxy[i][1]=tabxy[17][1]+19;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 12:
                                tabxy[i][1]=tabxy[17][1]+20;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 13:
                                tabxy[i][1]=tabxy[17][1]+21;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 14:
                                tabxy[i][1]=tabxy[17][1]+22;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 15:
                                tabxy[i][1]=tabxy[17][1]+23;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 16:
                                tabxy[i][1]=tabxy[17][1]+24;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 17:
                                tabxy[i][1]=tabxy[17][1]+25;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 18:
                                tabxy[i][1]=tabxy[17][1]+26;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 19:
                                tabxy[i][1]=tabxy[17][1]+27;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 20:
                                tabxy[i][1]=tabxy[17][1]+28;
                                tabxy[i][2]=tabxy[17][2]+11;
                                break;
                            case 21:
                                tabxy[i][1]=tabxy[17][1]+33;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 22:
                                tabxy[i][1]=tabxy[17][1]+35;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 23:
                                tabxy[i][1]=tabxy[17][1]+37;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 24:
                                tabxy[i][1]=tabxy[17][1]+39;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                            case 25:
                                tabxy[i][1]=tabxy[17][1]+41;
                                tabxy[i][2]=tabxy[17][2]+6;
                                break;
                        }
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        color(12,0);
                        printf("|");
                        color(5,0);
                    }
                    tabcom[21]=1;
                }
            }
        }
        if (tabcom[21]==1) // déplacement tir
        {
            if (tabcom[8]<5)
            {
                if (tabtime[1]%100==0)
                {
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][2]=tabxy[i][2]+1;
                            color(12,0);
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf("|");
                            color(5,0);
                        }
                    }
                }
            }
            if (tabcom[8]>=5)
            {
                if (tabtime[1]%50==0)
                {
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][2]=tabxy[i][2]+1;
                            mvt=(rand() % (2 - 1 + 1)) + 1;
                            if (mvt==1)
                            {
                                mvt=-1;
                            }
                            if (mvt==2)
                            {
                                mvt=1;
                            }
                            tabxy[i][1]=tabxy[i][1]+mvt;
                            for (u=20;u<=24;u=u+1)
                            {
                                if (u!=i && (tabxy[i][1]!=tabxy[u][1]))
                                {
                                    tabxy[i][1]=tabxy[i][1]-mvt;
                                }
                            }
                            if (tabxy[i][1]<=3)
                            {
                                tabxy[i][1]=tabxy[i][1]+1;
                            }
                            else if (tabxy[i][1]>=147)
                            {
                                tabxy[i][1]=tabxy[i][1]-1;
                            }
                            color(12,0);
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf("|");
                            color(5,0);
                        }
                    }
                }
            }
        }
        if (tabcom[21]==1) //collision tirs-sol
        {
            for (i=20;i<=24;i=i+1)
            {
                if (tabxy[i][1]!=0)
                {
                    if (tabxy[i][2]==50)
                    {
                        gotoxy(tabxy[i][1],tabxy[i][2]);
                        printf(" ");
                        tabxy[i][1]=0;
                        tabcom[23]=tabcom[23]+1;
                    }
                }
            }
        }
        if(chx==1) //colision tir-vaisseau
        {
            if (tabcom[21]==1)
            {
                for (i=20;i<=24;i=i+1) // coordonnée tir
                {
                    for (u=3;u<=3;u=u+1) //espace de contact possible
                    {
                        if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau1[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[6]=tabcom[6]-1;
                            tabcom[9]=tabcom[9]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                    for (u=0;u<=5;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau1[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[6]=tabcom[6]-1;
                            tabcom[9]=tabcom[9]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
            }
        }
        else if (chx==2)
        {
            if (tabcom[21]==1)
            {
                for (i=20;i<=24;i=i+1)
                {
                    for (u=0;u<=5;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau2[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[6]=tabcom[6]-1;
                            tabcom[9]=tabcom[9]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                    for (u=0;u<=5;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau2[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[6]=tabcom[6]-1;
                            tabcom[9]=tabcom[9]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
            }
        }
        else if (chx==3)
        {
            if (tabcom[21]==1)
            {
                for (i=20;i<=24;i=i+1)
                {
                    for (u=5;u<=6;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<4;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau3[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[9]=tabcom[9]-1;
                            tabcom[6]=tabcom[6]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                    for (u=1;u<=10;u=u+1)
                    {
                        if (u==1||u==5||u==6||u==10)
                        {
                            if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[i][1],tabxy[i][2]);
                                printf(" ");
                                for(ligne=0;ligne<4;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau3[ligne]);
                                    color(5,0);
                                }
                                tabcom[24]=tabcom[24]+1;
                                tabcom[9]=tabcom[9]-1;
                                tabcom[6]=tabcom[6]-1;
                                tabxy[i][1]=0;
                                tabcom[23]=tabcom[23]+1;
                            }
                        }
                    }
                    for (u=0;u<=11;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2]+2)&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<4;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau3[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[9]=tabcom[9]-1;
                            tabcom[6]=tabcom[6]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                    for (u=3;u<=8;u=u+1)
                    {
                        if ((tabxy[i][2]==tabxy[1][2]+3)&&(tabxy[i][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            for(ligne=0;ligne<4;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau3[ligne]);
                                color(5,0);
                            }
                            tabcom[24]=tabcom[24]+1;
                            tabcom[9]=tabcom[9]-1;
                            tabcom[6]=tabcom[6]-1;
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
            }
        }
        if (tabcom[8]<4 || (tabcom[8]<9 && tabcom[8]>4 ))
        {
            if (tabcom[23]==3)
            {
                tabcom[21]=0;
                tabcom[23]=0;
            }
        }
        if (tabcom[8]==4 || tabcom[8]==9)
        {
            if (tabcom[23]==5)
            {
                tabcom[21]=0;
                tabcom[23]=0;
            }
        }
        switch (chx) //disparition boss
        {
            case 1:
                if (tabcom[9]>=10)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    score[1]=score[1]+5000*0.5;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    tabcom[8]=tabcom[8]+1;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
            case 2:
                if (tabcom[9]>=20)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    score[1]=score[1]+5000;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    tabcom[8]=tabcom[8]+1;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
            case 3:
                if (tabcom[9]>=30)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    score[1]=score[1]+5000*1.5;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    tabcom[8]=tabcom[8]+1;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
        }
        //Boss disparait car joueur touché 5 fois par le boss
        switch (chx)
        {
            case 1:
                if (tabcom[24]>=5)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    tabcom[6]=tabcom[6]-2;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
            case 2:
                if (tabcom[24]>=5)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    tabcom[6]=tabcom[6]-3;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
            case 3:
                if (tabcom[24]>=5)
                {
                    tabcom[20]=0;
                    tabcom[21]=0;
                    tabcom[22]=0;
                    tabcom[9]=0;
                    tabcom[6]=tabcom[6]-4;
                    for(ligne=0;ligne<11;ligne++)
                    {
                        gotoxy(tabxy[17][1],tabxy[17][2]+ligne);
                        printf("%s",clearboss[ligne]);
                    }
                    tabxy[17][1]=0;
                    for (i=20;i<=24;i=i+1)
                    {
                        if (tabxy[i][1]!=0)
                        {
                            gotoxy(tabxy[i][1],tabxy[i][2]);
                            printf(" ");
                            tabxy[i][1]=0;
                            tabcom[23]=tabcom[23]+1;
                        }
                    }
                }
                break;
        }
    }
}

/****************************************************************
 rôle : Permet d'afficher le score du joueur
 Entrée : choix du vaisseau, du mode, de la couleur du vaisseau et tableau du temps, de compteur et du score
 Sortie : Rien
*****************************************************************/
void AffichageScore(int chx,int mode,int tabtime[9],double score[2],int tabcom[40],int couleur)
{
    int i; //Increment

    color(15,0); //Couleur du texte
    gotoxy(173,25);
    printf("                         ");
    gotoxy(173,25);
    printf("Score: %.0lf",score[1]);
    gotoxy(173,27);
    printf("                         ");
    gotoxy(173,27);
    printf("Bombes: %d",tabcom[5]);
    gotoxy(164,3);
    printf("                                    ");
    gotoxy(172,30);
    printf("                         ");
    gotoxy(172,30);
    printf("Vie: ");
    gotoxy(151,20);
    printf("APPUYER SUR ECHAP POUR METTRE LE JEU EN PAUSE");
    for(i=0;i<(tabcom[6]*2);i=i+2) //Affichage des carrés de vie
    {
        gotoxy(177+i,30);
        printf("[]");
    }
    if (tabcom[22]==1) //Si mode boss alors affiche du nombre de vies du Boss
    {
        gotoxy(164,3);
        printf("Vie du Boss: ");
        switch (chx)
        {
            case 1:
                for(i=0;i<((10-tabcom[9])*2);i=i+2)
                {
                    gotoxy(177+i,3);
                    printf("[]");
                }
                break;
            case 2:
                if (((tabcom[9]/3)%2)!=0)
                {
                    if (((tabcom[9]/3)%2)==1)
                    {
                        tabcom[26]=tabcom[9]-1;
                    }
                }
                for(i=0;i<((10-(tabcom[26]/2))*2);i=i+1)
                {
                    gotoxy(177+i,3);
                    printf("[]");
                }
                break;
            case 3:
                if (((tabcom[9]/3)%3)!=0)
                {
                    if (((tabcom[9]/3)%3)==1)
                    {
                        tabcom[26]=tabcom[9]-1;
                    }
                    else if (((tabcom[9]/3)%3)==2)
                    {
                        tabcom[26]=tabcom[9]-2;
                    }
                }
                for(i=0;i<((10-(tabcom[26]/3))*2);i=i+1)
                {
                    gotoxy(177+i,3);
                    printf("[]");
                }
                break;
        }
    }
    color(5,0);
}

/****************************************************************
 rôle : Cette fonction sert à mettre fin à la partie que l'utilisateur perde ou gagne
 Entrée : choix du mode et tableau de compteur
 Sortie : Rien
*****************************************************************/
void GameOver(int tabcom[40],int mode)
{
    if(mode==1)
    {
        if (tabcom[6]<=0) //Si mode 1 et vies=0 alors fin de partie et partie perdue
        {
            tabcom[25]=1;
            tabcom[29]=0;
        }

    }
    else if (mode==2)
    {
        if (tabcom[6]<=0) //Si mode 2 et vies=0 alors fin de partie et partie perdue
        {
            tabcom[25]=1;
            tabcom[29]=0;
        }
        else  if (tabcom[8]>=10)  //Si le nombre de boss vaincus est supérieur ou égale à 10 alors fin de partie et partie gagné
        {
            tabcom[25]=1;
            tabcom[29]=1;
        }

    }
}

/****************************************************************
 rôle : Gestion des vitamines pour la vie et la bombe
 Entrée : choix du vaisseau et de la couleur du vaisseau et tableau du temps, de compteur et de position
 Sortie : Rien
*****************************************************************/
void vitamine(int chx,int tabtime[9],int tabxy[50][2],int tabcom[40],int couleur)
{
    int u,i,ligne; //Increment et ligne du programme
    char vaisseau1[2][6]={"  |", //Dessin du vaisseau 1
                          "-/-\\-"};
    char vaisseau2[2][8]={"|-/\\-|",//Dessin du vaisseau 2
                          "|-\\/-|"};
    char vaisseau3[4][16]={"     /\\",//Dessin du vaisseau 3
                           " |   ||   |",
                           "/-\\--/\\--/-\\",
                           "   |-/\\-|"};

    tabtime[5]=tabtime[5]+25;
    if (tabtime[5]>=tabtime[3]) //apparition vitamine
    {
        tabtime[3]=0;
        tabtime[5]=0;

        if (tabxy[18][1]==0)
        {
            if (tabcom[22]==0)
            {
                tabxy[18][2]=3;
            }
            else
            {
                tabxy[18][2]=12;
            }
            tabxy[18][1]=tabxy[18][1]= (rand() %  (146 - 3 + 1)) + 3;
            gotoxy(tabxy[18][1],tabxy[18][2]);
            tabcom[27]=(rand() % (2 - 1)) + 1;
            if (tabcom[27]==1)
            {
                printf("V");
            }
            if (tabcom[27]==2)
            {
                printf("P");
            }
            tabcom[2]=1;
        }
    }
    if ((tabtime[1]%175 )==0) //déplacement vitamines
    {
        if (tabxy[18][1]!=0)
        {
            switch (tabcom[27])
            {
                case 1:
                    if (tabcom[2]==1)
                    {
                        gotoxy(tabxy[18][1],tabxy[18][2]);
                        printf(" ");
                        tabxy[18][2]=tabxy[18][2]+1;
                        gotoxy(tabxy[18][1],tabxy[18][2]);
                        printf("V");
                    }
                    break;
                case 2:
                    if (tabcom[2]==1)
                    {
                        gotoxy(tabxy[18][1],tabxy[18][2]);
                        printf(" ");
                        tabxy[18][2]=tabxy[18][2]+1;
                        gotoxy(tabxy[18][1],tabxy[18][2]);
                        printf("P");
                    }
                    break;
            }
        }
    }
    if (tabxy[18][1]!=0) // collision vaisseau
    {
        if(chx==1)
            {
                if (tabcom[2]==1)
                {
                    for (u=3;u<=3;u=u+1) //espace de contact possible
                    {
                            if ((tabxy[18][2]==tabxy[1][2])&&(tabxy[18][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[i][1],tabxy[i][2]);
                                printf(" ");
                                for(ligne=0;ligne<2;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau1[ligne]);
                                    color(5,0);
                                }
                                if (tabcom[27]==1)
                                {
                                    tabcom[6]=tabcom[6]+1;
                                    tabxy[18][1]=0;
                                }
                                else if (tabcom[27]==2)
                                {
                                    tabcom[5]=tabcom[5]+1;
                                    tabxy[18][1]=0;
                                }
                                tabcom[31]=tabcom[31]+1;
                            }
                    }
                    for (u=0;u<=5;u=u+1)
                    {
                        if ((tabxy[18][2]==tabxy[1][2]+1)&&(tabxy[18][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[18][1],tabxy[18][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau1[ligne]);
                                color(5,0);
                            }
                            if (tabcom[27]==1)
                            {
                                tabcom[6]=tabcom[6]+1;
                                tabxy[18][1]=0;
                            }
                            else if (tabcom[27]==2)
                            {
                                tabcom[5]=tabcom[5]+1;
                                tabxy[18][1]=0;
                            }
                            tabcom[31]=tabcom[31]+1;
                        }
                    }
                }
            }
            else if (chx==2)
            {
                if (tabcom[2]==1)
                {
                    for (u=0;u<=5;u=u+1)
                        {
                            if ((tabxy[18][2]==tabxy[1][2])&&(tabxy[18][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[18][1],tabxy[18][2]);
                                printf(" ");
                                for(ligne=0;ligne<2;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau2[ligne]);
                                    color(5,0);
                                }
                                if (tabcom[27]==1)
                                {
                                    tabcom[6]=tabcom[6]+1;
                                    tabxy[18][1]=0;
                                }
                                else if (tabcom[27]==2)
                                {
                                    tabcom[5]=tabcom[5]+1;
                                    tabxy[18][1]=0;
                                }
                                tabcom[31]=tabcom[31]+1;
                            }
                        }
                    for (u=0;u<=5;u=u+1)
                    {
                        if ((tabxy[18][2]==tabxy[1][2]+1)&&(tabxy[18][1]==tabxy[1][1]+u))
                        {
                            gotoxy(tabxy[18][1],tabxy[18][2]);
                            printf(" ");
                            for(ligne=0;ligne<2;ligne++)
                            {
                                gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                color(couleur,0);
                                printf("%s",vaisseau2[ligne]);
                                color(5,0);
                            }
                            if (tabcom[27]==1)
                            {
                                tabcom[6]=tabcom[6]+1;
                                tabxy[18][1]=0;
                            }
                            else if (tabcom[27]==2)
                            {
                                tabcom[5]=tabcom[5]+1;
                                tabxy[18][1]=0;
                            }
                            tabcom[31]=tabcom[31]+1;
                        }
                    }
                }
            }
            else if (chx==3)
            {
                if (tabcom[2]==1)
                {
                    for (i=18;i<=18;i=i+1)
                    {
                        for (u=5;u<=6;u=u+1)
                        {
                            if ((tabxy[i][2]==tabxy[1][2])&&(tabxy[i][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[i][1],tabxy[i][2]);
                                printf(" ");
                                for(ligne=0;ligne<4;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau3[ligne]);
                                    color(5,0);
                                }
                                if (tabcom[27]==1)
                                {
                                    tabcom[6]=tabcom[6]+1;
                                    tabxy[18][1]=0;
                                }
                                else if (tabcom[27]==2)
                                {
                                    tabcom[5]=tabcom[5]+1;
                                    tabxy[18][1]=0;
                                }
                                tabcom[31]=tabcom[31]+1;
                            }
                        }
                        for (u=1;u<=10;u=u+1)
                        {
                            if (u==1||u==5||u==6||u==10)
                            {
                                if ((tabxy[i][2]==tabxy[1][2]+1)&&(tabxy[i][1]==tabxy[1][1]+u))
                                {
                                    gotoxy(tabxy[i][1],tabxy[i][2]);
                                    printf(" ");
                                    for(ligne=0;ligne<4;ligne++)
                                    {
                                        gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                        color(couleur,0);
                                        printf("%s",vaisseau3[ligne]);
                                        color(5,0);
                                    }
                                    if (tabcom[27]==1)
                                    {
                                        tabcom[6]=tabcom[6]+1;
                                        tabxy[18][1]=0;
                                    }
                                    else if (tabcom[27]==2)
                                    {
                                        tabcom[5]=tabcom[5]+1;
                                        tabxy[18][1]=0;
                                    }
                                    tabcom[31]=tabcom[31]+1;
                                }
                            }
                        }
                        for (u=0;u<=11;u=u+1)
                        {
                            if ((tabxy[i][2]==tabxy[1][2]+2)&&(tabxy[i][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[i][1],tabxy[i][2]);
                                printf(" ");
                                for(ligne=0;ligne<4;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau3[ligne]);
                                    color(5,0);
                                }
                                if (tabcom[27]==1)
                                {
                                    tabcom[6]=tabcom[6]+1;
                                    tabxy[18][1]=0;
                                }
                                else if (tabcom[27]==2)
                                {
                                    tabcom[5]=tabcom[5]+1;
                                    tabxy[18][1]=0;
                                }
                                tabcom[31]=tabcom[31]+1;
                            }
                        }
                        for (u=3;u<=8;u=u+1)
                        {
                            if ((tabxy[i][2]==tabxy[1][2]+3)&&(tabxy[i][1]==tabxy[1][1]+u))
                            {
                                gotoxy(tabxy[i][1],tabxy[i][2]);
                                printf(" ");
                                for(ligne=0;ligne<4;ligne++)
                                {
                                    gotoxy(tabxy[1][1],tabxy[1][2]+ligne);
                                    color(couleur,0);
                                    printf("%s",vaisseau3[ligne]);
                                    color(5,0);
                                }
                                if (tabcom[27]==1)
                                {
                                    tabcom[6]=tabcom[6]+1;
                                    tabxy[18][1]=0;
                                }
                                else if (tabcom[27]==2)
                                {
                                    tabcom[5]=tabcom[5]+1;
                                    tabxy[18][1]=0;
                                }
                                tabcom[31]=tabcom[31]+1;
                            }
                        }
                    }
                }
            }
    }
    if (tabcom[2]==1) //collision sol
    {
        if (tabxy[18][1]!=0)
        {
            if (tabxy[18][2]>=50)
            {
                gotoxy(tabxy[18][1],tabxy[18][2]);
                printf(" ");
                tabxy[18][1]=0;
            }
        }
    }
}

/****************************************************************
 rôle : Permet d'afficher le score dans un fichier texte pour avoir les scores des précédentes parties
 Entrée : choix du mode et tableau du score, de compteur et de postion
 Sortie : Rien
*****************************************************************/
void EnregistrementScore (double score[2],int tabcom[40],int mode,int tabxy[50][2])
{
    char pseudo[100]; // Pseudo du joueur
    char chaine[TAILLE_MAX] = ""; //Chaine avec la taille max
    int i=0,x=0,y=0,u=0; // Increment
    int longueurChaine = 0; //Longueur de la chaine

    longueurChaine = strlen(chaine);

    FILE* fichier = NULL;

    tabxy[25][1]=5;
    fichier = fopen("score.txt", "r+"); // Ouverture du ficher en r+ qui signifie qu'on peut lire et écrire dans ce fichier

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            if (u!=3)
            {
                if (chaine=='/')
                {
                    i=i+1;
                }
                else
                {
                    if (tabxy[25][2]>=47)
                    {
                        x=x+16;
                        u=u+1;
                        tabxy[25][1]=5+x;
                        i=0;
                        y=0;
                        tabxy[25][2]=5+(i*10)+y;
                    }
                    gotoxy(tabxy[25][1],tabxy[25][2]);
                    printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
                    y=y+1;
                    tabxy[25][2]=5+(i*10)+y;
                }
            }
        }
        gotoxy(49,25);
        printf("ENTREZ VOTRE PSEUDO(8 lettres maximum): ");
        scanf("%s",&pseudo);
        longueurChaine = strlen(pseudo);
        while (longueurChaine>8) //Saisie validée du pseudo
        {
            printf("\nVEUILLEZ ENTRER UN PSEUDO VALIDE(8 lettres maximum): ");
            scanf("%s",&pseudo);
            longueurChaine = strlen(pseudo);
        }
        fprintf(fichier,"\nPseudo: %s",pseudo); //Affiche le pseudo
        fprintf(fichier,"\nScore: %.0lf",score[1]); //Affiche le score
        fprintf(fichier,"\nVitamines obtenues: %d",tabcom[31]); //Affiche le nombre de vitamines obtenues
        fprintf(fichier,"\nEnnemies vaincus: %d",tabcom[30]); //Affiche le nombre d'ennemis vaincus
        if (mode==2)
        {
            fprintf(fichier,"\nBoss vaincus: %d",tabcom[8]); //Si mode Boos alors affiche aussi le nombre de boss vaincus
        }
        fprintf(fichier,"\n/");
        gotoxy(49,20);
        printf("VOUS AVEZ GAGNER !!!");
        if (tabcom[29]==1)
        {
            gotoxy(49,20);
            printf("FELICITATIONS !!! VOUS AVEZ GAGNER !!!");
        }
        else
        {
            gotoxy(49,20);
            printf("VOUS AVEZ PERDU !!!");
        }

    }
    else
    {
        fichier = fopen("score.txt", "a");
        gotoxy(40,25);
        printf("AUCUN SCORE PRECEDENT");
        gotoxy(89,47);
        printf("ENTREZ VOTRE PSEUDO(8 lettres maximum): ");
        scanf("%s",&pseudo);
        longueurChaine = strlen(pseudo);
        while (longueurChaine>8)
        {
            printf("\nVEUILLEZ ENTRER UN PSEUDO VALIDE(8 lettres maximum): ");
            scanf("%s",&pseudo);
            longueurChaine = strlen(pseudo);
        }
        fprintf(fichier,"\nPseudo: %s",pseudo);
        fprintf(fichier,"\nScore: %.0lf",score[1]);
        fprintf(fichier,"\nVitamines obtenues: %d",tabcom[31]);
        fprintf(fichier,"\nEnnemies vaincus: %d",tabcom[30]);
        if (mode==2)
        {
            fprintf(fichier,"\nBoss vaincus: %d",tabcom[8]);
        }
        fprintf(fichier,"\n/");
        if (tabcom[29]==1)
        {
            gotoxy(40,20);
            printf("FELICITATIONS !!! VOUS AVEZ GAGNER !!!");
        }
        else
        {
            gotoxy(40,20);
            printf("VOUS AVEZ PERDU !!!");
        }
    }
    fclose(fichier);
}

/****************************************************************
 rôle : Affichage des règles du jeu
 Entrée : Rien
 Sortie : Rien
*****************************************************************/
void afficherRegle(void)
{
    char imgregle[6][94]={"______  _____  _____  _      _____  _____    ______  _   _       ___  _____  _   _ ",
                          "| ___ \\|  ___||  __ \\| |    |  ___|/  ___|   |  _  \\| | | |     |_  ||  ___|| | | |",
                          "| |_/ /| |__  | |  \\/| |    | |__  \\ `--.    | | | || | | |       | || |__  | | | |",
                          "|    / |  __| | | __ | |    |  __|  `--. \\   | | | || | | |       | ||  __| | | | |",
                          "| |\\ \\ | |___ | |_\\ \\| |____| |___ /\\__/ /   | |/ / | |_| |   /\\__/ /| |___ | |_| |",
                          "\\_| \\_|\\____/  \\____/\\_____/\\____/ \\____/    |___/   \\___/    \\____/ \\____/  \\___/"};
    int ligne; //Ligne du programme

    system("CLS");
    for(ligne=0;ligne<6;ligne++) //Affichage de l'image
    {
        gotoxy(56,5+ligne);
        printf("%s",imgregle[ligne]);
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n-POUR SE DEPLACER, UTILISEZ LES TOUCHES : z,q,s,d" //Affichage des règles du jeu
           "\n--POUR TIRER,IL FAUT UTILISER LA TOUCHE : espace"
           "\n--POUR UTILISER VOTRE BONUS ''BOMBE'' 'P', UTILISEZ LA TOUCHE : f"
           "\n-DES VITAMINES POURRONT APPARAITRE SOUS DEUX FORMES: 'P':BOMBE ET 'V':VIE"
           "\n--LA VITAMINE BOMBE VOUS PERMETTRA DE FAIRE DISPARAITRE TOUS LES ENNEMIS A L'ECRAN (SAUF BOSS)"
           "\n--LA VITAMINE VIE VOUS RENDRA UNE VIE"
           "\n-LES ENNEMIES SONT SYMBOLISE PAR: |-o-|"
           "\n--UN ENNEMIE VAUT 500 POINTS"
           "\n-UN MODE BOSS, UN BOSS APPARAITRA PERIODIQUEMENT AU COUR DE VOTRE PARTIE"
           "\n--TUER UN BOSS VOUS RAPPORTERA 5000 POINTS"
           "\n--SI VOUS VOUS FAITES TOUCHER 5 FOIS PAR UN BOSS VOUS PERDREZ DES POINTS VIE (QUANTITE DETERMINEE PAR LA DIFFICULTE CHOISIE)"
           "\n--SI UN BOSS VOUS TOUCHE IL RECUPERE UN POINT DE VIE"
           "\n--CHAQUE BOSS REAPPARAITRA EN ETANT PLUS FORT");
    printf("\n\nAPPUYER SUR UNE TOUCHE POUR CONTINUER");
    getchar();
}
