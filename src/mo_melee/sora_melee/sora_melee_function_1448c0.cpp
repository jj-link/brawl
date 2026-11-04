#include <types.h>
#pragma force_active on
extern "C" s32 fn_27_143B54(s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_27_1448C0(s32 a, s32 b, s32 c, s32 d, s32 flags, s32 e, s32 f) {
    if ((flags & 0x1) && fn_27_143B54(a, b, c, d, 0, e, f) == 0) return 0;
    if ((flags & 0x2) && fn_27_143B54(a, b, c, d, 1, e, f) == 0) return 0;
    if ((flags & 0x4) && fn_27_143B54(a, b, c, d, 2, e, f) == 0) return 0;
    if ((flags & 0x8) && fn_27_143B54(a, b, c, d, 3, e, f) == 0) return 0;
    if ((flags & 0x10) && fn_27_143B54(a, b, c, d, 4, e, f) == 0) return 0;
    if ((flags & 0x20) && fn_27_143B54(a, b, c, d, 5, e, f) == 0) return 0;
    if ((flags & 0x40) && fn_27_143B54(a, b, c, d, 6, e, f) == 0) return 0;
    if ((flags & 0x80) && fn_27_143B54(a, b, c, d, 7, e, f) == 0) return 0;
    if ((flags & 0x100) && fn_27_143B54(a, b, c, d, 8, e, f) == 0) return 0;
    if ((flags & 0x200) && fn_27_143B54(a, b, c, d, 9, e, f) == 0) return 0;
    if ((flags & 0x400) && fn_27_143B54(a, b, c, d, 10, e, f) == 0) return 0;
    if ((flags & 0x800) && fn_27_143B54(a, b, c, d, 11, e, f) == 0) return 0;
    if ((flags & 0x1000) && fn_27_143B54(a, b, c, d, 12, e, f) == 0) return 0;
    if ((flags & 0x2000) && fn_27_143B54(a, b, c, d, 13, e, f) == 0) return 0;
    if ((flags & 0x4000) && fn_27_143B54(a, b, c, d, 14, e, f) == 0) return 0;
    if ((flags & 0x8000) && fn_27_143B54(a, b, c, d, 15, e, f) == 0) return 0;
    return 1;
}
