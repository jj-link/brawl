#pragma force_active on
typedef void (*FnPtr)(void);

extern void fn_802437D4(void);
extern void fn_80243960(void);
extern void fn_80243B3C(void);
extern void fn_80243C78(void);
extern void fn_80243E64(void);
extern void fn_8024405C(void);
extern void fn_8024416C(void);
extern unsigned char lbl_8052C4C0[];

void fn_80243764(void) {
    ((FnPtr *)lbl_8052C4C0)[33] = fn_802437D4;
    ((FnPtr *)lbl_8052C4C0)[34] = fn_80243960;
    ((FnPtr *)lbl_8052C4C0)[35] = 0;
    ((FnPtr *)lbl_8052C4C0)[36] = fn_80243B3C;
    ((FnPtr *)lbl_8052C4C0)[37] = fn_80243C78;
    ((FnPtr *)lbl_8052C4C0)[38] = fn_80243E64;
    ((FnPtr *)lbl_8052C4C0)[39] = 0;
    ((FnPtr *)lbl_8052C4C0)[40] = 0;
    ((FnPtr *)lbl_8052C4C0)[41] = fn_8024405C;
    ((FnPtr *)lbl_8052C4C0)[42] = fn_8024416C;
}
