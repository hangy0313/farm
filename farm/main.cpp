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

void createAnimal(Animal* a[], int &index);
void giveName(Animal* a[], int &index);
void giveEnergy(Animal* a[], int &index);
void assignTrough(Animal* a[], int &index);
bool checkTrough(Animal* a[], int &index, int num);

void feed(Animal* a[], int &index, int troughArr[]);
void showTroughInfo(Animal* a[], int &index, int troughArr[]);

void display(Animal* a[], int &index);

void call(Animal* a[], int &index);
template <class T>
void call(Animal* a[], int &index, T t);
void call(Animal* a[], int &index, bool all);

void advance(Animal* a[], int &index, int troughArr[]);
void checkDecease(Animal* a[], int &index, int troughArr[]);

int main(int argc, const char * argv[])
{
    int index = 0, trough[maxTroughNum] = {0};
    string ans, name;
    Animal *arr[maxAnimalNum];
    
    
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
            createAnimal(arr, index);
        }
        if(ans == "2"){
            feed(arr, index, trough);
        }
        if(ans == "3"){
            display(arr, index);
            showTroughInfo(arr, index, trough);
        }
        if(ans == "4"){
            call(arr, index);
        }
        if(ans == "5"){
            advance(arr, index, trough);
        }

        if(ans == "end"){
            break;
        }
    }

    return 0;
}

void createAnimal(Animal* a[], int &index)
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
        a[index] = new Cow;
        giveName(a, index);
        index++;
    }
    if(answer == "2"){
        a[index] = new Cat;
        giveName(a, index);
        index++;
    }
    if(answer == "3"){
        a[index] = new Chicken;
        giveName(a, index);
        index++;
    }
    if(answer == "4"){
        a[index] = new Horse;
        giveName(a, index);
        index++;
    }
}

void giveName(Animal* a[], int &index)
{
    string name;
    
    cout << "Enter a name for your animal:\n";
    cin >> name;
    a[index]->setName(name);
    giveEnergy(a, index);
}

void giveEnergy(Animal* a[], int &index)
{
    int energy;
    
    cout << "Enter energy for your animal:\n";
    cin >> energy;
    a[index]->setEnergyLevel(energy);
    assignTrough(a, index);
}

void assignTrough(Animal* a[], int &index)
{
    int num;
    
    do{
        cout << "assign a trough for your animal:\n";
        cin >> num;
        
    }while(!checkTrough(a, index, num));
            
    a[index]->setTroughSlotNum(num);
}

bool checkTrough(Animal* a[], int &index, int num)
{
    bool check = true;
    
    for(int i = 0;i < index;i++){
        if(num == a[i]->getTroughSlotNum()){
            check = false;
            cout << "trough_num: " << num << " is used\n";
            break;
        }
    }
    
    return check;
}

void feed(Animal* a[], int &index, int troughArr[])
{
    int troughNumber, number;
    
    showTroughInfo(a, index, troughArr);
    
    cout << endl << endl;
    cout << "Trough_num: \n";
    cin >> troughNumber;
    cout << "How many: \n";
    cin >> number;
    troughArr[troughNumber] += number;
    
    showTroughInfo(a, index, troughArr);
}

void showTroughInfo(Animal* a[], int &index, int troughArr[])
{
    int troughNum, animalNum;
    
    cout << "======TROUGH_INFOMATION=======\n";
    for(troughNum = 0;troughNum < maxTroughNum;troughNum++){
        cout << "trough_num: " << troughNum << "  " << troughArr[troughNum] << " ";
        for(animalNum = 0;animalNum < index;animalNum++){
            if(troughNum == a[animalNum]->getTroughSlotNum()){
                cout << endl << "====> name: " << a[animalNum]->getName()
                     << "energy_level: " << a[animalNum]->getEnergyLevel();
                
                continue;
            }
        }
        cout << endl;
    }
    cout << "==============================\n\n\n";
}

void display(Animal* a[], int &index)
{
    cout << "======ANIMAL_INFOMATION=======\n";
    for(int i = 0;i < index;i++){
        a[i]->show();
    }
    cout << "==============================\n\n\n";
}


template <class T>
void call(Animal* a[], int &index, T t) {
    int i;
    
    cout << "======YO!YO!MAN!!=====\n";
    for(i = 0;i < index;i++){
        if(typeid(t).name() == typeid(*a[i]).name()){
            cout << "name: " << a[i]->getName() << endl;
            a[i]->yell();
            cout << endl;
        }
    }
    cout << "=======================\n\n\n";
}

void call(Animal* a[], int &index, bool all)
{
    int i;
    
    cout << "======YO!YO!MAN!!=====\n";
    for(i = 0;i < index;i++){
        cout << "name: " << a[i]->getName() << endl;
        a[i]->yell();
        cout << endl;
    }
    cout << "=======================\n\n\n";
}

void call(Animal* a[], int &index)
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
        call(a, index, c);
    }else if(answer == "2"){
        Cat c;
        call(a, index, c);
    }else if(answer == "3"){
        Chicken c;
        call(a, index, c);
    }else if(answer == "4"){
        Horse h;
        call(a, index, h);
    }else{
        all = 1;
        call(a, index, all);
    }
}

void advance(Animal* a[], int &index, int troughArr[])
{
    int animalNum;
    
    for(animalNum = 0;animalNum < index;animalNum++){
        a[animalNum]->active(troughArr);
    }
    
    checkDecease(a, index, troughArr);
}

void checkDecease(Animal* a[], int &index, int troughArr[])
{
    int animalNum, nowIndex;
    
    for(animalNum = 0;animalNum < index;animalNum++){
        if(a[animalNum]->getEnergyLevel() <= 0){
            cout << a[animalNum]->getName() << " is dead" << endl;
            troughArr[a[animalNum]->getTroughSlotNum()] = 0;
            
            delete a[animalNum];
            for(nowIndex = animalNum;nowIndex < index-1;nowIndex++){
                a[nowIndex] = a[nowIndex+1];
            }
            a[nowIndex] = NULL;
            
            index--;
        }
    }
}

