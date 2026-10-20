#include <gr/ground.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_80110B98(void*, u32, Ground*);

struct ByteBits6D {
    u8 : 1;
    u8 valid : 1;
    u8 : 6;
};

struct ByteBits6C {
    u8 : 2;
    u8 valid : 1;
    u8 clipping : 1;
    u8 : 4;
};

void Ground::setValid(u32 valid) {
    u8* p = (u8*)this;
    u8 old = p[0x6D];

    if (((old >> 6) & 1) != valid) {
        ((ByteBits6D*)(p + 0x6D))->valid = valid;
        setVisibility(valid);

        ByteBits6C* bits = (ByteBits6C*)(p + 0x6C);
        bits->valid = valid;

        if (m_collision) {
            if (bits->valid && bits->clipping)
                fn_80110B98(m_collision, 1, this);
            else
                fn_80110B98(m_collision, 0, this);
        }
    }
}
