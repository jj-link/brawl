#include <types.h>
#pragma force_active on

extern "C" {
typedef struct {
    u32 pad0;
    u32 pad4;
    u32 flags;
} fn_27_1A3DEC_obj;

void fn_27_1A3DEC(fn_27_1A3DEC_obj* p) {
    p->flags &= 0xFFFFFFFD;
}
}
