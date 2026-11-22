#pragma force_active on
extern int lbl_8059ED80;
extern char lbl_8047E240[];
typedef struct Blk60 {
    void *p0;
    int v4;
    void *p8;
    int vC;
    int v10;
    int v14;
} Blk60;
typedef struct Blk80 {
    void *w0;
    int w4;
    void *w8;
    int wC;
    int w10;
    void *w14;
    void *w18;
    void *w1C;
    char pad20[0x14];
    int w34;
    char pad38[0x8];
    int w40;
    short w44;
} Blk80;
extern void fn_80228834(const char *, ...);
extern void fn_802288DC(const char *, ...);
extern void *fn_802137A4(int, int, int);
extern int fn_802137A8(int, void *);
extern int fn_80212FAC(int, int, int, int, void *, void *, void *);
extern int fn_80213090(int, int, int, int, void *);
extern void DCFlushRange(void *, unsigned int);
extern void *memset(void *, int, unsigned int);
extern void fn_80228A88(void);

int fn_80228E98(int arg0, unsigned char arg1, short arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
{
    const char *base = lbl_8047E240;
    int t;
    char *r30;
    int var;
    char *r28;
    char *r27;
    char *r26;

    r28 = fn_802137A4(lbl_8059ED80, 0x60, 0x20);
    if (r28 == 0)
        fn_802288DC(base + 0x154, lbl_8059ED80, 0x60, r28);
    r27 = fn_802137A4(lbl_8059ED80, 0x20, 0x20);
    if (r27 == 0)
        fn_802288DC(base + 0x154, lbl_8059ED80, 0x20, r27);
    r26 = fn_802137A4(lbl_8059ED80, 0x20, 0x20);
    if (r26 == 0)
        fn_802288DC(base + 0x154, lbl_8059ED80, 0x20, r26);
    if (r28 == 0 || r27 == 0 || r26 == 0) {
        fn_802288DC(base + 0x2ac);
        var = -22;
        goto cleanup;
    }
    *(unsigned char *)r27 = arg1;
    *(short *)r26 = arg2;
    ((Blk60 *)r28)->p0 = r27;
    ((Blk60 *)r28)->v4 = 1;
    ((Blk60 *)r28)->p8 = r26;
    ((Blk60 *)r28)->vC = 2;
    ((Blk60 *)r28)->v10 = arg3;
    ((Blk60 *)r28)->v14 = arg2;
    DCFlushRange(r27, 0x20);
    DCFlushRange(r26, 0x20);
    DCFlushRange(r28, 0x60);
    if (arg7 == 0) {
        var = fn_80213090(arg0, arg4, 2, 1, r28);
        fn_80228834(base + 0x2d0, var);
        goto cleanup;
    }
    r30 = fn_802137A4(lbl_8059ED80, 0x80, 0x20);
    if (r30 == 0)
        fn_802288DC(base + 0x154, lbl_8059ED80, 0x80, r30);
    if (r30 == 0) {
        fn_802288DC(base + 0x2f0);
        var = -22;
        goto cleanup;
    }
    memset(r30, 0, 0x80);
    ((Blk80 *)r30)->w0 = (void *)arg5;
    ((Blk80 *)r30)->w8 = (void *)arg6;
    fn_80228834(base + 0x31c, arg5, arg6);
    ((Blk80 *)r30)->w34 = 3;
    ((Blk80 *)r30)->w14 = r27;
    ((Blk80 *)r30)->w18 = r26;
    ((Blk80 *)r30)->w1C = r28;
    ((Blk80 *)r30)->w40 = arg3;
    ((Blk80 *)r30)->w44 = arg2;
    var = fn_80212FAC(arg0, arg4, 2, 1, r28, (void *)fn_80228A88, r30);
    if (var < 0) {
        if (r30 != 0) {
            t = fn_802137A8(lbl_8059ED80, r30);
            if (t < 0)
                fn_802288DC(base + 0x108, lbl_8059ED80, r30, t);
        }

cleanup:
    if (r27 != 0) {
        t = fn_802137A8(lbl_8059ED80, r27);
        if (t < 0)
            fn_802288DC(base + 0x108, lbl_8059ED80, r27, t);
    }
    if (r26 != 0) {
        t = fn_802137A8(lbl_8059ED80, r26);
        if (t < 0)
            fn_802288DC(base + 0x108, lbl_8059ED80, r26, t);
    }
    if (r28 != 0) {
        t = fn_802137A8(lbl_8059ED80, r28);
        if (t < 0)
            fn_802288DC(base + 0x108, lbl_8059ED80, r28, t);
    }
    }
    return var;
}
