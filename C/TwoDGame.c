#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    // Strings do not exist in C, use 2D char
    char map[20][100];

    map[2][2] = "P";

    bool proceed = true;
    bool argsCheck = false;

    int argsRunIndex = 0;

    char directions[] = {"North", "East", "South", "West"};
    int directionX[]    = {      0,     -1,       0,      1};
    int directionY[]    = {      1,      0,      -1,      0};


    int currentDirection = 0;

    int currentPosition[] = {2,2};
    

    // This is for starting input. Watch video!
    
    
    if(argc > 0){
            argsCheck = true;
        }

	while(proceed){

        
        for(int i=0; i<20; i++){
            for(int j=0; j<100; j++){
                if(map[i][j] == NULL)
                    printf("░");
                   
                else
                    printf(map[i][j]);
                    
            }
            printf("\n");
            
        }


        printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game");          

        char input[1];

        if(!argsCheck){
            scanf("%d", &input);
        }else{
            // The args is to check for args before running
            if(argsRunIndex == argc){
                argsCheck=false;
                *input = "e";
            }else{
                *input = argv[argsRunIndex];
                argsRunIndex++;
            }
        }
    
        switch(*input) {
            case 'w':
                map[currentPosition[1]][currentPosition[0]] = "#";
               
                if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){

                    currentPosition[0] = currentPosition[0] - directionX[currentDirection];
                    currentPosition[1] = currentPosition[1] - directionY[currentDirection];
                  
                }
                map[currentPosition[1]][currentPosition[0]] = "P";
                break;
            case 'a':
                currentDirection--;
                
                if(currentDirection < 0){
                    currentDirection = 3;
                }
                break;
            case 'd':
                currentDirection++;

                if(currentDirection > 3){
                    currentDirection = 0;
                }
                break;
            case 'e':
                printf("You are facing in the "+directions[currentDirection]+"ward direction!");
                break;
            case 'q':
                proceed = false;
                break;
                
            default:
                printf("You must enter one of the commands!");

            }


        }
    return 0;
}
