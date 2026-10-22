#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern void fn_802150C8(int, int, int);

int fn_8020AC38(int *arg0, int arg1, int arg2) {
    int v;
    int p;
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    p = *arg0;
    v = -1;
    switch (arg2) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    case 2:
        v = 2;
        break;
    }
    fn_802150C8(p, arg1, v);
    return fn_8020CAEC();
}
