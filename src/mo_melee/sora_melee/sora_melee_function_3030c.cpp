#include <types.h>
#pragma force_active on

struct SubObj {
    u8 pad[0x73];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 flag : 1;
    u8 f4 : 4;
};

struct Obj {
    u8 pad[4];
    SubObj* sub;
};

extern "C" void fn_27_3030C(Obj* obj, u32 flag) {
    if (obj->sub == 0) {
        return;
    }
    obj->sub->flag = flag;
}
