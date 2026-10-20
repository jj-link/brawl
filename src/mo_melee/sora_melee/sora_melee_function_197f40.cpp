#include <types.h>
#pragma force_active on

struct FnBits {
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_197F40(void* p, u32 v) {
    FnBits* b = (FnBits*)((char*)p + 8);
    b->hi = v;
}
