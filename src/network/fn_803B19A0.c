#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 pad0[0x21C];
    u8 flags;
    u8 pad21D[0xB];
    u32 value228;
    u32 value22C;
    u32 value230;
    u32 value234;
    u8 pad238[0x10];
} FileInfo;

typedef struct {
    u8 pad0[8];
    u32 value8;
    u32 valueC;
    u32 value10;
    u32 flags;
    u8 pad18[3];
    s8 mode;
    u8 data[0x428];
    u8 extra[4];
} Output;

extern s32 fn_803BE3D0(s32, void *, void *);
extern s32 fn_803B5644(void *, void *, s32, void *);
extern u32 fn_803A9A78(void *);
extern void fn_803BF90C(void *, void *, void *);
extern s32 fn_803B161C(Output *);

s32 fn_803B19A0(s32 arg0, s32 arg1, s8 arg2, Output *arg3)
{
    FileInfo info;
    u8 work[0x70];
    u8 path[0x10];
    u8 key[0x10];
    s32 result;

    result = fn_803BE3D0(arg1, path, key);
    if (result != 0) return result;

    result = fn_803B5644(work, &info, arg0, path);
    if (result != 0) return result;

    if (!(info.flags & 0x10)) return 0x14;

    arg3->valueC = info.value234;
    arg3->value10 = 0;
    arg3->value8 = info.value22C;
    arg3->mode = arg2;
    arg3->flags = 0;

    if (fn_803A9A78(key) == 1U) {
        fn_803BF90C(arg3->data, 0, key);
        arg3->flags |= 1;
    } else {
        fn_803BF90C(arg3->data, arg3->extra, key);
        arg3->flags |= 2;
    }

    return fn_803B161C(arg3);
}
