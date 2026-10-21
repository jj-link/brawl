#pragma force_active on
typedef int s32;
typedef unsigned short u16;

extern "C" {
void fn_80112D64(s32 arg0, u16 *arg1) {
    s32 idx = *arg1;
    *(s32 *)(arg0 + idx * 4 + 0xF0) = 0;
    {
        s32 *bits = (s32 *)(arg0 + (idx >> 5) * 4 + 0xCC);
        *bits = *bits & ~(1 << (idx & 31));
    }
    *arg1 = 0xFFFF;
}
}
