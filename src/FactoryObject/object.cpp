#include "object.h"



Object::Object()
{

}

Object::~Object()
{

}

bool Object::Register(ClassInfo* ci)
{
    if(ci)
    {
        if(classInfoMap.find(ci->m_classname) == classInfoMap.end())
        {
            classInfoMap.insert(std::map< string,ClassInfo*>::value_type(ci->m_classname,ci));
        }
    }
    return true;
}

Object* Object::CreateObject(std::string name)
{
    std::map< string,ClassInfo*>::const_iterator iter = classInfoMap.find(name);
    if(iter != classInfoMap.end() )
    {
        return iter->second->CreateObject();
    }
    return NULL;
}
IMPLEMENT_CLASS(Object)




