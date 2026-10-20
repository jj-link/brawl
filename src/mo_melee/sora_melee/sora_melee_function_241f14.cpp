#pragma force_active on
typedef unsigned char u8;

struct fn27Obj {
    char pad[0x43];
    u8 m43;
};

extern "C" {
bool fn_27_241F14(fn27Obj* p) {
    return p->m43 == 1;
}
}
