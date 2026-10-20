#include <types.h>
#pragma force_active on

class soFlagTarget {
public:
    virtual ~soFlagTarget();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void setFlag(s32 value, u32 id);
};

extern "C" void fn_27_2FB020(void* unused, u8* owner) {
    soFlagTarget* target = *(soFlagTarget**)(*(u8**)(owner + 0xD8) + 0x64);
    target->setFlag(0, 0x10000040);
    target->setFlag(0, 0x10000041);
    target->setFlag(0, 0x10000042);
}
