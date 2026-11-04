#include <ec/ec_trace.h>
#pragma force_active on

extern int lbl_805A1998;
extern unsigned char lbl_805A19A0[0x8];

static float traceReciprocal(u32 value) {
    return *reinterpret_cast<float*>(&lbl_805A1998) /
           static_cast<float>(value);
}

void ecTrace::end(u32 p1, u32 p2) {
    u8* self = reinterpret_cast<u8*>(this);
    u8 state = self[0x0F];

    if (state == 0) {
        if (p2 == 0) {
            self[0x0F] = 1;
            *reinterpret_cast<float*>(self + 0x78) =
                p1 == 0 ? *reinterpret_cast<float*>(&lbl_805A1998)
                        : traceReciprocal(p1);
        } else {
            *reinterpret_cast<u32*>(self + 0x7C) = p2;
            *reinterpret_cast<u32*>(self + 0x80) = p1;
        }
    } else if (state == 1) {
        *reinterpret_cast<float*>(self + 0x78) =
            p1 == 0 ? *reinterpret_cast<float*>(&lbl_805A1998)
                    : traceReciprocal(p1);
    }
}
