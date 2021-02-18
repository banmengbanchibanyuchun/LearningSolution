#include "LoadDllFactory.h"

#include <QLibrary>

LoadDllFactory * LoadDllFactory::Instance()
{
    static LoadDllFactory instance1;
    return  &instance1;
}

bool LoadDllFactory::LoadElements(QStringList elments)
{
    return  false;
}

bool LoadDllFactory::LoadElementsLibrary()
{
    for( int i = 0 ; i< DetailVector.size();++i)
    {
        LoadDllDetail detail = DetailVector[i];

        QLibrary m_myDllHInst( detail.path + detail.dllname );
        if(m_myDllHInst.load())
        {
             FnRegisterLoadDlls funCreateObj = (FnRegisterLoadDlls)m_myDllHInst.resolve("RegisterLoadDlls");

             if(funCreateObj())
             {
             }
        }

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
        、*/
    }
    return  false;
}

void LoadDllFactory::RegisterConstructor(LoadIDllConstrucor *loadIDllConstrucor)
{
    Constructormap[loadIDllConstrucor->GetClassName()] = loadIDllConstrucor;
}

QVector<LoadDllDetail> LoadDllFactory::GetCollection()
{
    return DetailVector;
}

LoadIDll * LoadDllFactory::Create(const QString &name)
{
    auto it = Constructormap.find( name );
    if( it !=  Constructormap.end())
    {
        return it->second->Construcor() ;
    }
    return NULL;
}

LoadDllFactory::LoadDllFactory()
{
    ReadConfig();
    //LoadElementsLibrary();
}

LoadDllFactory::~LoadDllFactory()
{

}

void LoadDllFactory::ReadConfig()
{
    LoadDllDetail detail;
    detail.dllname = "FactoryObjectA.dll";
    detail.classname = "LoaddllA";
    DetailVector.push_back( detail );
}
