#pragma force_active on
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern char *fn_803970E4(int a, int b);

int fn_80396D78(int arg0) {
    char *p;
    int ret;
    fn_803974FC();
    p = fn_803970E4(fn_80397580(), arg0);
    if (p == 0) {
        ret = -1;
    } else {
        *(int *)(p + 0xdc) = 0;
        ret = 0;
        *(int *)(p + 0xc8) = 1;
        *(int *)(p + 0xb0) = 0;
        *(int *)(p + 0xb4) = 0;
        *(int *)(p + 0xb8) = 0;
        *(int *)(p + 0xbc) = 0;
    }
    return ret;
}
