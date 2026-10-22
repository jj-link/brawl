#pragma force_active on
extern int fn_803974FC(void);
extern int fn_80397580(void);
extern void fn_8039094C(void);
extern void fn_80397568(int);
extern void *fn_803908F8(void);
extern void **fn_80397570(int);
extern void fn_80390950(int);
extern void fn_80397578(int);
extern void fn_80390A30(void);

int fn_80394664(int *arg0) {
    int r30;
    int r29;
    int *node;
    void **slot;

    r30 = fn_803974FC();
    r29 = fn_80397580();
    fn_8039094C();
    fn_80397568(r30);
    node = (int *)fn_803908F8();
    if (node != 0) {
        slot = fn_80397570(r30);
        *arg0 = node[2];
        *slot = node;
    } else {
        *arg0 = -1;
    }
    fn_80390950(r29);
    if (*arg0 < 0) {
        fn_80397578(r30);
        fn_80390A30();
        return 0;
    }
    return 1;
}
