#pragma force_active on
typedef unsigned char u8;

struct S {
    char pad0[0x350];
    int unk350;
    char pad1[0x380 - 0x354];
    bool unk380;
    bool unk381;
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char rest : 6;
};

extern "C" void fn_800C6E64(S* s, int arg1, int arg2, int arg3) {
    s->unk380 = arg1 == 0;
    s->unk381 = arg1 - 1 == 0;
    s->b7 = arg2;
    s->b6 = arg3;
    s->unk350 = 2;
}
