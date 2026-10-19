#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x56];
    u8 flag;
};

struct PairPtr {
    Inner* a;
    Inner* b;
};

struct Obj {
    u8 pad[0x28];
    Inner* p28;
    PairPtr* p2c;
};

extern const float lbl_27_rodata_324;

extern "C" {
void fn_27_12A90(Obj* obj, float v) {
    u8 r = (lbl_27_rodata_324 == v);
    if (obj->p28 != nullptr) {
        obj->p28->flag = r;
        return;
    }
    PairPtr* pp = obj->p2c;
    if (pp == nullptr) {
        return;
    }
    pp->a->flag = r;
    pp->b->flag = r;
}
}
