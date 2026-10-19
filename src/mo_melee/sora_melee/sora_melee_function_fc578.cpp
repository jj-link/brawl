#include <types.h>
#pragma force_active on

struct fnRefProvider {
    virtual void vf0();
    virtual u32* getRef(u32 idx);
};

extern "C" {
void fn_27_FC578(fnRefProvider* obj, u32* src, u32 idx) {
    u32* p = obj->getRef(idx);
    *p = *src;
}
}
