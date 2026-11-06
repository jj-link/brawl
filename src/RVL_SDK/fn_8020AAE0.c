#pragma force_active on

extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_80215178(int, int, int, int, int);
extern int fn_8020D3E0(void);

int fn_8020AAE0(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    *(int *)(arg4 + 4) = arg3;
    fn_80215178(*arg0, arg1, arg2, (int)fn_8020D3E0, arg4);
    return fn_8020CAEC();
}
