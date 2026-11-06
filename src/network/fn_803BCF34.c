#pragma force_active on

typedef unsigned int u32;
typedef struct { int a, b, c, d; } Four;
typedef struct { int a, b, c; } Three;

extern char lbl_8053B248[];
extern int fn_803C0CC4(char *);
extern int fn_803BBED8(char *, int);

int fn_803BCF34(char *arg0, int arg1)
{
    char *obj;
    char *conn;
    Four save4;
    Three save3;
    int ret;

    if (lbl_8053B248 > arg0 || lbl_8053B248 + 0x27FB8 < arg0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    if (arg0 == 0) {
        obj = 0;
    } else {
        obj = *(char **)(*(char **)(arg0 + 8) + 0x268);
    }
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        return 0x26;
    }
    ret = fn_803C0CC4(obj);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = ret;
        *(int *)(arg0 + 0x18) = ret;
        return ret;
    }
    if (arg0 == 0 || (conn = *(char **)(arg0 + 8)) == 0 ||
        !(*(u32 *)arg0 & 1) || !(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(obj + 0x186C) = 0x26;
        return 0x26;
    }
    if (!(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 0x26;
        *(int *)(obj + 0x186C) = 0x26;
        return 0x26;
    }
    if (arg1 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = 10;
        *(int *)(arg0 + 0x18) = 10;
        return 10;
    }
    *(char **)(obj + 0x1608) = arg0;
    save4 = *(Four *)(arg0 + 0x1C);
    save3 = *(Three *)(arg0 + 0xC);
    ret = fn_803BBED8(arg0, arg1);
    *(Four *)(arg0 + 0x1C) = save4;
    *(Three *)(arg0 + 0xC) = save3;
    *(int *)(obj + 0x1608) = 0;
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = ret;
        *(int *)(arg0 + 0x18) = ret;
        return ret;
    }
    return 0;
}
