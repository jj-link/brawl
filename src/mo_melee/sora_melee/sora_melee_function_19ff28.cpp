#include <types.h>
#pragma force_active on

typedef struct {
    u32 a;
    u32 b;
    unsigned : 12;
    unsigned val : 1;
} S;

extern "C" int fn_27_19FF28(S* p) {
    return p->val;
}
