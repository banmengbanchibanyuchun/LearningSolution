#pragma warning(disable:4786)
#include <map>
#include <string>
#include <iostream>
#include <qDebug>
#include <Object.h>
#include <ClassInfo.h>
#include <QLibrary>
#include <IDLLIFsWrap.h>
#include <LoadDllFactory.h>

#include <LoadIDll.h>
#include <windows.h>

using namespace std;
/*
class Object;
class ClassInfo;

static std::map< string,ClassInfo*> classInfoMap;  //全局map,存放名称,类信息指针对
typedef Object* (*ObjectConstructorFn)(void);
bool Register(ClassInfo* ci);

class ClassInfo
{
public:
    ClassInfo(const string ClassName,ObjectConstructorFn fun)
        :m_classname(ClassName),m_objectconstructor(fun)
    { Register(this); }
    virtual ~ClassInfo(){};
    Object* CreateObject()const { return m_objectconstructor ? (*m_objectconstructor)():0;}
    bool IsDynamic()const { return NULL != m_objectconstructor;}
    ObjectConstructorFn GetConstructor()const{ return m_objectconstructor;}
public:
    string m_classname;
    ObjectConstructorFn m_objectconstructor;
};

#define DECLARE_CLASS(name)	\
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



class Object
{
    DECLARE_CLASS(Object)
public:
    Object(){};
    virtual ~Object(){};
    static bool Register(ClassInfo* ci);
    static Object* CreateObject(string name);    //基类提供公共接口, 以便其子类拥有动态创建的能力
};
IMPLEMENT_CLASS(Object)

bool Object::Register(ClassInfo* ci)
{
    if(ci)  {
        if(classInfoMap.find(ci->m_classname) == classInfoMap.end()){
            classInfoMap.insert(std::map< string,ClassInfo*>::value_type(ci->m_classname,ci));
        }
    }
    return true;
}

Object* Object::CreateObject(std::string name)
{
    std::map< string,ClassInfo*>::const_iterator iter = classInfoMap.find(name);
    if(iter != classInfoMap.end() )  {
        return iter->second->CreateObject();
    }
    return NULL;
}

bool Register(ClassInfo* ci)
{
    return Object::Register(ci);
}

class A:public Object
{
    DECLARE_CLASS(A)
public:
    A(){qDebug()<<hex<<(long)this<<" A constructor!"<<endl;};
    virtual ~A(){};
};
IMPLEMENT_CLASS(A)
*/
int main(int argc, char* argv[])
{
   // QLibrary hdll("FactoryObjectA.dll" );
   // ClassInfo::loadlib("FactoryObjectA.dll");
   // Object* a = Object::CreateObject("A");

    /*
    IDLLIFsWrap*        m_pIFsWrapObj;
    typedef long (*FunCreateIFsWrapObj)(IDLLIFsWrap **pp_obj);
    QLibrary m_myDllHInst( "FactoryObjectA.dll" );
    if( m_myDllHInst.load() )
    {

        FunCreateIFsWrapObj funCreateObj = (FunCreateIFsWrapObj)m_myDllHInst.resolve("CreateIFsWrapObj");
        if (nullptr == funCreateObj)
        {
            m_myDllHInst.unload();
            return FALSE;
        }

        if (0 != funCreateObj(&m_pIFsWrapObj))
        {
             m_myDllHInst.unload();
            return FALSE;
        }

       int result =  m_pIFsWrapObj->Add( 1,2 );
       qDebug()<<("  result：")<<result;
    }

*/
    /*
    HINSTANCE           m_myDllHInst;
    IDLLIFsWrap*        m_pIFsWrapObj;
    typedef long (*FunCreateIFsWrapObj)(IDLLIFsWrap **pp_obj);
    m_myDllHInst = LoadLibrary(("MyDLL.dll"));

    if (nullptr == m_myDllHInst)
        return FALSE;

    FunCreateIFsWrapObj funCreateObj = (FunCreateIFsWrapObj)GetProcAddress(m_myDllHInst, "CreateIFsWrapObj");
    if (nullptr == funCreateObj)
    {
        FreeLibrary(m_myDllHInst);
        m_myDllHInst = nullptr;
        return FALSE;
    }

    if (0 != funCreateObj(&m_pIFsWrapObj))
    {
        ASSERT(nullptr == m_pIFsWrapObj);
        FreeLibrary(m_myDllHInst);
        m_myDllHInst = nullptr;
        return FALSE;
    }

    ASSERT(nullptr != m_myDllHInst);
    ASSERT(nullptr != m_pIFsWrapObj);

*/

    LoadDllFactory::Instance()->LoadElementsLibrary();
    LoadIDll * dll = LoadDllFactory::Instance()->Create( "LoaddllA" );

    qDebug()<<("  Hello World!\n")<<dll->add(1,2);
    getchar();
    return 0;
}
