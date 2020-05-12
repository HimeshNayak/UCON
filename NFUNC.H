// Code Last Compiled on 13 June, 2018

// nfunc.h
// All non-File Functions 

// Code Developed By : Himesh Nayak, XII-A, JKPS

void logoAnimation()
{
	int i = 60;
	clrscr();
	cout<<setw(i)<<" ------------------------------------- "<<endl;
	cout<<setw(i)<<"|                                     |"<<endl;
	cout<<setw(i)<<"|           -------  ------- .     |  |"<<endl;
	cout<<setw(i)<<"|  |       |        |       | .    |  |"<<endl;
	cout<<setw(i)<<"|  |       |        |       |  .   |  |"<<endl;
	cout<<setw(i)<<"|  |       |        |       |   .  |  |"<<endl;
	cout<<setw(i)<<"|  |       |        |       |    . |  |"<<endl;
	cout<<setw(i)<<"|  |       |        |       |     .|  |"<<endl;
	cout<<setw(i)<<"|   ------- -------  -------          |"<<endl;
	cout<<setw(i)<<"|                                     |"<<endl;
	cout<<setw(i)<<" ------------------------------------- "<<endl;
	cout<<setw(i)<<endl;
	cout<<setw(42)<<"UCON"<<endl;
	cout<<setw(53)<<"U are Connected On Network"<<endl<<endl;
	cout<<setw(80)<<"Developed By Himesh Nayak And Aaryan Arora XII-A\n\n";
}

void hashPass(char p[20])
{
	for (int i = 0; i < strlen(p); i++)
		p[i] += i;
}

void enterPass(char p[20])
{
	int i = 0;
	char a;
	while(i < 20)
	{
		a = getch();
		if ((a>= 'a' && a <= 'z')||(a>= 'A' && a <= 'Z')||(a>= '0' && a <= '9'))
		{
			p[i] = a;
			i++;
			cout<<'*';
		}
		else if (a == '\b')
		{
			cout<<"\b \b";
			i--;
		}
		else if (a == '\r')
		{
			p[i] = '\0';
			break;
		}
	}
	hashPass(p);
	cout<<endl;
}