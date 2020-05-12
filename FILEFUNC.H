// Code Last Compiled on 13 June, 2018

// filefunc.h
// All File related userdefined functions

// Code Developed By : Himesh Nayak, XII-A, JKPS

int login(char user[25], char pass[20])
{
	fstream f;
	f.open("acc.dat", ios::binary|ios::in);
	account s;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmpi(user, s.retName())==0)
		{
			if(strcmp(pass, s.retPass())==0)
			{
				return 1;
			}
		}
	}
	f.close();
	return 0;
}

void frin(char user[25])
{
	fstream fil;
	fil.open("friends.dat",ios::binary|ios::app);
	friends f;
	strcpy(f.retFrom2(), user);
	f.input2();
	fil.write((char*)&f,sizeof(f));
	cout<<"Friend Request Sent...\n\n";
	fil.close();
}

void frout(char a[20])
{
	fstream fil;
	fil.open("friends.dat",ios::binary|ios::in|ios::out);
	friends F;
	int cnt=0;
	int friReqNum = 0;
	while(fil.read((char*)&F,sizeof(friends)))
	{ 
		if(strcmpi(F.retTo2(),a)==0)
		{
			F.output2();
			++friReqNum;
			char ch;
			cout<<"Do you want to accept this Friend Request (Y/N) : ";
			cin>>ch;
			ch = toupper(ch);
			if (ch == 'Y')
			{
				F.accepted(a, F.retFrom2());
				fil.seekg(cnt*sizeof(friends),ios::beg);
				fil.write((char*)&F,sizeof(friends));
				break;
			}
		}
		cnt++;
	}
	fil.close();
	if (friReqNum == 0)
		cout<<"No Friend Requests Yet!!!\n\n";
}

void myfriends(char user[25])
{
	ifstream fil;
	fil.open("friends.dat",ios::binary);
	friends f;
	int friends = 0;
	cout<<"My Friends : \n\n";
	while(fil.read((char*)&f,sizeof(f)))
	{
		if(f.retAccept() == 1)
		{
			if (strcmpi(user,f.retTo2())==0)
				cout<<++friends<<". "<<f.retFrom2()<<endl;
			else if (strcmpi(user,f.retFrom2())==0)
				cout<<++friends<<". "<<f.retTo2()<<endl;
		}
	}
	fil.close();
	cout<<"You have "<<friends<<" friends.\n\n";
}

void mesOut(char user[25])
{
	ifstream f;
	f.open("messages.dat", ios::binary);
	messages m;
	int flag = 0;
	while (f.read((char*)&m, sizeof(m)))
	if(strcmpi(user, m.retTo())==0)
		{
			m.output();
			flag = 1;
		}
	if (flag == 0)
		cout<<"No Messages Yet!!!\n\n";
	f.close();
}

void mesIn(char user[25])
{
	fstream f;
	f.open("messages.dat", ios::binary|ios::app);
	messages m;
	strcpy(m.retFrom(), user);
	m.input();
	f.write((char*)&m, sizeof(m));
	f.close();
}

void postIn(char user[25])
{
	fstream f;
	f.open("posts.dat", ios::binary|ios::app);
	posts s;
	strcpy(s.retFrom(), user);
	s.input();
	f.write((char*)&s, sizeof(s));
	f.close();
}

void postOut()
{
	ifstream f;
	f.open("posts.dat", ios::binary);
	posts p;
	while (f.read((char*)&p, sizeof(p)))
	{
		if (strcmpi(p.retFrom(), "noOne") != 0)
			p.output();
		else cout<<"NO POSTS YET!!!";
	}
	f.close();
}

void fconnect(char a[20])
{
	ifstream f;
	f.open("acc.dat",ios::binary);
	account s;
	while(f.read((char*)&s,sizeof(s)))
		if(strcmpi(s.retName(),a)!=0)
			s.outf();
	f.close();
}

void accinfo(char a[20])
{
	ifstream f;
	f.open("acc.dat",ios::binary);
	account s;
	while(f.read((char*)&s,sizeof(s)))
		if(strcmpi(s.retName(),a)==0)
			s.outdata();
   f.close();
}
void deletion(char a[20])
{
	ifstream fmain("acc.dat",ios::binary|ios::in);
	ofstream ftemp("new.dat",ios::binary|ios::out);
	account E;
	char FOUND='N';
	while(fmain.read((char*)&E,sizeof(E)))
	{	
		if(strcmpi(E.retName(),a)!=0)
			ftemp.write((char*)&E,sizeof(account));
		else
			FOUND='Y';
	}
	if(FOUND=='N')
		cout<<"\nRecord Not Found";
	fmain.close();
	ftemp.close();
	remove("acc.dat");
	rename("new.dat","acc.dat");
}

void modify(char a[20])
{
	fstream f;
	f.open("acc.dat",ios::binary|ios::in|ios::out);
	account A;
	int cnt=0;
	char found='N';
	while(f.read((char*)&A,sizeof(account)))
	{ 
		if(strcmpi(A.retName(),a)==0)
		{
			cout<<"\n \n Enter New Information \n";
			A.inaccdata();
			f.seekg(cnt*sizeof(account),ios::beg);
			f.write((char*)&A,sizeof(account));
			found='Y';
			break;
		}
		cnt++;
	}
	if(found=='Y')
	cout<<"Record updated \n";
	else
	cout<<"Record not found";
	f.close();
}

void showStart(char user[25])
{
	clrscr();
	logoAnimation();
	cout<<"Welcome "<<user<<endl<<endl;
	char options[7][20] = {
		"Account Settings",
		"Messages",
		"Friends Connect",
		"Posts",
		"Games",
		"Log Out"
	};
	int i = 0;
	while (i < 6)
	{
		cout<<(i+1)<<". "<<options[i]<<endl;
		i++;
	}
}

void homeScreen(char user[25])
{
	showStart(user);
	char ch = 'Y';
	int opt, opt2;
	do
	{
		cout<<endl<<"Enter Your Option : ";
		cin>>opt;
		switch(opt)
		{
			case 1 :
				cout<<"\nEnter 1 for Information \n";
				cout<<"Enter 2 to Delete your Account \n";
				cout<<"Enter 3 to Modify your Account \n";
				cout<<"Enter your Choice : ";
				cin>>opt2;
				cout<<endl;
				if(opt2==1)
				{
					accinfo(user);
					getch();
				}
				if(opt2==2)
				{
					ch = 'N';
					deletion(user);
				}
				if(opt2==3)
				{
					modify(user);
					getch();
				}	
				break;
			case 2 :
				cout<<"\nEnter 1 to Write a Message\n";
				cout<<"Enter 2 to Read Messages\n";
				cout<<"Enter your Choice : ";
				cin>>opt2;
				if (opt2 == 1)
				{
					cout<<endl;
					fconnect(user);
					mesIn(user);
					getch();
				}
				else if (opt2 == 2)
				{
					cout<<endl;
					mesOut(user);
					getch();
				}
				else cout<<"You have entered a wrong choice...\n\n";
				break;
			case 3 : cout<<endl;
				myfriends(user);
				char s;
				cout<<"\nEnter 1 to Send a Friend Request\n";
				cout<<"Enter 2 to See Friend Requests\n";
				cout<<"Enter your Choice : ";
				cin>>opt2;
				if (opt2 == 1)
				{
					cout<<endl;
					fconnect(user);
					frin(user);
					getch();
				}
				else if (opt2 == 2)
				{
					cout<<endl;
					frout(user);
					getch();
				}
				break;
			case 4 :
				cout<<"\nEnter 1 to Write a Post\n";
				cout<<"Enter 2 to Read Posts\n";
				cout<<"Enter your Choice : ";
				cin>>opt2;
				if (opt2 == 1)
				{
					cout<<endl;
					postIn(user);
					getch();
				}
				else if (opt2 == 2)
				{
					cout<<endl;
					postOut();
					getch();
				}
				break;
			case 5 : cout<<"\nEnter your choice \n";
				cout<<"1.Suduko \n";
				cout<<"2.Tic-Tac-Toe \n";
				cout<<"3.Hangman \n";
				cin>>opt2;
				switch(opt2)
				{
					case 1: suduko();
						break;
					case 2: tictac();
						break;
					case 3: hangman();
						break;
				}
				break;
			case 6 : ch = 'N';
				break;
			default : cout<<"Sorry wrong choice entered...\n\n";
		}
		if (ch == 'N')
		{
			cout<<"Logging you out of UCON...\n\n";
			getch();
		}
		showStart(user);
	}while(ch != 'N');
}

void createA()
{
	fstream f;
	f.open("acc.dat", ios::binary|ios::app);
	account A;
	A.inaccdata();
	f.write((char*)&A, sizeof(A));
	f.close();
	char ch='y';
	int num = 0;
	while(ch != 'n' && num < 3)
	{
		char pass2[20];
		cout<<"Re-Enter the Password : ";
		enterPass(pass2);
		num++;
		if (login(A.retName(), pass2) == 1)
		{
			ch='n';
			homeScreen(A.retName());
		}
		else
		{
			cout<<"The password entered did not match...\n\n";
		}
	}
}