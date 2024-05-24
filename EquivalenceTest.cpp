#include <iostream>
#include "Minion.h"
#include "Wizard.h"
#include "Attack.h"
using namespace std;


class EquivalenceTest{
    public:
    void runTest(){
        testAttack();
    }
    private:
    void testAttack(){
        Minion minion;
        Wizard wiz(100);

       
        minion.attack(20,wiz);
        if(wiz.get_health()!=80){
            cout<<"Test failed!The health should be 80."<<endl;
        }else{
            cout<<"Test passed!The health is 80"<<endl;
        }
       
        minion.attack(-20,wiz);
        if(wiz.get_health()!=100){
            cout<<"Test failed!Invalid damage."<<endl;
        }else{
            cout<<"Test passed!The health will remain 100"<<endl;
        }
        minion.attack(0,wiz);
        if(wiz.get_health()!=100){
            cout<<"Test failed!Invalid damage."<<endl;
        }else{
            cout<<"Test passed!The health will remain 100"<<endl;
        }
        
    }
};