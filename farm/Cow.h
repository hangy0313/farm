//
//  Cow.h
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#ifndef __farm__Cow__
#define __farm__Cow__

#include <iostream>
#include "Animal.h"

class Cow:public Animal
{
public:
    Cow();
    virtual void yell();
};

#endif /* defined(__farm__Cow__) */
