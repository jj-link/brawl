#include <types.h>
#pragma force_active on

typedef struct {
    u32 a;
    u32 b;
    u32 hi : 2;
    u32 lo : 30;
} Flags;

extern "C" void fn_27_198E74(Flags* p, u32 v) {
    p->hi = v;
}
