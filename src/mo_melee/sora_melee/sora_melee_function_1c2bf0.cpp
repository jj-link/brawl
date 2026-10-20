#include <types.h>
#pragma force_active on

struct SubRet {
    u32 m_pad;
    u32 m_val;
};

class SubObj {
public:
    virtual void f1();
    virtual SubRet* f3();
};

class Owner {
public:
    u32 m_pad[4];
    SubObj m_sub;
};

extern "C" u32 fn_27_1C2BF0(Owner* self) {
    return self->m_sub.f3()->m_val;
}
