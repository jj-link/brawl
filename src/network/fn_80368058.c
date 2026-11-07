#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x108];
    int field108;
    unsigned char pad10C[0xE8];
    int field1F4;
} Context;

extern unsigned char lbl_8048EAB4[];
extern void fn_803732E0(Context **, const void *);
extern int fn_8036DB08(Context **, void *, int);

int fn_80368058(Context **arg0, void *arg1, int arg2)
{
    Context *ctx;
    if (arg0 == 0 || (ctx = *arg0) == 0) {
        return 2;
    }
    if (ctx->field108 != 0) {
        return 0;
    }
    if (ctx->field1F4 == 4) {
        fn_803732E0(arg0, lbl_8048EAB4);
        return 2;
    }
    return fn_8036DB08(arg0, arg1, arg2);
}