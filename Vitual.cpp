#include <iostream>
using namespace std;

class Character{
    public:
    virtual void attack()=0;
};
class Warrior:public Character{
    public:
    void attack(){
        cout<<"Attack by Warrior!!";
    }
};
class Mage:public Character{
    public:
    void attack(){
        cout<<"Attack by Mage!!";
    }
};

int main(){
    Character*A=new Warrior();
    A->attack();

    Character*B=new Mage();
    B->attack();

    delete A;
    delete B;
    
    return 0;
}
