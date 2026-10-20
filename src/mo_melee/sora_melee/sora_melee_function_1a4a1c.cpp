#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_1A4A1C(Obj* p) {
    p->flags &= ~0x80000u;
}
}
