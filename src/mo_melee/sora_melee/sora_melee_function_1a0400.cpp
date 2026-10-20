#include <types.h>
#pragma force_active on

typedef struct {
    unsigned : 7;
    unsigned field : 7;
    unsigned : 18;
} TargetBF;

extern "C" void fn_27_1A0400(u32* p, unsigned val) {
    ((TargetBF*)(p + 2))->field = val;
}
