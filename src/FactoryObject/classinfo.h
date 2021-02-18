#ifndef CLASSINFO_H
#define CLASSINFO_H

#include <map>
#include <string>
#include <iostream>
#include <qDebug>
#include "FactoryObject_global.h"

using namespace std;

class Object;
class ClassInfo;

static std::map< string,ClassInfo*> classInfoMap;  //全局map,存放名称,类信息指针对
typedef Object* (*ObjectConstructorFn)(void);


class FACTORYOBJECT_EXPORT ClassInfo
{
public:
    static void loadlib(QString name );
    ClassInfo(const string ClassName,ObjectConstructorFn fun);
    virtual ~ClassInfo();
    Object* CreateObject()const;
    bool IsDynamic()const ;
    ObjectConstructorFn GetConstructor()const;
public:
    string m_classname;
    ObjectConstructorFn m_objectconstructor;
};

#define DECLARE_CLASS(name)	;\
    protected:	\
        static ClassInfo ms_classinfo;    \
    public:	\
        virtual ClassInfo* GetClassInfo() const; \
        static Object* CreateObject();    //这个createobject是传递给ms_classinfo中,
                                          //当遍历classInfoMap时, 可以用于创建实例

#define IMPLEMENT_CLASS_COMMON(name, func)	\
        ClassInfo name::ms_classinfo(#name, (ObjectConstructorFn)func); \
        ClassInfo* name::GetClassInfo() const\
        { return &name::ms_classinfo;}

#define IMPLEMENT_CLASS(name)	\
        IMPLEMENT_CLASS_COMMON(name, name::CreateObject) \
        Object* name::CreateObject()\
        {return new name;}


#endif // CLASSINFO_H


