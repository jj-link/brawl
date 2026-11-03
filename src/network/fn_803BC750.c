#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_8053B248[];

extern int fn_803C0CC4(char *obj);
extern int fn_803BBBB8(char *obj, int, int, int, char *, int *);

int fn_803BC750(int arg0, int arg1, int arg2, char *arg3, int *arg4)
{
    char *obj;
    char *conn;
    int sp8;
    int ret;

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
    ret = fn_803C0CC4(obj);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(obj + 0x186C) = ret;
        return ret;
    }
    if (arg3 == 0 || (conn = *(char **)(arg3 + 8)) == 0 ||
        !(*(u32 *)arg3 & 1) || !(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(obj + 0x186C) = 0x26;
        return 0x26;
    }
    if (!(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
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
    ret = fn_803BBBB8(obj, arg0, arg1, arg2, arg3, &sp8);
    *arg4 = sp8;
    *(int *)(obj + 0x1608) = 0;
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(*(char **)(*(char **)(arg3 + 8) + 0x38) + 0x186C) = ret;
        *(int *)(arg3 + 0x18) = ret;
    }
    return ret;
}
