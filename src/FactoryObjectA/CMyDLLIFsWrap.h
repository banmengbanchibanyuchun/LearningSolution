#ifndef CMYDLLIFSWRAP_H
#define CMYDLLIFSWRAP_H

#include <IDLLIFsWrap.h>


class CMyDLLIFsWrap : public IDLLIFsWrap
{
public:
    CMyDLLIFsWrap();
    virtual ~CMyDLLIFsWrap();
    virtual void DeleteSelf();
    virtual int Add(int x, int y);
};

#endif // CMYDLLIFSWRAP_H
