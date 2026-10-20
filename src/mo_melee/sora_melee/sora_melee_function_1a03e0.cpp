#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 c : 7;
    u32 d : 25;
};

extern "C" void fn_27_1A03E0(X* self, u32 v) {
    self->c = v;
}
