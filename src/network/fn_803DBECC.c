#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 pad[0x21C];
    u8 flags;
    u8 pad21D[0xF];
    u32 value22C;
    u32 pad230;
    u32 value234;
    u8 tail[0x10];
} Info;

typedef struct {
    u8 pad[8];
    u32 value8;
    u32 valueC;
    u32 value10;
    u32 flags;
    u8 pad18[3];
    u8 kind;
    u8 data[0x428];
    u8 extra[4];
} Object;

extern s32 fn_803E722C(s32, void *, void *);
extern s32 fn_803DF754(void *, void *, s32, void *);
extern u32 fn_803D66F4(void *);
extern void fn_803E8738(void *, void *, void *);
extern s32 fn_803DBBC8(Object *);

s32 fn_803DBECC(s32 arg0, s32 arg1, signed char arg2, Object *arg3)
{
    Info info;
    u8 sp28[0x70];
    u8 sp18[0x10];
    u8 sp8[0x10];
    s32 result;

    result = fn_803E722C(arg1, sp18, sp8);
    if (result != 0)
        return result;

    result = fn_803DF754(sp28, &info, arg0, sp18);
    if (result != 0)
        return result;

    if (!(info.flags & 0x10))
        return 0x14;

    arg3->valueC = info.value234;
    arg3->value10 = 0;
    arg3->value8 = info.value22C;
    arg3->kind = arg2;
    arg3->flags = 0;

    if (fn_803D66F4(sp8) == 1U) {
        fn_803E8738(arg3->data, 0, sp8);
        arg3->flags |= 1;
    } else {
        fn_803E8738(arg3->data, arg3->extra, sp8);
        arg3->flags |= 2;
    }

    return fn_803DBBC8(arg3);
}
