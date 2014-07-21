//
//  main.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Animal.h"
#include "Cat.h"
#include "Cow.h"
#include "Chicken.h"
#include "Horse.h"

using namespace std;

const int maxTroughNum = 10;
const int maxAnimalNum = 10;

static Animal* animalArr[maxAnimalNum];
static int troughArr[maxTroughNum];
static int animalNowIndex = 0;
static int animalLastIndex = 0;
static int animalTotalNumber = 0;

bool animalIsValid();
bool troughIsValid(int num);
bool animalArrIsAssigned(int num);

void createAnimal();
void setAnimal();

void feed();
void showTroughInfo();

void display();

void call();

void advance();
void checkDecease();

int main(int argc, const char * argv[])
{
    string ans;
    
    while(1){
        cout << "*********************" << endl;
        cout << "* 1    => creation  *" << endl;
        cout << "* 2    => feed      *" << endl;
        cout << "* 3    => display   *" << endl;
        cout << "* 4    => yell      *" << endl;
        cout << "* 5    => advance   *" << endl;
        cout << "* end  => exit      *" << endl;
        cout << "*********************" << endl;
        cin >> ans;
        if(ans == "1"){
            createAnimal();
        }
        if(ans == "2"){
            feed();
        }
        if(ans == "3"){
            display();
            showTroughInfo();
        }
        if(ans == "4"){
            call();
        }
        if(ans == "5"){
            advance();
        }

        if(ans == "end"){
            break;
        }
    }

    return 0;
}

bool animalIsValid()
{
    bool check;
    
    check = animalTotalNumber < maxAnimalNum;
    
    if(!check){
        cout << "Too much animals.\n";
    }
    
    return check;
}

bool troughIsValid(int num)
{
    bool check;
    
    if(num < 0){
        cout << "Invalid input number\n";
        
        return false;
    }
    
    check = num < maxTroughNum;
    if(!check){
        cout << "No such number of trogh\n";
    }
    
    return check;
}

bool animalArrIsAssigned(int num)
{
    bool check = true;

    if(animalArr[num] == nullptr){
        check = false;
    }
    
    return check;
}

void createAnimal()
{
    string answer;
    int num;
    
    if(!animalIsValid()){
        return;
    }
    
    cout << "======create animal=======\n";
    cout << "1. Cow\n";
    cout << "2. Cat\n";
    cout << "3. Chichen\n";
    cout << "4. Horse\n";
    cout << "==========================\n";
    cin >> answer;
    
    if(answer == "1"){
        animalArr[animalNowIndex] = new Cow;
        setAnimal();
    }
    if(answer == "2"){
        animalArr[animalNowIndex] = new Cat;
        setAnimal();
    }
    if(answer == "3"){
        animalArr[animalNowIndex] = new Chicken;
        setAnimal();
    }
    if(answer == "4"){
        animalArr[animalNowIndex] = new Horse;
        setAnimal();
    }
    
    for(num = maxAnimalNum;num >= 0;num--){
        if(!animalArrIsAssigned(num)){
            animalNowIndex = num;
        }
    }
    
    if(animalLastIndex < animalNowIndex){
        animalLastIndex = animalNowIndex;
    }
    animalTotalNumber++;
}

void setAnimal()
{
    int energy, eatPeriod, maxFoodAmt;
    string name;
    
    cout << "Enter a name for your animal:\n";
    cin >> name;
    animalArr[animalNowIndex]->setName(name);

    cout << "Enter energy for your animal:\n";
    cin >> energy;
    animalArr[animalNowIndex]->setEnergyLevel(energy);
    
    animalArr[animalNowIndex]->setTroughSlotNum(animalNowIndex);
    
    cout << "Enter the period of each eating instant:\n";
    cin >> eatPeriod;
    animalArr[animalNowIndex]->setEatPeriod(eatPeriod);
    
    cout << "Enter maximun food amount that can be eaten each time from its trough:\n";
    cin >> maxFoodAmt;
    animalArr[animalNowIndex]->setMaxFoodAmt(maxFoodAmt);
}

void feed()
{
    int troughNumber, number;
    
    showTroughInfo();
    
    cout << endl << endl;
    cout << "Trough_num: \n";
    cin >> troughNumber;
    
    if(!troughIsValid(troughNumber)){
        return;
    }
    
    cout << "How many: \n";
    cin >> number;
    troughArr[troughNumber] += number;
    showTroughInfo();
}

void showTroughInfo()
{
    int troughNum;
    
    cout << "======TROUGH_INFOMATION=======\n";
    for(troughNum = 0;troughNum < maxTroughNum;troughNum++){
        cout << setw(3) << troughNum << ". capacity: " << setw(4) << troughArr[troughNum];
        if(animalArrIsAssigned(troughNum)){
        cout << " ==> name: " << setw(4) << animalArr[troughNum]->getName()
             << "  energy_level: " << setw(4) << animalArr[troughNum]->getEnergyLevel();
        }else{
            cout << " ==> No one using";
        }
        cout << endl;
    }
    cout << "==============================\n\n\n";
}

void display()
{
    cout << "======ANIMAL_INFOMATION=======\n";
    for(int i = 0;i <= animalLastIndex;i++){
        if(animalArrIsAssigned(i)){
            animalArr[i]->show();
        }
    }
    cout << "==============================\n\n\n";
}

void call()
{
    int animalIndex, startIndex = 0, endIndex = animalLastIndex;
    int answer;
    
    cout << "====Yell====\n";
    cout << "  0. ==> ALL\n";

    for(animalIndex = 0;animalIndex <= animalLastIndex;animalIndex++){
        if(animalArrIsAssigned(animalIndex)){
            cout << setw(3) << animalIndex+1 << ".  ==>  name: "
                 << setw(4) << animalArr[animalIndex]->getName() << endl;
        }
    }
    cin >> answer;
    
    
    if(answer != 0){
        startIndex = answer - 1;
        endIndex = answer;
    }
    cout << "======YO!YO!MAN!!=====\n";
    for(animalIndex = startIndex;animalIndex < endIndex;animalIndex++){
        if(animalArrIsAssigned(animalIndex)){
            cout << "name: " << setw(4) << animalArr[animalIndex]->getName() << endl;
            animalArr[animalIndex]->yell();
        }
    }
    cout << "=======================\n\n\n";

}

void advance()
{
    int animalNum;
    
    for(animalNum = 0;animalNum <= animalLastIndex;animalNum++){
        if(animalArrIsAssigned(animalNum)){
            animalArr[animalNum]->active(troughArr);
        }
    }
    
    checkDecease();
}

void checkDecease()
{
    int animalNum, lastNum = 0;
    bool firstDelete = true;
    
    for(animalNum = 0;animalNum <= animalLastIndex;animalNum++){
        if(animalArrIsAssigned(animalNum)){
            if(animalArr[animalNum]->getEnergyLevel() <= 0){
                cout << setw(4) << animalArr[animalNum]->getName() << " is dead" << endl;
                animalArr[animalNum] = nullptr;
                
                if((animalNowIndex > animalNum) && firstDelete){
                    animalNowIndex = animalNum;
                }
                
                firstDelete = false;
                animalTotalNumber--;
            }else{
                lastNum = animalNum;
            }
        }
    }
    animalLastIndex = lastNum;
}

