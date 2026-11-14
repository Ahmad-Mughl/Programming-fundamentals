//22L-7699
//22L-7666
//PF LAB PROJECT
//GROCERY STORE MANAGEMENT SYSTEM

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main_header(){
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t           WELCOME TO MF-SUPERMART SYSTEM           " << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;
}

char main_options(char op){
	cout << "\t\t------------------------" << endl;
	cout << "\t\tMAIN MENU OPTIONS:" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t1.Admin" << endl;
	cout << "\t\t2.Employee" << endl;
	cout << "\t\t3.Exit" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tEnter your Option: ";
	cin >> op;
	cout << endl;
	return op;
}

int admin_options(int a){
	string username;
	string password;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t\tUsername: ";
	cin >> username; //ENTER mfspmrt
	cout << "\t\t\tPassword: ";
	cin >> password; //ENTER a1b2c3d4
	cout << "\t\t------------------------" << endl;
	cout << endl;
	if (username == "mfspmrt" && password == ""){
		cout << "\t\t------------------------" << endl;
		cout << "\t\t1.Add new product" << endl;
		cout << "\t\t2.Delete an Item" << endl;
		cout << "\t\t3.Assign prices" << endl;
		cout << "\t\t4.View product quantity" << endl;
		cout << "\t\t5.Update quantity" << endl;
		cout << "\t\t6.View prices of items" << endl;
		cout << "\t\t7.Exit" << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\t\tYour Option: ";
		cin >> a;
		cout << endl;
	}
	while (username != "mfspmrt" || password != "a1b2c3d4")
	{
		cout << "You have entered a wrong password or wrong user name! " << endl;
		cout << "Please entered the right password and right user name! " << endl;
		cout << "Enter the right user name... ";
		cin >> username;
		cout << "Enter the right password... ";
		cin >> password;
		cout << "\t\t------------------------" << endl;
		cout << "\t\t1.Add new product" << endl;
		cout << "\t\t2.Delete an Item" << endl;
		cout << "\t\t3.Assign prices" << endl;
		cout << "\t\t4.View product quantity" << endl;
		cout << "\t\t5.Update quantity" << endl;
		cout << "\t\t6.View prices of items" << endl;
		cout << "\t\t7.Exit" << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\t\tYour Option: ";
		cin >> a;
		cout << endl;
	}
	return a; 
}

int employee_options(int e){
	cout << "\t\t------------------------" << endl;
	cout << "\t\t1.Create a Bill" << endl;
	cout << "\t\t2.Check the price" << endl;
	cout << "\t\t3.Check the quantity" << endl;
	cout << "\t\t4.Exit" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t\tYour Option: ";
	cin >> e;
	cout << endl;
	if (e == '4'){
		cout << "\t\t\tTHANK YOU FOR BEING AT MF-SUPERMART" << endl;
		cout << endl;
	}
	return e;
}

void outro(char o){
	cout << "\t\t\t\tEND OF SYSTEM PROGRAM." << endl;
	cout << endl;
}

void file_read(int id[], string name[], string weight[], string mfg_date[], string exp_date[], float price[], int quantity[]){

	fstream read;
	int i = 0;
	read.open("new.txt");
	while (!read.eof()){

		read >> id[i];
		read >> name[i];
		read >> weight[i];
		read >> mfg_date[i];
		read >> exp_date[i];
		read >> price[i];
		read >> quantity[i];
		i++;
	}
}

int main(){

	main_header();

	int id[3];
	string name[3];
	string weight[3];
	string mfg_date[3];
	string exp_date[3];
	float price[3];
	int quantity[3];


	char op = '0';
	op = main_options(op);
	int pro;

	if (op == '1'){
		int a = 0;
		int b = admin_options(a);
		int loop = 0;
		while (loop = 0){
			if (b == 1){
				cout << "\t\tEnter the product to be added: ";
				cin >> pro;
			}
			if (b == 2){
				cout << "\t\tEnter the product to be deleted: ";
				cin >> pro;
			}
			if (b == 3){
				cout << "\t\tEnter the product to be assigned with the price:";
				cin >> pro;
				float price1;
				for (int i = 0; i < 3; i++){
					if (pro == id[i]){
						cout << "\t\tEnter the price";
						cin >> price1;
						price[i] = price1;
					}
				}
			}
			if (b == 4){
				cout << "\t\tEnter the product you want to view info about: ";
				cin >> pro;
				for (int i = 0; i < 3; i++){
					if (pro == id[i]){
						cout << "\t\t\tProduct quantity: " << quantity[i];
					}
				}
			}
			if (b == 5){
				cout << "\t\tEnter the product to update quantity:";
				cin >> pro;
				float quantity1;
				for (int i = 0; i < 50; i++){
					if (pro == id[i]){
						cout << "\t\t\tEnter the quantity";
						cin >> quantity1;
						quantity[i] = quantity1;
					}
				}
			}
			if (b == 6){
				cout << "\t\tEnter the product you want to view info about: ";
				cin >> pro;
				for (int i = 0; i < 50; i++){
					if (pro == id[i]){
						cout << "\t\t\tProduct price: " << price[i];
					}
				}
			}
			if (b == 7){
				cout << "\t\t\tTHANK YOU FOR BEING AT MF-SUPERMART" << endl;
				loop++;
			}
			loop++;
		}
	}

	if (op == '2'){
		int e = 0;
		employee_options(e);
		cin >> e;
		if (e == 1){
			cout << "\t***    MF-SUPERMART BILLING    ***" << endl;
			cout << "\t\tProduct: ";
			cin >> pro;
			cout << "\t\tPrice: " << price[5];
			cout << "\t\tQuantity: " << quantity[5];
			cout << endl;
			cout << "\tTHANK YOU FOR PURCHASING!\tWE WOULD BE DELIGHTED TO SEE YOU AGAIN!" << endl;
			cout << endl;
		}
	}
	if (op =='3'){
		cout << "\t\t\tTHANK YOU FOR BEING AT MF-SUPERMART" << endl;
		cout << endl;
		char out = 0;
		outro(out);
	}
	
	cout << endl;
	file_read(id, name, weight, mfg_date, exp_date, price, quantity);
	return 0;
}