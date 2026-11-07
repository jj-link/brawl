#include <string.h>
#pragma force_active on
typedef struct Context {
    char pad0[0x108];
    int field108;
    char pad10c[0x340];
    int field44c;
} Context;
typedef struct Detail {
    int field0;
    int field4;
    char *field8;
    char *fieldc;
    int field10;
    int field14;
} Detail;
typedef struct Entry {
    int field0;
    int field4;
    Detail *field8;
} Entry;
typedef struct Output {
    int field0;
    int field4;
    char field8[0x100];
    char field108[0x100];
    int field208;
    int field20c;
} Output;
extern unsigned char lbl_8048EB50[];
extern unsigned char lbl_8048EB60[];
extern void fn_803732E0(Context **, const void *);
extern Entry *fn_80370AF0(Context **, int);
extern void fn_80372DD8(char *, const char *, unsigned long);
int fn_803683E8(Context **arg0, int arg1, Output *arg2) {
    Context *ctx;
    Entry *entry;
    Detail *detail;
    int count;
    if (arg0 == 0 || (ctx = *arg0) == 0) return 2;
    if (ctx->field108 != 0) {
        memset(arg2, 0, 0x210);
        return 0;
    }
    if (arg2 == 0) {
        fn_803732E0(arg0, lbl_8048EB50);
        return 2;
    }
    count = ctx->field44c;
    if (arg1 < 0 || arg1 >= count) {
        fn_803732E0(arg0, lbl_8048EB60);
        return 2;
    }
    entry = fn_80370AF0(arg0, arg1);
    if (entry == 0) {
        fn_803732E0(arg0, lbl_8048EB60);
        return 2;
    }
    detail = entry->field8;
    arg2->field0 = entry->field0;
    arg2->field4 = detail->field4;
    if (detail->field8 != 0)
        fn_80372DD8(arg2->field8, detail->field8, 0x100);
    else
        arg2->field8[0] = 0;
    if (detail->fieldc != 0)
        fn_80372DD8(arg2->field108, detail->fieldc, 0x100);
    else
        arg2->field108[0] = 0;
    arg2->field208 = detail->field10;
    arg2->field20c = detail->field14;
    return 0;
}