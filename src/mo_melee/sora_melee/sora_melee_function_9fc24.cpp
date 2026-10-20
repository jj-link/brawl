#pragma force_active on
typedef unsigned long u32;
typedef int s32;

class ecMgr {
public:
    void endEffect(u32 id);
};

extern ecMgr* g_ecMgr;

struct fn27Obj {
    s32 m_0;
    s32 m_4;
    u32 m_8;
};

extern "C" bool fn_27_9FC24(fn27Obj* self) {
    s32 n = self->m_4 - 1;
    self->m_4 = n;
    if (n <= 0) {
        g_ecMgr->endEffect(self->m_8);
        self->m_8 = 0;
        self->m_4 = 0;
        self->m_0 = -1;
        return true;
    }
    return false;
}
