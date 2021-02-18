#ifndef LOADDLLA_H
#define LOADDLLA_H

#include <LoadIDll.h>
#include "../FactoryObject/LoadDllFactory.h"

class LoaddllA : public LoadIDll
{

public:
    LoaddllA();
public:
    virtual int add(int ,int ) ;
};
DEF_LAODDLL_CONSTRUCTOR(LoaddllA);
#endif // LOADDLLA_H
