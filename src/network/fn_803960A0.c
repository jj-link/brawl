#pragma force_active on
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern int *fn_803970DC(int a, int *b);

int fn_803960A0(int *arg0) {
    int *p;
    fn_803974FC();
    p = fn_803970DC(fn_80397580(), arg0);
    if (p == 0) {
        return -1;
    }
    return *p;
}
