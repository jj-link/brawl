#pragma force_active on
typedef struct Entry {
    int a;
    int b;
} Entry;

typedef struct Context {
    unsigned char pad[0x1A8];
    Entry entries[9];
} Context;

extern unsigned char lbl_8048EA30[];
extern void fn_803732E0(Context **, const void *);

int fn_80367CB0(Context **arg0, int arg1, int arg2, int arg3)
{
    Context *ctx;

    if (arg0 == 0 || *arg0 == 0) {
        return 2;
    }

    if (arg1 < 0 || arg1 >= 9) {
        fn_803732E0(arg0, lbl_8048EA30);
        return 2;
    }

    ctx = *arg0;
    ctx->entries[arg1].a = arg2;
    ctx->entries[arg1].b = arg3;
    return 0;
}
