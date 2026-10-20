#include <types.h>
#pragma force_active on

struct fn27Node {
    u32 m_0;
    u32 m_4;
};

class fn27Src {
public:
    virtual void vf0();
    virtual fn27Node* vf3(s32 index);
};

struct fn27Work {
    s32 m_0;
    s16 m_4;
    s16 m_6;
    u8 m_8[0x33 - 8];
    u8 m_33;
};

extern "C" void fn_27_41E20(fn27Work* work, fn27Src* src) {
    if (work->m_33 == 1) {
        for (s32 i = 0; i < work->m_6; i++) {
            fn27Node* node = src->vf3(work->m_4 + i);
            node->m_0 = node->m_4;
        }
        work->m_33 = 0;
    }
}
