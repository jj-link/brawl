#include <types.h>
#pragma force_active on
extern void fn_8039272C(void *, void *, s32);

s32 fn_80391000(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 len;
    u8 *self;
    s32 count;
    s32 offset;
    u8 *dst;
    self = arg0;
    if (arg2 + arg3 <= *(s32 *)self) {
        dst = arg1;
        offset = arg2;
        count = arg3;
        if (count != 0) {
            if (offset < 0x400) {
                len = count;
                if (len > 0x400 - offset)
                    len = 0x400 - offset;
                fn_8039272C(dst, self + offset + 0x38, len);
                offset += len;
                count -= len;
                dst += len;
            }
            if (count != 0) {
                s32 num;
                offset -= 0x400;
                self = *(u8 **)(self + 0x34);
                num = offset >> 9;
                offset &= 0x1FF;
                while (num-- != 0) {
                    self = *(u8 **)self;
                }
                while (count != 0) {
                    len = count;
                    if (len > 0x200 - offset)
                        len = 0x200 - offset;
                    fn_8039272C(dst, self + offset + 4, len);
                    offset += len;
                    self = *(u8 **)self;
                    offset &= 0x1FF;
                    count -= len;
                    dst += len;
                }
            }
        }
        return 1;
    }
    return 0;
}