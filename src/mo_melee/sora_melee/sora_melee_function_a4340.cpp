#include <types.h>
#pragma force_active on

class IBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

class Holder {
public:
    u8 m_pad[0x30];
    IBase* m_obj;
};

extern "C" void fn_27_A75A4();

extern "C" void fn_27_A4340(Holder* p) {
    p->m_obj->v1();
    fn_27_A75A4();
}
