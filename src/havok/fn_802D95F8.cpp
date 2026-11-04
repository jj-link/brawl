#pragma force_active on
extern "C" void fn_802839D4(void* p, float s);

struct Obj {
    char pad0[0xC];
    float f0C;
    float f10;
    char pad1[0x40 - 0x14];
    float f40;
};

extern "C" void fn_802D95F8(Obj* a, int unused1, Obj* b, int unused2, Obj* c) {
    float s1 = a->f0C;
    float s2 = a->f10;
    b->f40 = b->f40 * s1;
    fn_802839D4(&b->f10, s1);
    c->f40 = c->f40 * s2;
    fn_802839D4(&c->f10, s2);
}
