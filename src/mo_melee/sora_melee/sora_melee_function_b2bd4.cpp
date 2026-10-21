#include <types.h>
#pragma force_active on

extern "C" void fn_27_B1D60(void* o, u32 v);

class Inner {
public:
    virtual void v0();
    virtual void* at(s32 i);
    virtual void v2();
    virtual s32 size();
};

struct Outer {
    char _pad[0x18];
    Inner* m_inner;
};

extern "C" void fn_27_B2BD4(Outer* self, u32 v, s32 idx) {
    if (idx == -1) {
        s32 n = self->m_inner->size();
        for (s32 i = 0; i < n; i++) {
            fn_27_B1D60(self->m_inner->at(i), v);
        }
    } else {
        fn_27_B1D60(self->m_inner->at(idx), v);
    }
}
