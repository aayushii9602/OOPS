/* This is edited by aayushi on master branch*/
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

double Amount; // global viarble to store the total amount that is to be credited to Admin's account

// Function:printDetail
// Description: Prints the details of the User
// Input param:  NULL
// Return Type:  vector of string

vector<string> login()
{
    vector<string> v;
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "\033[0;32m"; //(“\033[0;31m”);
    cout << "-------------------------------WELCOME TO THE SYSTEM---------------------------------\n";
    cout << "\033[0;35m";

    cout << "Press 1 to CONTINUE\nPress 0 to EXIT\n";
    ll ans;
    cin >> ans;
    if (ans == 0)
        exit(0);
    else
    {
        string username, password, code;
        int count;
        while (1)
        {
            string u, p, x;
            cout << "Press 'A' if you are Admin\nPress 'E' if you are Employee\nPress 'U' if you are User\n";
            cout << "\033[0;37m";
            cin >> code;
            system("cls");
            cout << "please enter the following details" << endl;
            cout << "USERNAME :";
            cin >> username;
            cout << "PASSWORD :";
            cin >> password;

            ifstream input("database.txt");
            while (input >> u >> p >> x)
            {
                if (u == username && p == password && x == code)

                {
                    count = 1;
                    system("cls");
                }
            }
            input.close();
            if (count == 1)
            {
                cout << "\nHello" << username << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
                v.pb(username);
                // v.pb(password);
                v.pb(code);
                return v;
                // break;
            }
            else
            {
                cout << "\nLOGIN ERROR\nPlease check your username and password\n";
                cout << "Do you want to EXIT?\nPress Y(YES) or N(NO)";
                char m;
                cin >> m;
                if (m == 'Y')
                    exit(0);
                else
                    continue;
            }
        }
        if (count == 1)
        {
            v.pb(username);
            // v.pb(password);
            v.pb(code);
            return v;
        }
        else
        {
            v.pb("NIL");
            return v;
        }
    }
}

class InsufficientBalance
{
public:
    string msg;
    // Constructor
    InsufficientBalance(string msg)
    {
        this->msg = msg;
    }

    // Function:what
    // Description: return the Insufficient balance message
    // Input param:  message string
    // Return Type:  string
    string what()
    {
        return msg;
    }
};

class InvalidUnits
{
public:
    string msg;
    // Constructor
    InvalidUnits(string msg)
    {
        this->msg = msg;
    }

    // Function:what
    // Description: return the invalid number of Units message
    // Input param:  message string
    // Return Type:  string
    string what()
    {
        return msg;
    }
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

    // Function:CalculteamountOfCommercial
    // Description: calculates the total amount that commercial user has to pay.
    // Input param:  number of units, vector of amount Per Segment Of Unit Commercial
    // Return Type:  double
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

    // Function:CalculteamountOfDomestic
    // Description: calculates the total amount that domestic user has to pay.
    // Input param:  number of units, vector of amount Per Segment Of Unit Domestic
    // Return Type:  double

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
    void payBillDomestic(GenerateBill *B)
    {

        dueAmount = B->CalculteamountOfDomestic(this->numberOfUnitsUsed, amountPerSegmentOfUnitDomestic);
        cout << "You need ot pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO\n";
        ll x;
        cin >> x;
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                cout << "User Details before the transcation\n";
                this->printDetails();
                bankBalance -= dueAmount;
                Amount += dueAmount;
                dueAmount = 0;
                cout << "Thanks for paying the bill\n";
                cout << "User Details after the transcation\n";
                this->printDetails();
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
    void payBillCommercial(GenerateBill *B)
    {

        dueAmount = B->CalculteamountOfCommercial(this->numberOfUnitsUsed, amountPerSegmentOfUnitCommercial);
        cout << "You need ot pay:" << dueAmount << endl;
        cout << "You want to pay now??\nPrint 1 for YES and 0 for NO";
        ll x;
        cin >> x;
        if (x)
        {
            if (dueAmount <= bankBalance)
            {
                cout << "User Details before the transcation\n";
                this->printDetails();
                bankBalance -= dueAmount;
                Amount += dueAmount;
                dueAmount = 0;
                cout << "Thanks for paying the bill\n";
                cout << "User Details after the transcation\n";
                this->printDetails();
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
    User *USER;

    // Default Constructor
    Employee()
    {
        phoneNumber = "nil";
        employeeId = "nil";
        name = "nil";
        area = "nil";
    }

    // Parameterized Constructor
    Employee(string phoneNumber, string employeeId, string name, string area)
    {
        this->phoneNumber = phoneNumber;
        this->employeeId = employeeId;
        this->name = name;
        this->area = area;
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
            cout << "-------------------------------------------------------------------------------------\n";
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
            cout << "Do you want to change the value of " << i + 1 << " segment, which is: " << v[i] << endl;
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
            cout << "Do you want to change the value of " << i + 1 << " segment, which is: " << v[i] << endl;
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
    static Admin *instance;
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

public:
    static Admin *getinstance()
    {
        if (!instance)
            instance = new Admin; // alloacting in heap memory
        return instance;
    }

    // Function:printDetail
    // Description: Prints the details of the Admin
    // Input param:  NULL
    // Return Type:  NULL

    void printDetails()
    {
        cout << "Admin Details :" << endl;
        cout << "Name          :" << this->name << endl;
        cout << "adminId       :" << this->adminId << endl;
        cout << "Bank Balance  :" << this->bankBalance << endl;
    }

    // Function:setname
    // Description: sets the admin name
    // Input param:  name
    // Return Type:  NULL

    void setname(string name)
    {
        this->name = name;
    }

    // Function:setAdminId
    // Description: sets the admin Id
    // Input param:  admin Id
    // Return Type:  NULL

    void setAdminId(string adminId)
    {
        this->adminId = adminId;
    }

    // Function:adminViewsEmployee
    // Description: Admin can virew the details of employee
    // Input param:  vector of Employee, start-point , end-point
    // Return Type:  NULL

    void adminViewsEmployee(vector<Employee> E, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            E[i].printDetails();
            cout << "-------------------------------------------------------------------------------------\n";
        }
    }

    // Function:adminViewsUsers
    // Description: Admin can view the details of Users
    // Input param:  vector of Users, start-point , end-point
    // Return Type:  NULL

    void adminViewsUsers(vector<User *> U, ll startpoint, ll endpoint)
    {
        for (ll i = startpoint; i < endpoint; i++)
        {

            U[i]->printDetails();
            cout << "-------------------------------------------------------------------------------------\n";
        }
    }

    // Function:setBankBalance
    // Description: gives the bank balance of admin
    // Input param:  NULL
    // Return Type:  double

    double getBankBalance()
    {
        return this->bankBalance;
    }

    // Function:setBankBalance
    // Description: updates the admin's bank balance
    // Input param:  bankBalance
    // Return Type:  NULL

    void setBankBalance(double x)
    {
        this->bankBalance += x;
    }
};

Admin *Admin::instance = 0;

int main()
{

    Admin *a = a->getinstance();

    vector<Employee> E;

    Employee E1("9959152837", "Empe1001", "Sumit Sharma", "Vidhyanagar");
    E.pb(E1);
    Employee E2("8923451910", "Empe1002", "Rekha Jain", "Gokul Road");
    E.pb(E2);
    Employee E3("7299035627", "Empe1003", "Kiran L H", "Gandhi Nagar");
    E.pb(E3);
    Employee E4("9825367102", "Empe1004", "Shradha B", "Chirtakkot");
    E.pb(E4);
    Employee E5("9938710263", "Empe1005", "Hemant Rao", "B k Road");
    E.pb(E5);

    vector<User *> U;
    vector<CommercialUser> CU;
    vector<DomesticUser> DU;

    CommercialUser CU1("9826371820", "E1CU101", "somanath", "9-10, Bhagirath Industrial Esta", 94290.78, 770);
    U.pb(&CU1);
    CU.pb(CU1);
    CommercialUser CU2("7792235468", "E2CU102", "Shekhar", "5, Somasundara Mudali St,Parrys", 103405.8, 1180);
    U.pb(&CU2);
    CU.pb(CU2);
    CommercialUser CU3("9825112230", "E3CU103", "Lata ", "47/48, Fm Cariappa Road", 201000.0, 980);
    U.pb(&CU3);
    CU.pb(CU3);
    CommercialUser CU4("7816352901", "E4CU104", "Muskan", "8b,Lindsay Street, New Market", 10730.0, 9100);
    U.pb(&CU4);
    CU.pb(CU4);
    CommercialUser CU5("8127399830", "E5CU105", "Harish", "No 2, 2nd Main Road, Gandhinagar", 183092.0, 2240);
    U.pb(&CU5);
    CU.pb(CU5);
    CommercialUser CU6("8654297516", "E1CU106", "Saira", "3/22, Vidyanagar", 15001.0, 440);
    U.pb(&CU6);
    CU.pb(CU6);
    CommercialUser CU7("9788547621", "E2CU107", "Kumar", "III Link Road, Vazira, Borivali", 12504.0, 320);
    U.pb(&CU7);
    CU.pb(CU7);
    CommercialUser CU8("9004507861", "E3CU108", "Priyesh", "NO88, Srinivasa Nagar, 2NS Main Road", 14589.0, 784);
    U.pb(&CU8);
    CU.pb(CU8);
    CommercialUser CU9("9307842655", "E4CU109", "Sejal", "BMC Software, Kolkata", 25000.0, 445);
    U.pb(&CU9);
    CU.pb(CU9);
    CommercialUser CU10("7878412578", "E5CU1010", "Ahaaan", "Life Style International Pvt. Ltd., Main Road", 20000.0, 740);
    U.pb(&CU10);
    CU.pb(CU10);

    DomesticUser DU1("9755528687", "E1DU101", "Aravind", "Govt. Ind Est, Charkop Naka,", 9429.78, 77);
    U.pb(&DU1);
    DU.pb(DU1);
    DomesticUser DU2("8555393361", "E2DU102", "Dhrit", "G, Vardaan House, Darya Ganj", 10345.8, 118);
    U.pb(&DU2);
    DU.pb(DU2);
    DomesticUser DU3("7555110402", "E3DU103", "Manu", "Khernagar, Kajal Plastics Near Uttam Book Depo, Bandra (east)", 20000.0, 380);
    U.pb(&DU3);
    DU.pb(DU3);
    DomesticUser DU4("9655585472", "E4DU104", "Abhinav", "710, Mittal Towers, 7th Floor,a Wing M G Road, M G Road", 1730.0, 300);
    U.pb(&DU4);
    DU.pb(DU4);
    DomesticUser DU5("7555074534", "E5DU105", "Talika", "8487, Arakashan Road, Pahar Ganj", 13092.0, 540);
    U.pb(&DU5);
    DU.pb(DU5);
    DomesticUser DU6("7888594625", "E1DU106", "Sunaina", "13/9, Daksha Bldg, Vallabh Baug Lane", 7025.26, 250);
    U.pb(&DU6);
    DU.pb(DU6);
    DomesticUser DU7("9878565854", "E2DU107", "Kartik", "523, Lotus Homes, Sector-4", 14250.25, 214);
    U.pb(&DU7);
    DU.pb(DU7);
    DomesticUser DU8("8348457865", "E3DU108", "Arjun ", "Green Homes, Mango Road", 20250.0, 420);
    U.pb(&DU8);
    DU.pb(DU8);
    DomesticUser DU9("9678654585", "E4DU109", "Apeksha", "K-74, Kendriya Vihar, Sector-12", 1543.0, 100);
    U.pb(&DU9);
    DU.pb(DU9);
    DomesticUser DU10("7854587456", "E5DU1010", "Ankita", "22, Vasant Kunj, near Apollo Hospital ", 10254.0, 140);
    U.pb(&DU10);
    DU.pb(DU10);

    cout << CU.size() << endl;
    GenerateBill B;
    // login();
    while (1)
    {
        vector<string> Checker;
        Checker = login();
        if (Checker[1] == "A")
        {
            while (1)
            {
                cout << "\nPress 1: To view your details\nPress 2: To view Employee Details\nPress 3: TO view All the User Details\nPress 4: To check the total revenue generated\nPress 5: TO Log out\n";
                ll choice;
                cin >> choice;
                if (choice == 1)
                {
                    a->setname("Vasant Kumar");
                    a->setAdminId("ADMIN1");
                    a->setBankBalance(190000.0);
                    // Amount = 0.0;
                    a->printDetails();
                }
                else if (choice == 2)
                    a->adminViewsEmployee(E, 0, E.size());
                else if (choice == 3)
                    a->adminViewsUsers(U, 0, U.size());
                else if (choice == 4)
                {
                    a->setBankBalance(Amount);
                    cout << "Total revenue generated :" << Amount << endl;
                }
                else
                    break;
            }
        }

        else if (Checker[1] == "E")
        {
            Employee TestEmp;
            for (ll i = 0; i < E.size(); i++)
            {
                if (Checker[0] == E[i].employeeId)
                {
                    TestEmp = E[i];
                    break;
                }
            }
            while (1)
            {
                cout << "\nPress 1: To view your details\nPress 2: TO view All the User Details\nPress 3: To change the tariff of the commercial user\n Press 4: to change the tariff od domestic user\nPress 5 : TO Log out\n ";
                ll choice;
                cin >> choice;
                if (choice == 1)
                    TestEmp.printDetails();
                else if (choice == 2)
                    TestEmp.EmployeeViewsUser(U, 0, U.size());
                else if (choice == 3)
                    TestEmp.changeTarrifOfCommercial(U[0]->amountPerSegmentOfUnitCommercial);
                else if (choice == 4)
                    TestEmp.changeTarrifOfDomestic(U[9]->amountPerSegmentOfUnitDomestic);
                else
                    break;
            }
        }

        else if (Checker[1] == "U")
        {
            for (ll i = 0; i < CU.size(); i++)
            {
                if (Checker[0] == CU[i].userId)
                {
                    while (1)
                    {
                        cout << "Press 1:To print your Details\nPress 2: to Pay your Bill\nPress 3: To LOG-OUT\n";
                        ll choice;
                        cin >> choice;
                        if (choice == 1)
                            CU[i].printDetails();
                        if (choice == 2)
                            CU[i].payBillCommercial(&B);
                        if (choice == 3)
                            break;
                    }
                    break;
                }
            }
            for (ll i = 0; i < DU.size(); i++)
            {
                if (Checker[0] == DU[i].userId)
                {
                    while (1)
                    {
                        cout << "Press 1:To print your Details\nPress 2: to Pay your Bill\nPress 3: To LOG-OUT\n";
                        ll choice;
                        cin >> choice;
                        if (choice == 1)
                            DU[i].printDetails();
                        if (choice == 2)
                            DU[i].payBillDomestic(&B);
                        if (choice == 3)
                            break;
                    }

                    // flag = 2;
                    break;
                }
            }
        }
    }
    try
    {
        CU1.payBillCommercial(&B);
        CU2.payBillCommercial(&B);
        CU3.payBillCommercial(&B);
        DU4.payBillDomestic(&B);
        DU5.payBillDomestic(&B);
        DU6.payBillDomestic(&B);
    }
    catch (InvalidUnits &i)
    {
        cout << endl;
        cout << i.what() << endl;
        cout << endl;
    }
    try
    {
        CU1.payBillCommercial(&B);
        CU7.payBillCommercial(&B);
        CU9.payBillCommercial(&B);
        CU3.payBillCommercial(&B);
        CU5.payBillCommercial(&B);

        DU1.payBillDomestic(&B);
        DU2.payBillDomestic(&B);
        DU7.payBillDomestic(&B);
        DU6.payBillDomestic(&B);
        DU8.payBillDomestic(&B);
    }
    catch (InsufficientBalance &s)
    {
        cout << endl;
        cout << s.what() << endl;
        cout << endl;
    }
    return 0;
}
