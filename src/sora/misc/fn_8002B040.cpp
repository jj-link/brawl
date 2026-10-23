#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct gfPadStatus {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    s8 unk38;
    u8 pad39[3];
    s32 unk3C;
};

class gfPadSystem {
public:
    s32 getDebugPadStatus(s32 arg0, gfPadStatus *arg1);
    u8 pad0[0x38];
    u16 unk38;
    u8 pad3A[0x8CA];
    s32 unk904;
    s32 unk908;
    s32 unk90C;
    s32 unk910;
    s32 unk914;
    s32 unk918;
    f32 unk91C;
    f32 unk920;
    f32 unk924;
    f32 unk928;
    f32 unk92C;
    f32 unk930;
    u8 unk934;
    u8 unk935;
    u8 unk936;
    u8 unk937;
    u8 unk938;
    u8 unk939;
    u8 unk93A;
    u8 unk93B;
    u8 unk93C;
    u8 pad93D[3];
    s32 unk940;
};

extern f32 lbl_805A1528;

s32 gfPadSystem::getDebugPadStatus(s32 arg0, gfPadStatus *arg1) {
    if (arg0 == 0xF0) {
        arg1->unk0 = unk904;
        arg1->unk4 = unk908;
        arg1->unk8 = unk90C;
        arg1->unkC = unk910;
        arg1->unk10 = unk914;
        arg1->unk14 = unk918;
        arg1->unk18 = unk91C;
        arg1->unk1C = unk920;
        arg1->unk20 = unk924;
        arg1->unk24 = unk928;
        arg1->unk28 = unk92C;
        arg1->unk2C = unk930;
        arg1->unk30 = unk934;
        arg1->unk31 = unk935;
        arg1->unk32 = unk936;
        arg1->unk33 = unk937;
        arg1->unk34 = unk938;
        arg1->unk35 = unk939;
        arg1->unk36 = unk93A;
        arg1->unk37 = unk93B;
        arg1->unk38 = unk93C;
        arg1->unk3C = unk940;
    } else if ((1 << arg0) & unk38) {
        u8 *base = (u8 *)this + (arg0 << 6);
        arg1->unk0 = *(s32 *)(base + 0x244);
        arg1->unk4 = *(s32 *)(base + 0x248);
        arg1->unk8 = *(s32 *)(base + 0x24C);
        arg1->unkC = *(s32 *)(base + 0x250);
        arg1->unk10 = *(s32 *)(base + 0x254);
        arg1->unk14 = *(s32 *)(base + 0x258);
        arg1->unk18 = *(f32 *)(base + 0x25C);
        arg1->unk1C = *(f32 *)(base + 0x260);
        arg1->unk20 = *(f32 *)(base + 0x264);
        arg1->unk24 = *(f32 *)(base + 0x268);
        arg1->unk28 = *(f32 *)(base + 0x26C);
        arg1->unk2C = *(f32 *)(base + 0x270);
        arg1->unk30 = *(u8 *)(base + 0x274);
        arg1->unk31 = *(u8 *)(base + 0x275);
        arg1->unk32 = *(u8 *)(base + 0x276);
        arg1->unk33 = *(u8 *)(base + 0x277);
        arg1->unk34 = *(u8 *)(base + 0x278);
        arg1->unk35 = *(u8 *)(base + 0x279);
        arg1->unk36 = *(u8 *)(base + 0x27A);
        arg1->unk37 = *(u8 *)(base + 0x27B);
        arg1->unk38 = *(u8 *)(base + 0x27C);
        arg1->unk3C = *(s32 *)(base + 0x280);
    } else {
        f32 f = lbl_805A1528;
        arg1->unk14 = 0;
        arg1->unk10 = 0;
        arg1->unkC = 0;
        arg1->unk8 = 0;
        arg1->unk4 = 0;
        arg1->unk0 = 0;
        arg1->unk31 = 0;
        arg1->unk30 = 0;
        arg1->unk33 = 0;
        arg1->unk32 = 0;
        arg1->unk35 = 0;
        arg1->unk34 = 0;
        arg1->unk37 = 0;
        arg1->unk36 = 0;
        arg1->unk24 = f;
        arg1->unk20 = f;
        arg1->unk1C = f;
        arg1->unk18 = f;
        arg1->unk2C = f;
        arg1->unk28 = f;
        arg1->unk38 = -1;
        arg1->unk3C = 0;
    }
    return 1;
}
