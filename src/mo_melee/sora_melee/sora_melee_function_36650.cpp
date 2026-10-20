#include <types.h>
#pragma force_active on

class soSomeObj {
public:
    virtual void vf0();
    virtual soSomeObj* vf1();
    virtual void vf2();
    virtual void vf3();
    char pad[0x34];
    void* m_38;
    void* m_3c;
};

struct soOuter {
    char pad[8];
    soSomeObj* m_08;
};

extern "C" void fn_27_37D7C(void*, void*, s32, s32);

extern "C" void fn_27_36650(soOuter* a, void* b, s32 c) {
    soSomeObj* obj = a->m_08->vf1();
    fn_27_37D7C(obj, obj->m_38, 1, c);
    fn_27_37D7C(obj, obj->m_3c, 1, c);
}
