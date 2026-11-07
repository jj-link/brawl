#include <string.h>
#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x108];
    int field108;
    unsigned char pad10C[0xE8];
    int field1F4;
} Context;
extern unsigned char lbl_8048EA40[];
extern unsigned char lbl_8048EAB4[];
extern void fn_803732E0(Context **, const void *);
extern int fn_8036E6DC(Context **, void *, int, int, void (*)(Context **, void *, int), int);
int fn_80367F78(Context **arg0, void *arg1, int arg2, int arg3, void (*callback)(Context **, void *, int), int arg5)
{
    Context *ctx;
    char buffer[0x204];
    if (arg0 == 0 || (ctx = *arg0) == 0 || arg1 == 0) return 2;
    if (callback == 0) {
        fn_803732E0(arg0, lbl_8048EA40);
        return 2;
    }
    if (ctx->field108 != 0) {
        memset(buffer, 0, 0x204);
        callback(arg0, buffer, arg5);
        return 0;
    }
    if (ctx->field1F4 == 4) {
        fn_803732E0(arg0, lbl_8048EAB4);
        return 2;
    }
    return fn_8036E6DC(arg0, arg1, arg2, arg3, callback, arg5);
}