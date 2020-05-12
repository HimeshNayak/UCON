// Code Last Compiled on 10 June, 2018

// tictac.cpp
// Contains Tic-Tac-Toe Game

// Code Developed By : Himesh Nayak, XII-A, JKPS

const int size = 3; 
char grid[size][size] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 

void printGrid() 
{ 
	clrscr(); 
	cout<<endl; 
	for (int i = 0; i < size; i++) 
	{ 
		cout<<"|"; 
	for (int j = 0; j < size; j++) 
		cout<<""<<grid[i][j]<<"|"; 
	cout<<endl<<endl; 
	} 
	cout<<endl; 
} 

int placeGrid(char place, int player) 
{ 
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{ 
			if (place == grid[i][j] && player % 2 != 0) 
			{ 
				grid[i][j] = 'O'; 
				return 0; 
			} 
			else if (place == grid[i][j] && player % 2 == 0) 
			{
				grid[i][j] = 'X'; 
				return 0; 
			} 
		} 
	}
	return 1; 
}
 
int whoWonFunc(int & win1, int & win2, int & whoWon) 
{
	int endGame = 0; 
    if (win1 == size) 
        whoWon = 1; 
    else if (win2 == size) 
        whoWon = 2; 
    win1 = 0; 
    win2 = 0; 
    for (int i = 0; i < size; i++) 
    {        
		for (int j = 0; j < size; j++) 
        { 
			if (grid[i][j] == 'O' || grid[i][j] == 'X') 
				++endGame; 
		} 
    } 
    if (endGame == 9) 
        whoWon = endGame; 
    return whoWon; 
} 

int checkGrid() 
{ 
	int win1 = 0, win2 = 0, whoWon = 0, i, j; 
    for (i = 0; i < size; i++) 
    { 
		if (grid[i][i] == 'O') 
			++win1; 
		else if(grid[i][i] == 'X') 
            ++win2; 
    } 
    if (whoWonFunc(win1, win2, whoWon) != 0) 
		return whoWon; 
    for (i = 0; i < size; i++) 
    { 
		if (grid[i][size - i - 1] == 'O') 
			++win1; 
        else if(grid[i][size - i - 1] == 'X') 
            ++win2; 
    } 
    if (whoWonFunc(win1, win2, whoWon) != 0) 
		return whoWon; 
    for (i = 0; i < size; i++) 
    {        
		for (j = 0; j < size; j++) 
        { 
            if (grid[i][j] == 'O') 
                ++win1; 
            else if(grid[i][j] == 'X') 
                ++win2; 
        } 
        if (whoWonFunc(win1, win2, whoWon) != 0) 
            return whoWon; 
        for (j = 0; j < size; j++) 
        {  if (grid[j][i] == 'O') 
                  ++win1; 
             else if(grid[j][i] == 'X') 
                  ++win2; 
        } 
        if (whoWonFunc(win1, win2, whoWon) != 0) 
        return whoWon; 
    } 
    return whoWon; 
} 

void tictac() 
{    
	char player1[15] = "", player2[15] = "", winner[15] = ""; 
    int win = 0; 
    char point; 
    clrscr(); 
    cout<<"Tic Tac Toe Game"<<endl<<endl; 
    cout<<"Player 1 : "; 
    gets(player1); 
    cout<<"Player 2 : "; 
    gets(player2); 
    printGrid(); 
    for (int move = 1; win == 0; move++) 
    {        
		if (move % 2 == 0) 
			cout<<player2<<", Enter where you want to play your move : "<<endl; 
        else cout<<player1<<", Enter where you want to play your move : "<<endl; 
        cin>>point; 
        if (placeGrid(point, move) == 1) 
        {   cout<<"Wrong Move!!!"<<endl; 
            --move; 
            continue; 
        } 
        printGrid(); 
        win = checkGrid(); 
    } 
    if (win == 1) 
        strcpy(winner, player1); 
    else if (win == 2) 
		strcpy(winner, player2); 
    else if (win == 9) 
    {     
		cout<<"Better Luck Next Time! Match Drawed!!!\n"; 
		cout<<"\nThe Game is developed by Himesh Nayak and Aaryan Aroara XII-A"<<endl<<endl; 
    } 
    if (win != 9)
	{
		cout<<"Congratulation "<<winner<<". You win!!!\n"; 
		cout<<"\nThe Game is developed by Himesh Nayak and Aaryan Arora XII-A"<<endl<<endl; 
	}
	getch();
}