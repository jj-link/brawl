#pragma force_active on
typedef struct {
    char pad[0x24];
    int field24;
    char pad28[0x28];
    void (*callback)(int, void *);
    void *arg;
} Obj;
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern void fn_80383470(void);
extern char lbl_80489690[];
extern Obj *lbl_805A0F70;
extern int lbl_805A0F74, lbl_805A0F78, lbl_805A0F7C;
int fn_80337CE4(int arg0) {
    int var_r31;
    int var_r3;
    void (*fn)(int, void *);
    if (arg0 == 0) return 0;
    fn_80335638(2, lbl_80489690, arg0);
    switch (arg0) {
    case 1: var_r31 = 6; var_r3 = -50; break;
    case 2: var_r31 = 6; var_r3 = -30; break;
    case 3: var_r31 = 6; var_r3 = -20; break;
    case 5: var_r31 = 6; var_r3 = -40; break;
    case 7: var_r31 = 6; var_r3 = -70; break;
    }
    if (lbl_805A0F74 == 1 && lbl_805A0F70 != 0 && var_r31 != 0) {
        fn_8033524C(var_r31, var_r3 - 0x16760);
        if (lbl_805A0F78 == 1) lbl_805A0F7C = 1;
        else fn_80383470();
        lbl_805A0F74 = 0;
        if (lbl_805A0F70 != 0) lbl_805A0F70->field24 = 0;
        fn = lbl_805A0F70->callback;
        if (fn != 0) fn(var_r31, lbl_805A0F70->arg);
    }
    return arg0;
}