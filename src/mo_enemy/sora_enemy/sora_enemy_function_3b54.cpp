#include <em/enemy.h>
#pragma force_active on

class emNameMsgProvider {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 getNameMsgId(u32 id);
};

s32 Enemy::getNameMsgId() {
    void* a = *(void**)((u8*)this + 0x1b4);
    emNameMsgProvider* b = *(emNameMsgProvider**)((u8*)a + 0x64);
    return b->getNameMsgId(0x10000016);
}
