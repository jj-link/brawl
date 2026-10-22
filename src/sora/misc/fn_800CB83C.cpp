#pragma force_active on
extern "C" unsigned char fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457AB0[];

struct Ent {
    char pad0[0x78];
    unsigned char flags;
    char pad1[0x10C - 0x79];
    unsigned char b10C;
    unsigned char b10D;
    char pad2[2];
    int w110;
    char pad3[0x218 - 0x114];
};

struct Base {
    char pad[0x70];
    Ent ents[1];
};

extern "C" unsigned char fn_800CB83C(Base* base, unsigned char* out1, int* out2) {
    unsigned char idx = fn_800C8548();
    Ent* e;
    if (idx == 0xff) {
        e = 0;
    } else {
        e = &base->ents[idx];
    }
    if (e == 0) return 0xff;
    if (!((e->flags >> 5) & 1)) return 0xff;
    *out1 = e->b10D;
    *out2 = e->w110;
    netReport__FPCce(lbl_80457AB0, e->b10C, *out1, *out2);
    return e->b10C;
}
