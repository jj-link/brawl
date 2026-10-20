#include <types.h>
#pragma force_active on

struct soEntry {
    u8 m_pad0[9];
    s8 m_val;
    u8 m_pad1[2];
};

class soFoo {
public:
    virtual ~soFoo();
    virtual void v2();
    virtual bool v4();

    u32 m_4;
    soEntry* m_8;
    s32 m_c;
};

extern "C" {
bool fn_27_1B19D0(soFoo* p) {
    if (!p->v4()) {
        p->m_c = -1;
        return false;
    }
    p->m_c = (s8)(p->m_8 + p->m_c)->m_val;
    return true;
}
}
