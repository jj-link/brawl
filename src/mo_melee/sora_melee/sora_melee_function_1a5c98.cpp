#include <types.h>
#pragma force_active on

extern "C" {

struct FnTarget {
    u8 pad[8];
    u32 hi : 20;
    u32 mid : 10;
    u32 lo : 2;
};

void fn_27_1A5C98(FnTarget* p, u32 v) {
    p->mid = v;
}

}
