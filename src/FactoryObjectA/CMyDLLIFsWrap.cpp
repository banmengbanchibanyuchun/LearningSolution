#include "CMyDLLIFsWrap.h"

long CreateIFsWrapObj(IDLLIFsWrap** ppObj)
{
    *ppObj = new CMyDLLIFsWrap();
    return 0;
}

CMyDLLIFsWrap::CMyDLLIFsWrap()
{
}
CMyDLLIFsWrap::~CMyDLLIFsWrap()
{
}

void CMyDLLIFsWrap::DeleteSelf(void)
{
    delete this;
}

int CMyDLLIFsWrap::Add(int x, int y)
{
    return x + y;
}
