#include <types.h>
#pragma force_active on

struct BitField {
    u32 low : 4;
    u32 high : 28;
};

extern "C" void fn_27_2649D4(void* base, u32 val) {
    BitField* p = (BitField*)((u8*)base + 8);
    p->low = val;
}
