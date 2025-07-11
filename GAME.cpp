#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);

void printMaze();
void printscore();
void moveGhost();
void moveGhosts();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUP();
void movePacmanDown();
void checkCollision(int,int );
 char maze[80][80] = {
    "##################################################################### ",
    "||.. ...................................................   ......  || ",
    "||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%   |%|..   %%%%   || ",
    "||..        |%|   |%|     |%|...     |%|      |%|   |%|..    |%|   || ",
    "||..        |%|   |%|     |%|...     |%|      |%|   |%|..    |%|   || ",
    "||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%      ..   %%%%.  || ",
    "||..        |%|       . . |%|...    .............  |%| ..       .  || ",
    "||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%     |%| ..   %%%%.  || ",
    "||..               |%|.             |%|......      |%| ..    |%|.  || ",
    "||..     ......... |%|.             |%|......|%|       ..    |%|.  || ",
    "||..|%|  |%|%%%|%|.|%|. |%|            ......|%|       ..|%| |%|.  || ",
    "||..|%|  |%|   |%|..    %%%%%%%%%%%%   ......|%|        .|%|.      || ",
    "||..|%|  |%|   |%|..          ...|%|      %%%%%%       . |%|.      || ",
    "||..|%|            .          ...|%|               |%| ..|%|.      || ",
    "||..|%|  %%%%%%%%%%%%%%       ...|%|%%%%%%%%%%%    |%| ..|%|%%%%%  || ",
    "||...............................................  |%| ..........  || ",
    "||   ............................................         .......  || ",
    "||..|%|  |%|  |%|..    %%%%%%%%%%%%%%  ......|%|   |%| ..|%|.      || ",
    "||..|%|  |%|  |%|..            ...|%|     %%%%%%   |%| ..|%|.      || ",
    "||..|%|           .            ...|%|              |%| ..|%|.      || ",
    "||..|%|  %%%%%%%%%%%%%         ...|%|%%%%%%%%%%    |%| ..|%|%%%%%  || ",
    "||................................................ |%| ..........  || ",
    "||  ..............................................        .......  || ",
    "##################################################################### "
};
  
int pacmanX = 4, pacmanY = 4;
int ghostX = 9, ghostY = 9; 
int ghostX1 = 20, ghostY1 = 25; 
int ghostX2 = 10, ghostY2 = 30; 
int ghostX3 = 2, ghostY3 = 35; 
int score = 0;
int lives=3;
int main(){
bool gameRunning = true;
system("CLS");
printMaze();
printscore();
gotoxy(pacmanY, pacmanX);
cout << "P";
while (gameRunning){
Sleep(100);
moveGhosts();
if (GetAsyncKeyState(VK_LEFT)){
movePacmanLeft(); }
if (GetAsyncKeyState(VK_RIGHT)){
movePacmanRight(); }
if (GetAsyncKeyState(VK_UP)){
movePacmanUP(); }
if (GetAsyncKeyState(VK_DOWN)){
movePacmanDown(); }
if (GetAsyncKeyState(VK_ESCAPE)){
gameRunning = false; }
}
}
void movePacmanLeft()
{
if (maze[pacmanX][pacmanY - 1] == ' ')
{
	
maze[pacmanX][pacmanY] = ' ';
gotoxy(pacmanY, pacmanX);
cout << " ";
pacmanY = pacmanY - 1;
gotoxy(pacmanY, pacmanX);
cout << "P";
}
else if( maze[pacmanX][pacmanY - 1] == '.')
{
	
maze[pacmanX][pacmanY] = ' ';
gotoxy(pacmanY, pacmanX);
cout << " ";
score+=1;
pacmanY = pacmanY - 1;
gotoxy(pacmanY, pacmanX);
cout << "P";
printscore();
}
}
void movePacmanRight()
{
if (maze[pacmanX][pacmanY + 1] == ' ' )
{
maze[pacmanX][pacmanY] = ' ';
gotoxy(pacmanY, pacmanX);
cout << " ";
pacmanY = pacmanY + 1;
gotoxy(pacmanY, pacmanX);
cout << "P";
}
else if( maze[pacmanX][pacmanY + 1] == '.')
{
	
maze[pacmanX][pacmanY] = ' ';
gotoxy(pacmanY, pacmanX);
cout << " ";
score+=1;
pacmanY = pacmanY + 1;
gotoxy(pacmanY, pacmanX);
cout << "P";
printscore();
}
}
void printMaze()
{
   for (int row = 0; row<24; row = row + 1)
 {
   for (int col = 0; col < 80; col = col + 1)
  {
    cout << maze[row][col];
}
    cout << endl;
}
}
void movePacmanUP()
{
    if (maze[pacmanX - 1][pacmanY] == ' ')
{
 maze[pacmanX][pacmanY] = ' ';
 gotoxy(pacmanY, pacmanX);
 cout << " ";
 pacmanX = pacmanX - 1;
 gotoxy(pacmanY, pacmanX);
 cout << "P";
}
    else if(maze[pacmanX - 1][pacmanY] == '.')
{
	
 maze[pacmanX][pacmanY] = ' ';
 gotoxy(pacmanY, pacmanX);
 cout << " ";
 score+=1;
 pacmanX = pacmanX - 1;
 gotoxy(pacmanY, pacmanX);
 cout << "P";
 printscore();
}
}
void movePacmanDown()
{
   if (maze[pacmanX + 1][pacmanY] == ' ' )
{
 maze[pacmanX][pacmanY] = ' ';
 gotoxy(pacmanY, pacmanX);
 cout << " ";
 pacmanX = pacmanX + 1;
 gotoxy(pacmanY, pacmanX);
 cout << "P";
}
  else if(maze[pacmanX + 1][pacmanY] == '.')
{
	
 maze[pacmanX][pacmanY] = ' ';
 gotoxy(pacmanY, pacmanX);
 cout << " ";
 score+=1;
 pacmanX = pacmanX + 1;
 gotoxy(pacmanY, pacmanX);
 cout << "P";
 printscore();
}
}
 void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printscore()
{
	gotoxy(2,24);
	cout<<"Score = "<<score<<"      Total Lives = 3";
}

void moveGhost(int& ghostX, int& ghostY) {
 int direction = GetTickCount() % 4; 

    int newX = ghostX, newY = ghostY;

    if (direction == 0 && maze[ghostX][ghostY - 1] == ' ') newY--;  
    else if (direction == 1 && maze[ghostX][ghostY + 1] == ' ') newY++;
    else if (direction == 2 && maze[ghostX - 1][ghostY] == ' ') newX--;
    else if (direction == 3 && maze[ghostX + 1][ghostY] == ' ') newX++;

    if (maze[newX][newY] == ' ') {
        gotoxy(ghostY, ghostX);
        cout << " ";
        ghostX = newX;
        ghostY = newY;
        gotoxy(ghostY, ghostX);
        cout << "G"; 
    }

}
void checkCollision(int ghostX, int ghostY) {
    if (pacmanX == ghostX && pacmanY == ghostY) {
        lives--;
		 gotoxy(2, 25);
            cout << "Remaining lives = "<<lives;
        

        if (lives <= 0) {
            gotoxy(2, 26);
            cout << "Game Over"; 
            exit(0); 
        }
        pacmanX = 4;
        pacmanY = 4;
    }
}
void moveGhosts(){
	moveGhost( ghostX, ghostY); 
	 checkCollision(ghostX,ghostY);
	moveGhost (ghostX1, ghostY1);
	 checkCollision(ghostX1,ghostY1); 
 	moveGhost(ghostX2, ghostY2) ; 
 	 checkCollision(ghostX2,ghostY2);
 	moveGhost(ghostX3, ghostY3);
	 checkCollision(ghostX3,ghostY3); 
}
