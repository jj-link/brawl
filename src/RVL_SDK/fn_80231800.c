#pragma force_active on
extern void fn_80228A80(void);
extern void fn_8023052C(void);
extern void fn_80230508(void* p);
extern struct {
    unsigned char pad[0x28];
    unsigned char unk28;
    unsigned char unk29;
    unsigned char rest[0x60 - 0x2A];
} lbl_80525F60;
extern unsigned char lbl_805A0D01;

void fn_80231800(void) {
    fn_80228A80();
    fn_8023052C();
    lbl_80525F60.unk29 = 5;
    lbl_80525F60.unk28 = 0;
    lbl_805A0D01 = 0;
    fn_80230508(&lbl_80525F60);
}
