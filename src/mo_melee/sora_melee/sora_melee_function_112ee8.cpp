#pragma force_active on
typedef unsigned char u8;

struct Obj {
    void *unk0;
    u8 pad4[6];
    u8 unk_a;
};

extern "C" void fn_27_1D5448(void *p);

extern "C" void fn_27_112EE8(Obj *p)
{
    if (p->unk_a == 1) {
        fn_27_1D5448((char *)p->unk0 + 0x9e8);
    }
}
