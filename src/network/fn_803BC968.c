#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

extern char lbl_8053B248[];

extern int fn_803C0E80(char *obj);
extern int fn_803BBC84(char *obj, int, int, int, char *, int *);
extern unsigned char fn_803B3BA8(short *, short *);

int fn_803BC968(int arg0, int arg1, int arg2, char *arg3, int *arg4)
{
    char *obj;
    int sp8;
    int ret;
    int result;

    if (arg4 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    *arg4 = 0;
    if ((lbl_8053B248 > arg3) || ((lbl_8053B248 + 0x27FB8) < arg3)) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    if (arg3 == 0) {
        obj = 0;
    } else {
        obj = *(char **)(*(char **)(arg3 + 8) + 0x268);
    }
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(*(char **)(*(char **)(arg3 + 8) + 0x38) + 0x186C) = 0x26;
        *(int *)(arg3 + 0x18) = 0x26;
        return 0x26;
    }
    ret = fn_803C0E80(obj);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(obj + 0x186C) = ret;
        return ret;
    }
    if (arg3 == 0 || *(char **)(arg3 + 8) == 0 ||
        !(*(u32 *)arg3 & 1) || !(*(u32 *)*(char **)(arg3 + 8) & 1) || !(*(u32 *)*(char **)(arg3 + 8) & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(obj + 0x186C) = 0x26;
        return 0x26;
    }
    if (!(*(u32 *)*(char **)(arg3 + 8) & 1) || !(*(u32 *)*(char **)(arg3 + 8) & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(obj + 0x186C) = 0x26;
        return 0x26;
    }
    if (arg0 == 0 || arg2 == 0 || arg1 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        *(int *)(*(char **)(*(char **)(arg3 + 8) + 0x38) + 0x186C) = 10;
        *(int *)(arg3 + 0x18) = 10;
        return 10;
    }
    *(char **)(obj + 0x1608) = arg3;
    result = fn_803BBC84(obj, arg0, arg1, arg2, arg3, &sp8);
    *arg4 = sp8;
    *(int *)(obj + 0x1608) = 0;
    if (result != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = result;
        *(int *)(*(char **)(*(char **)(arg3 + 8) + 0x38) + 0x186C) = result;
        *(int *)(arg3 + 0x18) = result;
    }
    if (sp8 != 0) {
        fn_803B3BA8((short *)(*(char **)(arg3 + 8) + 0x262), (short *)(*(char **)(arg3 + 8) + 0x260));
        *(u16 *)(*(char **)(arg3 + 8) + 0x25E) = *(u16 *)(*(char **)(arg3 + 8) + 0x262);
        *(int *)*(char **)(arg3 + 8) |= 4;
    }
    return result;
}
