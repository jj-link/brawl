#pragma force_active on
typedef signed char s8;

extern void fn_8020F130(s8 *, int, int);

void fn_8020F5C4(s8 arg0, int arg1) {
    s8 sp8;

    sp8 = arg0;
    fn_8020F130(&sp8, arg1, 0x60);
}
