#pragma force_active on
typedef unsigned int u32;

extern void OSReport(const char *, ...);
extern void fn_802137A8(int, void *);
extern char lbl_804927E0[];
extern char lbl_80492820[];
extern int lbl_8059FE98;
extern int lbl_805A1230;
extern int lbl_805A1234;

typedef struct Req {
    void (*unk0)(int, void *);
    void *unk4;
    int *unk8;
    int unkC;
    int unk10;
    int *unk14;
    void *unk18;
} Req;

int fn_803CB004(int arg0, Req *arg1)
{
    switch (arg1->unkC) {
    case 4:
        if (arg0 != 0) {
            if ((u32)(arg0 + 0x3F000000) == 0x20U) {
                OSReport(lbl_804927E0, arg0);
            } else {
                OSReport(lbl_80492820, arg0);
            }
            arg1->unk8[4] = 0;
        } else {
            if (arg1->unk8 != 0) {
                arg1->unk8[4] = *arg1->unk14;
                lbl_805A1230 = 0x10000;
                arg1->unk8[9] = 2;
            }
        }
        lbl_805A1234 = 0;
        break;
    case 18:
    case 25:
    case 38:
        lbl_805A1234 = 0;
        break;
    }
    if (arg1->unk0 != 0 && (u32)arg0 != 0xC2100000U) {
        arg1->unk0(arg0, arg1->unk4);
    }
    if (arg1->unk18 != 0) {
        fn_802137A8(lbl_8059FE98, arg1->unk18);
    }
    fn_802137A8(lbl_8059FE98, arg1);
    return arg0;
}
