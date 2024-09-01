#include<iostream>     // For input-output operations
#include<fstream>      // For file handling operations
#include<string>       // For string operations
#include<windows.h>    // For Windows-specific functions like console manipulation
#include <conio.h> // For _getch() function (Windows specific)
using namespace std;

//Global variables to store room information
int room[100],rent[100],A_pay[100],date[100],c=0;
bool check[100];
char A_C[100],size[100];
string names[100];
string phone[100];
string adress[100];
int day1,day2,m1,m2,y1,y2;

//Fuction prototypes
void Add_room();
void search_room();
void manage_room();
void check_in();
void avail_room();
void search_customer();
void check_out();
void summary();
int date_enter();
int date_calc(int ,int ,int);
void display();
void ClearConsoleToColors(int ForgC, int BackC);
void printLargeText(const std::string& text);

int main()
{
	///*
	//Declare variable to fetch data from files
	ifstream room_file,rent_file,A_pay_file,date_file,check_file,count,A_C_file,size_file;
	ifstream names_file,phone_file,adress_file;

	
	//Opening files to fetch data
	room_file.open("room.txt",ios::in);
	rent_file.open("Rent.txt",ios::in);
	A_pay_file.open("Adv_pay.txt",ios::in);
	date_file.open("date.txt",ios::in);
	check_file.open("check.txt",ios::in);
	A_C_file.open("A_C.txt",ios::in);
	size_file.open("Size.txt",ios::in);
	names_file.open("Names.txt",ios::in);
	phone_file.open("Phone.txt",ios::in);
	adress_file.open("Address.txt",ios::in);
	count.open("count.txt",ios::in);
	

	
	// Ensure to check if files are opened successfully
if (!room_file.is_open() || !rent_file.is_open() || !A_pay_file.is_open() ||
    !date_file.is_open() || !check_file.is_open() ||
    !A_C_file.is_open() || !size_file.is_open() || !names_file.is_open() ||
    !phone_file.is_open() || !adress_file.is_open() || !count.is_open())
	{
    	cout << "Error opening files!" << endl;
    	return 1;
	}
	count>>c;
	//Fetching data from files
	for(int input=0;input<c;input++)
	{
	room_file>>room[input];
	rent_file>>rent[input];
	A_pay_file>>A_pay[input];
	date_file>>date[input];
	check_file>>check[input];
	A_C_file>>A_C[input];
	size_file>>size[input];
	names_file>>names[input];
	phone_file>>phone[input];
	adress_file>>adress[input];
	}
	
	//closing files
	room_file.close();
	rent_file.close();
	A_pay_file.close();
	date_file.close();
	check_file.close();
	A_C_file.close();
	size_file.close();
	names_file.close();
	phone_file.close();
	adress_file.close();
	count.close();
	//*/
	int opt;
	string user = "";
	string password = "";
    char ch;
	///*
	ClearConsoleToColors(6,0); 
	cout<<"\t\t\t\t--------------------------\n";
	cout<<"\t\t\t\t|          Login         |\n";
	cout<<"\t\t\t\t--------------------------\n";
	cout<<"\t\tEnter user name :";
	
	//Masking the password input with '*'
    while ((ch = _getch()) != '\r') { // '\r' represents the Enter key
        user.push_back(ch);
        cout <<"*"; // Print '' instead of the actual character
    }
    cout << endl;
    
	cout<<"\t\tEnter Password  :";
	
	// Masking the password input with '*'
    while ((ch = _getch()) != '\r') { // '\r' represents the Enter key
        password.push_back(ch);
        cout << "-"; // Print '' instead of the actual character
    }
    cout << endl;
	
	if(!(password == "123" && (user == "Ali" || user == "ali")))
	exit(1);
	//*/
	display();

do
{
	system("cls");
	ClearConsoleToColors(0,15);
cout<<"\t--------------------------\n";
cout<<"\t|    Hotel Management    |\n";
cout<<"\t--------------------------\n";
cout<<"\n1. Manage Rooms";
cout<<"\n2. Check-In Room";
cout<<"\n3. Available Rooms";
cout<<"\n4. Search Customer";
cout<<"\n5. Check-Out Room";
cout<<"\n6. Guest Summary Report";
cout<<"\n7. Exit";
cout<<"\n\nEnter Option: ";
cin>>opt;
ClearConsoleToColors(2,15); 
switch(opt)
{
case 1:
	manage_room();
	break;
case 2:
	check_in();
	break;
case 3:
	avail_room();
	break;
case 4:
	search_customer();
	break;
case 5:
	check_out();
	break;
case 6:
	summary();
	break;
case 7:
	cout<<"Thank you for using software"<<endl;
	cout<<"Developed by ALI & HURAIRAH"<<endl;
	break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}
while(opt!=7);
///*
//Declare variable to store data from files
	ofstream room_file1,rent_file1,A_pay_file1,date_file1,check_file1,count1,A_C_file1,size_file1;
	ofstream names_file1,phone_file1,adress_file1;

	
	//Opening files to store data
	room_file1.open("room.txt",ios::trunc);
	rent_file1.open("Rent.txt",ios::trunc);
	A_pay_file1.open("Adv_pay.txt",ios::trunc);
	date_file1.open("date.txt",ios::trunc);
	check_file1.open("check.txt",ios::trunc);
	A_C_file1.open("A_C.txt",ios::trunc);
	size_file1.open("Size.txt",ios::trunc);
	names_file1.open("Names.txt",ios::trunc);
	phone_file1.open("Phone.txt",ios::trunc);
	adress_file1.open("Address.txt",ios::trunc);
	count1.open("count.txt",ios::trunc);


	// Ensure to check if files are opened successfully
if (!room_file1.is_open() || !rent_file1.is_open() || !A_pay_file1.is_open() ||
    !date_file1.is_open() || !check_file1.is_open() ||
    !A_C_file1.is_open() || !size_file1.is_open() || !names_file1.is_open() ||
    !phone_file1.is_open() || !adress_file1.is_open() || !count1.is_open())
	 {
    cerr << "Error opening files!" << endl;
    return 1;
}


	for(int input=0;input<c;input++)
	{
	room_file1<<room[input]<<endl;
	rent_file1<<rent[input]<<endl;
	A_pay_file1<<A_pay[input]<<endl;
	date_file1<<date[input]<<endl;
	check_file1<<check[input]<<endl;
	A_C_file1<<A_C[input]<<endl;
	size_file1<<size[input]<<endl;
	names_file1<<names[input]<<endl;
	phone_file1<<phone[input]<<endl;
	adress_file1<<adress[input]<<endl;
	}
	count1<<c;
	
	room_file1.close();
	rent_file1.close();
	A_pay_file1.close();
	date_file1.close();
	check_file1.close();
	A_C_file1.close();
	size_file1.close();
	names_file1.close();
	phone_file1.close();
	adress_file1.close();
	count1.close();
	//*/
}

//Function to manage rooms
void manage_room()
{
	int opt;
	do
	{
		system("cls");
		ClearConsoleToColors(12,15); 
	cout<<"\t--------------------------\n";
	cout<<"\t|    Manage Rooms        |\n";
	cout<<"\t--------------------------\n";
	cout<<"\n1. Add Room";
	cout<<"\n2. Search Room";
	cout<<"\n3. Back to Main Menu";
	cout<<"\n\nEnter Option: ";
	cin>>opt;
	ClearConsoleToColors(3,15); 
	switch(opt)
	{
		case 1:
			Add_room();
			break;
		case 2:
			search_room();
			break;
		case 3:
			break;
	}
    }
	while(opt!=3);
	
}

//Function to add rooms
void Add_room()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|      Add Rooms         |\n";
	cout<<"\t--------------------------\n";
	int z=0;
	cout<<"\nEnter room no :";
	cin>>room[c];
	cout<<"\nType AC/Non-AC (A/N):";
	cin>>A_C[c];
	do
	{
		if(A_C[c]=='A' ||A_C[c]=='a' ||A_C[c]=='N' ||A_C[c]=='n')
		z=1;
		else
		{cout<<"Enter correct option \n Type AC/Non-AC (A/N):";
		cin>>A_C[c];
		}
	}
	while(z==0);
	cout<<"Type size of the room (B/S):";
	cin>>size[c];
	z=0;
	do
	{
		if(size[c]=='B' ||size[c]=='b' ||size[c]=='S' ||size[c]=='s')
		z=1;
		else
		{cout<<"Enter correct option \n Type Big/Small (B/S):";
		 cin>>size[c];
	    }
	}
	while(z==0);
	cout<<"Enter daily rent :";
	cin>>rent[c];
	cout<<"\nRoom added succeesfully \n";
	check[c]=false;
	c++;
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;

}

//Function to search rooms
void search_room()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|    Search Rooms        |\n";
	cout<<"\t--------------------------\n";
	bool found=false;
	int search;
	cout<<"\nEnter room no you want to search:";
	cin>>search;
	for(int x=0;x<c;x++)
	{
		if(room[x]==search)
		{
			if(check[x]==true)
			cout<<"Room is reserved \n";
			else
			cout<<"Room is avaliable \n";
			
			cout<<"Room no is :"<<room[x]<<endl;
			cout<<"AC/Non-AC (A/N) :"<<A_C[x]<<endl;
			cout<<"size of the room (B/S):"<<size[x]<<endl;
			cout<<"Daily rent :"<<rent[x]<<endl;
			found=true;
			break;
		}
	}
	if(found==false)
	cout<<"Room not found \n";
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

//Function to check in room
void check_in()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|   Check-In Rooms       |\n";
	cout<<"\t--------------------------\n";
	int ch;
	bool found=false;
	cout<<"Enter room no in which you want to check in : ";
	cin>>ch;
	for(int x=0;x<c;x++)
	{
		if(room[x]==ch)
		{
			if(check[x]==true)
			{
			cout<<"Room is reserved /n";
			found=true;
		    }  
			else
			{
			cout<<"Enter customer name :";
			cin.ignore();
			getline(cin,names[x]);
			cout<<"Enter customer address:";
			cin.ignore();
			getline(cin,adress[x]);
			cout<<"Enter customer phone no:";
			cin>>phone[x];
			cout<<"Enter Advance payment:";
			cin>>A_pay[x];
			date[x]=date_enter();
			found=true;
			check[x]=true;
			break;
		    }
		}
    }
    if(found==false)
    cout<<"Room is not found "<<endl;
    char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

//Function to check Available Rooms
void avail_room()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|    Available Rooms     |\n";
	cout<<"\t--------------------------\n";
	int ch,avail=0;
	
	if (c==0)		
	cout<<"Room data is not available \n";
	else
	{
		cout<<"\nAvilable Rooms are following:\n";
	 for(int p=0;p<c;p++)
	 {
	 	if(check[p]==false)
	 	{
	 		cout<<"Room no is :"<<room[p]<<endl;
			cout<<"AC/Non-AC (A/N) :"<<A_C[p]<<endl;
			cout<<"size of the room (B/S):"<<size[p]<<endl;
			cout<<"Daily rent :"<<rent[p]<<endl;
			avail++;
			cout<<"------------------------------"<<endl;
		 }
	 }	
	if(avail==0)
	cout<<"All Rooms are reserved \n \n";
	}	
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

//Function to search customer
void search_customer()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|    Search Customer     |\n";
	cout<<"\t--------------------------\n";
	string find;
	int ch=0;
	for(int q=0;q<c;q++)
	{
		if(check[q]==true)
		ch++;
	}
	if(ch==0)
	cout<<"There is no reservation in hotel"<<endl;

	else
	{
		ch=0;
		cout<<"Enter customer name:";
		cin>>find;
		for(int q=0;q<c;q++)
		{
			if(names[q]==find)
			{
				cout<<"Customer is staying in room no :"<<room[q]<<endl;
				ch++;
				break;
			}
		}
		if(ch==0)
		cout<<"There is no reservation with this name "<<endl;
	}
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

// Variables for order management
int choise = 0, b = 1, s = 0, d = 0, t = 0, co = 0, i = 0;
int s1 = 0, d1 = 0, t1 = 0, c1 = 0, i1 = 0, tBill = 0;

//Fuctions to calculate bills
void menu() {
    cout << "::Menu::" << endl;
    cout << "1. Samosa 20/-" << endl;
    cout << "2. Dosa 35/-" << endl;
    cout << "3. Tea 10/-" << endl;
    cout << "4. Coffee 50/-" << endl;
    cout << "5. Ice Cream 30/-" << endl;
    cout << "0. Exit" << endl;
}

void quantity(int choise) {
    switch(choise) {
        case 1:
        case 2:
            cout << "Plate = ";
            break;
        case 3:
        case 4:
            cout << "Cups = ";
            break;
    }
}

void billing(int cBill) {
    tBill += cBill;
}

void order() {
	b=1;
    while(b) {
        menu();
        cout << "Enter choice: ";
        cin >> choise;

        switch(choise) {
            case 1:
                cout << "You have ordered Samosa" << endl;
                cout << "How many ";
                quantity(choise);
                cin >> s;
                s1 += s;
                cout << "Ok, anything else..." << endl;
                billing(s * 20);
                break;

            case 2:
                cout << "You have ordered Dosa" << endl;
                cout << "How many ";
                quantity(choise);
                cin >> d;
                d1 += d;
                cout << "Ok, anything else..." << endl;
                billing(d * 35);
                break;

            case 3:
                cout << "You have ordered Tea" << endl;
                cout << "How many ";
                quantity(choise);
                cin >> t;
                t1 += t;
                cout << "Ok, anything else..." << endl;
                billing(t * 10);
                break;

            case 4:
                cout << "You have ordered Coffee" << endl;
                cout << "How many ";
                quantity(choise);
                cin >> co;
                c1 += co;
                cout << "Ok, anything else..." << endl;
                billing(co * 50);
                break;

            case 5:
                cout << "You have ordered Ice Cream" << endl;
                cout << "How many ";
                quantity(choise);
                cin >> i;
                i1 += i;
                cout << "Ok, anything else..." << endl;
                billing(i * 30);
                break;

            case 0:
                cout << "Exit" << endl;
                b = 0;
                break;
        }
    }
}

void table() {
    if (s1) {
        cout << "Samosa    | " << s1 << " | 20  | " << s1 * 20 << endl;
    }
    if (d1) {
        cout << "Dosa      | " << d1 << " | 35  | " << d1 * 35 << endl;
    }
    if (t1) {
        cout << "Tea       | " << t1 << " | 10  | " << t1 * 10 << endl;
    }
    if (c1) {
        cout << "Coffee    | " << c1 << " | 50  | " << c1 * 50 << endl;
    }
    if (i1) {
        cout << "Ice Cream | " << i1 << " | 30  | " << i1 * 20 << endl;
    }
}

void bill() {
    cout << " Item      | Qty  | Rate | Total" << endl;
    cout << "--------------------------------------" << endl;
    table();
    cout << "--------------------------------------" << endl;
}

//Function to check out from the hotel

void check_out()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|       Check-Out        |\n";
	cout<<"\t--------------------------\n";
	int che,n,sbill;
	int ch=0;
	for(int q=0;q<c;q++)//To check no of reservation
	{
		if(check[q]==true)
		ch++;
	}
	bool found=false;
	if(ch==0)
	cout<<"There is no reservation in hotel"<<endl;
	else
	{
		cout<<"Enter the room no you want to check out:";
	    cin>>che;
	    for(int q=0;q<c;q++)
	    {
	    	if(room[q]==che)
	    	{
	    		if(check[q]==false)
	    		{
	    		cout<<"There is no reservation in this room"<<endl;
	    		found=true;
	        	}
	    		else
	    		{
	    			cout<<"No of days customer stayed:"<<date[q];
	    			n=date[q];
	    			printf("\n::Which food Customer odered during stay::\n");
                    order();
                    system("cls");
	    			cout<<"\t--------------------------\n";
	                cout<<"\t|    Check-Out Detail    |\n";
	                cout<<"\t--------------------------\n";
	    			cout<<"\nCustomer Name : "<<names[q];
	    			cout<<"\nRoom Number : "<<room[q];
	    			cout<<"\nAddress : "<<adress[q];
	    			cout<<"\nPhone : "<<phone[q]<<endl;
	    			bill();
	    			cout<<"The bill of food is : "<<tBill<<endl;
	    			sbill=(rent[q]*n)+tBill;
	    			cout<<"\nTotal Amount Due : "<<sbill<<" /";
	    			cout<<"\nAdvance Paid: "<<A_pay[q]<<" /";
	    			cout<<"\n*** Total Payable: "<<sbill-A_pay[q]<<endl;
	    			check[q]=false;
	    			found=true;
	    			break;
				}
	    		
			}
		}
		if(found==false)
		cout<<"Room not found \n";
	   
	}
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

//Function to find Summmary

void summary()
{
	system("cls");
	cout<<"\t--------------------------\n";
	cout<<"\t|     Guest Summary      |\n";
	cout<<"\t--------------------------\n";
	int ch=0;
	for(int q=0;q<c;q++)//To check no of reservation
	{
		if(check[q]==true)
		ch++;
	}
	if(ch==0)
	cout<<"There is no reservation in hotel"<<endl;
	else
	{
		for(int e=0;e<c;e++)
    	{
		if(check[e]==true)
		{
			cout<<"Customer Name  :"<<names[e]<<endl;
			cout<<"Room Number  :"<<room[e]<<endl;
			cout<<"Address  :"<<adress[e]<<endl;
			cout<<"Phone No  :"<<phone[e]<<endl;
			cout<<"---------------------------------\n";
		}
	    }
	}
	char c;
	cout<<"Enter any key to continue :";
	cin>>c;
}

int date_enter()
{
	int date1,date2,date_;
	date1=date2=date_=0;
	cout<<"Enter from date (day,mont,year) :";
	cin>>day1>>m1>>y1;
	cout<<"Enter to date (day,mont,year):";
	cin>>day2>>m2>>y2;
	date1=date_calc(day1,m1,y1);
	date2=date_calc(day2,m2,y2);
	if(y2>y1)
	{
		for(int year=y1;year<y2;year++)
		{
		if(( year%4==0 && year%100) || (year%400==0))
		date2=date2+366;
		else
		date2=date2+365;
		}	
	}
	date_=date2-date1;
	return date_;
}

int date_calc(int day,int m,int y)
{
	int days=0;
	int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(( y%4==0 && y%100 !=0) || (y%400==0))
	year[1]=29;
	for (int c=1;c<m;c++)
	{
		days=days+year[c];
	}
	days=days+day;
	return days;
}
//Function to change color
void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //This is used to get the handle to current output buffer.
     
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.
     
     COORD coord = {0, 0};
                      //This is a return value indicating how many characterss were written
                        //   It is not used but we need to capture this since it will be
                          //   written anyway (passing NULL causes an access violation).
                          
     DWORD count;

                                   //This is a structure containing all the console info
                          // It is used here to find the size of the console.
                          
     CONSOLE_SCREEN_BUFFER_INFO csbi;
                     //Now the current color will be set by this handle
                     
     SetConsoleTextAttribute(hStdOut, wColor);
     
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                              //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                              //This will set our cursor position for the next print statement
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

//Function to print hotel name
void printLargeText(const std::string& text) {
    string line1, line2, line3, line4, line5;

    // Traditional for loop with explicit condition
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (c == ' ') {
            line1 += "   ";
            line2 += "   ";
            line3 += "   ";
            line4 += "   ";
            line5 += "   ";
        } else {
            switch (toupper(c)) {
                case 'A':
                    line1 += "   A  ";
                    line2 += "  A A ";
                    line3 += " AAAAA";
                    line4 += " A   A";
                    line5 += " A   A";
                    break;
                case 'D':
                    line1 += " DDDD ";
                    line2 += " D   D";
                    line3 += " D   D";
                    line4 += " D   D";
                    line5 += " DDDD ";
                    break;
                case 'E':
                    line1 += " EEEEE";
                    line2 += " E    ";
                    line3 += " EEEEE";
                    line4 += " E    ";
                    line5 += " EEEEE";
                    break;
                case 'H':
                    line1 += " H   H";
                    line2 += " H   H";
                    line3 += " HHHHH";
                    line4 += " H   H";
                    line5 += " H   H";
                    break;
                case 'I':
                    line1 += " IIIII";
                    line2 += "   I  ";
                    line3 += "   I  ";
                    line4 += "   I  ";
                    line5 += " IIIII";
                    break;
                case 'L':
                    line1 += " L    ";
                    line2 += " L    ";
                    line3 += " L    ";
                    line4 += " L    ";
                    line5 += " LLLLL";
                    break;
                case 'O':
                    line1 += "  OOO ";
                    line2 += " O   O";
                    line3 += " O   O";
                    line4 += " O   O";
                    line5 += "  OOO ";
                    break;
                case 'P':
                    line1 += "\t\t\t  PPPP ";
                    line2 += "\t\t\t  P   P";
                    line3 += "\t\t\t  PPPP ";
                    line4 += "\t\t\t  P    ";
                    line5 += "\t\t\t  P    ";
                    break;
                case 'R':
                    line1 += " RRRR ";
                    line2 += " R   R";
                    line3 += " RRRR ";
                    line4 += " R  R ";
                    line5 += " R   R";
                    break;
                case 'S':
                    line1 += "  SSS ";
                    line2 += " S    ";
                    line3 += "  SSS ";
                    line4 += "     S";
                    line5 += "  SSS ";
                    break;
                case 'T':
                    line1 += " TTTTT";
                    line2 += "   T  ";
                    line3 += "   T  ";
                    line4 += "   T  ";
                    line5 += "   T  ";
                    break;
                default:
                    line1 += "     ";
                    line2 += "     ";
                    line3 += "     ";
                    line4 += "     ";
                    line5 += "     ";
                    break;
            }
        }
    }

    cout << line1 << "\n" << line2 << "\n" << line3 << "\n" << line4 << "\n" << line5 << std::endl;
}

//Function to print Names 3 time
void display()
{
	string text = "Paradise Hotel";
    ClearConsoleToColors(4,0);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    printLargeText(text);
    Sleep(1000);
    system("cls");
    Sleep(150);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	printLargeText(text);
    Sleep(1000);
    system("cls");
    Sleep(150);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    printLargeText(text);
    Sleep(3000);
    system("cls");
 }
