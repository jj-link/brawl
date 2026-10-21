#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0xD8];
    u8 flags;
};

extern "C" void fn_801AB038(Obj* p, unsigned int arg) {
    if (arg & 1) {
        p->flags |= 0x1;
    }
    if (arg & 2) {
        p->flags |= 0x2;
    }
    if (arg & 4) {
        p->flags |= 0x4;
    }
}
