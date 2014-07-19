//
//  Horse.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include "Horse.h"

Horse::Horse()
{
    setEatPeriod(4);
    setMaxFoodAmt(20);
    setPeriodDowncount(4);
}

void Horse::yell()
{
    if(getEnergyLevel() >=0 && getEnergyLevel() <= 5){
        cout << "Ne" << endl;
    }
    
    if(getEnergyLevel() >= 6 && getEnergyLevel() <= 10){
        cout << "Nei" << endl;
    }
    
    if(getEnergyLevel() >= 11 && getEnergyLevel() <= 20){
        cout << "Neigh" << endl;
    }
    
    if(getEnergyLevel() >= 21){
        cout << "Neeeigh" << endl;
    }
    
};
