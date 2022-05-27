#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

double Amount = 0.0;

class InsufficientBalance
{
public:
};

class InvalidUnits
{
public:
};

class GenerateBill
{
public:
    double calculateAmountOfUser = 0.0;

    // Default Constructor
    GenerateBill()
    {
        calculateAmountOfUser = 0.0;
    }

    double CalculteamountOfCommercial(ll numberOfUnits, vector<float> v)
    {
        if (numberOfUnits <= 150)
        {
            calculateAmountOfUser = 150 * v[0];
        }
        else if (numberOfUnits > 150 && numberOfUnits <= 1000)
        {
            calculateAmountOfUser = 150 * v[0] + (numberOfUnits - 150) * v[1];
        }
        else if (numberOfUnits > 1000 && numberOfUnits <= 1700)
        {
            calculateAmountOfUser = 150 * v[0] + 850 * v[1] + (numberOfUnits - 1000) * v[2];
        }
        else if (numberOfUnits > 1700 && numberOfUnits <= 2500)
        {
            calculateAmountOfUser = 150 * v[0] + 850 * v[1] + 700 * v[3] + (numberOfUnits - 1700) * v[4];
        }
        return calculateAmountOfUser;
    }

    double CalculteamountOfDomestic(ll numberOfUnits, vector<float> v)
    {
        if (numberOfUnits <= 50)
        {
            calculateAmountOfUser = 50 * v[0];
        }
        else if (numberOfUnits > 50 && numberOfUnits <= 100)
        {
            calculateAmountOfUser = 50 * v[0] + (numberOfUnits - 50) * v[1];
        }
        else if (numberOfUnits > 100 && numberOfUnits <= 170)
        {
            calculateAmountOfUser = 50 * v[0] + (50) * v[1] + (numberOfUnits - 100) * v[2];
        }
        else if (numberOfUnits > 170 && numberOfUnits <= 250)
        {
            calculateAmountOfUser = 50 * v[0] + 50 * v[1] + 70 * v[2] + (numberOfUnits - 170) * v[3];
        }
        return calculateAmountOfUser;
    }
};

class User
{
private:
    string phoneNumber;

public:
    string userId;
    string name;
    string address;
    double bankBalance;
    double dueAmount;
    vector<float> amountPerSegmentOfUnitCommercial;
    vector<float> amountPerSegmentOfUnitDomestic;
    GenerateBill *B;

    // Default Constructor
    User()
    {
    }

    // Parameterized Constructor
    User(string phoneNumber, string userId, string name, string address, double bankBalance)
    {
        this->phoneNumber = phoneNumber;
        this->userId = userId;
        this->name = name;
        this->address = address;
        this->bankBalance = bankBalance;
        amountPerSegmentOfUnitCommercial.pb(7.99);
        for (ll i = 1; i < 5; i++)
        {
            amountPerSegmentOfUnitCommercial.pb(7.99 + 2 * i);
        }

        amountPerSegmentOfUnitDomestic.pb(5.06);
        for (ll i = 1; i < 4; i++)
        {
            amountPerSegmentOfUnitDomestic.pb(5.06 + 2 * i);
        }
    }

    // Function:printDetail
    // Description: Prints the details of the User
    // Input param:  NULL
    // Return Type:  NULL
    virtual void printDetails() = 0;
    virtual void payBillDomestic(GenerateBill &B) {}
    virtual void payBillCommercial(GenerateBill &B) {}

    friend class Employee;
};

class DomesticUser : public User
{
public:
    ll numberOfUnitsUsed;

    GenerateBill *B;

    // Default Constructor
    DomesticUser() : User(), numberOfUnitsUsed(0) {}

    // Parameterized Constructor
    DomesticUser(string p, string id, string n, string address, float bb, ll units) : User(p, id, n, address, bb), numberOfUnitsUsed(units) {}

    // Function:printDetail
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

    // Function:payBillDomestic
    // Description: calculates the total amount that is to be paid by the domestic user
    // Input param:  NULL
    // Return Type:  NULL
    void payBillDomestic(GenerateBill &B)
    {

        dueAmount = B.CalculteamountOfDomestic(this->numberOfUnitsUsed, amountPerSegmentOfUnitDomestic);
        cout << "You need ot pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO\n";
        ll x;
        cin >> x;
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                bankBalance -= dueAmount;
                Amount += dueAmount;
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
};

class CommercialUser : public User
{
public:
    ll numberOfUnitsUsed;
    GenerateBill *B;

    // Default Constructor
    CommercialUser() : User(), numberOfUnitsUsed(0) {}

    // Parameterized Constructor
    CommercialUser(string p, string id, string n, string address, float bb, ll units) : User(p, id, n, address, bb), numberOfUnitsUsed(units) {}

    // Function:printDetail
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

    // Function:payBillCommercial
    // Description: calculates the total amount that is to be paid by the Commercial user
    // Input param:  NULL
    // Return Type:  NULL
    void payBillCommercial(GenerateBill &B)
    {

        dueAmount = B.CalculteamountOfCommercial(this->numberOfUnitsUsed, amountPerSegmentOfUnitCommercial);
        cout << "You need ot pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO";
        ll x;
        cin >> x;
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                bankBalance -= dueAmount;
                Amount += dueAmount;
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
};

class Employee
{
private:
    string phoneNumber;
    string area;

public:
    string name;
    string employeeId;
    double amountOfCommericalUser;
    double amountOfDomesticUser;
    User *USER;

    // Default Constructor
    Employee()
    {
        phoneNumber = "nil";
        employeeId = "nil";
        name = "nil";
        area = "nil";
        amountOfCommericalUser = 0.0;
        amountOfDomesticUser = 0.0;
    }

    // Parameterized Constructor
    Employee(string phoneNumber, string employeeId, string name, string area, double amountOfCommericalUser, double amountOfDomesticUser)
    {
        this->phoneNumber = phoneNumber;
        this->employeeId = employeeId;
        this->name = name;
        this->area = area;
        this->amountOfCommericalUser = amountOfCommericalUser;
        this->amountOfDomesticUser = amountOfDomesticUser;
    }

    // Function:printDetail
    // Description: Prints the details of the Employee
    // Input param:  NULL
    // Return Type:  NULL

    void printDetails()
    {
        cout << "NAME         :" << name << endl;
        cout << "employee-ID  :" << employeeId << endl;
        cout << "AREA         :" << area << endl;
    }

    // Function:EmployeeViewsUser
    // Description: Employee can view all the users
    // Input param:  User vector, startpoint, endpoint
    // Return Type:  NULL
    void EmployeeViewsUser(vector<User *> U, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            U[i]->printDetails();
            cout << endl;
        }
    }

    // Function:changeTarrifOfCommercial
    // Description: Employee can change Tarrif Of Commercial User
    // Input param:  amount Per Segment Of Unit Commercial vector
    // Return Type:  NULL

    void changeTarrifOfCommercial(vector<float> &v)
    {
        for (ll i = 0; i < v.size(); i++)
        {
            cout << "Dou you want to change the value of first 150 units that is: " << v[i] << endl;
            cout << "Type 1 to change , Type 0 to continue\n ";
            ll x;
            cin >> x;
            if (x)
            {
                cout << "Enter the new amount:\n";
                float value;
                cin >> value;
                v[i] = value;
            }
            else
                continue;
        }
    }

    // Function:changeTarrifOfDomestic
    // Description: Employee can change Tarrif Of Domestic User
    // Input param:  amount Per Segment Of Unit Domestic vector
    // Return Type:  NULL

    void changeTarrifOfDomestic(vector<float> &v)
    {
        for (ll i = 0; i < v.size(); i++)
        {
            cout << "Dou you want to change the value of first 150 units that is: " << v[i] << endl;
            cout << "Type 1 to change , Type 0 to continue\n ";
            ll x;
            cin >> x;
            if (x)
            {
                cout << "Enter the new amount:\n";
                float value;
                cin >> value;
                v[i] = value;
            }
            else
                continue;
        }
    }
};

class Admin
{
private:
    string phoneNumber;
    double bankBalance;

public:
    string adminId;
    string name;
    Employee *Emp;

    // Default Constructor
    Admin()
    {
        phoneNumber = "nil";
        adminId = "nil";
        name = "nil";
        bankBalance = 0.0;
    }

    // Parameterized Constructor
    Admin(string phoneNumber, string adminId, string name, double bankBalance)
    {
        this->phoneNumber = phoneNumber;
        this->adminId = adminId;
        this->name = name;
        this->bankBalance = bankBalance;
    }

    // Function:printDetail
    // Description: Prints the details of the Admin
    // Input param:  NULL
    // Return Type:  NULL
    void printDetail()
    {
        cout << "Admin Details : " << endl;
        cout << "Name          : " << name << endl;
        cout << "adminId       : " << adminId << endl;
    }

    void adminViewsEmployee(vector<Employee> E, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            E[i].printDetails();
            cout << endl;
        }
    }

    void adminViewsUsers(vector<User *> U, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            U[i]->printDetails();
            cout << endl;
        }
    }

    void BankBalance()
    {
        bankBalance = Amount;
        cout << "Admin's bank balance: " << bankBalance << endl;
    }
};

int main()
{
    Admin ADMIN("9810896298", "ADMIN1", "Vasant Kumar", 190000.0);

    vector<Employee> E;

    Employee E1("9959152837", "Empe1001", "Sumit Sharma", "Vidhyanagar", 22.4, 20.89);
    E.pb(E1);
    Employee E2("8923451910", "Empe1002", "Rekha Jain", "Gokul Road", 23.0, 22.9);
    E.pb(E2);
    Employee E3("7299035627", "Empe1003", "Kiran L H", "Gandhi Nagar", 22.4, 21.5);
    E.pb(E3);
    Employee E4("9825367102", "Empe1004", "Shradha B ", "Chirtakkot", 20.34, 20.11);
    E.pb(E4);
    Employee E5("9938710263", "Empe1005", "Hemant Rao", "B k Road", 21.9, 19.99);
    E.pb(E5);

    vector<User *> U;

    CommercialUser CU1("9826371820", "E1CU101", "somanath", "9-10, Bhagirath Industrial Esta", 94290.78, 770);
    U.pb(&CU1);
    CommercialUser CU2("7792235468", "E2CU102", "Shekhar", "5, Somasundara Mudali St,Parrys", 103405.8, 1180);
    U.pb(&CU2);
    CommercialUser CU3("9825112230", "E3CU103", "Lata ", "47/48, Fm Cariappa Road", 201000.0, 980);
    U.pb(&CU3);
    CommercialUser CU4("7816352901", "E4CU104", "Muskan", "8b,Lindsay Street, New Market", 10730.0, 9100);
    U.pb(&CU4);
    CommercialUser CU5("8127399830", "E5CU105", "Harish", "No 2, 2nd Main Road, Gandhinagar", 183092.0, 2240);
    U.pb(&CU5);

    DomesticUser DU1("9755528687", "E1DU101", "Aravind Sama", "Govt. Ind Est, Charkop Naka,", 9429.78, 77);
    U.pb(&DU1);
    DomesticUser DU2("8555393361", "E2DU102", "Dhriti Dar", "G, Vardaan House, Darya Ganj", 10345.8, 118);
    U.pb(&DU2);
    DomesticUser DU3("7555110402", "E3DU103", "Manu Chaudhari ", "Khernagar, Kajal Plastics Near Uttam Book Depo, Bandra (east)", 20000.0, 380);
    U.pb(&DU3);
    DomesticUser DU4("9655585472", "E4DU104", "Abhinav Mody", "710, Mittal Towers, 7th Floor,a Wing M G Road, M G Road", 1730.0, 300);
    U.pb(&DU4);
    DomesticUser DU5("7555074534", "E5DU105", "Talika Gour", "8487, Arakashan Road, Pahar Ganj", 13092.0, 540);
    U.pb(&DU5);

    // E1.EmployeeViewsUser(U, 0, 10);

    // ADMIN.adminViewsEmployee(E, 0, 5);

    // ADMIN.adminViewsUsers(U, 0, 10);

    GenerateBill B;

    for (ll i = 0; i < 10; i++)
    {
        cout << "before transaction:\n";
        U[i]->printDetails();
        if (U[i]->userId[2] == 'C')
            U[i]->payBillCommercial(B);
        else
            U[i]->payBillDomestic(B);
        cout << "after the transaction:\n";
        U[i]->printDetails();
        cout << "-------------------------------------------------------------------------------------\n";
    }

    // E1.changeTarrifOfCommercial(U[0]->amountPerSegmentOfUnitCommercial);
    // U[0]->payBillCommercial(B);
    ADMIN.BankBalance();
    return 0;
}