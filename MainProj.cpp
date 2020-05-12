// MainProj.cpp 
// Contains Main Function and include files
// Code Last Compiled on 13 June, 2018
// Code Developed By : Himesh Nayak, XIIA, JKPS

#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
#include"hangman.cpp"
#include"tictac.cpp"
#include"sudoku.cpp"
#include"nfunc.h"
#include"classes.h"
#include"filefunc.h"

void main()
{  
	int ch;
	do {
		logoAnimation();
	    cout<<"Press 1 to Login\n";
		cout<<"Press 2 to Signup with UCON\n";
		cout<<"Press 0 to Exit\n";
		cout<<"Enter your Choice : ";
		cin>>ch;
	    if (ch == 1)
		{
			char user[25], pass[20];
			cout<<"\n\nEnter Username : ";
			gets(user);
			cout<<"Enter Password : ";
			enterPass(pass);
			if (login(user, pass)== 1)
			{  
				homeScreen(user);
			}
			else 
			{
				cout<<"The Username or Password didn't match...";
				getch();
			}
		}
		else if (ch == 2)
		{
				cout<<endl;
				createA();
		}
		else if (ch == 0)
		{
			cout<<"Exiting Ucon...";
			getch();
		}
		else 
		{
			cout<<"You have entered a wrong choice\n\n";
			continue;
		}
	}while(ch!=0);
}