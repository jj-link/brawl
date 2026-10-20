#include <types.h>
#pragma force_active on

struct FlagBlock {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};

extern "C" int fn_27_D29D8(FlagBlock* block) {
    return (block->m_8 >> 22) & 1;
}
