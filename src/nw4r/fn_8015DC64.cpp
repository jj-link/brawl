#include <types.h>
#pragma force_active on

extern "C" {
extern u16 lbl_8059E868;
u8* fn_801DCE58(u8* data, s32* out);
}

struct Obj { u8 pad[0x18]; u16 value; };

static inline int isSingle(u32 c) {
    if (c > 0xFF) return 0;
    return (c >= 0x20 && c <= 0x7E) || (c >= 0xA1 && c <= 0xDF);
}

static inline int isDouble(u32 c) {
    u32 hi = (c >> 8) & 0xFF;
    u32 lo = c & 0xFF;
    return hi >= 0x81 && hi <= 0x98 && lo >= 0x40 && lo <= 0xFC;
}

extern "C" s32 fn_8015DC64(Obj* self, u32 c) {
    struct { u8 buf[4]; s32 result; } loc;
    int valid;

    switch (lbl_8059E868) {
    case 0:
        valid = 0;
        if (c >= 0x20 && c <= 0xFF) valid = 1;
        break;
    case 1: {
        int s = isSingle(c);
        valid = 1;
        if (!s) {
            if (!isDouble(c)) valid = 0;
        }
        break;
    }
    }

    c = valid ? c : self->value;

    u32 hi = (c >> 8) & 0xFF;
    if (hi == 0) {
        loc.buf[0] = c;
        loc.buf[1] = 0;
    } else {
        loc.buf[0] = hi;
        loc.buf[1] = c;
        loc.buf[2] = 0;
    }
    fn_801DCE58(loc.buf, &loc.result);
    return loc.result;
}
