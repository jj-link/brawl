#pragma force_active on

extern int fn_803CD270(void);
extern int fn_803D5254(int, int);
extern int fn_803D59C0(int, int);

int fn_803D5AC4(int arg0, int arg1) {
    if (arg0 == 0) return 0xF;
    if (arg1 == 0) return 0xF;
    if (fn_803CD270() == 0) return 1;
    if (fn_803D5254(arg1, 0x4C) & 0xFFFF) return 7;
    return fn_803D59C0(arg0, arg1);
}
