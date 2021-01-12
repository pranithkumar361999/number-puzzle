#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>


void displayTitle();
void displayBorder();
void displayTime(); 
void displayBoard();
void collectInput();
void swap(int x,int y);
int correct();
int puzzle[4][4];
int countOfKeyPresses();
int index=0,jindex=1,new_index,new_jindex;
int main(){
int n,i,j;
int key;
int keyPresses=0;

//initializing the values in a puzzle
puzzle[0][0]=2;
puzzle[0][1]=0;
puzzle[0][2]=3;
puzzle[0][3]=4;
puzzle[1][0]=1;
puzzle[1][1]=6;
puzzle[1][2]=7;
puzzle[1][3]=8;
puzzle[2][0]=5;
puzzle[2][1]=9;
puzzle[2][2]=10;
puzzle[2][3]=12;
puzzle[3][0]=13;
puzzle[3][1]=14;
puzzle[3][2]=11;
puzzle[3][3]=15;
	while(1){
			
			displayBorder();
			displayTitle();
			displayBorder();
			displayBoard();
			displayTime();
			printf("Enter the option:");
			printf("\n \t\t\tPress 1 to move up");
			printf("\n \t\t\tPress 2 to move down");
			printf("\n \t\t\tPress 3 to move left");
			printf("\n \t\t\tPress 4 to move right\n");
			scanf("%d",&key);
			keyPresses++;
			switch(key){
				case 8:    //up arrow
					if(index==-1){
						index=0;
						Beep(400,1000);
					}
					else{
					//	swap(puzzle[index][jindex],puzzle[index-1][jindex]);
						int temp;
						temp=puzzle[index][jindex];
						puzzle[index][jindex]=puzzle[index-1][jindex];
						puzzle[index-1][jindex]=temp;
						index = index-1;
					}
					break;
					
					
				case 2:    //down arrow
					if(index==4){
						index=index-1;
						Beep(750,1000);
					}
					else{
					//	swap(puzzle[index][jindex],puzzle[index+1][jindex]);
						int temp;
						temp=puzzle[index][jindex];
						puzzle[index][jindex]=puzzle[index+1][jindex];
						puzzle[index+1][jindex]=temp;
						index=index+1;
					}
					break;
					
					
				case 4:   //left arrow
					if(jindex==-1){
						jindex=0;
						Beep(750,1000);
					}
					else{
					//	swap(puzzle[index][jindex],puzzle[index][jindex-1]);
						int temp;
						temp=puzzle[index][jindex];
						puzzle[index][jindex]=puzzle[index][jindex-1];
						puzzle[index][jindex-1]=temp;
						jindex=jindex-1;
					}
					break;
					
					
				case 6:
					if(jindex==4){
						jindex=jindex-1;
						Beep(750,1000);
					}
					else{
						//swap(puzzle[index][jindex],puzzle[index][jindex+1]);
						int temp;
						temp=puzzle[index][jindex];
						puzzle[index][jindex]=puzzle[index][jindex+1];
						puzzle[index][jindex+1]=temp;
						jindex=jindex+1;
					}
					break;
					
					
				default:
					Beep(750,1000);
					break;
						
			}
			if(correct()){
				
				printf("The Puzzle is solved:\n");
				int i,j;
				
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						printf(" | %d |",puzzle[i][j]);
					}printf("\n");
				}
				
				printf("You Have taken %d steps to solve this puzzle\n",keyPresses);
				displayBorder();
				exit(0);
			}
		
	}
}


//displaying the border
void displayBorder(){
	int i;
	printf("\t\t\t");
	for(i=0;i<50;i++){
		printf("* ");
	}
	printf("\n");
}


//displaying the title
void displayTitle(){
	printf("\t\t\t Welcome to the puzzle game.....!");
	printf("\n");
}


//displaying the board
void displayBoard(){
	int i,j;
	for(i=0;i<4;i++){
		printf("\t\t\t");
		for(j=0;j<4;j++){
			printf(" | %d | ",puzzle[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}


// displaying the time
void displayTime(){
	time_t now;
	printf("%s ",ctime(&now));
}


//swap two cells in a puzzle
void swap(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}


//check if the puzzle is correct/
int correct(){
	int ct=1,i,j,act=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(puzzle[i][j]==ct%16){
				act++;
			}
			ct++;
		}
	}
	if(act==16){
		return 1;
	}
	else{
		return 0;
	}
}

