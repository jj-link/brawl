#pragma force_active on
extern void OSRegisterShutdownFunction(void *);
extern void fn_801D6410(int);
extern void *fn_801D6424(int);
extern void fn_801D6D30(void);
extern int lbl_80467258[];
extern int lbl_805A0678[2];

void fn_801D6640(void) {
    if (fn_801D6424(8) != fn_801D6D30) {
        lbl_805A0678[1] = 0;
        lbl_805A0678[0] = 0;
        fn_801D6410(8);
        OSRegisterShutdownFunction(lbl_80467258);
    }
}
