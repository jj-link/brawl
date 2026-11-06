#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
extern int fn_803A962C(s8);
extern int fn_803AA580(void *);
extern char lbl_8053B248[];

int fn_803C1E68(s8 arg0) {
    s16 temp;
    char *obj;
    char *base;
    int ret;
    int r;
    temp = fn_803A962C(arg0) - 0x41;
    if (temp < 0 || temp >= 0x1A) {
        obj = 0;
    } else {
        base = lbl_8053B248;
        base = base + temp * 0x1898;
        obj = base + 0x48;
    }
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    if (*(u16 *)(obj + 0x1878) & 2) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    if (!(*(u16 *)(obj + 0x1878) & 1)) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    r = fn_803AA580(obj);
    ret = r & ((-r | r) >> 31);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = ret;
        *(int *)(obj + 0x186c) = ret;
        return ret;
    }
    *(u16 *)(obj + 0x1878) = *(u16 *)(obj + 0x1878) & ~1;
    *(int *)(lbl_8053B248 + 0xc) = *(int *)(lbl_8053B248 + 0xc) - 1;
    return 0;
}