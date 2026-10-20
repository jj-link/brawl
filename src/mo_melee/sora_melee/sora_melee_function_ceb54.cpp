#include <types.h>
#pragma force_active on

typedef struct {
    u32 a;
    u32 b;
    u32 hi : 6;
    u32 rest : 26;
} S;

extern "C" {
void fn_27_CEB54(S* p, u32 v) {
    p->hi = v;
}
}
