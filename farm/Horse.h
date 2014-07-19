//
//  Horse.h
//  farm
//
//  Created by hangy on 2014/7/19.
//  Copyright (c) 2014年 hangy. All rights reserved.
//

#ifndef __farm__Horse__
#define __farm__Horse__

#include <iostream>
#include "Animal.h"

class Horse:public Animal
{
public:
    Horse();
    virtual void yell();
};

#endif /* defined(__farm__Horse__) */
