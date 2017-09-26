#include <iostream>
#include<Windows.h>
#include <stdio.h>
#include<conio.h>
using namespace std;
    // 35 = walls
	//060 = pacman right
	//062 = pacman left
	//118 = pacman up
	//94 = pacman down
    // 87 = ghost1

    const int rows = 32;
	const int columns = 32;

    //Start position is [6][0]
	int pacI =6 , pacJ = 0;
	//Ghost1 Start postion is [16][14]
	int ghostOneI = 8, ghostOneJ = 8;
	int i = 0 , j = 0;
    char key = 127;    
	char map[rows][columns]=
	{
		{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
		{35,111,111,111,111,111,111,35,35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35},
		{35,111,35,111,35,35,111,35,35,111,35,35,35,35,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,111,35},
		{35,111,35,111,35,35,111,35,35,111,35,35,35,35,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,111,35},
		{35,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35},
		{35,35,35,35,111,35,35,35,35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35,35,35,111,111,111,111,111,35},
		{074,000,000,000,111,35,000,000,000,000,000,000,35,35,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,111,111,35},
		{35,35,35,35,111,000,35,000,000,000,000,000,35,35,111,111,111,111,111,111,111,111,111,35,35,35,111,111,111,111,111,35},
		{35,111,111,111,111,35,000,000,000,000,000,000,35,35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35},
		{35,111,111,111,111,111,000,000,000,000,000,000,000,000,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35},
		{35,111,35,35,35,111,35,35,35,111,111,35,35,35,111,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,35},
		{35,111,35,35,35,111,35,35,35,111,111,35,35,35,111,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,35},
		{35,111,35,35,35,111,35,35,35,111,111,35,35,35,111,111,111,111,111,111,111,111,111,111,35,35,35,35,111,111,111,35},
		{35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,35},
		{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},		
	};

	char ghostCurrent = map[ghostOneI][ghostOneJ];

	void getKeyPress();
	void Ghost();
	void GoToXY(int column, int line);

	int lives = 3;
	int pillCount = 0;


	int main()
	{
	    HANDLE  hConsole;
	    
	    
	    char key = 0;
	    system("mode 80, 255");
	    int pills = 259;
		bool stopCounting  = false;
	    	    
	    do               //create the maze      //32 columns      //32 rows
	    { 
	      
	       GoToXY(0, 0);//Set Start position
	       Ghost();
	       for (i = 0; i <= 32; i++)//Rows
	       {	          
	          for (j = 0; j <= 32; j++)//Columns
	          {	             
	             if (map[i][j] == 35);//Walls
	             	             
	             else if (map[i][j] == 060 || map[i][j] == 062 || map[i][j] == 118 ||map[i][j] == 94);//Pacman
	                     
	             else if (map[i][j] == 000);//Blank
	                        
	             else if (map[i][j] == 87);//Ghost
	                       
	             else if (map[i][j] == 111);//pill
	                                   
	             cout << map[i][j];//displays map
				 
                  if ( j == 31)
	                cout << endl;
	 
	              if ( j == 32 && i == 32)
	                stopCounting = true;
				  if (lives==0||pillCount==pills)
		   {
			   cout <<"game over";system("cls");
			   getch();
			   break;
			   cout<<"game over"; //If condition true comes out of the loop
			   
		   }
	          } 
	       }
	       getKeyPress();//function for movement of pacman
	            
	       cout << "lives remaining " << lives << endl;
	       cout<<"pillCount"<<pillCount<<endl;
		  
	    }
	    while (lives >= 0 || pillCount <= pills);
		
	       
			return 0;
	cout<<"game over";Sleep (222);
system("pause");
	}
	bool ghostMoveUp()//up maovement of ghost
	{
	    char ghostNextUp = map[ghostOneI -1][ghostOneJ];	      
	    if ( ghostNextUp != 35)                            //Check the next upward block to be sure it is not a wall
	    {
	       if ( ghostNextUp == 111  )                      //Check the last block to see if there was a pill
	       {
	          
	          map[ghostOneI - 1][ghostOneJ] = 87;
	          map[ghostOneI][ghostOneJ] = ghostNextUp;
	          ghostOneI--;
	       }
	       else 
		   {
	          
	          map[ghostOneI][ghostOneJ] = 000;
	          map[ghostOneI - 1][ghostOneJ] = 87;
	          ghostOneI--;
	       }
	       return true;
	    }
	    else
	    {
	       return false;
	    }
	}
	 
	bool ghostMoveDown()// down movemnet of ghost
	{
	 
	    char ghostNextDown = map[ghostOneI + 1][ghostOneJ];
	    if ( ghostNextDown != 35)
	    {
	       if ( ghostNextDown == 111 )
	       {
	          map[ghostOneI + 1][ghostOneJ] = 87;
	          map[ghostOneI][ghostOneJ] = ghostNextDown;
	          ghostOneI++;
	       }
	       else
	       {
	          map[ghostOneI][ghostOneJ] = 000;
	          map[ghostOneI + 1][ghostOneJ] = 87;
	          ghostOneI++;
	       }
	       return true;
	    }
	    else
	    {
	       return false;
	    }
	}
 
	bool ghostMoveLeft()//left movement of ghost
	{
	    char ghostNextLeft = map[ghostOneI][ghostOneJ - 1];
	    if ( ghostNextLeft != 35)
      {
	          if ( ghostNextLeft == 111 )
	          {
                 map[ghostOneI][ghostOneJ - 1] = 87;
	             map[ghostOneI][ghostOneJ] = ghostNextLeft;
	             ghostOneJ--;
	          }
	          else
	          {
	             map[ghostOneI][ghostOneJ] = 000;
             map[ghostOneI][ghostOneJ - 1] = 87;
	             ghostOneJ--;
	          }
	           return true;
	       }
	        else
	       {
	          return false;
	       }
	 
	}
	 
	bool ghostMoveRight()//Right movement of ghost
    {
	    char ghostNextRight = map[ghostOneI][ghostOneJ + 1];
	    if ( ghostNextRight != 35)
	    {
	       
	       if ( ghostNextRight == 111 )
	       {
	          map[ghostOneI][ghostOneJ + 1] = 87;
	          map[ghostOneI][ghostOneJ] = ghostNextRight;
	          ghostOneJ++;
	       }
	       else
	       {
	          map[ghostOneI][ghostOneJ] = 000;
	          map[ghostOneI][ghostOneJ + 1] = 87;
	          ghostOneJ++;
	       }
	       return true;
	    }
	    else
	    {
	       return false;
	    }
	 
	}
	void Ghost()
	{
	    if(111)
		{ 
	       if ( pacI < ghostOneI)   //Ghost is moving up
	       { 
	          if (!ghostMoveUp()); //if wall found
	       }
	       else if (pacI > ghostOneI)   //Ghost is moving down
	       {
	          if (!ghostMoveDown());
	       }	       
	       if (pacJ < ghostOneJ)//Ghost is moving left
	       {
	          if (!ghostMoveLeft());
	       }	       
	       else if (pacJ > ghostOneJ)//Ghost is moving right
	       {
	          if (!ghostMoveRight());
	       }
	    }	 
	    //you caught the ghost
	    if (pacJ == ghostOneJ && pacI == ghostOneI )
	    {
			
	       map[pacI][pacJ] = 000;
	       ghostOneI = 8;
	       ghostOneJ = 8;
		   pacI = 6;
	       pacJ = 0;map[6][0] = 074;
	       map[8][8] = 87;lives--;map[ghostOneI][ghostOneJ] = 000;
	    }
	    
	}
void getKeyPress()
	{
	    key = _getch();
	    char pacTemp = '<';
	    //get a special key
	    
	       
	        if (key == 72) //up
	        {
	           if ( map[pacI- 1][pacJ] != 35)
	           {
	             if (map[pacI- 1][pacJ] == 111)
	             {
	                pillCount++;
	             }
	                map[pacI][pacJ] = 000;
	                map[pacI - 1][pacJ] = 118;
	                pacI--;
	           }
	         }
	         else if (key == 75) //left
	         {
	            if ( map[pacI][pacJ- 1] != 35)
	            {
	             if (map[pacI][pacJ - 1] == 111)
	             {
	                pillCount++;
	             }
	                map[pacI][pacJ] = 000;
                    map[pacI][pacJ - 1] = 076;
                    pacJ--;
                }
	         }
	         else if (key == 77) //right
	         {
	            if ( map[pacI][pacJ+ 1] != 35)
	            {
	             if (map[pacI][pacJ + 1] == 111)
	             {	                
	                pillCount++;
	             }
	             map[pacI][pacJ] = 000;
	             map[pacI][pacJ + 1] = 074;
	             pacJ++;
	            }
	         }
	         else if (key == 80) //down
	         {
             if ( map[pacI + 1][pacJ] != 35)
	           {
	             if (map[pacI + 1][pacJ] == 111)
	             {
					 pillCount++;
	             }
	             map[pacI][pacJ] = 000;
	             map[pacI + 1][pacJ] = 94;
	             pacI++;
	           }
	         }
	    
}
void GoToXY(int column, int line)//gotoxy function
{
	    
	    COORD coord;
	    coord.X = 0;
	    coord.Y = 0;
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    if (!SetConsoleCursorPosition(hConsole, coord));	    
}