#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_8004B608(s32, s32);

extern "C" s32 fn_8004ACDC(void* p, s32 arg) {
    s32 r = 0;
    s32 t = *(s32*)((char*)p + 0x18);
    if (t != 0) {
        *(u8*)((char*)p + 0x24) =
            (u8)(*(u8*)((char*)p + 0x24) & 0xFFFFFFEFu);
        r = fn_8004B608(t, arg);
    }
    return r;
}
