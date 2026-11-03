#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_8021523C(int, int, int, int, int);
extern int fn_8020D3E0(void);

int fn_8020ABC0(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    *(int *)(arg4 + 4) = arg3;
    fn_8021523C(*arg0, arg1, arg2, (int)fn_8020D3E0, arg4);
    return fn_8020CAEC();
}
