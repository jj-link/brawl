#include <types.h>
#pragma force_active on

struct FlagBits {
    u8 pad[0xa4];
    u8 f0 : 1;
    u8 f1 : 1;
};

extern "C" bool fn_103_1303C(const FlagBits* p) {
    return p->f1;
}
