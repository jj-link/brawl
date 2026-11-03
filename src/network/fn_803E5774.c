#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_805644C0[];

extern void PF_enterCritical(void *p);
extern void PF_exitCritical(void *p);
extern int PFCACHE_FlushFATCache(void *vol);
extern int PFCACHE_FlushDataCacheSpecific(void *vol, void *req);
extern int fn_803DDB2C(char *p, int arg);
extern int fn_803E9B64(void *obj);
extern void fn_803EBB58(char *req);

int fn_803E5774(char *arg0)
{
    char *obj;
    char *conn;
    char *t;
    int r30;
    int ret;

    r30 = 0;
    if (arg0 == 0) {
        obj = 0;
    } else {
        obj = *(char **)(*(char **)(arg0 + 8) + 0x268);
    }
    PF_enterCritical(obj + 0x1F90);
    ret = fn_803E9B64(obj);
    if (ret != 0 && (ret != 0xB || *(int *)(arg0 + 4) != 2)) {
        PF_exitCritical(obj + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = ret;
        *(int *)(obj + 0x1F80) = ret;
        return ret;
    }
    conn = *(char **)(arg0 + 8);
    if (!(*(u32 *)conn & 1) || !(*(u32 *)conn & 2)) {
        PF_exitCritical(obj + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = 0xA;
        *(int *)(obj + 0x1F80) = 0xA;
        return 0xA;
    }
    *(char **)(obj + 0x1644) = arg0;
    t = *(char **)(arg0 + 8);
    if (((int)*(u16 *)(t + 0x298) - 1) <= 0 && !(*(u8 *)(t + 0x258) & 0x19) && !(ret & 0xB)) {
        if ((*(u32 *)t & 4) || (*(u32 *)(obj + 0x1F88) & 1) != 1) {
            r30 = fn_803DDB2C(t + 0x3C, 1);
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
                    fn_803EBB58(arg0);
                }
                c2 = *(char **)(arg0 + 8);
                *(u16 *)(c2 + 0x27C) &= 0xFFFC;
            } else if (*(char **)(c2 + 0x284) != arg0) {
                r30 = 0x19;
            } else {
                *(u16 *)(c2 + 0x27E) = 0;
                *(u16 *)(arg0 + 0x2C) = 0;
                *(u32 *)(*(char **)(arg0 + 8) + 0x284) = 0;
                fn_803EBB58(arg0);
                c2 = *(char **)(arg0 + 8);
                *(u16 *)(c2 + 0x27C) &= 0xFFFC;
            }
        }
    }
    if (r30 != 0) {
        *(int *)(lbl_805644C0 + 0x40) = r30;
        *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x1F80) = r30;
        *(int *)(arg0 + 0x18) = r30;
    } else {
        if (*(u32 *)(obj + 0x1624) & 2) {
            r30 = PFCACHE_FlushFATCache(obj);
            if (r30 != 0) {
                *(int *)(lbl_805644C0 + 0x40) = r30;
                *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x1F80) = r30;
                *(int *)(arg0 + 0x18) = r30;
            } else {
                r30 = PFCACHE_FlushDataCacheSpecific(obj, arg0);
                if (r30 != 0) {
                    *(int *)(lbl_805644C0 + 0x40) = r30;
                    *(int *)(*(char **)(*(char **)(arg0 + 8) + 0x38) + 0x1F80) = r30;
                    *(int *)(arg0 + 0x18) = r30;
                }
            }
        }
        if (r30 == 0) {
            t = *(char **)(arg0 + 8);
            if (--*(u16 *)(t + 0x298) == 0) {
                *(u32 *)(*(char **)(arg0 + 8)) &= ~1u;
                *(u32 *)(*(char **)(arg0 + 8) + 0x20) = 0;
            }
            *(u32 *)arg0 &= ~1u;
            *(int *)(obj + 0x161C) = *(int *)(obj + 0x161C) - 1;
        }
    }
    *(char **)(obj + 0x1644) = 0;
    PF_exitCritical(obj + 0x1F90);
    return r30;
}
