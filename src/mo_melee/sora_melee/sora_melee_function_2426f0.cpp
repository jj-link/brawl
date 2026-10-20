#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad0[0x40];
    u8 f40;
    char pad1[0x1C];
    u8 f5d;
};

extern "C" void fn_27_2426F0(Obj* p) {
    if (p->f5d == 0) {
        return;
    }
    p->f5d = 0;
    p->f40 = 0;
}
