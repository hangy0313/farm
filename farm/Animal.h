//
//  Animal.h
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#ifndef __farm__Animal__
#define __farm__Animal__

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal();
    Animal(string n, int el);
    virtual ~Animal();
    
    virtual void yell() = 0;
    void show();
    void active(int troughArr[]);
    
    void setName(string n);
    string getName();
    
    void setEnergyLevel(int el);
    int getEnergyLevel();
    
    void setTroughSlotNum(int tsn);
    int getTroughSlotNum();
    
    void setEatPeriod(int ep);
    int getEatPeriod();
    
    void setMaxFoodAmt(int mfa);
    int getMaxFoodAmt();
    
    void setPeriodDowncount(int pd);
    int getPeriodDowncount();
    
    void setFoodAmt(int fa);
    int getFoodAmt();
private:
    string name;
    int energyLevel;
    int troughSlotNum;
    int eatPeriod;
    int maxFoodAmt;
    int PeriodDowncount;
    int foodAmt;
    
    void eat(int troughArr[]);
    void rest();
    int MIN(int num1, int num2);
};

#endif /* defined(__farm__Animal__) */
