#pragma force_active on
typedef struct Context {
    unsigned char pad0[0x100];
    int field100;
    unsigned char pad104[4];
    int field108;
    unsigned char pad10C[0xE8];
    int field1F4;
} Context;

typedef struct Entry {
    unsigned char pad0[0x10];
    void *field10;
    int field14;
} Entry;

extern unsigned char lbl_8048EAB4[];
extern void fn_803732E0(Context **, const void *);
extern int fn_80370758(Context **, void *, Entry **);
extern void fn_8035E00C(void *);
extern int fn_80370B4C(Entry *);
extern void fn_80370938(Context **, Entry *);

int fn_803682A8(Context **arg0, void *arg1)
{
    Entry *entry;
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
    if (fn_80370758(arg0, arg1, &entry) == 0) {
        return 0;
    }
    entry->field14--;
    if (ctx->field100 == 0 && entry->field14 <= 0) {
        fn_8035E00C(entry->field10);
        entry->field10 = 0;
        if (fn_80370B4C(entry) != 0) {
            fn_80370938(arg0, entry);
        }
    }
    return 0;
}
