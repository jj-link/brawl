#include <types.h>
#pragma force_active on

struct Obj {
    unsigned int pad[2];
    unsigned int field : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_1CFEB4(Obj* obj, u32 val) {
    obj->field = val;
}
