#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, u16 type, s32 align);
};

extern "C" {

extern SoHeapAllocator* lbl_805A0EB8;

void* __dt__14Class_80099F70Fv(void* obj, s32 flag) {
    if (obj != 0 && flag > 0) {
        lbl_805A0EB8->free(obj, *(u16*)((char*)obj + 4), 0x25);
    }
    return obj;
}

}
