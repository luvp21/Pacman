#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define xsize 58
#define ysize 31
#define qKey  0x51
#define yKey  0x59
#define nKey  0x4E

int score = 0;
typedef struct
{
    int x;
    int y;
}PIX;

PIX player;
PIX ghost1;
PIX ghost2;
PIX ghost3;
PIX ghost4;

char grid[ysize][xsize]= {
"[][][][][][][][][][][][][][][][][][][][][][][][][][][][]",
"[]oooooooooooooooooooooooo[][]oooooooooooooooooooooooo[]",
"[]oo[][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][]oo[]",
"[]oo[][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][]oo[]",
"[]oo[][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][]oo[]",
"[]oooooooooooooooooooooooooooooooooooooooooooooooooooo[]",
"[]oo[][][][]oo[][]oo[][][][][][][][]oo[][]oo[][][][]oo[]",
"[]oo[][][][]oo[][]oooooooo[][]oooooooo[][]oo[][][][]oo[]",
"[]oooooooooooo[][]oooooooo[][]oooooooo[][]oooooooooooo[]",
"[][][][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][][][]",
"[][][][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][][][]",
"[][][][][][]oo[][]                    [][]oo[][][][][][]",
"[][][][][][]oo[][]          C         [][]oo[][][][][][]",
"[][][][][][]oo[][]    []        []    [][]oo[][][][][][]",
"[]oooooooooooo        [] @ @ @ @[]        oooooooooooo[]",
"[][][][][][]oo[][]    [][][][][][]    [][]oo[][][][][][]",
"[][][][][][]oo[][]                    [][]oo[][][][][][]",
"[][][][][][]oo[][]                    [][]oo[][][][][][]",
"[][][][][][]oo[][]oooo[][][][][][]oooo[][]oo[][][][][][]",
"[][][][][][]oo[][]oooo[][][][][][]oooo[][]oo[][][][][][]",
"[]oooooooooooooooooooooooo[][]oooooooooooooooooooooooo[]",
"[]oo[][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][]oo[]",
"[]oo[][][][]oo[][][][][]oo[][]oo[][][][][]oo[][][][]oo[]",
"[]oooooo[][]oooooooooooooooooooooooooooooooo[][]oooooo[]",
"[][][]oo[][]oo[][]oo[][][][][][][][]oo[][]oo[][]oo[][][]",
"[][][]oo[][]oo[][]oo[][][][][][][][]oo[][]oo[][]oo[][][]",
"[]oooooooooooo[][]oooooooo[][]oooooooo[][]oooooooooooo[]",
"[]oo[][][][][][][][][][]oo[][]oo[][][][][][][][][][]oo[]",
"[]oo[][][][][][][][][][]oo[][]oo[][][][][][][][][][]oo[]",
"[]oooooooooooooooooooooooooooooooooooooooooooooooooooo[]",
"[][][][][][][][][][][][][][][][][][][][][][][][][][][][]",};

void print_grid(){
    printf("\e[32A");
    for(int i=0;i<ysize;i++){
        for(int j=0;j<xsize;j++){
            if(grid[i][j] == 'C'){
                printf("\033[1;33m%c",grid[i][j]);
            }
            else if(grid[i][j] == 'o'){
                printf("\033[1;0m%c",grid[i][j]);

            }
            else if(grid[i][j] == '@'){
                printf("\033[1;31m%c",grid[i][j]);
            }
            else printf("\033[1;34m%c",grid[i][j]);
        }
        printf("\n");
    }
    printf("\033[1;0m");
}

void movement(){

    if (GetAsyncKeyState(VK_UP))
    {
        if(grid[player.y-1][player.x] == ' '){
            player.y--;
            grid[player.y][player.x] = 'C';
            grid[player.y+1][player.x] =' ';
        }
        else if(grid[player.y-1][player.x] == 'o'){
            player.y--;
            grid[player.y][player.x] = 'C';
            grid[player.y+1][player.x] =' ';
            score++;
        }
    }

    else if (GetAsyncKeyState(VK_RIGHT))
    {
        if(grid[player.y][player.x+1] == ' ' ){
            player.x++;
            grid[player.y][player.x] = 'C';
            grid[player.y][player.x-1] =' ';
        }
        else if(grid[player.y][player.x+1] == 'o'){
            player.x++;
            grid[player.y][player.x] = 'C';
            grid[player.y][player.x-1] =' ';
            score++;
        }
    }

    else if (GetAsyncKeyState(VK_DOWN))
    {
        if(grid[player.y+1][player.x] == ' '){
            player.y++;
            grid[player.y][player.x] = 'C';
            grid[player.y-1][player.x] =' ';
        }
        else if(grid[player.y+1][player.x] == 'o' ){
            player.y++;
            grid[player.y][player.x] = 'C';
            grid[player.y-1][player.x] =' ';
            score++;
        }
    }

    else if (GetAsyncKeyState(VK_LEFT))
    {
        if(grid[player.y][player.x-1] == ' ' ){
            player.x--;
            grid[player.y][player.x] = 'C';
            grid[player.y][player.x+1] =' ';
        }
        else if(grid[player.y][player.x-1] == 'o'){
            player.x--;
            grid[player.y][player.x] = 'C';
            grid[player.y][player.x+1] =' ';
            score++;
        }
    }


}

void ghostmovement(int *x,int *y,int *Dir,int frame,char *p){

    if(frame > 20){
        switch (*Dir) {
        case 0:
            if(grid[*y-1][*x] == ' '){
                grid[*y][*x] =*p;
                *p = grid[*y-1][*x];
                *y = *y-1;
                grid[*y][*x] = '@';

            }
            else if(grid[*y-1][*x] == 'o'){

                grid[*y][*x] =*p;
                *p = grid[*y-1][*x];
                *y = *y-1;
                grid[*y][*x] = '@';

            }
            else{
                *Dir = rand() % 4;
            }
            break;

        case 1:
            if(grid[*y][*x+1] == ' ' ){
                grid[*y][*x] =*p;
                *p = grid[*y][*x+1];
                *x = *x+1;
                grid[*y][*x] = '@';
            }
            else if(grid[*y][*x+1] == 'o'){
                grid[*y][*x] =*p;
                *p = grid[*y][*x+1];
                *x = *x + 1;
                grid[*y][*x] = '@';
            }
            else {
                *Dir = rand() % 4;
            }
            break;

        case 2:
            if(grid[*y+1][*x] == ' '){
                grid[*y][*x] =*p;
                *p = grid[*y+1][*x];
                *y = *y+1;
                grid[*y][*x] = '@';
            }
            else if(grid[*y+1][*x] == 'o' ){
                grid[*y][*x] =*p;
                *p = grid[*y+1][*x];
                *y = *y+1;
                grid[*y][*x] = '@';
            }
            else {
                *Dir = rand() % 4;
            }
            break;

        case 3:
            if(grid[*y][*x-1] == ' ' ){
                grid[*y][*x] =*p;
                *p = grid[*y][*x-1];
                *x = *x-1;
                grid[*y][*x] = '@';
            }
            else if(grid[*y][*x-1] == 'o'){
                grid[*y][*x] =*p;
                *p = grid[*y][*x-1];
                *x = *x-1;
                grid[*y][*x] = '@';
            }
            else {
                *Dir = rand() % 4;
            }
            break;

        }
    }

}

int hittest(int x,int y,int frame){
    if((player.x == x && player.y-1 == y) ||
       (player.x == x && player.y+1 == y) ||
       (player.x-1 == x && player.y == y) ||
       (player.x+1 == x && player.y == y) ||
       (player.x-1 == x && player.y-1 == y) ||
       (player.x-1 == x && player.y+1 == y) ||
       (player.x+1 == x &&  player.y-1 == y) ||
       (player.x+1 == x && player.y+1 == y)){
        return 1;
    }
}

int main(){

    system("cls");
    srand(time(NULL));

    printf("WELCOME TO PACMAN! \n");
    printf("Short Guide: '\033[1;33mc\033[1;0m' is PACMAN, 'o' is your objectives, and '\033[1;31m@\033[1;0m' are the ghosts! \n");
    printf("Press any key to proceed...\n");

    system("pause>nul");
    system("cls");

    printf("Use arrow keys for up,left,right and down\nAlso, Press q for quit\n");
    printf("\e[?25l");

    for (int i = 0; i <= 31; i++)
    {
        printf("\n");
    }

    int frame = 0;
    int HT1 = 0,HT2 = 0,HT3 = 0,HT4 = 0;
    char print1 = ' ';
    char print2 = ' ';
    char print3 = ' ';
    char print4 = ' ';

    int Dir1 = 0;
    int Dir2 = 0;
    int Dir3 = 0;
    int Dir4 = 0;

    player.x = 28;
    player.y = 12;

    ghost1.x = 25;
    ghost1.y = 14;
    ghost2.x = 27;
    ghost2.y = 14;
    ghost3.x = 29;
    ghost3.y = 14;
    ghost4.x = 31;
    ghost4.y = 14;


    while(1){

        if (GetAsyncKeyState(qKey))  break;

        printf("score %d\n",score);

        if(score == 548){
            printf(" Congratulations! You Win! \n");
            break;
        };

        movement();
        HT1 = hittest(ghost1.x,ghost1.y,frame);
        HT2 = hittest(ghost2.x,ghost2.y,frame);
        HT3 = hittest(ghost3.x,ghost3.y,frame);
        HT4 = hittest(ghost4.x,ghost4.y,frame);

        if(HT1 == 1 || HT2 == 1 || HT3 == 1 || HT4 == 1){
            char temp;
            print_grid();
            printf("score %d\n",score);
            printf("Game Over\n");
            sleep(10);
            break;
        }

        ghostmovement(&ghost1.x,&ghost1.y,&Dir1,frame,&print1);
        ghostmovement(&ghost2.x,&ghost2.y,&Dir2,frame,&print2);
        ghostmovement(&ghost3.x,&ghost3.y,&Dir3,frame,&print3);
        ghostmovement(&ghost4.x,&ghost4.y,&Dir4,frame,&print4);

        print_grid();

        Sleep(80);
        frame++;
    }

}
