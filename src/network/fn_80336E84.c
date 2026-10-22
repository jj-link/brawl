#pragma force_active on
typedef unsigned char u8;

typedef struct G {
    int unk0;
    char pad4[0x18];
    int unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    char pad24[0xC];
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
} G;

extern G *lbl_805A0F70;

void fn_80336E84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    lbl_805A0F70->unk30 = a2;
    lbl_805A0F70->unk34 = a3;
    lbl_805A0F70->unk38 = a4;
    lbl_805A0F70->unk3C = a5;
    lbl_805A0F70->unk40 = a6;
    lbl_805A0F70->unk44 = a7;
    lbl_805A0F70->unk21 = 0;
    lbl_805A0F70->unk22 = 0;
    lbl_805A0F70->unk23 = 0;
    lbl_805A0F70->unk20 = 0;
    lbl_805A0F70->unk0 = 1;
    if (lbl_805A0F70->unk1C == 0) {
        lbl_805A0F70->unk23 = lbl_805A0F70->unk23 + 1;
    }
    lbl_805A0F70->unk23 = lbl_805A0F70->unk23 + 1;
}
