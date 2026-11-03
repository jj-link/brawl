#pragma force_active on
extern unsigned int lbl_80534030[];
extern long long fn_803F1470(long long, long long);

int fn_80352B78(long long *out) {
    long long value = *(long long *)(lbl_80534030 + 0x70);
    if (value == 0) return 0;
    *out = fn_803F1470(value, *(unsigned int *)0x800000f8 >> 2);
    return 1;
}
