#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s16 *fn_80362F54(s32);
extern s32 fn_80362F5C(s32);
extern s32 fn_8037B644(void *, s16 *, u32);
extern s32 fn_8037B7B4(void *, s32, s32);
extern void fn_8037BBB8(void *);
extern s32 fn_8037BBDC(void *);
extern s32 fn_8037C1C0(void *, s16 *, u32);

s32 fn_8037FCCC(void **arg0, u8 *arg1) {
    struct {
        s16 a;
        s8 b;
    } loc;
    s32 temp_r30;
    s32 var_r29;
    u32 temp_r31;

    temp_r30 = *(s32 *)((u8 *)*arg0 + 8);
    loc.a = 0;
    loc.b = 0;
    var_r29 = 0;

    if (*(s32 *)(*(u8 **)(arg1 + 0x160) + 0x14) != 0) {
        var_r29 = 4 - fn_80362F5C(temp_r30) % 4;
        if (var_r29 == 4) {
            var_r29 = 0;
        }
    }

    if (*(s32 *)(arg1 + 0x194) == 0) {
        temp_r31 = fn_80362F5C(temp_r30);
        if (fn_8037C1C0(arg1, fn_80362F54(temp_r30), temp_r31) == 0) {
            return 0;
        }
        return fn_8037C1C0(arg1, &loc.a, (u32)var_r29) != 0;
    }

    temp_r31 = fn_80362F5C(temp_r30);
    if (fn_8037B644(arg1 + 0x78, fn_80362F54(temp_r30), temp_r31) == 0 ||
        fn_8037B644(arg1 + 0x78, &loc.a, (u32)var_r29) == 0 ||
        fn_8037B7B4(arg1 + 0x54, *(s32 *)(arg1 + 0x7c),
                    *(s32 *)(arg1 + 0x84)) == 0) {
        return 0;
    }

    fn_8037BBB8(arg1 + 0x78);
    if (fn_8037BBDC(arg1) == 0) {
        return 0;
    }
    if (*(s32 *)(arg1 + 0x64) == *(s32 *)(arg1 + 0x60)) {
        fn_8037BBB8(arg1 + 0x54);
    }
    return 1;
}
