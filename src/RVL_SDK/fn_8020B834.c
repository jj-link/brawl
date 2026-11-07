#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020B6EC(int, int, int, int, int);
extern int fn_8020CAEC(int);

int fn_8020B834(int arg0, int arg1) {
    if (fn_8020CAD4() != 0) {
        return fn_8020CAEC(fn_8020B6EC(arg0, arg1, 0, 0, 0));
    }
    return -0x80;
}
