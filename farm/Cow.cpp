//
//  Cow.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include "Cow.h"

void Cow::yell()
{
    if(getEnergyLevel() >=0 && getEnergyLevel() <= 5){
        cout << "mm" << endl;
    }
    
    if(getEnergyLevel() >= 6 && getEnergyLevel() <= 10){
        cout << "Mu" << endl;
    }
    
    if(getEnergyLevel() >= 11 && getEnergyLevel() <= 20){
        cout << "Muu" << endl;
    }
    
    if(getEnergyLevel() >= 21){
        cout << "MUUUU" << endl;
    }
    
};
