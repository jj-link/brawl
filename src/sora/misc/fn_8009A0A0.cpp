#include <types.h>
#pragma force_active on

extern "C" {

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, u16 type, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct FreeObj {
    void* vtable;
    u16 type;
};

void* fn_8009A0A0(void* arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        lbl_805A0EB8->free(arg0, ((FreeObj*)arg0)->type, 0x13);
    }
    return arg0;
}

}
