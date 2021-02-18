#ifndef OBJECT_H
#define OBJECT_H

#include "classinfo.h"
#include "FactoryObject_global.h"


class FACTORYOBJECT_EXPORT Object
{
   DECLARE_CLASS(Object);
public:
    Object();
    virtual ~Object();
    static bool Register(ClassInfo* ci);
    static Object* CreateObject(string name);    //基类提供公共接口, 以便其子类拥有动态创建的能力
};


#endif // OBJECT_H
