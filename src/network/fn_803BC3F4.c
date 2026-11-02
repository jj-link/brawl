#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_8053B248[];

extern int fn_803AA540(char *obj);
extern int fn_803B0140(char *obj);
extern int fn_803B0174(char *obj, char *req);
extern int fn_803B37BC(char *p, int flag);
extern int fn_803C0CC4(char *obj);
extern void fn_803C2E88(char *req);

int fn_803BC3F4(char *arg0)
{
    char *obj;
    char *conn;
    char *t;
    int r30;
    int ret;

    if ((lbl_8053B248 > arg0) || ((lbl_8053B248 + 0x27FB8) < arg0)) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    if (arg0 == 0) {
        obj = 0;
    } else {
        obj = *(char **)(*(char **)(arg0 + 8) + 0x268);
    }
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }
    ret = fn_803C0CC4(obj);
    r30 = ret;
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        *(int *)(obj + 0x186C) = ret;
        return ret;
    }
    if (fn_803AA540(obj) != 0 && *(int *)(arg0 + 4) != 2) {
        return 11;
    }
    if (arg0 == 0 || (conn = *(char **)(arg0 + 8)) == 0 ||
        !(*(u32 *)arg0 & 1) || !(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        *(int *)(obj + 0x186C) = 10;
        return 10;
    }
    if (!(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        *(int *)(obj + 0x186C) = 10;
        return 10;
    }
    *(char **)(obj + 0x1608) = arg0;
    t = *(char **)(arg0 + 8);
    if (((int)*(u16 *)(t + 0x28C) - 1) <= 0 && !(*(u8 *)(t + 0x258) & 0x19) && fn_803AA540(obj) == 0) {
        conn = *(char **)(arg0 + 8);
        if ((*(u32 *)conn & 4) || (*(u32 *)(obj + 0x1874) & 1) != 1) {
            r30 = fn_803B37BC(conn + 0x3C, 1);
        }
    }
    {
        u16 n = *(u16 *)(arg0 + 0x2C);
        if (n != 0) {
            char *c2 = *(char **)(arg0 + 8);
            if (*(u16 *)(c2 + 0x27C) & 1) {
                *(u16 *)(c2 + 0x27E) = (u16)(*(u16 *)(c2 + 0x27E) - n);
                *(u16 *)(arg0 + 0x2C) = 0;
                if (*(u16 *)(*(char **)(arg0 + 8) + 0x27E) == 0) {
                    fn_803C2E88(arg0);
                }
                c2 = *(char **)(arg0 + 8);
                *(u16 *)(c2 + 0x27C) &= 0xFFFC;
            } else if (*(char **)(c2 + 0x284) != arg0) {
                r30 = 0x19;
            } else {
                *(u16 *)(c2 + 0x27E) = 0;
                *(u16 *)(arg0 + 0x2C) = 0;
                *(u32 *)(*(char **)(arg0 + 8) + 0x284) = 0;
                fn_803C2E88(arg0);
                c2 = *(char **)(arg0 + 8);
                *(u16 *)(c2 + 0x27C) &= 0xFFFC;
            }
        }
    }
    if (r30 != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = r30;
        *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = r30;
        *(int *)(arg0 + 0x18) = r30;
    } else {
        if (*(u32 *)(obj + 0x15E8) & 2) {
            r30 = fn_803B0140(obj);
            if (r30 != 0) {
                *(int *)(lbl_8053B248 + 0x1C) = r30;
                *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = r30;
                *(int *)(arg0 + 0x18) = r30;
            } else {
                r30 = fn_803B0174(obj, arg0);
                if (r30 != 0) {
                    *(int *)(lbl_8053B248 + 0x1C) = r30;
                    *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x186C) = r30;
                    *(int *)(arg0 + 0x18) = r30;
                }
            }
        }
        if (r30 == 0) {
            t = *(char **)(arg0 + 8);
            if (--*(u16 *)(t + 0x28C) == 0) {
                *(u32 *)t &= ~1u;
                *(u32 *)(t + 0x20) = 0;
            }
            *(u32 *)arg0 &= ~1u;
            *(int *)(obj + 0x15E0) = *(int *)(obj + 0x15E0) - 1;
        }
    }
    *(int *)(obj + 0x1608) = 0;
    return r30;
}
