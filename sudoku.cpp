// Code Last Compiled on 10 June, 2018

// sudoku.cpp
// Contains Sudoku Game

// Code Developed By : Himesh Nayak, XII-A, JKPS

void suduko() 
{ 
	clrscr(); 
	int square[9][9] = {{3, 0, 0, 9, 0, 4, 0, 1, 2}, {6, 0, 1, 2, 0, 3, 0, 4, 0}, {9, 2, 0, 0, 1, 5, 0, 7, 0},  
						{7, 0, 0, 6, 9, 0, 0, 0, 5}, {0, 0, 2, 7, 0, 1, 6, 0, 0}, {5, 0, 0, 0, 4, 8, 0, 0, 1}, 
						{0, 0, 0, 4, 3, 0, 0, 5, 7}, {0, 3, 0, 0, 0, 7, 1, 0, 0}, {0, 5, 0, 0, 8, 0, 0, 0, 0}}; 
	int squareTemp[9][9] = {{3, 7, 5, 9, 6, 4, 8, 1, 2}, {6, 8, 1, 2, 7, 3, 5, 4, 9}, {9, 2, 4, 8, 1, 5, 3, 7, 6}, 
							{7, 1, 3, 6, 9, 2, 4, 8, 5}, {8, 4, 2, 7, 5, 1, 6, 9, 3}, {5, 9, 6, 3, 4, 8, 7, 2, 1}, 
							{1, 6, 8, 4, 3, 9, 2, 5, 7}, {4, 3, 9, 5, 2, 7, 1, 6, 8}, {2, 5, 7, 1, 8, 6, 9, 3, 4}};  
	int num, flag, x, y, print = 0, i, j; 
	char choice; 
	do {  
		while (1) 
		{ 
			cout<<"Here is the Suduko which you have to solve."<<endl; 
			cout<<"Enter number as -1 to quit the game."<<endl<<endl; 
			for (i = 0; i < 9; i++) 
			{     
				if (i % 3 == 0 && i != 0) 
				{          
					for (int k = 0; k < 9 + 2; k++) 
					   cout<<" - "; 
					cout<<endl; 
				} 
				for (j = 0; j < 9; j++) 
				{ 
					if (j % 3 == 0 && j != 0) 
						cout<<"| "; 
					cout<<' '<<square[i][j]<<' '; 
				} 
				cout<<endl; 
				}	  
				if (print == 1) 
					cout<<"Wow!!! That is the correct place and number"<<endl; 
				else if (print == 2) 
				{ 
					cout<<"Wrong Move!!! That is not the correct place and”; cout<<”number"<<endl; } 
					flag = 0; 
					for (i = 0; i < 9; i++) 
					{	 
						for (j = 0; j < 9; j++) 
						if (square[i][j] == 0) 
						++flag; 
					} 
					if (flag == 0) break; 
					cout<<"Enter where you want to put the number?"<<endl; 
					cout<<"Enter the row number : "; 
					cin>>y; 
					if (x == -1) break; 
					cout<<"Enter the column number : "; 
					cin>>x; 
					if (y == -1) break; 
					cout<<"Enter the number : "; 
					cin>>num; 
					if (num == -1) break; 
					if (num == squareTemp[y-1][x-1]) 
					{ 
						square[y-1][x-1] = squareTemp[y-1][x-1]; 
						print = 1; 
					} 
					else print = 2; 
					clrscr(); 
				} 
			cout<<"Want to play again? : ";
			cin>>choice; 
			choice = tolower(choice); 
			cout<<"\nThe Game is developed by Himesh Nayak and Aaryan Arora XII-A"<<endl<<endl;
			clrscr(); 
		}while(choice != 'n'); 
}	