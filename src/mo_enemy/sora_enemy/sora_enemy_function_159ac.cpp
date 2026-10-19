#pragma force_active on
typedef int s32;

extern "C" {
s32 fn_41_159AC(s32 p1, s32 p2) {
    if (p2 <= -1 && p2 >= 14) {
        return 0;
    }
    return p1 + (p2 << 6) + 0x770;
}
}
