//
//  Chicken.h
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#ifndef __farm__Chicken__
#define __farm__Chicken__

#include <iostream>
#include "Animal.h"

class Chicken:public Animal
{
public:
    virtual void yell();
};

#endif /* defined(__farm__Chicken__) */
