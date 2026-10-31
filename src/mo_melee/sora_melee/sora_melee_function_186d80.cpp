#include <types.h>
#pragma force_active on

class fnObjBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(s32 a, s32 b);
};

extern "C" void fn_27_186D80(void* unused, u8* self, s32 id) {
    if (id == 0xda) {
        return;
    }
    if (id == 0xdb) {
        return;
    }
    fnObjBase* obj = *(fnObjBase**)(*(u8**)(self + 0xd8) + 0x40);
    return obj->vf10(1, 0);
}
