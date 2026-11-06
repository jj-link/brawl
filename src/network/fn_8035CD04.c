#pragma force_active on
extern int fn_803A7654(int, int, ...);

int fn_8035CD04(int arg0, int arg1)
{
    int value;
    int flags;

    value = fn_803A7654(arg0, 3, 0);
    flags = value | 4;
    if (arg1 != 0) {
        flags = value & ~4;
    }
    if (fn_803A7654(arg0, 4, flags) == 0) {
        return 1;
    }
    return 0;
}
