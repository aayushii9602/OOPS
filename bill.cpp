// this is edited by Aayushi on branch changes
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

// vector<pair<string, string>> p;
// ll flag = 0;

// Function:void login
// Description:creates an account if your are a new user, or else logs you in
// Input param:interger
// Return Type:NULL
/*
void login()
{

    // vector<string, char> v;

    // cout << "press 1 to login\n";
    // cout << "Press 2 to register\n";
    // cout << "Press 3 to exit\n";
    // ll x;
    // cin >> x;
    while (1)
    {
        cout << "press 1 to login\n";
        cout << "Press 2 to register\n";
        cout << "Press 3 to exit\n";
        ll x;
        cin >> x;
        if (x == 1)
        {
            string username, password;
            cout << "Enter your username\n";
            cin >> username;
            char code;
            cout << "Enter A, if you are admin \nEnter E if you are ann epmloyee\nEnter U if you are a user";
            cin >> code;
            cout << "Enter your password\n";
            cin >> password;
            // v.push_back(username, code);

            ll f = 0;
            if (f)
            {
                flag = 1;
                cout << "Wait we will terminate you to your account\n";

                // return v[0];
                cout << "Wait we will terminate you to your account\n";
            }
            else
            {
                cout << "you have entered the wrong password or username\n";
            }
        }
        else if (x == 2)
        {
            string username, password, password1;
            char code;
            cout << "Enter A, if you are admin \nEnter E if you are ann epmloyee\nEnter U if you are a user";
            cin >> code;
            cout << "enter new username:\n";
            cin >> username;
            while (1)
            {
                cout << "enter your password\n";
                cin >> password;
                cout << "Re-enter your password\n";
                cin >> password1;
                if (password == password1)
                {
                    if (code == 'A')
                    {
                        ofstream MyFile("Admin.txt");
                        MyFile << "username: " << username << "\tPassword: " << password;
                        // MyFile.close();
                        cout << username << " You have successfully registered to the portal\n";
                        break;
                    }
                    else if (code == 'E')
                    {
                        ofstream MyFile("Employee.txt");
                        MyFile << "username: " << username << "\tPassword: " << password;
                        // MyFile.close();
                        cout << username << " You have successfully registered to the portal\n";
                        break;
                    }
                    else if (code == 'U')
                    {
                        ofstream MyFile("User.txt");
                        MyFile << "username: " << username << "\tPassword: " << password;
                        // MyFile.close();
                        cout << username << " You have successfully registered to the portal\n";
                        break;
                    }
                }
                else
                {
                    cout << "password and re-entered password doesnt match \n";
                    cout << "Do you want to create an account?\n, If yes the press Y or else press N\n";
                    char x;
                    cin >> x;
                    if (x == 'Y')
                        continue;
                    else
                        break;
                }
            }
        }
        else
        {
            // return;
            exit(0);
        }
    }
}
*/

class Employee
{
private:
    string phoneNumber;
    string area;

public:
    string userId;
    string name;
    float amountCommercial;
    float amountDomestic;

    // Default Constructor

    Employee()
    {
        phoneNumber = "nil";
        userId = "nil";
        name = "nil";
        area = "nil";
        amountCommercial = 0.0;
        amountDomestic = 0.0;
    }

    // Parameterized Constructor

    Employee(string p, string id, string name, string area, float amtc, float amtd)
    {
        phoneNumber = p;
        userId = id;
        this->name = name;
        this->area = area;
        amountCommercial = amtc;
        amountDomestic = amtd;
    }

    // Function:calculateBillOfCommercial
    // Description:calculates the Bill that is to be paid by Commercial user based on the number of units the user have consumed
    // Input param:long long int numberOfUnitsUsed
    // Return Type:float

    float calculateBillOfCommercial(ll numberOfUnitsUsed)
    {
        // cout << amountCommercial << endl;
        float calculatedAmount = amountCommercial * numberOfUnitsUsed * 1.0;
        return calculatedAmount;
    }

    // Function:calculateBillOfDomestic
    // Description:calculates the Bill that is to be paid by Domestic user based on the number of units the user have consumed
    // Input param:long long int numberOfUnitsUsed
    // Return Type:float

    float calculateBillOfDomestic(ll numberOfUnitsUsed)
    {
        float calculatedAmount = amountDomestic * numberOfUnitsUsed * 1.0;
        // adminBankBalance += calculatedAmount;
        // UpdateBalance(calculatedAmount);
        return calculatedAmount;
    }

    // Function:UpdateCommercialAmount
    // Description:update the amount per unit of a commercial user
    // Input param:amount that has incremented or decremented from amount per unit of a commercial user
    // Return Type:NULL

    void UpdateCommercialAmount(ll x)
    {
        amountCommercial += x;
    }

    // Function:UpdateDomesticAmount
    // Description:update the amount per unit of a Domestic user
    // Input param:amount that has incremented or decremented from the amount per unit of a Domestic user
    // Return Type:NULL

    void UpdateDomesticAmount(ll x)
    {
        amountDomestic += x;
    }

    // Function:printDetails
    // Description: Prints the details of the Employee
    // Input param:  NULL
    // Return Type:  NULL
    void printDetails()
    {
        cout << "NAME         :" << name << endl;
        cout << "USER-ID      :" << userId << endl;
        cout << "AREA         :" << area << endl;
    }

    // void viewCommercial(vector<CommercialUser> C, ll startpoint, ll endpoint)
    // {
    //     for (ll i = startpoint; i < endpoint; i++)
    //     {
    //         cout << "YEs\n";
    //     }
    // }
    friend class Admin;
};

class Admin
{

private:
    string phoneNumber;
    float adminBankBalance;

public:
    string userId;
    string name;
    Employee *Emp;

    // Default Constructor

    Admin()
    {
        phoneNumber = "nil";
        userId = "nil";
        name = "nil";
        adminBankBalance = 0.0;
    }

    // Parameterized Constuctor

    Admin(string p, string id, string n, float abb)
    {
        phoneNumber = p;
        userId = id;
        name = n;
        adminBankBalance = abb;
    }

    // Function:printDetail
    // Description: Prints the details of the Admin
    // Input param:  NULL
    // Return Type:  NULL

    void printDetail()
    {
        cout << "Admin Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "UserId: " << userId << endl;
    }

    void UpdateBalance(float dueAmmount)
    {
        adminBankBalance += Emp->calculateBillOfCommercial(77);
    }

    void view(vector<Employee> E, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            E[i].printDetails();
            cout << endl;
        }
    }
    // friend class Employee;
};

class User
{
private:
    string phoneNumber;

public:
    string userId;
    string name;
    string address;
    float bankBalance;
    float dueAmount;
    char code;
    GenerateBill *B;

    // Default Constructor

    User()
    {
        phoneNumber = "nil";
        userId = "nil";
        name = "nil";
        address = "nil";
        bankBalance = 0.0;
        dueAmount = 0.0;
        code = 'N';
    }

    // Parameterized Constructor

    User(string p, string id, string n, string address, float bb, char c)
    {
        phoneNumber = p;
        userId = id;
        name = n;
        this->address = address;
        bankBalance = bb;
        dueAmount = 0;
        code = c;
    }

    // Function:printDetails
    // Description: Prints the details of the User
    // Input param:  NULL
    // Return Type:  NULL
    // Pure virtual function

    virtual void printDetails() = 0;
    virtual void payBill(GenerateBill &B) {}
    friend class Employee;
};

class CommercialUser : public User
{
public:
    ll numberOfUnitsUsed;
    GenerateBill *B;

    // Default Constructor

    CommercialUser() : User()
    {
    }

    // Parameterized Constructor

    CommercialUser(string p, string id, string n, string address, float bb, char c, ll units) : User(p, id, n, address, bb, c), numberOfUnitsUsed(units) {}

    // Function:printDetails
    // Description: Prints the details of the Commercial User
    // Input param:  NULL
    // Return Type:  NULL

    void printDetails()
    {
        cout << "NAME         :" << name << endl;
        cout << "USER-ID      :" << userId << endl;
        cout << "ADDRESS      :" << address << endl;
        cout << "BANK BALANCE :" << bankBalance << endl;
    }

    // Function:payBill
    // Description: amount to be paid is calculated using calculateBillOfCommercial function and if the bank balance is greater than the due amount, then the user pays the bill
    // Input param:  NULL
    // Return Type:  NULL
    void payBill(GenerateBill &B)
    {
        // cout << numberOfUnitsUsed << endl;
        dueAmount = B.AmountOfCommercial(this->numberOfUnitsUsed);
        cout << "You need to pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO\n";
        ll x;
        cin >> x;
        // exception handler
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                bankBalance -= dueAmount;
                cout << "Thanks for paying the bill\n";
            }
            else
            {
                cout << "You have insufficient balance\n";
            }
        }
        else
        {
            cout << "Please pay the electricity billl as soon as possible\n";
        }
    }

    friend class User;

    // friend class Employee;
};

class DomesticUser : public User
{
public:
    ll numberOfUnitsUsed;
    GenerateBill *B;

    // Default Constructor

    DomesticUser() : User() {}

    // Parameterized Constructor

    DomesticUser(string p, string id, string n, string address, float bb, char c, ll units) : User(p, id, n, address, bb, c), numberOfUnitsUsed(units) {}

    // Function:printDetails
    // Description: Prints the details of the Domestic User
    // Input param:  NULL
    // Return Type:  NULL

    void printDetails()
    {
        cout << "NAME         :" << name << endl;
        cout << "USER-ID      :" << userId << endl;
        cout << "ADDRESS      :" << address << endl;
        cout << "BANK BALANCE :" << bankBalance << endl;
    }

    // Function:payBill
    // Description: amount to be paid is calculated using calculateBillOfDomestic function and if the bank balance is greater than the due amount, then the user pays the bill
    // Input param:  NULL
    // Return Type:  NULL
    void payBill(GenerateBill &B)
    {
        // cout << numberOfUnitsUsed << endl;
        // dueAmount = AmountOfDomestic(&B);
        // dueAmount = 0.0;
        dueAmount = B.AmountOfDomestic(this->numberOfUnitsUsed);
        cout << "You need ot pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO";
        ll x;
        cin >> x;
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                bankBalance -= dueAmount;
                cout << "Thanks for paying the bill\n";
            }
            else
            {
                cout << "You have insufficient balance\n";
            }
        }
        else
        {
            cout << "Please pay the electricity billl as soon as possible\n";
        }
    }

    friend class User;
};

class GenerateBill
{
public:
    float calculateAmountOfUser = 0;

    GenerateBill()
    {
    }

    float AmountOfCommercial(ll UnitsUsed)
    {
        if (UnitsUsed <= 50)
        {
            calculateAmountOfUser = 50 * 15.75;
        }
        else if (UnitsUsed > 50 && UnitsUsed <= 65)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 17.0;
        }
        else if (UnitsUsed > 65 && UnitsUsed <= 100)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 17.85;
        }
        else if (UnitsUsed > 100)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 19.75;
        }
        return calculateAmountOfUser;
    }

    float AmountOfDomestic(ll UnitsUsed)
    {
        if (UnitsUsed <= 50)
        {
            calculateAmountOfUser = 50 * 15.75;
        }
        else if (UnitsUsed > 50 && UnitsUsed <= 65)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 17.0;
        }
        else if (UnitsUsed > 65 && UnitsUsed <= 100)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 17.85;
        }
        else if (UnitsUsed > 100)
        {
            calculateAmountOfUser = 50 * 15.75 + (UnitsUsed - 50) * 19.75;
        }
        return calculateAmountOfUser;
    }
};

int main()
{
    // login
    // vector<string, string> v;
    // v[0] = login();

    Admin Admin("9810896298", "ADMIN1", "Vasant Kumar", 190000.0);
    // Admin.printDetail();
    // Admin.view();

    vector<Employee> E;

    Employee E1("9959152837", "Empe1001", "Sumit Sharma", "Vidhyanagar", 22.4, 20.89);
    E.pb(E1);
    Employee E2("8923451910", "Empe1002", "Rekha Jain", "Vidhyanagar", 23.0, 22.9);
    E.pb(E2);
    Employee E3("7299035627", "Empe1003", "Kiran L H", "Vidhyanagar", 22.4, 21.5);
    E.pb(E3);
    Employee E4("9825367102", "Empe1004", "Shradha B ", "Vidhyanagar", 20.34, 20.11);
    E.pb(E4);
    Employee E5("9938710263", "Empe1005", "Hemant Rao", "Vidhyanagar", 21.9, 19.99);
    E.pb(E5);

    // ADMIN CAN VIEW EMPLOYEE DETAILS
    Admin.view(E, 0, 5);

    // Vector of commercial user objects
    // vector<CommercialUser> C;
    vector<User *> U;

    CommercialUser CU1("9826371820", "E1CU101", "somanath", "9-10, Bhagirath Industrial Esta", 9429.78, 'C', 77);
    U.pb(&CU1);
    CommercialUser CU2("7792235468", "E2CU102", "Shekhar", "5, Somasundara Mudali St,Parrys", 10345.8, 'C', 118);
    U.pb(&CU2);
    CommercialUser CU3("9825112230", "E3CU103", "Lata ", "47/48, Fm Cariappa Road", 20000.0, 'C', 380);
    U.pb(&CU3);
    CommercialUser CU4("7816352901", "E4CU104", "Muskan", "8b,Lindsay Street, New Market", 1730.0, 'C', 300);
    U.pb(&CU4);
    CommercialUser CU5("8127399830", "E5CU105", "Harish", "No 2, 2nd Main Road, Gandhinagar", 13092.0, 'C', 540);
    U.pb(&CU5);

    DomesticUser DU1("9755528687", "E1DU101", "Aravind Sama", "Govt. Ind Est, Charkop Naka,", 9429.78, 'D', 77);
    U.pb(&DU1);
    DomesticUser DU2("8555393361", "E2DU102", "Dhriti Dar", "G, Vardaan House, Darya Ganj", 10345.8, 'D', 118);
    U.pb(&DU2);
    DomesticUser DU3("7555110402", "E3DU103", "Manu Chaudhari ", "Khernagar, Kajal Plastics Near Uttam Book Depo, Bandra (east)", 20000.0, 'D', 380);
    U.pb(&DU3);
    DomesticUser DU4("9655585472", "E4DU104", "Abhinav Mody", "710, Mittal Towers, 7th Floor,a Wing M G Road, M G Road", 1730.0, 'D', 300);
    U.pb(&DU4);
    DomesticUser DU5("7555074534", "E5DU105", "Talika Gour", "8487, Arakashan Road, Pahar Ganj", 13092.0, 'D', 540);
    U.pb(&DU5);

    GenerateBill B;

    /*
    for (ll i = 0; i < U.size(); i++)
    {
        U[i]->printDetails();
        cout << "-------------------------------------------------------------------------------------\n";
    }
*/
    // vector<CommercialUser> VC2;
    // vector<CommercialUser> VC3;
    // vector<CommercialUser> VC4;
    // vector<CommercialUser> VC5;
    // for (ll i = 0; i < C.size(); i++)
    // {
    //     if (C[i].userId[1] == '1')
    //         VC1.pb(C[i]);
    //     else if (C[i].userId[1] == '2')
    //         VC2.pb(C[i]);
    //     else if (C[i].userId[1] == '3')
    //         VC3.pb(C[i]);
    //     else if (C[i].userId[1] == '4')
    //         VC4.pb(C[i]);
    //     else if (C[i].userId[1] == '5')
    //         VC5.pb(C[i]);
    // }

    // vector<vector<CommercialUser>> EC;
    // EC.pb(VC1);
    // EC.pb(VC2);
    // EC.pb(VC3);
    // EC.pb(VC4);
    // EC.pb(VC5);

    // Employee is trying to view the details of its user
    // for (ll i = 0; i < E.size(); i++)
    // {
    //     E[i].viewCommercial([i], 0, 5);
    // }

    for (ll i = 0; i < 0; i++)
    {
        cout << "before transaction:\n";
        U[i]->printDetails();
        if (U[i]->code == 'C')
            U[i]->payBill(B);
        else
            U[i]->payBill(B);
        cout << "after the transaction:\n";
        U[i]->printDetails();
        cout << "-------------------------------------------------------------------------------------\n";
        // cout << endl;
    }

    return 0;
}