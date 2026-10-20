#include <types.h>
#pragma force_active on

struct FieldObj {
    u8 pad[8];
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_D1F44(void* p, u32 v) {
    ((FieldObj*)p)->hi = v;
}
