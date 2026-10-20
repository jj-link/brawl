#include <types.h>
#pragma force_active on

class ecMgr {
public:
    void setMdlAnmIdx(u32, u32, s8);
};

extern ecMgr* g_ecMgr;

struct FnObj27 {
    s32 m_0;
    s32 m_4;
    u32 m_8;
    u32 m_c;
};

extern "C" {
void fn_27_2D5EB4(FnObj27* self) {
    g_ecMgr->setMdlAnmIdx(self->m_c, 1, 1);
    self->m_0 = 2;
    self->m_4 = 0;
}
}
