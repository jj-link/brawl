#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad[0x1e];
    u8 flag : 1;
};

extern "C" {
bool fn_27_11208C(Obj** p) {
    return (*p)->flag;
}
}
