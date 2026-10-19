#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_6F30C(void*);

struct fnInner {
    virtual void vf0();
    virtual fnInner* vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" u32 fn_27_6C858(char* self) {
    fnInner* inner = *(fnInner**)(self + 0x48);
    char* q = (char*)inner->vf1();
    u32 r = fn_27_6F30C((void*)(q + 0x1c));
    u32 p = *(u32*)(r + 0x44);
    p = *(u32*)(p + 0x8);
    return *(u32*)(p + 0x28);
}
