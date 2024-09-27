#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random> 

//sabi ni brocode wag daw gumamit ng using name std cuz baka ma call mo aksidente mga std function na same name
//adam niggation
//mga niggaz
using std::cout;
using std::cin;
using std::string;
using std::getline;

struct Acc{
    string name;
    string bday;
    string contact; //string na to instead of int kasi nagkaka error pag mahaba or something bullshit basta ok to pag string
    string accNum;
    string pinCode;
    double balance;
};

struct Node{
    Acc data;
    Node* next;
    Node(Acc x) : data(x), next(NULL){}
};

class System{
    private:
        Node* head;
        int createAccNumber();
    public:
        System() : head(NULL){}
        void registerAcc();
        void enterAcc(string n, string p);
        void checkRegister();
        void showBalance();
        int withdraw();
        void deposit(double x);
        void fundTransfer(int x);
        void changePin();
        void showAcc(string x);

};

void System::registerAcc(){

Acc x;
cout<<"Input name: ";
cin.ignore();
getline(cin, x.name);

cout <<"Input Birth Date(M/D/Y): "; cin >> x.bday;
cout <<"Input Contact Number: "; cin >> x.contact;
cout <<"Input Pin: "; cin >> x.pinCode;
x.accNum = std::to_string(createAccNumber());

Node* p, *q, *newNode;
p = q = head;

newNode = new Node(x);

while(p != NULL){
    q = p;
    p = p->next;
}

if(p == head)
    head = newNode;
else{
    q->next = newNode;
    newNode->next = p;
    }

showAcc(x.accNum);

}

int System::createAccNumber(){//helped by allen iverson
   std::vector<int> numbers;

    // Fill vector with all possible 6-digit numbers
    for (int i = 100000; i <= 999999; ++i) {
        numbers.push_back(i);
    }
    // Seed random number generator using random_device and engine
    std::random_device rd;
    std::default_random_engine rng(rd());

    // Shuffle the vector
    std::shuffle(numbers.begin(), numbers.end(), rng);

    // Return the first number from the shuffled vector
    return numbers[0]; // Assuming you want a single unique 6-digit number
}

void System::enterAcc(string n, string pin){
Node* p, *q;
p = q = head;

while(p != NULL && n != p->data.accNum && pin !=p->data.pinCode){
        q = p;
        p = p->next;
    }

if(p == NULL){
    cout << "Unsuccessful. PLS TRY AGAIN";
    return;
    }
else{
    cout<<"Account Login Successful";
    showAcc(n);//testing kung gumagana kupal
}

}


void System::showBalance(){

}

void System::showAcc(string x){
Node *p, *q;
p = q = head;

while (p != NULL && p->data.accNum != x){
    q = p;
    p = p->next;
  }
if (p==NULL){
    cout<<"Acc not found.\n";
    system("pause");
}

else{
    system("cls");
    cout << "Your acc number is: " << p->data.accNum << '\n';
    cout << "Acc name: " << p->data.name << '\n';
    cout << "Bday: " << p->data.bday << '\n';
    cout << "Contact: " << p->data.contact << '\n';
    cout << "Pin code: " << p->data.pinCode << '\n';

    system("pause");
}

}

int System::withdraw(){
    return 0;
}

void System::deposit(double x){

}

void System::fundTransfer(int x){

}

void System::changePin(){

}

int firstMenu(){
    int op;

    system("cls");

    cout<<"Menu\n";
    cout<<"1. Not Register Acc\n";
    cout<<"2. Open Acc\n";
    cout<<"-> ";

    cin >> op;
    return op;
}
int mainMenu(){
    int op;

    system("cls");

    cout<<"Menu\n";
    cout<<"1. --\n";
    cout<<"2. ---\n";
    cout<<"3. ---\n";
    cout<<"4. ---\n";
    cout<<"5. ---\n";
    cout<<"6. Exit\n";
    cout<<"Select(1-6)\n ";
    cout<<"-> ";

    cin >> op;
    return op;
}

int main(){

System atm;
string num, pin;
    while(true){

        switch(firstMenu()){
        case 1:
            system("cls");
            atm.registerAcc();
            cout << "Successful Account Registration\n";
            system("pause");
            break;

        case 2:
            system("cls");
            cout<<"Enter Account Number: "; cin >> num;
            cout<<"Enter Pin: "; cin >> pin;
            atm.enterAcc(num, pin);
            break;

        default:
            cout<<"Invalid input.\n";
            cin.clear(); //para to sa pag aksidente na input anything othern than a number. kasi pag nagtype ka ng letter nag eeror na
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
        }
    }

    return 0;
}
