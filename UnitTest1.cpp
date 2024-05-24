#include<iostream>
#include "Character.h"
using namespace std;

class UnitTest1{
    public:
    void runTest(){
        testcheckHealth();
        testIsAlive();
    }
    private:
    void testcheckHealth(){
        Character character(200);
        character.set_health(50);
        character.checkHealth();
        if(character.get_health()==50){
            cout<<"The character's health is correct.It should be 50!"<<endl;
        }else{
            cout<<"Test failed.The health should be 50"<<endl;
        }
        character.set_health(0);
        character.checkHealth();
        if(character.get_health()==0){
            cout<<"The character's health is correct!.It should be 0!"<<endl;
        }else{
            cout<<"Test failed.The health should be 0"<<endl;
        }
        character.set_health(-10);
        character.checkHealth();
        if(character.get_health()==0){
            cout<<"The character's health is correct.It should be 0!"<<endl;
        }else{
            cout<<"Test failed.The health should be 0"<<endl;
        }

    }
    void testIsAlive(){
        Character character(200);
        if(character.get_isAlive()==true){
            cout<<"Character should be alive!"<<endl;
        }
        else{
            cout<<"Test failed.Character should be alive."<<endl;
        }
        character.set_health(0);
        character.checkHealth();
        if(character.get_isAlive()==false){
            cout<<"Character should be dead!"<<endl;
        }
        else{
            cout<<"Test failed.Character should be dead."<<endl;
        }
        character.set_health(-10);
        character.checkHealth();
        if(character.get_isAlive()==false){
            cout<<"Character should be dead!"<<endl;
        }
        else{
            cout<<"Test failed.Character should be dead."<<endl;
        }


    }
  
};
