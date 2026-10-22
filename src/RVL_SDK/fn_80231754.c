#pragma force_active on
typedef struct { int unk0; char pad[0x25]; unsigned char unk29; char pad1[2]; char q[8]; unsigned short unk34; char pad3[6]; char r[8]; unsigned short unk44; } State;
extern State lbl_80525F60;
extern void fn_8023052C(void);
extern int fn_80230508(void);
extern void fn_8022F77C(void *);
extern void fn_8022F0E0(void);
extern void fn_80230C4C(void);
extern void fn_80228D74(int, void *, int);

void fn_80231754(void) {
    fn_8023052C();
    lbl_80525F60.unk29 = 0;
    fn_80230508();
    if (lbl_80525F60.unk34 != 0) {
        while (lbl_80525F60.unk34 != 0) {
            fn_8022F77C(&lbl_80525F60.unk34 - 4);
            fn_8022F0E0();
        }
    }
    if (lbl_80525F60.unk44 != 0) {
        while (lbl_80525F60.unk44 != 0) {
            fn_8022F77C(&lbl_80525F60.unk44 - 4);
            fn_8022F0E0();
        }
    }
    fn_80228D74(lbl_80525F60.unk0, (void *)fn_80230C4C, 0);
}
