#include <types.h>
#pragma force_active on

struct Request {
    u32 m_id;
    u16 m_flag;
};

class Callee {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual s32 request(Request* request, s32 id, u16* flag, s8 param4);
};

struct Holder {
    u32 _0;
    u32 _4;
    Callee* m_obj;
};

extern "C" s16 fn_27_1B1658(Holder* holder, u32 id, s8 flag) {
    Request request;
    request.m_id = id;
    request.m_flag = 0;
    return holder->m_obj->request(&request, -1, &request.m_flag, flag);
}
