#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x20];
    u8 unk20;
    int unk24;
};

struct Outer {
    u8 pad[0x28];
    Inner* unk28;
};

extern "C" int* fn_801D3698(int, int, Inner*);

extern "C" int fn_801C7BAC(Outer* __restrict arg0) {
    Inner* p = arg0->unk28;
    int* r = fn_801D3698(p->unk20, p->unk24, p);
    if (r == 0) {
        return 0;
    }
    return *r - 1;
}
