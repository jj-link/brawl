#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x10];
    u8 unk10;
    u8 pad11[3];
    int unk14;
};

struct Outer {
    u8 pad[0x28];
    Inner* unk28;
};

extern "C" int* fn_801D3698(int, int, Inner*);

extern "C" int fn_801C7B6C(Outer* __restrict arg0) {
    Inner* p = arg0->unk28;
    int* r = fn_801D3698(p->unk10, p->unk14, p);
    if (r == 0) {
        return 0;
    }
    return *r;
}
