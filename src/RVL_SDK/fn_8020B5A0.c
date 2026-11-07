#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020B3D8(int, int, void *, int, int);
extern int fn_8020CAEC(void);

int fn_8020B5A0(int arg0, int arg1) {
    if (fn_8020CAD4() != 0) {
        fn_8020B3D8(arg0, arg1, 0, 0, 0);
        return fn_8020CAEC();
    }
    return -0x80;
}
