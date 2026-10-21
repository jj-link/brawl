#pragma force_active on
typedef int s32;

s32 fn_80396EEC(s32 a, s32 b, s32 c);

s32 fn_803970E4(s32 a, s32 b) {
    s32 r;

    r = fn_80396EEC(a, b, 0);
    if (r != 0) {
        return *(s32 *)(r + 0x10);
    }
    return b;
}
