#include <types.h>
#pragma force_active on

class fnObj27 {
public:
    virtual void f0(s32 a, s32 b);
    virtual void f1(s32 a, s32 b);
    virtual void f2(s32 a, s32 b);
};

extern "C" void fn_27_C2C18(fnObj27* self, s32 base, s32 count, s32 mod) {
    for (s32 i = count - 1; i >= 0; i--) {
        s32 a = base + i;
        if (a >= mod) {
            a -= mod;
        }
        s32 b = a + 1;
        if (b >= mod) {
            b -= mod;
        }
        self->f0(a, b);
    }
}
