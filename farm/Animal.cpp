//
//  Animal.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include "Animal.h"

Animal::Animal(){};

Animal::Animal(string n, int el):name(n), energyLevel(el){};

Animal::~Animal(){};

void Animal::show()
{
    string kind;
    
    kind = typeid(*this).name();
    kind = kind.substr(1, kind.length()-1);
    
    cout << "----------" << endl;
    cout << kind << endl;
    cout << "----------" << endl;
    cout << "name: " << getName() << endl;
    cout << "energy_evel: " << getEnergyLevel() << endl;
    cout << "trough_slot_num: " << getTroughSlotNum() << endl;
    
    cout << endl;
};

void Animal::active(int troughArr[])
{
    if(getPeriodDowncount() == 0){
        cout << "EAt\n";
        eat(troughArr);
    }else{
        cout << "REST\n";
        rest();
    }
}

void Animal::eat(int troughArr[])
{
    int energy;
    
    energy = MIN(getMaxFoodAmt(), troughArr[getTroughSlotNum()]);
    
    setEnergyLevel(getEnergyLevel()+energy);
    troughArr[getTroughSlotNum()] -= energy;
    setPeriodDowncount(getEatPeriod());
    
    show();
    cout << "trough_num:" << getTroughSlotNum() << " " << troughArr[getTroughSlotNum()] << endl << endl;
}

void Animal::rest()
{
    setEnergyLevel(getEnergyLevel()-1);
    setPeriodDowncount(getPeriodDowncount()-1);
    
    show();
}

int Animal::MIN(int num1, int num2)
{
    if(num1 < num2){
        return num1;
    }else{
        return num2;
    }
}

void Animal::setName(string n)
{
    name = n;
}

string Animal::getName()
{
    return name;
}

void Animal::setEnergyLevel(int el)
{
    energyLevel = el;
};

int Animal::getEnergyLevel()
{
    return energyLevel;
};

void Animal::setTroughSlotNum(int tsn)
{
    troughSlotNum = tsn;
};

int Animal::getTroughSlotNum()
{
    return troughSlotNum;
};

void Animal::setEatPeriod(int ep)
{
    eatPeriod = ep;
    setPeriodDowncount(ep);
};

int Animal::getEatPeriod()
{
    return eatPeriod;
};

void Animal::setMaxFoodAmt(int mfa)
{
    maxFoodAmt = mfa;
};

int Animal::getMaxFoodAmt()
{
    return maxFoodAmt;
};

void Animal::setPeriodDowncount(int pd)
{
    PeriodDowncount = pd;
};

int Animal::getPeriodDowncount()
{
    return PeriodDowncount;
};

void Animal::setFoodAmt(int fa)
{
    foodAmt = fa;
}

int Animal::getFoodAmt()
{
    return foodAmt;
}