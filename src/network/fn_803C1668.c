#pragma force_active on
typedef signed char s8;
typedef signed short s16;

extern int fn_803A962C(s8 a);
extern char lbl_8053B248[];

void *fn_803C1668(s8 arg0) {
    s16 temp;

    temp = fn_803A962C(arg0) - 0x41;
    if (temp < 0 || temp >= 0x1A) {
        return 0;
    }
    return lbl_8053B248 + temp * 0x1898 + 0x48;
}
