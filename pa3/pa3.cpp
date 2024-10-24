//Partner: Xavier Galanes
#include <iostream>
using namespace std;

class TestClass {
private:
    static int privateStaticMember;
    int privateNonStaticMember;
public:
    static int publicStaticMember;
    int publicNonStaticMember;

    TestClass(int x) : publicNonStaticMember(x) {}

    void displayer() const;

    static void printPublicStatic();

    static void setPrivateStaticVar(int i);
    static int getPrivateStaticVar();

    void setPrivateNonStaticVar(int i);
    int getPrivateNonStaticVar() const;
};

int TestClass::publicStaticMember = 10;
int TestClass::privateStaticMember = 20;

void TestClass::setPrivateStaticVar(int j) {
    privateStaticMember = j;
}
int TestClass::getPrivateStaticVar() {
    return privateStaticMember;
}

void TestClass::setPrivateNonStaticVar(int z) {
    privateNonStaticMember = z;
}
int TestClass::getPrivateNonStaticVar() const {
    return privateNonStaticMember;
}

void TestClass::displayer() const {
    cout << "The object is at the address: " << this << endl;
    cout << "publicNonStaticMember: " << publicNonStaticMember << " is at the address: " << &publicNonStaticMember << endl;
    cout << "privateNonStaticMember: " << privateNonStaticMember << " is at the address: " << &privateNonStaticMember << endl;
    cout << endl;
}

void TestClass::printPublicStatic() {
    cout << "publicStaticMember: " << publicStaticMember << " contains the address: " << &publicStaticMember << endl;
    cout << "privateStaticMember: " << privateStaticMember << " contains the address: " << &privateStaticMember << endl;
}

int main() {
    TestClass object1(54);
    TestClass object2(23);
    TestClass::publicStaticMember = 452;
    TestClass::setPrivateStaticVar(213);

    cout << "Object 1 information:" << endl;
    object1.displayer();
    cout << "Object 2 information:" << endl;
    object2.displayer();
    cout << "The static members are:" << endl;
    TestClass::printPublicStatic();
}

//What we think the addresses of the static and non-static members
//means is that for static, since the addresses is the same as the object
//this shows that there is only one shared location for it and belongs to the class,
//not the actual object itself. On the other hand, non-static members each have their own
//addresses because they are stored within the memory of the object itself.