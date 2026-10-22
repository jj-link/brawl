#pragma force_active on
typedef signed int s32;

s32 fn_801E42E4(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 fn_801E46FC(s32 a);

s32 fn_801E4560(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a3 = arg3;
    s32 count = arg2;
    while (count != 0) {
        s32 chunk = (count < 4) ? count : 4;
        if (fn_801E42E4(arg0, arg1, chunk, a3, 0) == 0) {
            return 0;
        }
        if (fn_801E46FC(arg0) == 0) {
            return 0;
        }
        arg1 += chunk;
        count -= chunk;
    }
    return 1;
}
