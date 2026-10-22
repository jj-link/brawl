#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" int fn_8005EC64(void* self);
extern "C" void fn_8005EA4C(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" void fn_8005EFF4(void* self, s32 unused, s32 arg2, s32 arg3, s32 arg4) {
    s32 result = fn_8005EC64(self);
    if (result < 0x137) {
        if (((u8*)self)[0x42] != 0) {
            fn_8005EA4C(self, result, 0, 0, 1, 0xFF);
        }
        u32 flag = ((u32)(-arg4) | (u32)arg4) >> 31;
        fn_8005EA4C(self, result, arg2, arg3, flag, 0xFF);
    }
}
