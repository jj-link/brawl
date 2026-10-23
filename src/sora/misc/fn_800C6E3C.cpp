#pragma force_active on
struct S {
    unsigned char pad0[0x350];
    int unk350;
    unsigned char pad1[0x380 - 0x354];
    unsigned char unk380;
    unsigned char unk381;
    struct {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char rest : 6;
    } unk382;
};

extern "C" void fn_800C6E3C(S *p, int arg1, int arg2) {
    p->unk380 = 1;
    p->unk381 = 1;
    p->unk382.bit0 = arg1;
    p->unk382.bit1 = arg2;
    p->unk350 = 2;
}
