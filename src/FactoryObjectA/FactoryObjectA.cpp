#include "FactoryObjectA.h"

#include "qdebug.h"

FactoryObjectA::FactoryObjectA()
{
    qDebug()<<" A constructor!";
}

IMPLEMENT_CLASS(FactoryObjectA)
