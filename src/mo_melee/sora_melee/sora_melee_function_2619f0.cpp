#include <gr/ground.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_80110B98(void*, u32, Ground*);

struct ByteBits69 {
    u8 : 1;
    u8 flag : 1;
    u8 : 6;
};

struct ByteBits68 {
    u8 : 2;
    u8 valid : 1;
    u8 effect : 1;
    u8 : 4;
};

void Ground::setValidAttachedEffect(u32 valid) {
    u8* p = (u8*)this;
    u8 old = p[0x6D];

    if (((old >> 6) & 1) != valid) {
        ((ByteBits69*)(p + 0x6D))->flag = valid;
        setVisibilityAttachedEffect(valid);

        ByteBits68* bits = (ByteBits68*)(p + 0x6C);
        bits->valid = valid;

        if (m_collision) {
            if (bits->valid && bits->effect)
                fn_80110B98(m_collision, 1, this);
            else
                fn_80110B98(m_collision, 0, this);
        }
    }
}
