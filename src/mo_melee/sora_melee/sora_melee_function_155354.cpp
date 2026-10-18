#include <types.h>
#pragma force_active on

class fn_27_155354_Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf5(u32 id, void* arg);
};

extern "C" void fn_27_155354(void* unused, void* p4) {
    fn_27_155354_Base* obj = (fn_27_155354_Base*)*(void**)((u8*)*(void**)((u8*)p4 + 0xd8) + 0x70);
    obj->vf5(0x6d, p4);
}
