#pragma force_active on
typedef struct {
    int unk0;
    char pad4[0xC];
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char pad14[0xC];
    int unk20;
    char pad24[4];
    char unk28;
    char unk29;
    char pad2A[0x36];
} State;

extern State lbl_80525F60;
extern char lbl_805A0D00;
extern char lbl_805A0D01;
extern void fn_80228A80(void);
extern void fn_8023052C(void);
extern int fn_80230508(void);

void fn_80230C4C(signed char arg) {
    lbl_80525F60.unk0 = 0;
    lbl_80525F60.unk10 = 0;
    lbl_80525F60.unk11 = 0;
    lbl_80525F60.unk12 = 0;
    lbl_80525F60.unk13 = 0;
    lbl_805A0D00 = 0;
    fn_80228A80();
    fn_8023052C();
    lbl_80525F60.unk28 = 0;
    lbl_80525F60.unk29 = 5;
    lbl_805A0D01 = 0;
    fn_80230508();
    if (lbl_80525F60.unk20 != 0) {
        ((void (*)(int, signed char))lbl_80525F60.unk20)(4, arg);
    }
}
