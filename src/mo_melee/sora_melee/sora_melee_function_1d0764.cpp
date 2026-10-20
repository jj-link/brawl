#include <types.h>
#pragma force_active on

struct MyStruct {
    u32 m_0;
    u32 m_4;
    struct {
        u32 a : 4;
        s32 b : 4;
        u32 c : 24;
    } m_8;
};

extern "C" s32 fn_27_1D0764(MyStruct* self) {
    return self->m_8.b;
}
