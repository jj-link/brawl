#include <types.h>
#pragma force_active on

struct Pair {
    u32 m_x;
    u32 m_y;
};

struct Ctx {
    u32 pad[2];
    Pair m_pair;
};

extern "C" Pair fn_94_DD40(const Ctx* ctx)
{
    return ctx->m_pair;
}
