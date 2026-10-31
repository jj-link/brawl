#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_501F4(void *self, s32 idx);

typedef struct Flags {
    u32 a : 8;
    u32 b : 8;
    u32 c : 15;
    u32 d : 1;
} Flags;

void fn_27_502EC(void *self, s32 idx) {
    Flags *p = (Flags *)(*(u8 **)((u8 *)self + 0xa4) + idx * 0x34 + 0x28);
    p->b = p->b - 1;

    Flags *q = (Flags *)(*(u8 **)((u8 *)self + 0xa4) + idx * 0x34 + 0x28);
    if (q->b != 0) {
        return;
    }
    if (q->d == 0) {
        return;
    }
    fn_27_501F4(self, idx);
}
}
