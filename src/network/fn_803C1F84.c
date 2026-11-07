#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;

extern int fn_803A962C(s8);
extern int fn_803AA4E8(void *);
extern void fn_803BC090(void *);
extern void fn_803B032C(void *);
extern void fn_803B1AA4(void *);
extern int fn_803C093C(void *, int);
extern char lbl_8053B248[];

int fn_803C1F84(s8 arg0, int arg1) {
    s16 temp;
    char *obj;
    char *base;
    int ret;
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
    if (!(*(u16 *)(obj + 0x1878) & 1)) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    if (fn_803AA4E8(obj) == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    if (*(int *)(obj + 0x15e0) != 0) {
        fn_803BC090(obj);
        fn_803B032C(obj);
    }
    if (*(int *)(obj + 0x15e4) != 0) {
        fn_803B1AA4(obj);
    }
    ret = fn_803C093C(obj, arg1);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = ret;
        *(int *)(obj + 0x186c) = ret;
        return ret;
    }
    *(u16 *)(obj + 0x187c) |= 4;
    if (*(int *)(obj + 0x1c) == 2) {
        *(int *)(obj + 0x38) = *(int *)(obj + 0x34) - 1;
    } else {
        *(int *)(obj + 0x38) = *(int *)(obj + 0x34);
    }
    return 0;
}