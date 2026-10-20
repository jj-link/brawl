#include <types.h>
#pragma force_active on

struct FieldHolder {
    u8 pad[8];
    u32 hi : 20;
    u32 mid : 10;
    u32 lo : 2;
};

extern "C" {
void fn_27_1A5FA4(FieldHolder* obj, u32 val) {
    obj->mid = val;
}
}
