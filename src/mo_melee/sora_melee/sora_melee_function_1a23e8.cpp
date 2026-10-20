#include <types.h>
#pragma force_active on

struct Holder {
    u32 _0;
    u32 _4;
    union {
        u32 raw;
        struct {
            u32 low : 12;
            u32 flag : 1;
            u32 rest : 19;
        };
    };
};

extern "C" {
u32 fn_27_1A23E8(Holder* p) {
    return p->flag;
}
}
