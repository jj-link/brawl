#include <types.h>
#pragma force_active on

struct BitFields {
    unsigned high : 4;
    unsigned low : 28;
};

extern "C" void fn_27_295AC4(void* a, u32 b) {
    struct BitFields* p = (struct BitFields*)((u8*)a + 8);
    p->high = b;
}
