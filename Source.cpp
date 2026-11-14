#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int naam = 50;

void sale_function(string product_name[naam], int product_number[naam], float product_weight[naam], int product_MFG[naam]
    , int product_EXP[naam], int product_price[naam], int product_quantity[naam]) {


    int total_price = 0;
    int no_of_purchasing_items = 0;
    int quantity_purchased;
    int data[naam];
    int a = 0;
    int p_id;

    cout << "please enter the number of items you want to purchase: ";
    cin >> no_of_purchasing_items;

    for (int count = 0; count < no_of_purchasing_items; count++) {
        cout << "Product ID: ";
        cin >> p_id;

        for (int i = 0; i < naam; i++) {
            if (p_id == product_number[i]) {
                cout << "Quantity = ";
                cin >> quantity_purchased;
                if (product_quantity[i] >= quantity_purchased) {
                    product_quantity[i] = product_quantity[i] - (quantity_purchased);
                    cout << "succesfully purchased " << quantity_purchased << product_name[i] << endl;
                    total_price = total_price + (quantity_purchased * product_price[i]);
                    cout << endl;
                    data[a] = i;
                    a++;
                }

                else {
                    cout << "not enough quantity available" << endl;
                }

                if (product_number[i] < 0) {
                    cout << "item not available" << endl;
                }
            }
        }
    }

    cout << "total price = Rs." << total_price << endl;

    cout << "Thank you for using our services\nWe would be delighted to see you again!" << endl;

    ofstream out;

    out.open("invoice.txt");

    if (out.is_open()) {
        out << "Name" << "\t" << "Product ID" << "\t" << "Price" << "\t" << "Quantity" << endl;
        for (int i = 0; i < no_of_purchasing_items; i++) {

            out << product_name[data[i]] << " ";

            out << product_number[data[i]] << " ";

            out << product_price[data[i]] << " ";

            out << quantity_purchased << " " << endl;
        }
    }
    out.close();
}










void new_item(string product_name[], int product_number[], float product_weight[], int product_MFG[], int product_EXP[], int product_price[], int product_quantity[], int& i) {


    int a = 0;

    int count = 0;

    ofstream out;

    cout << "please enter the number of items you want to add: ";
    int choice = 0;
    cin >> choice;
    for (int counter = 0; counter < choice; counter++) {

        if (choice != 0) {

            cout << "please enter the NAME of product number " << counter + 1 << " : ";
            getline(cin, product_name[i + 1], '/');

            cout << "please enter the PRODUCT CODE of item number " << counter + 1 << " : ";
            cin >> product_number[i + 1];

            cout << "please enter the WEIGHT of the item number " << counter + 1 << " : ";
            cin >> product_weight[i + 1];

            cout << "please enter the MANUFACTURING DATE of the item number " << counter + 1 << " : ";
            cin >> product_MFG[i + 1];

            cout << "please enter the EXPIRY DATE of the item number " << counter + 1 << " : ";
            cin >> product_EXP[i + 1];

            cout << "please enter the PRICE of the item number " << counter + 1 << " : ";
            cin >> product_price[i + 1];

            cout << "please enter the QUANTITY of the item number " << counter + 1 << " : ";
            cin >> product_quantity[i + 1];


            a++;

            cout << endl;
            cout << endl;
            cout << endl;

        }


        out.open("items.txt", ios::app);

        if (out.is_open()) {
            out << product_name[i + 1] << "/ ";

            out << product_number[i + 1] << " ";

            out << product_weight[i + 1] << " ";

            out << product_MFG[i + 1] << " ";

            out << product_EXP[i + 1] << " ";

            out << product_price[i + 1] << " ";

            out << product_quantity[i + 1] << " ";

            count++;
        }
        out.close();

    }

}


void delete_item(string product_name[naam], int product_number[naam], float product_weight[naam], int product_MFG[naam], int product_EXP[naam], int product_price[naam], int product_quantity[naam]) {

    int cj = 0;
    cout << "enter the product number to delete:  ";
    cin >> cj;

    ofstream out;

    for (int counter = 0; counter < cj; counter++) {
        if (product_number[counter] == cj) {
            product_name[counter] = " ";
            product_number[counter] = 0;
            product_weight[counter] = 0;
            product_MFG[counter] = 0;
            product_EXP[counter] = 0;
            product_price[counter] = 0;
            product_quantity[counter] = 0;
        }
        fstream clear;

        clear.open("item2", ios::trunc);

        clear.close();

        out.open("item2", ios::out);

        if (out.is_open()) {
            out << product_name[counter] << " ";

            out << product_number[counter] << " ";

            out << product_weight[counter] << " ";

            out << product_MFG[counter] << " ";

            out << product_EXP[counter] << " ";

            out << product_price[counter] << " ";

            out << product_quantity[counter] << " ";


        }
        out.close();


    }
}


void update_price(int product_number[naam], int product_price[naam]) {


    int updated_price = 0;

    cout << "please enter the product code for the new price: ";
    int choice = 0;
    cin >> choice;

    cout << "please enter the updated price: ";
    cin >> updated_price;

    for (int counter = 0; counter < 50; counter++) {

        if (product_number[counter] == choice) {
            product_price[counter] = updated_price;
        }
    }
}


void update_mfg_date(int product_number[naam], int product_MFG[naam]) {

    int updated_mf_date = 0;

    cout << "please enter the product code for the new price: ";
    int choice = 0;
    cin >> choice;

    cout << "please enter the updated price: ";
    cin >> updated_mf_date;

    for (int counter = 0; counter < 50; counter++) {

        if (product_number[counter] == choice) {
            product_MFG[counter] = updated_mf_date;
        }
    }
}

void update_exp_date(int product_number[], int product_EXP[]) {

    int updated_exp_date = 0;

    cout << "please enter the product code for the new price: ";
    int choice = 0;
    cin >> choice;

    cout << "please enter the updated price: ";
    cin >> updated_exp_date;

    for (int counter = 0; counter < 50; counter++) {

        if (product_number[counter] == choice) {
            product_EXP[counter] = updated_exp_date;
        }
    }
}




void search_price(int product_number[], int product_price[]) {

    int search_price;
    cout << "enter the product number to search the price for:  ";
    cin >> search_price;


    for (int counter = 0; counter < naam; counter++) {

        if (product_number[counter] == search_price) {
            cout << product_price[counter] << ".Rs" << endl;
        }
    }
}

void update_quantity(int product_number[], int product_quantity[]) {

    int updated_quantiy = 0;


    cout << "please enter the product code for the new price: ";
    int choice = 0;
    cin >> choice;

    cout << "please enter the updated price: ";
    cin >> updated_quantiy;

    for (int counter = 0; counter < 50; counter++) {

        if (product_number[counter] == choice) {
            product_quantity[counter] = updated_quantiy;
        }
    }
}

void search_quanity(int product_number[], int product_quantity[]) {

    int search_q;
    cout << "enter the product number to search the price for:  ";
    cin >> search_q;


    for (int counter = 0; counter < naam; counter++) {

        if (product_number[counter] == search_q) {
            cout << product_quantity[counter] << ".Rs" << endl;
        }
    }
}

//void sale_function(string product_name[naam], int product_number[naam],
//    float product_weight[naam], int product_MFG[naam], int product_EXP[naam], int product_price[naam],
//    int product_quantity[naam]) {
//
//    cout << "Product ID: ";
//    int p_id;
//    cin >> p_id;
//    int quantity_purcahsed;
//    for (int i = 0; i < 50; i++) {
//        if (p_id == product_number[i]) {
//            cout << "Quantity = ";
//            cin >> quantity_purcahsed;
//            product_quantity[i] = product_quantity[i] - quantity_purcahsed;
//        }
//    }


//
//}

int main() {

    string product_name[naam];
    int product_number[naam];
    float product_weight[naam];
    int product_MFG[naam];
    int product_EXP[naam];
    int product_price[naam];
    int product_quantity[naam];

    int handling = 0;

    int b = handling;

    ifstream in;
    in.open("items.txt");

    while (!in.eof()) {
        getline(in, product_name[handling], '/');
        in >> product_number[handling];
        in >> product_weight[handling];
        in >> product_MFG[handling];
        in >> product_EXP[handling];
        in >> product_price[handling];
        in >> product_quantity[handling];

        handling++;
    }
    in.close();

    cout << "\t\t\tPlease select from the following options: " << endl;
    cout << "\t\t\t1) Insert new item" << endl;
    cout << "\t\t\t2) Delete an item" << endl;
    cout << "\t\t\t3) Update quantity" << endl;
    cout << "\t\t\t4) Update Mfg dates" << endl;
    cout << "\t\t\t5) Update Exp dates" << endl;
    cout << "\t\t\t6) Update price" << endl;
    cout << "\t\t\t7) Search the price of an item" << endl;
    cout << "\t\t\t8) Search the remaining quantity of an item" << endl;
    cout << "\t\t\t9) Sale Item" << endl;

    int option;

    cout << endl << "Please Enter your Choice = ";
    cin >> option;


    if (option == 1) {
        new_item(product_name, product_number, product_weight, product_MFG, product_EXP, product_price, product_quantity, b);
    }
    if (option == 2) {
        delete_item(product_name, product_number, product_weight, product_MFG, product_EXP, product_price, product_quantity);
    }
    if (option == 3) {
        update_quantity(product_number, product_quantity);
    }
    if (option == 4) {
        update_mfg_date(product_number, product_MFG);
    }
    if (option == 5) {
        update_exp_date(product_number, product_EXP);
    }
    if (option == 6) {
        update_price(product_number, product_price);
    }
    if (option == 7) {
        search_price(product_number, product_price);
    }
    if (option == 8) {
        search_quanity(product_number, product_quantity);
    }
    /*  if (option == 9) {
          sale_function(product_name, product_number, product_weight, product_MFG, product_EXP, product_price, product_quantity);
      }
      */






    return 0;
}