//
//  Chicken.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include "Chicken.h"

Chicken::Chicken()
{
    setEatPeriod(1);
    setMaxFoodAmt(5);
    setPeriodDowncount(1);
}

void Chicken::yell()
{
    if(getEnergyLevel() >=0 && getEnergyLevel() <= 5){
        cout << "Cl" << endl;
    }
    
    if(getEnergyLevel() >= 6 && getEnergyLevel() <= 10){
        cout << "Clu" << endl;
    }
    
    if(getEnergyLevel() >= 11 && getEnergyLevel() <= 20){
        cout << "Cluck" << endl;
    }
    
    if(getEnergyLevel() >= 21){
        cout << "Cluuckk, Cluck" << endl;
    }
    
};
