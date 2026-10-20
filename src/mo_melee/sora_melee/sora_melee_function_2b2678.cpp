#include <types.h>
#pragma force_active on

struct fn_27_2B2678_Self {
    u32 pad0;
    u32 pad4;
    u32 f8;
    u32 fC;
    u32 pad10;
    u32 pad14;
    u32 f18;
};

extern "C" void* getInstance__9itManagerFv();
extern "C" u32 fn_27_2A0E24(void* itMgr, u32 a, u32 b);
extern "C" void* getManager__11soArchiveDbFUl(u32 index);
extern "C" int getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);

extern "C" {
int fn_27_2B2678(fn_27_2B2678_Self* self, const char* name) {
    u32 r = fn_27_2A0E24(getInstance__9itManagerFv(), self->f8, self->fC);
    void* mgr = getManager__11soArchiveDbFUl(2);
    return getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, self->f18, name, 0, 0, r);
}
}
