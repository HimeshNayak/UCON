// Code Last Compiled on 13 June, 2018

// classes.h
// This file contains : All userdefined classes

// Code Developed By : Himesh Nayak, XII-A, JKPS 

struct date
{
	int dd, mm, yy;
};

class account
{
	char fname[10];
	char lname[10];
	char username[10];
	char pass[20];
	char email[30];
	char phone[12];
	date d;
	char gender;
public:
	char* retName()
	{
		return username;
	}
	char* retPass()
	{
		return pass;
	}
	void inaccdata();
	void outdata();
	void outf();
};

class friends
{
	char to2[20];
	char from2[20];
	int accept;
public:
	char* retTo2()
	{
		return to2;
	}
	char* retFrom2()
	{
		return from2;
	}
	int retAccept()
	{
		return accept;
	}
	friends()
	{
		accept = 0;
	}
	void input2();
	void output2();
	void accepted(char* , char*);
};

class messages
{
	char to[20];
	char from[20];
	char msg[100];
public:
	char* retTo()
	{
		return to;
	}
	char* retFrom()
	{
		return from;
	}
	messages();
	void input();
	void output();
};

class posts
{
	char from[20];
	char post[100];
public:
	char* retFrom()
	{
		return from;
	}
	posts();
	void input();
	void output();
};

// Member Functions Definations

// Class account:

void account::inaccdata()
{
	cout<<"Enter First Name : ";
	gets(fname);
	cout<<"Enter Last Name : ";
	gets(lname);
	cout<<"Enter Email Address : ";
	gets(email);
	cout<<"Enter Phone Number : ";
	gets(phone);
	cout<<"Enter Username : ";
	gets(username);
	cout<<"Enter the Password : ";
	enterPass(pass);
}

void account::outdata()
{
	cout<<"Username : "<<username<<endl;
	cout<<"First Name : "<<fname<<endl;
	cout<<"Last Name : "<<lname<<endl;
	cout<<"Email Address : "<<email<<endl;
	cout<<"Phone Number : "<<phone<<endl<<endl;
}
void account::outf()
{
	cout<<" . "<<username<<endl;
}

// Class friends

void friends::input2()
{
	cout<<"To whom do you want to Send Request to : ";
    gets(to2);
}

void friends::output2()
{
	cout<<"Friend Request By :- "<<retFrom2()<<endl;
}

void friends::accepted(char* A, char* B)
{
	strcpy(retTo2(), A);
	strcpy(retFrom2(), B);
	accept = 1;
}


// Class messages:

messages::messages()
{
	strcpy(to, "noOne");
	strcpy(from, "noOne");
}

void messages::input()
{
	cout<<"To whom you want to give the message to :";
	gets(to);
	cout<<"Type in the message : ";
	gets(msg);
}

void messages::output()
{
	cout<<"Message By : "<<retFrom()<<endl;
	cout<<msg<<endl<<endl;
}

// Class posts:

posts::posts()
{
	strcpy(from, "noOne");
	strcpy(post, "No Posts Yet");
}

void posts::input()
{
	cout<<"Type in the post : ";
	gets(post);
}

void posts::output()
{
	cout<<"Post By : "<<retFrom()<<endl;
	cout<<post<<endl;
}