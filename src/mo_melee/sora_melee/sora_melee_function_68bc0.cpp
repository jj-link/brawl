#include <types.h>
#pragma force_active on

class fnChild {
public:
    virtual void f0();
    virtual fnChild* f1();
    u32 m_04;
    u32 m_08;
};

class fnParent {
public:
    u8 m_pad[0x14];
    fnChild* m_child;
    s32 m_key;
};

extern "C" void fn_27_68BC0(fnParent* p, s32 key, u32 val) {
    if (p->m_key == key) {
        p->m_child->f1()->m_08 = val;
    }
}
