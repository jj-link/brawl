#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_802150CC(int, int, int, int, int);
extern int fn_8020D3E0(void);

int fn_8020ACD8(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    int v;
    int p;
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    *(int *)(arg4 + 4) = arg3;
    v = -1;
    p = *arg0;
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
    fn_802150CC(p, arg1, v, (int)fn_8020D3E0, arg4);
    return fn_8020CAEC();
}
