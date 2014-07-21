//
//  Cat.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include "Cat.h"

void Cat::yell()
{
    if(getEnergyLevel() >=0 && getEnergyLevel() <= 5){
        cout << "Me" << endl;
    }
    
    if(getEnergyLevel() >= 6 && getEnergyLevel() <= 10){
        cout << "Mew" << endl;
    }
    
    if(getEnergyLevel() >= 11 && getEnergyLevel() <= 20){
        cout << "Meow" << endl;
    }
    
    if(getEnergyLevel() >= 21){
        cout << "Meeoooow" << endl;
    }
    
};
