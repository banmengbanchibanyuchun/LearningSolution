#include "LoaddllA.h"

LoaddllA::LoaddllA()
{

}

int LoaddllA::add(int a, int b)
{

    return a+b;
}

REGISTER_LOADDLL
{
    IMPL_REGISTER_LOADDLL(LoaddllA);
}
