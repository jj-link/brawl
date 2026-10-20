#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad[0x44];
    u8 flags;
};

extern "C" {
void fn_27_B6668(Obj* p) {
    p->flags &= ~0x40;
}
}
