//
//  main.cpp
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#include <iostream>
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

void createAnimal();
void giveName();
void giveEnergy();
void assignTrough();
bool troughIsUsed(int num);

void feed();
void showTroughInfo();

void display();

void call();
template <class T>
void call(T t);
void call(bool all);

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

void createAnimal()
{
    string answer;
    
    cout << "======create animal=======\n";
    cout << "1. Cow\n";
    cout << "2. Cat\n";
    cout << "3. Chichen\n";
    cout << "4. Horse\n";
    cout << "==========================\n";
    cin >> answer;
    
    if(answer == "1"){
        animalArr[animalArrIndex] = new Cow;
        giveName();
        animalArrIndex++;
    }
    if(answer == "2"){
        animalArr[animalArrIndex] = new Cat;
        giveName();
        animalArrIndex++;
    }
    if(answer == "3"){
        animalArr[animalArrIndex] = new Chicken;
        giveName();
        animalArrIndex++;
    }
    if(answer == "4"){
        animalArr[animalArrIndex] = new Horse;
        giveName();
        animalArrIndex++;
    }
}

void giveName()
{
    string name;
    
    cout << "Enter a name for your animal:\n";
    cin >> name;
    animalArr[animalArrIndex]->setName(name);
    giveEnergy();
}

void giveEnergy()
{
    int energy;
    
    cout << "Enter energy for your animal:\n";
    cin >> energy;
    animalArr[animalArrIndex]->setEnergyLevel(energy);
    assignTrough();
}

void assignTrough()
{
    int num;
    
    do{
        cout << "assign a trough for your animal:\n";
        cin >> num;
        
    }while(troughIsUsed(num));
            
    animalArr[animalArrIndex]->setTroughSlotNum(num);
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
        cout << "trough_num: " << num << " is used\n";
    }else{
        cout << "trough_num: " << num << " is no animal used\n";
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
    if(troughIsUsed(troughNumber)){
        cout << "How many: \n";
        cin >> number;
        troughArr[troughNumber] += number;
        showTroughInfo();
    }
}

void showTroughInfo()
{
    int troughNum, animalNum;
    bool used;
    
    cout << "======TROUGH_INFOMATION=======\n";
    for(troughNum = 0;troughNum < maxTroughNum;troughNum++){
        used = false;
        cout << "(" << troughNum << ") capacity: " << troughArr[troughNum];
        for(animalNum = 0;animalNum < animalArrIndex;animalNum++){
            if(troughNum == animalArr[animalNum]->getTroughSlotNum()){
                cout << " ==> name: " << animalArr[animalNum]->getName()
                     << "  energy_level: " << animalArr[animalNum]->getEnergyLevel();
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
            cout << "name: " << animalArr[i]->getName() << endl;
            animalArr[i]->yell();
            cout << endl;
        }
    }
    cout << "=======================\n\n\n";
}

void call(bool all)
{
    int i;
    
    cout << "======YO!YO!MAN!!=====\n";
    for(i = 0;i < animalArrIndex;i++){
        cout << "name: " << animalArr[i]->getName() << endl;
        animalArr[i]->yell();
        cout << endl;
    }
    cout << "=======================\n\n\n";
}

void call()
{
    string answer;
    bool all = 0;
    
    cout << "====Yell====\n";
    cout << "0. ALL\n";
    cout << "1. Cow\n";
    cout << "2. Cat\n";
    cout << "3. Chichen\n";
    cout << "4. Horse\n";
    cin >> answer;
    
    if(answer == "1"){
        Cow c;
        call(c);
    }else if(answer == "2"){
        Cat c;
        call(c);
    }else if(answer == "3"){
        Chicken c;
        call(c);
    }else if(answer == "4"){
        Horse h;
        call(h);
    }else{
        all = 1;
        call(all);
    }
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
    int animalNum, nowanimalArrIndex;
    
    for(animalNum = 0;animalNum < animalArrIndex;animalNum++){
        if(animalArr[animalNum]->getEnergyLevel() <= 0){
            cout << animalArr[animalNum]->getName() << " is dead" << endl;
            troughArr[animalArr[animalNum]->getTroughSlotNum()] = 0;
            
            delete animalArr[animalNum];
            for(nowanimalArrIndex = animalNum;nowanimalArrIndex < animalArrIndex-1;nowanimalArrIndex++){
                animalArr[nowanimalArrIndex] = animalArr[nowanimalArrIndex+1];
            }
            
            animalArr[nowanimalArrIndex] = NULL;
            animalArrIndex--;
            animalNum--;
        }
    }
}

