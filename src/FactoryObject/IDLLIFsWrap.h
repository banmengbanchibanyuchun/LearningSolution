#ifndef IDLLIFSWRAP_H
#define IDLLIFSWRAP_H


class IDLLIFsWrap
{
public:
    virtual void DeleteSelf( ) = 0;
    virtual int Add(int x, int y) = 0;
};

extern "C" __declspec(dllexport) long CreateIFsWrapObj(IDLLIFsWrap** ppObj);

#endif // IDLLIFSWRAP_H
