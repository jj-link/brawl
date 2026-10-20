#include <types.h>
#pragma force_active on

struct fn_27_1DB3B4_Obj {
    u8 pad[0xa4];
    u8 a : 2;
    u8 flag : 1;
    u8 rest : 5;
};

extern "C" bool fn_27_1DB3B4(fn_27_1DB3B4_Obj* p) {
    return p->flag;
}
