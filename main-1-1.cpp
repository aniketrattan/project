#include <iostream>
using namespace std;
#include "Minion.h"
#include "MiniBoss.h"
#include "Boss.h"


int main(){
    Minion*A;
    MiniBoss B;
    A=&B;
    A->attack();

    return 0;
}


