#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DimX 10
#define DimY 10

#define true 1
#define false 0

#define rock 0
#define mud 1
#define border 2

char swamp[DimX + 2][DimY + 2];
typedef struct PathStruct{
    int x;
    int y;
}path[DimX];
void placeRock(int x, int y){
    swamp[x][y]='*';
}

void placeMud (int x, int y){
    swamp[x][y]='.';
}

int pathFinder(){
    int x=0,y;
    int pointFound;
    while (x!=DimX) {

    }

    return 0;
}

int swampGenerator(){
    int x,y,pint,col;
    char pchar;
    int coordOtherRock[2];
    int deltaY;
    int pointCreated;
    srand(time(NULL)+clock());
    for (x=1;x<DimX+1;x++){
        for (y=1;y<DimY+1;y++){
            pointCreated=false;
            while (pointCreated==false){
                pint= rand()%2;
                switch (pint){
                    case rock:
                        //'*'
                        //check if there are other rocks in the column
                        for (col=y-2;col<y;col++){
                            if (swamp[x][col]=='*'){
                                deltaY= y-col;
                                switch (deltaY){
                                    case 1:
                                        if (swamp[x-1][y]!='*' &&
                                                swamp [x-1][col]!='*'){
                                            placeRock(x,y);
                                            pointCreated=true;
                                        }
                                        break;
                                    case 2:
                                        if (swamp[x-1][y-1]!='*'){
                                            placeRock(x,y);
                                            pointCreated=true;
                                        }
                                        break;
                                    default:
                                        printf("ERROR (DELTAY)");
                                        return 1;
                                }
                            }
                        }
                        //verify if you can put a rock
                        //if xprevious == x check if xprevious-1 == rock
                        //put a rock
                        break;
                    case mud:
                        //'.'
                        placeMud(x,y);
                        pointCreated = true
                        break;
                    default:
                        printf("ERROR (RAND)");
                        return 1;
                }
            }
        }
    }
    return 0;
}

int borderGenerator(){
    int x,y;
    for (x=0;x<DimX+2;x++){
        swamp[x][0]= border;
        swamp[x][DimY+1]= border;
    }
    return 0;
}


int main() {
    int pathFound=false;
    int cycle=1;
    //generate borders
    if (borderGenerator()!=0){
        printf("ERROR(BORDER GENERATOR)");
        return 1;
    }
    while (pathFound==false) {
        //generate swamp
        if (swampGenerator()!=0){
            printf("ERROR(SWAMP GENERATOR)");
            return 1;
        }
        //calculate path
        if (pathFinder()!=0){
            printf("Could not find path - cycle %d\n", cycle);
        } else {
            pathFound = true;
        }
        cycle++;
    }
    return 0;
}