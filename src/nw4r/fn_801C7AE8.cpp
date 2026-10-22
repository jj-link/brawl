#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

struct UnkInner {
    u8 pad[0x28];
    u8 unk28;
    u32 unk2C;
};

struct UnkSrc {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
};

struct UnkDst {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct UnkOuter {
    u8 pad[0x28];
    UnkInner* unk28;
};

extern "C" UnkSrc* fn_801D3698(u8, u32, UnkInner*);

extern "C" int fn_801C7AE8(UnkOuter* __restrict arg0, UnkDst* arg1) {
    UnkInner* inner = arg0->unk28;
    UnkSrc* r = fn_801D3698(inner->unk28, inner->unk2C, inner);
    if (arg1 == 0) {
        return 0;
    }
    arg1->unk0 = r->unk0;
    arg1->unk4 = r->unk2;
    arg1->unk8 = r->unk4;
    arg1->unkC = r->unk6;
    arg1->unk10 = r->unk8;
    arg1->unk14 = r->unkA;
    arg1->unk18 = r->unkC;
    return 1;
}
