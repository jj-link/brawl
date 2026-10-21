#include <types.h>
#pragma force_active on

struct Block {
    u8 _0[0x14];
    u32 m_off;
};

struct BlockOwner {
    u8 _0[0x2c];
    Block* m_block;
};

struct Mid {
    u8 _0[0x18];
    BlockOwner* m_owner;
};

struct Root {
    u8 _0[0x14];
    Mid* m_mid;
};

extern "C" void* fn_800B6188(Root* p) {
    BlockOwner* o = p->m_mid->m_owner;
    if (o == 0) {
        return 0;
    }
    Block* b = o->m_block;
    u32 off = b->m_off;
    if (off != 0) {
        return (u8*)b + off;
    }
    return 0;
}
