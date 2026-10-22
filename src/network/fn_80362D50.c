#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

s32 fn_80362F64(s32, s32, s32, s32*, s32);

s32 fn_80362D50(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8 = 0;
    s32 a0 = arg0;
    s32 a2 = arg2;
    s32 a1 = arg1;
    while (sp8 < a2) {
        if (fn_80362F64(a0, a1, a2, &sp8, -1) == 0) {
            return 0;
        }
    }
    return 1;
}
