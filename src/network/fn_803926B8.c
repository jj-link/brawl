#pragma force_active on
extern int fn_803A81A8(int, int, int, void **);
extern void fn_8039272C(void *, const void *, int);
extern void fn_803A848C(void *);

int fn_803926B8(int unused, int arg) {
    int result = 0;
    void *p;
    if (fn_803A81A8(arg, 0, 0, &p) == 0) {
        fn_8039272C(&result, *(char **)((char *)p + 0x18) + 4, 4);
        fn_803A848C(p);
    } else {
        result = 0;
    }
    return result;
}