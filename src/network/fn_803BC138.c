#pragma force_active on
extern char lbl_8053B248[];
extern void *fn_803BE3D8(int);
extern int fn_803C0E80(void);
extern int fn_803B5638(void *, void *, void *, int, int);
extern int fn_803BBFF8(void *, void **);
extern int fn_803B3A44(void *, void *);
extern int fn_803B7780(void *, unsigned int, int, unsigned int);
extern int fn_803B0140(void *);

static int has_entry(void *p) {
    void *entry = 0;
    if (p == 0) return 0;
    fn_803BBFF8(p, &entry);
    return entry != 0;
}

static int process(int *ctx, int arg0) {
    unsigned char object[0x240];
    char req[0x70];
    int ret;
    unsigned int value;
    ret = fn_803B5638(req, object, ctx, arg0, 0);
    if (ret != 0) return ret;
    if (object[0x21c] & 0x19) return 11;
    if (has_entry(object)) return 19;
    value = *(unsigned int *)(object + 0x234);
    ret = fn_803B3A44(object, req);
    if (ret != 0) return ret;
    return fn_803B7780(req + 8, value, -1, *(unsigned int *)(object + 0x228));
}

int fn_803BC138(int arg0) {
    int *ctx;
    int ret;

    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    ctx = fn_803BE3D8(arg0);
    if (ctx == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    ret = fn_803C0E80();
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = ret;
        ctx[0x186c / 4] = ret;
        return ret;
    }
    ctx[0x1608 / 4] = 0;
    ret = process(ctx, arg0);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = ret;
        ctx[0x186c / 4] = ret;
    } else {
        ret = fn_803B0140(ctx);
        if (ret != 0) {
            *(int *)(lbl_8053B248 + 0x1c) = ret;
            ctx[0x186c / 4] = ret;
        }
    }
    return ret;
}