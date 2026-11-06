#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x108];
    int field108;
} Context;

typedef struct Entry {
    unsigned char pad0[8];
    int field8;
} Entry;

extern int fn_80370758(Context **, void *, Entry **);

int fn_803685D0(Context **arg0, void *arg1)
{
    Context *ctx;
    Entry *entry;

    if (arg0 == 0 || (ctx = *arg0) == 0) {
        return 0;
    }
    if (ctx->field108 != 0) {
        return 0;
    }
    if (fn_80370758(arg0, arg1, &entry) != 0 && entry->field8 != 0) {
        return 1;
    }
    return 0;
}
