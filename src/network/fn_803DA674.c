#pragma force_active on
extern int fn_803D979C(int, int, int, int, int);

int fn_803DA674(int a, int b, int c, int d) {
    int x = fn_803D979C(a, *(int *)&a + 0x1634, b, c, d);
    return x & ((-x | x) >> 31);
}
