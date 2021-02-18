#include "classinfo.h"

#include "object.h"

#include <QLibrary>


bool Register(ClassInfo *ci)
{
    return Object::Register(ci);
}

void ClassInfo::loadlib(QString name)
{
    QLibrary hdll(name );
}

ClassInfo::ClassInfo( const string ClassName,ObjectConstructorFn fun )
    :m_classname(ClassName),m_objectconstructor(fun)
{
    Register(this);
}

ClassInfo::~ClassInfo()
{}

Object* ClassInfo::CreateObject()const
{
    return m_objectconstructor ? (*m_objectconstructor)():0;
}

bool ClassInfo::IsDynamic()const
{
    return NULL != m_objectconstructor;
}

ObjectConstructorFn ClassInfo::GetConstructor()const
{
    return m_objectconstructor;
}

