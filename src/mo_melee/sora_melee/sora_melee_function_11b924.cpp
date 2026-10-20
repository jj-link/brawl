#include <types.h>
#pragma force_active on

extern "C" {
struct FnStruct27 {
    u8 pad[8];
    u32 hi : 5;
    u32 lo : 27;
};

void fn_27_11B924(FnStruct27* p, u32 v) {
    p->hi = v;
}
}
