// this is edited by Aayushi Gupta on branch changes
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

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
        phoneNumber = 'nil';
        userId = 'nil';
        name = 'nil';
        area = 'nil';
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

    float calculateBillOfCommercial(CommercialUser &cu)
    {
        float calculatedAmount = amountCommercial * cu.numberOfUnitsUsed;
        return calculatedAmount;
    }

    float calculateBillOfDomestic(DomesticUser &du)
    {
        float calculatedAmount = amountDomestic * du.numberOfUnitsUsed;
        return calculatedAmount;
    }
};

class Admin
{

private:
    string phoneNumber;

public:
    string userId;
    string name;
    Employee *Employee;

    // Default Constructor

    Admin()
    {
        phoneNumber = 'nil';
        userId = 'nil';
        name = 'nil';
    }

    // Parameterized Constuctor

    Admin(string p, string id, string n)
    {
        phoneNumber = p;
        userId = id;
        name = n;
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

    // Default Constructor

    User()
    {
        phoneNumber = 'nil';
        userId = 'nil';
        name = 'nil';
        address = 'nil';
        bankBalance = 'nil';
        dueAmount = 'nil';
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
};

class CommercialUser : public User
{
public:
    ll numberOfUnitsUsed;

    // Default Constructor

    CommercialUser() : User() {}

    // Parameterized Constructor

    CommercialUser(string p, string id, string n, string address, float bb, char c, ll units) : User(p, id, n, address, bb, c), numberOfUnitsUsed(units) {}

    // Function:printDetails
    // Description: Prints the details of the Commercial User
    // Input param:  NULL
    // Return Type:  NULL

    void printDetails()
    {
        cout << "print the details of commercial user\n";
    }

    friend class User;
};

class DomesticUser : public User
{
public:
    ll numberOfUnitsUsed;

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
        cout << "print the details of Domestic user\n";
    }
    // void payBill()
    // {
    //     dueAmount = calculateBillOfDomestic(*this);
    // }

    friend class User;
};

int main()
{

    return 0;
}