
/*******     S N A K E   G A M E       *******/
/*******  Made By : ABADILA  ALAKTIF   *******/

#include <iostream>
#include <ctime>   // to use time in srand(time(null))
#include <cstdlib> 
#include <conio.h>
#include <Windows.h>  //to use keyboard

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


using namespace std;



class map {
	public:
	int widht ,height;   // map 
	int fruitx,fruity;	 // the position of the fruit in the map
};

class snake {
	public:
		int headx,heady; // the position of the snake's head in the map 
		int tailN, dir;  // the length of the tail 
		int tailX[50],tailY[50]; // array contains the old snake's positions  
};

class player {
	public :
		int score; // the player score
		bool lose; //the stat of the player 
};

map map1;        // create a map
snake snake1;    // create a snake
player player1;  // create a player

void shift (int arr[],int size){ 
	for(int i=size-2;i>=0;i--){	arr[i+1]=arr[i];	}
	}


void generatefruit(){
	srand(time(0));
	map1.fruitx=rand() %(map1.widht-2)+1;   // generate a fruit in a random place in the map    
	map1.fruity=rand() %(map1.height-2)+1;  // generate a fruit in a random place in the map 
}

void setup(){
	
	map1.widht =40;   // bypixels
	map1.height =20;  // by pixles
    generatefruit();  
    snake1.headx=map1.widht /2;  // The spown of the snake
    snake1.heady=map1.height /2; // The spown of the snake
    snake1.tailN=0;
    player1.score=0;
    player1.lose=false;
}

void draw (){
	system("cls");
	int i,j;
	for(i=0;i<map1.height;i++){
		for(j=0;j<map1.widht;j++){
			if (i==0||i==map1.height -1)	cout <<"-";  // map limits
			else if (j==0||j==map1.widht -1) cout <<"|"; // map limits
			else if (i==snake1.heady && j== snake1.headx) cout<< "O"; // Snake Head Symbol
			else if (i==map1.fruity && j== map1.fruitx) cout<< "$";   // fruit Symbol
			else  {
				bool printed =false ;
				for(int z=0;z<snake1.tailN;z++){
					if (snake1.tailX[z]==j && snake1.tailY[z]==i){
						cout <<".";  // Snake's Tail Symbol
						printed = true;
						break;
					}
					}
				if (!printed) cout<<" ";
				}
			}
		cout << endl;
}
cout << "Your SCORE:" <<player1.score<< endl;
}
	 
	 

void input (){
	if (_kbhit()){
		char c= _getch();  // the key pressed by the player in the keyoard 
		
		switch (c){
			
			case KEY_UP :snake1.dir =1;break;
			case KEY_DOWN :snake1.dir =2;break;
			case KEY_RIGHT :snake1.dir =3;break;
			case KEY_LEFT :snake1.dir =4;break;
		}
	}
	
}

void move() {
    shift(snake1.tailX,50);
	shift(snake1.tailY,50);
	snake1.tailX[0]=snake1.headx;
	snake1.tailY[0]=snake1.heady;
		
   	if (snake1.dir==1)snake1.heady --; // move UP
	if (snake1.dir==2)snake1.heady ++; // move DOWN
	if (snake1.dir==3)snake1.headx ++; // move RIGHT
	if (snake1.dir==4)snake1.headx --; // move LEFT
	
	
	
	
    if (snake1.heady >= map1.height || snake1.heady <=0 ||snake1.headx >= map1.widht || snake1.headx <=0 ) player1.lose=true;
    if (snake1.headx ==map1.fruitx && snake1.heady ==map1.fruity) {generatefruit(); // if the snake eat the fruit we generate a new one
	snake1.tailN++; // if the snake eat the fruit the tail grow up
	player1.score++; }
	}
	

int main(){
	setup();
	while (!player1.lose){  
		draw();
		input();
		move();
		Sleep(50);
	}
	cout<< "GAME OVER\n";
	cout <<"\nGood LUCK Next Time\n";
	cout << "made by : ABADILA ALAKTIF\n";

	system("pause");
	return 0;
}
