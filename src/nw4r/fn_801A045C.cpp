#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;

struct Obj44C0 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 d4;
    unsigned int d8;
};

extern "C" {
extern u8 lbl_805A0538;
extern Obj44C0 lbl_804A44C0;
extern void fn_80191CF0(s32*, u8, u8);
extern void fn_8019DA9C(u8, u8, u8, u8, s32);
}

extern "C" void fn_801A045C(s32* arg0) {
    if (*arg0) {
        u8 temp = lbl_805A0538;
        lbl_805A0538 = 0;
        fn_80191CF0(arg0, lbl_804A44C0.b0, temp);
        unsigned int d8 = lbl_804A44C0.d8;
        if ((d8 & 4) && (d8 & 3) != 3) {
            fn_8019DA9C(lbl_804A44C0.b0, lbl_804A44C0.b1, lbl_804A44C0.b2, lbl_804A44C0.b3, lbl_804A44C0.d4);
            lbl_804A44C0.d8 |= 3;
        }
    }
}
