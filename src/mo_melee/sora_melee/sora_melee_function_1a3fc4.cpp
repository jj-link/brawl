#include <types.h>
#pragma force_active on

struct FnBits {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A3FC4(void* p, u32 v) {
    FnBits* f = (FnBits*)((char*)p + 8);
    f->b = v;
}
