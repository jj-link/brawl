#pragma force_active on
extern int fn_803C4450(void);
extern int fn_803CA1FC(int, int);

int fn_803CA9CC(int arg0) {
    int entry;
    int result;
    if (arg0 == 0) return -0x14;
    entry = fn_803C4450();
    if (entry == 0) return -0x14;
    result = fn_803CA1FC(arg0, entry + 0x3c);
    return result & ~-((result == 0) & 1);
}