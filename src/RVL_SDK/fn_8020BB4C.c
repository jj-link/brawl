#pragma force_active on

extern int fn_8020CAD4(void);
extern int fn_8020B8A8(int, int, int, int, int);
extern int fn_8020CAEC(void);

int fn_8020BB4C(int arg0, int arg1, int arg2, int arg3, int arg4) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }

    *(int *)(arg4 + 4) = arg3;
    *(int *)(arg4 + 8) = arg1;
    fn_8020B8A8(arg0, arg2, arg4, 1, 1);
    return fn_8020CAEC();
}
