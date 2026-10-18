#include <types.h>
#pragma force_active on

struct SamusPair {
    u32 a;
    u32 b;
};

extern "C" u32* fn_94_AAC4(SamusPair* p, int i) {
    return &p[i].b;
}
