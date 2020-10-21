#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>//ฟังก์ชันแปลตัวเลขเป้นหนังสือ
using namespace std;
int a;
void menu_bank();
void main_menu();
void deposit_1();
void Withdraw();
void Transfer_money();
void report_account();
void report_all();
string account[100][3] = {
						 {"001","Jiraporn ","Saving"},
						 {"002","Phanakron","Saving"},
						 {"003","Smith","Saving"},
						 };
float amount[100]={10000,20000,30000};
string report[100][4] ;
float balance[100];
float Money[100];
int index;
int main()
{	//หน้าแรก เมนูธนาคาร
	main_menu();
	system ("cls");
	return(0);
}
//รายการที่สามารถทำได้
void menu_bank()
{
	float money= 0;
	float deposit,withdraw,transfer;
	char menu;
	system("cls");

	cout << "Welcome "<< account[index][1] << endl;
	cout << "Type account : " << account[index][2] << endl;
	cout << "Account balance : "<<fixed<<setprecision(2) << amount[index] << endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "1.Deposit" << endl;
	cout << "2.Withdraw" << endl;
	cout << "3.Transfer" << endl;
	cout << "4.Report" << endl;
	cout << "5.Exit"<<endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	
	cout << "Please select a menu : " ;
	cin >> menu ;
		
		switch(menu) {
			case '1': 
				system ("cls");
				deposit_1();
				break;
		
			case '2':
				system ("cls");
				Withdraw();
				break;
			case '3': 
				system ("cls");
				Transfer_money();
				break;
			case '4':
				system ("cls");
				report_account();
				break;
			case '5':
				cout << "----Exit----\n";
				main_menu();
				break;
			default:
				cout << "Please try again.\n";
				menu_bank();
		}		
	
}


void main_menu()
{
	string ac_num;
	int balance;
	string nameaccount,deposit_type,type ;
	char menu,select1 ;
	bool pass = false, pass2 = true;
	string account_input;
	system ("cls");
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "\tWELCOME TO THE BANK\n";
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "1.Bank Services" << endl;
		cout << "2.Bank Report" << endl;
		cout << "3.Exit"<<endl;
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "Please select a Menu : " ;
		cin >> menu ;
		
		
		if(menu=='1')
		{
			//ล็อคอินเข้าเมนู
			cout << "Please enter account number : ";
			cin>>ac_num;

			for(int i = 0; i < 100; i++)
			{
				if (ac_num == account[i][0]) 
				{
					pass = true;
					index = i; //อ้างอิงตำแหน่งในอาเรยย์
				}
			}
			if (pass)
			{
				menu_bank();
			}
			else 
			{
				system ("cls");
				cout << "----Account not found--- " << endl;
				cout << "1.Register account\n";
				cout << "2.Back to menu \n";
				cout << "Enter menu : ";
				cin >> select1;
					switch (select1)
						{
							case '1':
								system ("cls");
								cout << "==========Register=============\n";
									for(int j = 0; j < 100; j++) 
									{
										if (account[j][0].empty())
										{	
											cout <<"Please enter account number :";
											cin >> account_input;
											for (int c = 0 ; c < 100 ; c++ )
											{
												if (account[c][0] == account_input)
												{
													pass2 = false; // ถ้าเจอให้ pass2 เป็นเท็จ
													break;
												}
											}
											if (pass2 == true)
											{
												cout << "Please enter username : ";
												cin >> account[j][1];
												cout << "Please enter type (Saving(S) | Fixed deposit (FD)) : ";
												cin>>type;
												if(type=="S" ||"s")
													type="Saving";
												if(type=="FD"||"fd"||"Fd"||"fD")
													type="Fixed deposit";

												account[j][2]=type;
												amount[j]= 0;
												account[j][0] = account_input;
											}
											else 
											{
												cout << "---This acount already used---"<<endl;
											}
											cout << "Press enter key to menu \n"<<endl;
											cin.get();
											cin.ignore();
											break;
										}
									}
								main_menu();
								break;
				
							case '2':
								main_menu();
								break;
							default	:
								main_menu();
				
						}
				
			}
			cout << setfill('-')<<setw(40)<<"-"<<endl;
		}

		else if (menu == '2')
		{
			system ("cls");
			report_all();
		}
		else if (menu == '3') 
		{
			cout << "----Exit----\n";
			exit(0);
		}
		else
		{
			cout << "Please try again.\n";
			main_menu();
		}
		
}
void deposit_1()
{
	float deposit;
	char select1;
	cout << "Deposit money : ";
	cin >> deposit;
	amount[index] += deposit;
	stringstream ss;
	ss << amount[index];
	for(int j = 0; j < 100; j++) 
	{
		if (report[j][0].empty())
		{	
			stringstream money;
			money << deposit;
			report[j][0] = account[index][0];
			report[j][1] = "Deposit"; //ประเภทในรายงาน
			Money[j] = deposit;
			balance[j] = amount[index];
			report[j][3] ="none";
			break;
		}
	}
	cout << "Your Balance is : " <<fixed<<setprecision(2)<< amount[index] << endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Would you like to make a new deposit ?: " << endl;
	cout << "1.Yes\n";
	cout << "2.Back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					deposit_1();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
				
			}
}
void Withdraw()
{
  float withdraw;
	char select1;
	bool pass=true;
	cout << "Withdraw money : ";
	cin >> withdraw;
	if(amount[index]< withdraw)
	{
		cout<<"Not enough money"<<endl;
		pass=false;
	}
	if(pass==true)
	{
		amount[index]-= withdraw;
		cout << "Your Balance is : "<<fixed<<setprecision(2) <<amount[index] << endl;
		stringstream ss;
		ss << amount[index];
		for(int j = 0; j < 100; j++) 
		{
			if (report[j][0].empty())
			{	
				stringstream money;
				money << withdraw ;
				report[j][0] = account[index][0];
				report[j][1] = "Withdraw"; //ประเภทในรายงาน
				Money[j] = withdraw;
				balance[j] = amount[index];
				report[j][3] ="none";
				break;
			}
		}
	}
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Wouldn you like to make a new withdraw ? : " << endl;
	cout << "1.Yes\n";
	cout << "2.back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					Withdraw();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
				
			}
}
void Transfer_money()
{
	float transfer;
	char select1;
	string acc;
	bool pass = false ;
	int acc_index;
	cout << "Transfer To Account :";
	cin >> acc;
	cout << "Transfer money : ";
	cin >> transfer;
	for(int i = 0; i < 100; i++)//หาทุก บัญชีว่าตรงกันไหม		
	{
				if (acc == account[i][0]) 
				{
					pass = true;
					acc_index = i; 
					break;
				}
	}
	if(pass==false)
	{
		cout << "----Account not found----\n";
	}	
	if(amount[index]< transfer) 
	{	cout<<"Not enough money"<<endl;
		pass=false;	
	}
	
	if (pass == true)
	{

		
		amount[index]-= transfer;
		amount[acc_index] += transfer;
		cout << "Your Balance is : " <<fixed<<setprecision(2)<< amount[index] << endl;
		stringstream ss;
		ss << amount[index];
		for(int j = 0; j < 100; j++) 
	{
		if (report[j][0].empty())
		{	
			stringstream money;
			money << transfer ;
			report[j][0] = account[index][0];
			report[j][1] = "Transfer"; //ประเภทในรายงาน
			Money[j] = transfer;
			balance[j] = amount[index];
			report[j][3] ="none";//บันทึกรายการว่าโอนไปให้คนนี้เท่าไหร่
			break;
		}
	}
	}
	
	
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Wouldn you like to make a new transfer ? : " << endl;
	cout << "1.Yes\n";
	cout << "2.Back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					Transfer_money();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
			}
}
void report_account()
{
	cout << setw(65)<<setfill (' ') << "REPORT " <<endl;
	cout << setw(20)<<"No."<<setw(20)<<" Type"<<setw(20)<< "Money" << setw(20) <<"Balance"<<setw(20)<< "Recipient"<<endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		if (report[i][0] == account[index][0])
		{
			cout << setw(20)<<setfill (' ')<< i+1 <<setw(20)<< setfill (' ')<< report[i][1] <<setw(20)<< setfill (' ')<<fixed<<setprecision(2) << Money[i] << setw(20)<< setfill (' ')<<fixed<<setprecision(2) << balance[i]; 
			cout << setw(20)<< setfill (' ') << report[i][3]<<endl;
		}
	}
	cout << "Press enter key to menu \n";
	cin.get();//รับค่าคีย์บอร์ด
	cin.ignore();//ให้กดปุ่มไหนก็ได้จะกลับไปหน้าแรก
	menu_bank();
}
void report_all()
{
	cout << "\n\n";
	cout << setw(65)<<setfill (' ') << "REPORT ALL" <<endl;
	cout <<endl;
	cout << setfill('=')<<setw(120)<<"="<<endl;
	cout << setw(20)<<setfill (' ')<<"No."<<setw(20)<<setfill (' ')<<"Account number";
	cout << setw(20)<<setfill (' ')<< "Name" << setw(20)<<setfill (' ') << "type"<< setw(20) << "Amount"<<endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		if(!account[i][0].empty())//เช็คว่ามันว่างหรือป่าว
		{
			cout << setw(20)<<setfill (' ')<< i +1 <<setw(20)<<setfill (' ')<< account[i][0] <<setw(20)<<setfill (' ')<< account[i][1] ;
			cout << setw(20)<<setfill (' ')<< account[i][2] << setw(20) <<setfill (' ')<<fixed<<setprecision(2) << amount[i] <<endl;
		}
		else
		{
		break;
		}
	}
	cout << setfill('=')<<setw(120)<<"="<<endl;
	cout << "Press enter key to menu \n";
	cin.get();//รับค่าคีย์บอร์ด
	cin.ignore();//ให้กดปุ่มไหนก็ได้จะกลับไปหน้าแรก
	main_menu();
}
