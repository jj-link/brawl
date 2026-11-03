#pragma force_active on
extern int fn_803A685C(int, int *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6944(int, int);

int fn_803A7FF0(void) {
    int handle;
    int result;
    int value = 0;
    result = fn_803A685C(0, &handle);
    if (result == 0) {
        value = fn_80212D40(handle, 0x10, 0, 0, 0, 0);
        fn_803A6944(0, result);
    }
    return value;
}
