#include <types.h>
#pragma force_active on

typedef struct {
    u32 pad[2];
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
} FnState;

extern "C" void fn_27_CBA90(FnState* p, u32 v) {
    p->f = v;
}
