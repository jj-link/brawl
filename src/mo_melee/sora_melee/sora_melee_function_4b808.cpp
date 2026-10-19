#include <types.h>
#pragma force_active on

struct stRet {
    u32 unk0;
};

struct stSub {
    virtual ~stSub();
    virtual stRet* f1();
};

struct stOwner {
    u8 pad[0x2c];
    stSub* m_sub;
};

extern "C" void fn_27_4B808(stOwner* p) {
    stRet* r = p->m_sub->f1();
    r->unk0 = 0;
}
