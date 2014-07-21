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
static int animalArrIndex = 0;

bool animalIsValid();
bool troughIsValid(int num);

void createAnimal();
void setAnimal();

bool troughIsUsed(int num);

void feed();
void showTroughInfo();

void display();

void call();
template <class T>
void call(T t);

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
    
    check = animalArrIndex < maxAnimalNum;
    
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

void createAnimal()
{
    string answer;
    
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
        animalArr[animalArrIndex] = new Cow;
        setAnimal();
        animalArrIndex++;
    }
    if(answer == "2"){
        animalArr[animalArrIndex] = new Cat;
        setAnimal();
        animalArrIndex++;
    }
    if(answer == "3"){
        animalArr[animalArrIndex] = new Chicken;
        setAnimal();
        animalArrIndex++;
    }
    if(answer == "4"){
        animalArr[animalArrIndex] = new Horse;
        setAnimal();
        animalArrIndex++;
    }
}

void setAnimal()
{
    int energy, eatPeriod, maxFoodAmt;
    string name;
    
    cout << "Enter a name for your animal:\n";
    cin >> name;
    animalArr[animalArrIndex]->setName(name);

    cout << "Enter energy for your animal:\n";
    cin >> energy;
    animalArr[animalArrIndex]->setEnergyLevel(energy);
    
    animalArr[animalArrIndex]->setTroughSlotNum(animalArrIndex);
    
    cout << "Enter the period of each eating instant:\n";
    cin >> eatPeriod;
    animalArr[animalArrIndex]->setEatPeriod(eatPeriod);
    
    cout << "Enter maximun food amount that can be eaten each time from its trough:\n";
    cin >> maxFoodAmt;
    animalArr[animalArrIndex]->setMaxFoodAmt(maxFoodAmt);
}

bool troughIsUsed(int num)
{
    bool check = false;
    
    for(int i = 0;i < animalArrIndex;i++){
        if(num == animalArr[i]->getTroughSlotNum()){
            check = true;
            break;
        }
    }
    
    if(check){
        cout << "trough_num: " << setw(3) << num << " is used\n";
    }else{
        cout << "trough_num: " << setw(3) << num << " is no animal used\n";
    }
    
    return check;
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
    
    if(troughIsUsed(troughNumber)){
        return;
    }
    
    cout << "How many: \n";
    cin >> number;
    troughArr[troughNumber] += number;
    showTroughInfo();
}

void showTroughInfo()
{
    int troughNum, animalNum;
    bool used;
    
    cout << "======TROUGH_INFOMATION=======\n";
    for(troughNum = 0;troughNum < maxTroughNum;troughNum++){
        used = false;
        cout << setw(3) << troughNum << ". capacity: " << setw(4) << troughArr[troughNum];
        for(animalNum = 0;animalNum < animalArrIndex;animalNum++){
            if(troughNum == animalArr[animalNum]->getTroughSlotNum()){
                cout << " ==> name: " << setw(4) << animalArr[animalNum]->getName()
                     << "  energy_level: " << setw(4) << animalArr[animalNum]->getEnergyLevel();
                used = true;
                continue;
            }
        }
        if(!used){
            cout << " ==> No one using";
        }
        cout << endl;
    }
    cout << "==============================\n\n\n";
}

void display()
{
    cout << "======ANIMAL_INFOMATION=======\n";
    for(int i = 0;i < animalArrIndex;i++){
        animalArr[i]->show();
    }
    cout << "==============================\n\n\n";
}


template <class T>
void call(T t) {
    int i;
    
    cout << "======YO!YO!MAN!!=====\n";
    for(i = 0;i < animalArrIndex;i++){
        if(typeid(t).name() == typeid(*animalArr[i]).name()){
            cout << "name: " << setw(4) << animalArr[i]->getName() << endl;
            animalArr[i]->yell();
            cout << endl;
        }
    }
    cout << "=======================\n\n\n";
}

void call()
{
    int animalIndex, startIndex = 0, endIndex = animalArrIndex;
    int answer;
    
    cout << "====Yell====\n";
    cout << "  0. ==> ALL\n";

    for(animalIndex = 0;animalIndex < animalArrIndex;animalIndex++){
        cout << setw(3) << animalIndex+1 << ".  ==>  name: "
             << setw(4) << animalArr[animalIndex]->getName() << endl;
    }
    cin >> answer;
    
    
    if(answer != 0){
        startIndex = answer - 1;
        endIndex = answer;
    }
    cout << "======YO!YO!MAN!!=====\n";
    for(animalIndex = startIndex;animalIndex < endIndex;animalIndex++){
            cout << "name: " << setw(4) << animalArr[animalIndex]->getName() << endl;
            animalArr[animalIndex]->yell();
        }
    cout << "=======================\n\n\n";

}

void advance()
{
    int animalNum;
    
    for(animalNum = 0;animalNum < animalArrIndex;animalNum++){
        animalArr[animalNum]->active(troughArr);
    }
    
    checkDecease();
}

void checkDecease()
{
    int animalNum, nowAnimalArrIndex, troughNum;
    
    for(animalNum = 0;animalNum < animalArrIndex;animalNum++){
        if(animalArr[animalNum]->getEnergyLevel() <= 0){
            cout << setw(4) << animalArr[animalNum]->getName() << " is dead" << endl;
            troughArr[animalArr[animalNum]->getTroughSlotNum()] = 0;
            
            delete animalArr[animalNum];
            for(nowAnimalArrIndex = animalNum;nowAnimalArrIndex < animalArrIndex-1;nowAnimalArrIndex++){
                troughNum = animalArr[nowAnimalArrIndex+1]->getTroughSlotNum();
                
                animalArr[nowAnimalArrIndex] = animalArr[nowAnimalArrIndex + 1];
                troughArr[nowAnimalArrIndex] = troughArr[nowAnimalArrIndex + 1];
                animalArr[nowAnimalArrIndex]->setTroughSlotNum(troughNum - 1);
            }
            
            animalArr[nowAnimalArrIndex] = NULL;
            troughArr[nowAnimalArrIndex] = 0;
            animalArrIndex--;
            animalNum--;
        }
    }
}

