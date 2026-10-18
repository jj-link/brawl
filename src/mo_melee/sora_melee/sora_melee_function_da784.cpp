#include <types.h>
#pragma force_active on

struct fnInner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(s32 value);
};

struct fnOuter {
    u32 unk0;
    u32 unk4;
    fnInner* m_inner;
};

extern "C" {
void fn_27_DA784(fnOuter* outer, s16 value) {
    outer->m_inner->v10(value);
}
}
