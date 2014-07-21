//
//  Cat.h
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#ifndef __farm__Cat__
#define __farm__Cat__

#include <iostream>
#include "Animal.h"

class Cat:public Animal
{
public:
    virtual void yell();
};

#endif /* defined(__farm__Cat__) */
