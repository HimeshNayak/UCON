// Code Last Compiled on 10 June, 2018

// hangman.cpp
// Contains Hangman Game

// Code Developed By : Himesh Nayak, XII-A, JKPS
 
void hangman() 
{
	clrscr(); 
	char words[5][25] = {	{"HIMESH AND AARYAN"}, 
							{"CONST"}, 
							{"ARRAY"}, 
							{"REFERENCE PARAMETER"}, 
							{"BINARY DIGITS"}}; 
	char questions[5][70] = {{"Who has developed this game?"}, 
                            {"What keyword we use for declaring a constant value?"}, 
                            {"What is contiguous memory location?"}, 
                            {"Which parameter has & (Ampersand)?"}, 
                            {"BIT stand for?"}}; 
	char wordsTemp[25], choice, guess; 
	int index, lives, flag = 0, flagCorrect, i; 
	do {     
		cout<<"Hangman Game"<<endl<<endl; 
		lives = 5; 
		randomize();
		index = random(5); 
		strcpy(wordsTemp, words[index]); 
		for (i = 0; wordsTemp[i] != '\0'; i++) 
		{ 
			if (wordsTemp[i] == 'A' || wordsTemp[i] == 'E' || wordsTemp[i] == 'I' || wordsTemp[i] == 'O' || wordsTemp[i] == 'U'|| wordsTemp[i] == ' '); 
			else wordsTemp[i] = '_'; 
		} 
		while (strcmp(words[index], wordsTemp)) 
		{ 	
			flagCorrect = 0; 
			if (lives < 0) 
			{ 
				cout<<"Game Over!!! \nNo Lives Left."; 
				cout<<"\nThis game is made by Himesh Nayak and Aaryan XII-A"<<endl; 
				flag = 1; 
				break; 
			}	 
			puts(questions[index]); 
			cout<<endl; 
			for (i = 0; wordsTemp[i] != '\0'; i++) 
				cout<<' '<<wordsTemp[i]; 
			cout<<endl<<endl<<"Lives left = "<<lives; 
			cout<<endl<<endl<<"Enter a guess : "; 
			cin>>guess; 
            cout<<endl; 
			guess = toupper(guess); 
			for (i = 0; wordsTemp[i] != '\0'; i++) 
			if (guess == words[index][i]) 
			{ 	
				wordsTemp[i] = words[index][i]; 
				flagCorrect = 1; 
			} 
			if (flagCorrect == 0) --lives; 
				cout<<endl<<endl; 
		} 
		if (flag == 0 ) 
		{ 
			cout<<"Congrats You Win!!!"<<endl; 	
			cout<<"This game is made by Himesh Nayak and Aaryan Arora XII-A"<<endl; 
			cout<<questions[index]<<" : "<<words[index]<<endl<<endl; 
		} 
		cout<<"Do you want to try again? (y/n) : "; 
		cin>>choice; 
		choice = tolower(choice); 
		clrscr(); 
	}while (choice != 'n'); 
}