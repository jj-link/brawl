#include <types.h>
#pragma force_active on

struct FtWork10BF0 {
    u8 pad[0xa4];
    u8 a : 1;
    u8 b : 1;
    u8 c : 6;
};

extern "C" bool fn_111_10BF0(const FtWork10BF0* work) {
    return work->b != 0;
}
