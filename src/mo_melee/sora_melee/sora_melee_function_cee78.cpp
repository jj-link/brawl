#include <types.h>
#pragma force_active on

struct X {
    int a;
    int b;
    s32 m_8;
};

extern "C" s32 fn_27_CEE78(X* self) {
    return self->m_8 >> 26;
}
