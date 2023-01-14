#include <stdio.h>
#include<string.h>

#define N 9 


int sodoku[N][N];
char mohamed [N][N+1];





void printSodoku(int sodoku[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d", sodoku[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");


}

int isSafe(int sodoku[N][N], int x, int y, int num){
    for(int i = 0; i < N; i++){
        if(sodoku[x][i] == num){
            return 0;
        }
    }
    for(int i = 0; i < N; i++){
        if(sodoku[i][y] == num){
            return 0;
        }
    }
    int startRow = x - x % 3;
    int startColumn = y - y % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sodoku[i+startRow][j+startColumn] == num)
                return 0;

        }
    }
    return 1;
}





int solveSodoku(int sodoku[N][N], int x, int y){
    if(x == N - 1 && y == N)
        return 1;
    
    if(y == N){
        x++;
        y = 0;
    }
    if (sodoku[x][y] > 0)
        return solveSodoku(sodoku, x, y+1);

        for(int num = 1; num <= N; num++){
            if(isSafe(sodoku, x, y, num)==1){
                sodoku[x][y] = num;            
            
            if(solveSodoku(sodoku, x, y+1) ==1)
                return 1;
            

        }

    sodoku[x][y] = 0;
        }
    return 0;
}   

int main(){

    printf("FUCVKKK\n");    
    FILE *f;
    f = fopen("D:\\jkjjkgnjgn.txt", "r");
    //fscanf(f, "%d", sodoku[N][N]);
    for(int i = 0; i < N; i++){
        fscanf(f, "%s", mohamed[i]);
        printf("%s\n", mohamed[i]);
    }
    
    fclose(f);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            //printf("%c ", mohamed[i][j]);
        //printf("\n");
        printf("");
    }
        

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //mohamed[i][j]-'0';
            sodoku[i][j] = mohamed[i][j] - '0';
        }    
    }
    

    printf("\n\n");
    if(solveSodoku(sodoku, 0, 0)==1){
    	printSodoku(sodoku);
	}
    else printf("No Solution");
    




return 0;

}
