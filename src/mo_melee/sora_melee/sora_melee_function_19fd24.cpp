#include <types.h>
#pragma force_active on

namespace {
    struct Bitfields {
        u8 _0[8];
        s32 m_8 : 3;
    };
}

extern "C" int fn_27_19FD24(Bitfields* arg0) {
    return arg0->m_8;
}
