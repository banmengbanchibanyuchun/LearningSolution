#ifndef LOADDLLFACTORY_H
#define LOADDLLFACTORY_H


#include <QStringList>
#include <map>


#include "FactoryObject_global.h"


typedef bool (*FnRegisterLoadDlls)() ;
#define  REGISTER_LOADDLL extern "C" __declspec(dllexport) bool RegisterLoadDlls()

//#define ;
class LoadIDll;
class LoadIDllConstrucor;


struct LoadDllDetail
{
    QString dllname;
    QString classname;
    QString desc;
    QString path;
};

class FACTORYOBJECT_EXPORT LoadDllFactory
{
public:
    static LoadDllFactory * Instance();
    bool LoadElements( QStringList  elments  = QStringList() );
    bool LoadElementsLibrary();
    void RegisterConstructor(LoadIDllConstrucor * loadIDllConstrucor);
    QVector<LoadDllDetail> GetCollection();
    LoadIDll *Create( const QString & name );
private:
    LoadDllFactory();
    ~LoadDllFactory();

    void ReadConfig();
    std::map<QString, LoadIDllConstrucor*> Constructormap;
    QVector<LoadDllDetail> DetailVector;
};


class FACTORYOBJECT_EXPORT LoadIDllConstrucor
{
public:
    virtual LoadIDll * Construcor() = 0;
    virtual const QString GetClassName() = 0;
};

#define DEF_LAODDLL_CONSTRUCTOR(a) \
    class a##Construcor :public LoadIDllConstrucor \
    {                                               \
    public:                                     \
        virtual LoadIDll * Construcor()         \
        {                                         \
            LoadIDll * inst = new a();          \
            return inst;        \
        }                           \
        virtual const QString GetClassName() \
        {                                   \
            return #a;              \
        }                   \
    };


#define IMPL_REGISTER_LOADDLL(A) \
    LoadIDllConstrucor *ctor = new  A##Construcor;  \
    LoadDllFactory::Instance()->RegisterConstructor(ctor);

#endif // LOADDLLFACTORY_H
