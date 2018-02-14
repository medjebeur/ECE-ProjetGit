#define taillec 20
#define taillelj 5
#define taillecj 5
#define ROW_SIZE 20
#define COL_SIZE 20
#define EMPTY_CELL '.'
#include<stdio.h>
#include <windows.h>
#include <conio.h>

// LES ENNUIS COMMENCENT LIGNE 598
#define COLPIECE_SIZE 5
#define ROWPIECE_SIZE 5
#define COLPIECES_SIZE 20
#define ROWPIECES_SIZE 12

char myBoard[20][20];
char myPiece[5][5];
char myPieces[12][20];
char PieceToShowTmp[5][5];
char myPieceTmp[5][5];


char allPieces[21][5][5] =
{
    {   {'A','.','.', '.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'}
    },
    {   {'B','B','.', '.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'}
    },
    {   {'C','C', 'C', '.','.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'}
    },
    {   {'D','D', '.', '.', '.'},
        {'D', '.', '.', '.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'}
    },

    {   {'E','E', 'E', 'E','.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'},
        {'.', '.', '.','.', '.'}
    },


    {   {'F','.', '.', '.','.'},
        {'F', '.', '.', '.','.'},
        {'F', '.', '.', '.','.'},
        {'F',  '.', '.', '.','.'},
        {'F',  '.', '.', '.','.'}
    },
    {   {'G', '.', '.', '.','.'},
        {'G',  '.', '.', '.','.'},
        {'G', 'G', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'H', '.', '.', '.','.'},
        {'H', 'H', '.', '.','.'},
        {'H', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'I','I', '.', '.','.'},
        {' I', 'I', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'J','J', '.', '.','.'},
        {'.', 'J', 'J', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },

    {   {'K','.', '.', '.','.'},
        {'K', 'K', 'K', '.','.'},
        {'.', 'K', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'L','L', 'L', 'L','.'},
        {'.', '.', '.', 'L','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'.','M', '.', '.','.'},
        {'.', 'M', '.', '.','.'},
        {'M', 'M', '.', '.','.'},
        {'M', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'},
    },
    {   {'.','N', '.', '.','.'},
        {'N', 'N', '.', '.','.'},
        {'N', 'N', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'O','O', '.', '.','-'},
        {'.', 'O', '.', '.','-'},
        {'O', 'O', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'P','.', '.', '.','-'},
        {'P', 'P', 'P', '.','-'},
        {'.', '.', 'P', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'Q','.', '.', '.','-'},
        {'Q', 'Q', '.', '.','-'},
        {'Q', '.', '.', '.','-'},
        {'Q', '.', '.', '.','.'},
        {'.','.', '.', '.','.'}
    },
    {   {'.','R', '.', '.','-'},
        {'.', 'R', '.', '.','-'},
        {'R', 'R', 'R', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.','.','.'}
    },
    {   {'S','.', '.', '.','-'},
        {'S', '.', '.', '.','-'},
        {'S', 'S', 'S', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'T','T', '.', '.','-'},
        {'.', 'T', 'T', '.','-'},
        {'.', '.', 'T', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    },
    {   {'.','U', '.', '.','-'},
        {'U', 'U', 'U', '.','-'},
        {'.', 'U', '.', '.','.'},
        {'.', '.', '.', '.','.'},
        {'.', '.', '.', '.','.'}
    }
};




void gotoligcol( int i, int j )//fonctiongotligcol
{
    COORD mycoord;
    mycoord.X = myBoard[i];
    mycoord.Y = myBoard[j];
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void debutjeu()// entree dans le jeu
{
    int nbj;
    int temps=0;
    int temps1=0;
    printf("Jeu du Blokus\n Combien de joueurs ?\n");
    scanf("%d",&nbj);
    if(nbj<2||nbj>4)
    {
        printf("Seulement deux à quatre joueurs");
        printf("Voici le mode deux joueurs");

    }
    else

        printf("Vous avez choisi le mode %d joueurs",nbj);



    for(temps=0; temps<10000; temps++)
        for(temps1=0; temps1<10000; temps1++) {}

    system("cls");

}

void showCell(char cellToShow)
{

    printf("%c",cellToShow);
    printf("%c",' ');
    printf("%c",' ');
}

void showHeadCell(char* cellToShow)
{

    printf("%.*s", 2, cellToShow);
}

void  fullMyBoard()
{
    extern char myBoard[20][20];

    int i;
    int j;
    int k;
    int l;
    int m;


    for(i = 0; i < ROW_SIZE; i++)
    {
        for(j = 0; j < COL_SIZE; j++)
        {
            myBoard[i][j]=EMPTY_CELL;

        }
    }
    printf("%d\n",i);

}



int choixPiece()//modif
{

    int IDPiece;

    printf("Veuillez choisir une pièce");
    scanf("%d",&IDPiece);
    printf("Il s'agit de %d ",IDPiece);
    return IDPiece;
}
void showPiece(int IDPiece)//ajout
{

    int i;
    int j;
    extern char allPieces[21][5][5];
    // choixPiece();
    printf("Vous avez choisi la pièce %d",IDPiece);
    printf("\n");
    printf("-------------------------------");
    printf("\n");

    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            printf("%c",  allPieces[IDPiece][i][j]);

        }
        printf("\n");
    }
    printf("\n");
    printf("-------------------------------");
    printf("\n");

}
void showmyboard()
{
    extern char myBoard[20][20];

    int i;
    int j;

    /*for(j = 0; j < COLPIECES_SIZE; j++)
       {
       showHeadCell("?????");
       }
       */
    printf("0 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 ");
    printf("\n");
    for(i = 0; i < ROW_SIZE; i++)
    {

        for(j = 0; j <COL_SIZE; j++)
        {

            showCell(myBoard[i][j]);
        }

        if(myBoard[i][j]!=' ')
        {
            Color(4, 0);
            printf("%d\n",i);
        }
        else
        {
            Color(15, 0);
            printf("%d\n",i);
        }
    }
}
void  fullMyPiece()
{
    extern char myPiece[5][5];
    int i;
    int j;
    for(i = 0; i < ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            myPiece[i][j]=EMPTY_CELL;
        }
    }
}
void showmypiece()
{
    extern char myPiece[5][5];
    int i;
    int j;
    for(i = 0; i < ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            showCell(myPiece[i][j]);
        }

        printf("\n");
    }
}
void  fullMyPieces()
{

    extern char allPieces[21][5][5];
    extern char myPieces[12][20];
    int i;
    int j;
    int k;
    int l;
    int m;


    for(i = 0; i < ROWPIECES_SIZE; i++)
    {
        for(j = 0; j < COLPIECES_SIZE; j++)
        {
            myPieces[i][j]=EMPTY_CELL;

        }
    }
    myPieces[0][0] = allPieces[0][0][0];
    myPieces[0][2] = allPieces[1][0][0];
    myPieces[0][3] = allPieces[1][0][1];
    myPieces[0][5] = allPieces[2][0][0];
    myPieces[0][6] = allPieces[2][0][1];
    myPieces[0][7] = allPieces[2][0][2];
    myPieces[0][9] = allPieces[3][0][1];
    myPieces[0][10] = allPieces[3][0][0];
    myPieces[1][9] = allPieces[3][1][0];
    myPieces[0][12] = allPieces[4][0][0];
    myPieces[0][13] = allPieces[4][0][0];
    myPieces[0][14] = allPieces[4][0][0];
    myPieces[0][15] = allPieces[4][0][0];
    myPieces[0][18] = allPieces[5][0][0];
    myPieces[1][18] = allPieces[5][0][0];
    myPieces[2][18] = allPieces[5][0][0];
    myPieces[3][18] = allPieces[5][0][0];
    myPieces[4][18] = allPieces[5][0][0];
    myPieces[2][0] = allPieces[6][0][0];
    myPieces[3][0] = allPieces[6][0][0];
    myPieces[4][0] = allPieces[6][0][0];
    myPieces[4][1] = allPieces[6][0][0];
    myPieces[2][3] = allPieces[7][0][0];
    myPieces[4][3] = allPieces[7][0][0];
    myPieces[3][3] = allPieces[7][0][0];
    myPieces[3][4] = allPieces[7][0][0];
    myPieces[2][6] = allPieces[8][0][0];
    myPieces[3][7] = allPieces[8][0][0];
    myPieces[3][6] = allPieces[8][0][0];
    myPieces[2][7] = allPieces[8][0][0];
    myPieces[3][10] = allPieces[9][0][0];
    myPieces[3][11] = allPieces[9][0][0];
    myPieces[4][11] = allPieces[9][0][0];
    myPieces[4][12] = allPieces[9][0][0];
    myPieces[2][14] = allPieces[10][0][0];
    myPieces[3][14] = allPieces[10][0][0];
    myPieces[3][15] = allPieces[10][0][0];
    myPieces[3][16] = allPieces[10][0][0];
    myPieces[4][15] = allPieces[10][0][0];
    myPieces[6][0] = allPieces[11][0][0];
    myPieces[6][1] = allPieces[11][0][0];
    myPieces[6][2] = allPieces[11][0][0];
    myPieces[6][3] = allPieces[11][0][0];
    myPieces[7][3] = allPieces[11][0][0];
    myPieces[7][5] = allPieces[12][0][1];
    myPieces[7][6] = allPieces[12][0][1];
    myPieces[6][6] = allPieces[12][0][1];
    myPieces[8][5] = allPieces[12][0][1];
    myPieces[5][6] = allPieces[12][0][1];
    myPieces[6][8] = allPieces[13][0][1];
    myPieces[7][8] = allPieces[13][0][1];
    myPieces[7][9] = allPieces[13][0][1];
    myPieces[6][9] = allPieces[13][0][1];
    myPieces[5][9] = allPieces[13][0][1];
    myPieces[6][13] = allPieces[14][0][0];
    myPieces[6][14] = allPieces[14][0][0];
    myPieces[7][14] = allPieces[14][0][0];
    myPieces[8][13] = allPieces[14][0][0];
    myPieces[8][14] = allPieces[14][0][0];
    myPieces[6][16] = allPieces[15][0][0];
    myPieces[7][16] = allPieces[15][0][0];
    myPieces[7][17] = allPieces[15][0][0];
    myPieces[7][18] = allPieces[15][0][0];
    myPieces[8][18] = allPieces[15][0][0];
    myPieces[8][0] = allPieces[16][0][0];
    myPieces[9][0] = allPieces[16][0][0];
    myPieces[9][1] = allPieces[16][0][0];
    myPieces[10][0] = allPieces[16][0][0];
    myPieces[11][0] = allPieces[16][0][0];
    myPieces[9][3] = allPieces[17][0][1];
    myPieces[10][3] = allPieces[17][0][1];
    myPieces[11][2] = allPieces[17][0][1];
    myPieces[11][3] = allPieces[17][0][1];
    myPieces[11][4] = allPieces[17][0][1];
    myPieces[9][7] = allPieces[18][0][0];
    myPieces[10][7] = allPieces[18][0][0];
    myPieces[11][7] = allPieces[18][0][0];
    myPieces[11][8] = allPieces[18][0][0];
    myPieces[11][9] = allPieces[18][0][0];
    myPieces[9][10] = allPieces[19][0][0];
    myPieces[9][11] = allPieces[19][0][0];
    myPieces[10][11] = allPieces[19][0][0];
    myPieces[10][12] = allPieces[19][0][0];
    myPieces[11][12] = allPieces[19][0][0];
    myPieces[10][14] = allPieces[20][0][1];
    myPieces[10][15] = allPieces[20][0][1];
    myPieces[9][15] = allPieces[20][0][1];
    myPieces[11][15] = allPieces[20][0][1];
    myPieces[10][16] = allPieces[20][0][1];



    printf("\n\n\n\n");



}
void showmypieces()
{
    extern char myPieces[12][20];
    int i;
    int j;

    /*for(j = 0; j < COLPIECES_SIZE; j++)
       {
       showHeadCell("?????");
       }
       */
    printf("0 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 ");
    printf("\n");
    for(i = 0; i < ROWPIECES_SIZE; i++)
    {

        for(j = 0; j < COLPIECES_SIZE; j++)
        {

            showCell(myPieces[i][j]);
        }

        if(myPieces[i][j]!=' ')
        {
            Color(4, 0);
            printf("%d\n",i);
        }
        else
        {
            Color(15, 0);
            printf("%d\n",i);
        }
    }
}
void PutThisPieceInMyPieces(int IDPiece,int paramx, int paramy)
{


    extern char myBoard[20][20];
    extern char allPieces[21][5][5];

    printf("\n");
    printf("Vous avez selectionne la pièce %d",IDPiece);
    printf("\n");
    printf("------------debug-----------------");
    printf("\n");
    int i;
    int j;
    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            printf("%c",  allPieces[IDPiece][i][j]);

        }
        printf("\n");
    }
    printf("-------------fin-----------5-------");
    printf("\n");
    showCell(allPieces[1][0][0]);
    printf("\n");
    printf("-------------fin------------------");
    printf("\n");



    // myPieces[paramx][paramy]=

    int x =0;
    int y=0;
    // moveElement(paramx,paramy,IDPiece,x,y);
    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            myBoard[paramx+i][paramy+j] = allPieces[IDPiece][x+i][y+j];

        }
    }

    /*
    myPieces[paramx][paramy+1] = allPieces[IDPiece][x][y+1];
    myPieces[paramx][paramy+2] = allPieces[IDPiece][x][y+2];
    myPieces[paramx][paramy+3] = allPieces[IDPiece][x][y+3];
    myPieces[paramx][paramy+4] = allPieces[IDPiece][x][y+4];
    myPieces[paramx+1][paramy] = allPieces[IDPiece][x+1][y];
    myPieces[paramx+1][paramy+1] = allPieces[IDPiece][x+1][y+1];
    myPieces[paramx+1][paramy+2] = allPieces[IDPiece][x+1][y+2];
    myPieces[paramx+1][paramy+3] = allPieces[IDPiece][x+1][y+3];
    myPieces[paramx+1][paramy+4] = allPieces[IDPiece][x+1][y+4];

    myPieces[paramx+2][paramy+1] = allPieces[IDPiece][x+2][y+1];
    myPieces[paramx+1][paramy+2] = allPieces[IDPiece][x+1][y+2];
    myPieces[paramx+1][paramy+3] = allPieces[IDPiece][x+1][y+3];
    myPieces[paramx+1][paramy+4] = allPieces[IDPiece][x+1][y+4];
    myPieces[paramx+2][paramy] = allPieces[IDPiece][x+2][y];
    myPieces[paramx+2][paramy+1] = allPieces[IDPiece][x+2][y+1];
    myPieces[paramx+2][paramy+2] = allPieces[IDPiece][x+2][y+2];
    myPieces[paramx+2][paramy+3] = allPieces[IDPiece][x+3][y+3];
    myPieces[paramx+2][paramy+4] = allPieces[IDPiece][x+4][y+4];
    myPieces[paramx+3][paramy] = allPieces[IDPiece][x+3][y];
    myPieces[paramx+3][paramy+1] = allPieces[IDPiece][x+3][y+1];
    myPieces[paramx+3][paramy+2] = allPieces[IDPiece][x+3][y+2];
    myPieces[paramx+3][paramy+3] = allPieces[IDPiece][x+3][y+3];
    myPieces[paramx+3][paramy+4] = allPieces[IDPiece][x+3][y+4];
    myPieces[paramx+4][paramy] = allPieces[IDPiece][x+4][y];
    myPieces[paramx+4][paramy+1] = allPieces[IDPiece][x+4][y+1];
    myPieces[paramx+4][paramy+2] = allPieces[IDPiece][x+4][y+2];
    myPieces[paramx+4][paramy+3] = allPieces[IDPiece][x+4][y+3];
    myPieces[paramx+4][paramy+4] = allPieces[IDPiece][x+4][y+4];

    */
    printf("%c",&myBoard);
}


// //char Piece[x][y];
//  MyPieces[0]



void moveElement(int paramx,int paramy,int IDPiece,int x,int y)
{

    extern char myPieces[12][20];
    extern char allPieces[21][5][5];
    char tmpChar;
    tmpChar = allPieces[IDPiece][x][y];
    myPieces[paramx][paramy] = tmpChar;
}
void NotAFreePlace(int x, int y)
{

    extern char myBoard[20][20];
    if(myBoard[x][y]!='.')
    {
        int i=1;
        printf("Saisie impossible , la place est déjà occupée");
        printf("Saisissez x puis y");

        while(i=1)

            scanf("%d",&x);


        scanf("%d",&y);
        if(myBoard[x][y]=='.')
            i++;
    }
}

void PieceToShow(int IDPiece)
{
    int j;
    int i;
    extern char allPieces[21][5][5];
    extern char PieceToShowTmp[5][5];
    // moveElement(paramx,paramy,IDPiece,x,y);


    /*   for(j = 0; j < COLPIECE_SIZE; j++)
       {

           PieceToShowTmp[0][j] = myPiece[0][ 4-j];

       }


       for(j = 0; j < COLPIECE_SIZE; j++)
       {
           PieceToShowTmp[1][ +j] = myPiece[4-j][1];

       }

       for(j = 0; j < COLPIECE_SIZE; j++)
       {
           PieceToShowTmp[2][ +j] = myPiece[ 4-j][2];

       }

       for(j = 0; j < COLPIECE_SIZE; j++)
       {
           PieceToShowTmp[3][ +j] = myPiece[4-j][3];

       }

       for(j = 0; j < COLPIECE_SIZE; j++)
       {
           PieceToShowTmp[4][ +j] = myPiece[4-j][4];

       }*/

    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            PieceToShowTmp[i][j] = allPieces[IDPiece][i][j];//formule de rotation
//affichage du tableau temporaire
        }
        printf("%c",&allPieces[IDPiece][i][j]);
    }

}




void PutThisPieceInMyGame(int IDPiece)
{


    extern char myPieceTmp[5][5];
    extern char allPieces[21][5][5];

    printf("\n");
    printf("Vous avez selectionne la posissoiu %d",IDPiece);
    printf("\n");
    printf("------------debug-----------------");
    printf("\n");
    int i;
    int j;
    printf("------------debugauj-----------------\n");



for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        { myPieceTmp[4-j][i] = allPieces[IDPiece][i][j];


 printf("%c",myPieceTmp[i][j]);

        }
        printf("\n");
    }
    printf("-------------fin-----------5-------");
    printf("\n");
    showCell(allPieces[1][0][0]);
    printf("\n");
    printf("-------------fin------------------");
    printf("\n");
printf("------------finaujdebug-----------------");


    // myPieces[paramx][paramy]=

    int x =0;
    int y=0;
    // moveElement(paramx,paramy,IDPiece,x,y);
    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            myPieceTmp[i][j] = allPieces[IDPiece][i][j];

        }
    }
 printf("ggj");
      printf("%c",allPieces);
    printf("chj");
    /*
    myPieces[paramx][paramy+1] = allPieces[IDPiece][x][y+1];
    myPieces[paramx][paramy+2] = allPieces[IDPiece][x][y+2];
    myPieces[paramx][paramy+3] = allPieces[IDPiece][x][y+3];
    myPieces[paramx][paramy+4] = allPieces[IDPiece][x][y+4];
    myPieces[paramx+1][paramy] = allPieces[IDPiece][x+1][y];
    myPieces[paramx+1][paramy+1] = allPieces[IDPiece][x+1][y+1];
    myPieces[paramx+1][paramy+2] = allPieces[IDPiece][x+1][y+2];
    myPieces[paramx+1][paramy+3] = allPieces[IDPiece][x+1][y+3];
    myPieces[paramx+1][paramy+4] = allPieces[IDPiece][x+1][y+4];

    myPieces[paramx+2][paramy+1] = allPieces[IDPiece][x+2][y+1];
    myPieces[paramx+1][paramy+2] = allPieces[IDPiece][x+1][y+2];
    myPieces[paramx+1][paramy+3] = allPieces[IDPiece][x+1][y+3];
    myPieces[paramx+1][paramy+4] = allPieces[IDPiece][x+1][y+4];
    myPieces[paramx+2][paramy] = allPieces[IDPiece][x+2][y];
    myPieces[paramx+2][paramy+1] = allPieces[IDPiece][x+2][y+1];
    myPieces[paramx+2][paramy+2] = allPieces[IDPiece][x+2][y+2];
    myPieces[paramx+2][paramy+3] = allPieces[IDPiece][x+3][y+3];
    myPieces[paramx+2][paramy+4] = allPieces[IDPiece][x+4][y+4];
    myPieces[paramx+3][paramy] = allPieces[IDPiece][x+3][y];
    myPieces[paramx+3][paramy+1] = allPieces[IDPiece][x+3][y+1];
    myPieces[paramx+3][paramy+2] = allPieces[IDPiece][x+3][y+2];
    myPieces[paramx+3][paramy+3] = allPieces[IDPiece][x+3][y+3];
    myPieces[paramx+3][paramy+4] = allPieces[IDPiece][x+3][y+4];
    myPieces[paramx+4][paramy] = allPieces[IDPiece][x+4][y];
    myPieces[paramx+4][paramy+1] = allPieces[IDPiece][x+4][y+1];
    myPieces[paramx+4][paramy+2] = allPieces[IDPiece][x+4][y+2];
    myPieces[paramx+4][paramy+3] = allPieces[IDPiece][x+4][y+3];
    myPieces[paramx+4][paramy+4] = allPieces[IDPiece][x+4][y+4];

    */

}
void PutThisPieceOnTheGame(int IDPiece)//mettre la pièce après rotation dans le tableau myPiece
{

    extern char PieceToShowTmp[5][5];
    extern char myBoard[20][20];
    extern char allPieces[21][5][5];
    extern char myPiece[5][5];

    printf("\n");
    printf("Vous avez selectionne la pièce %d",IDPiece);
    printf("\n");
    printf("------------debuglk-----------------");
    printf("\n");
    int i;

    int j;

    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
            printf("%c",  PieceToShowTmp[i][j]);

        }
        printf("\n");
    }
    printf("-------------fin------------------");
    printf("\n");
    showCell(allPieces[1][0][0]);
    printf("\n");
    printf("-------------fin------------------");
    printf("\n");



    // myPieces[paramx][paramy]=

    int x =0;
    int y=0;
    // moveElement(paramx,paramy,IDPiece,x,y);
    for(i = 0; i< ROWPIECE_SIZE; i++)
    {
        for(j = 0; j < COLPIECE_SIZE; j++)
        {
             PieceToShowTmp[i][j]=allPieces[IDPiece][i][j];//affectations des valeurs
            printf("%c",PieceToShowTmp[i][j]);
            printf("test");
        }
    }



}
void ChoosePieceDirection(int IDPiece)
{
    char key;
    while(1)
    {
        if (kbhit())
        {
            key=getch();
            switch(key)
            {
            case'g' :
                printf("RGiss");
                PutThisPieceInMyGame(IDPiece);

                break;
            case'd' :
                printf("rd");
                PutThisPieceOnTheGame(IDPiece);
                PutThisPieceOnTheGame(IDPiece);
                PutThisPieceOnTheGame(IDPiece);
                break;
            case'i' :
                printf("inversion");
                PutThisPieceOnTheGame(IDPiece);
                PutThisPieceOnTheGame(IDPiece);
                break;

            }
        }
    }
}
int main()
{

    char direction;
// int id =donnemoiunInt();

    fullMyBoard();
    showmyboard();

    fullMyPiece();
    showmypiece();
    // debutjeu();
//    fullMyPieces();


    showmypieces();

    //
    int IDPiece =1;
    while(IDPiece != 100)
    {
        printf("\n");
        printf("##########  DEBUT DU TOUR  ##############");
        printf("\n");
        IDPiece=choixPiece();
        printf("%c",IDPiece);
        printf("\n");


        showPiece(IDPiece);

        int x;
        printf("Veuillez choisir x");
        scanf("%d",&x);
        if(x>12)
        {
            printf("Erreur ,veuillez saisir de nouveau");

        }
        printf("\n");
        int y;
        printf("Veuillez choisir y");
        scanf("%d",&y);
        NotAFreePlace(x, y);
        if(y>21)
        {
            printf("Erreur ,veuillez saisir de nouveau");
        }
        printf("\n");


       // PutThisPieceInMyPieces( IDPiece, x,  y);
        //PieceToShow(IDPiece);

        showmypiece();
        printf("bug");
        PieceToShow(IDPiece);
        printf("grosbug");
        fflush(stdin);
        PutThisPieceInMyGame(IDPiece);
        printf("bugiobite");


        /*        if ( çaEntre(IDPiece,x,y)){

                       PutThisPieceInMyPieces(IDPiece,x,y);

                }else{
                    tu dis que ça passe pas et tu demande une saisie en +

                }*/




        printf("\n");
        printf("-----------------------------");
        printf("\n");


        showmyboard();
        printf("\n");
        printf("-----------------------------");
        printf("\n");

        showPiece(IDPiece);

        printf("Veuillez saisir la direction de votre pièce");

ChoosePieceDirection(IDPiece);
//PutThisPieceOnTheGame(IDPiece);



        printf("##########  FIN DU TOUR  ##############");
        printf("\n");
    }


    //showCell(EMPTY_CELL);
}

//



