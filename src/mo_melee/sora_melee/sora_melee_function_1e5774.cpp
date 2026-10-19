#include <types.h>
#pragma force_active on

struct fnObj3F;

struct fnObjBase {
    virtual void vf0();
    virtual fnObj3F* vf1(void* p);
};

struct fnObj3F {
    u32 m_word;
};

extern "C" {
void fn_27_1E5774(fnObjBase* self, u32* src, void* arg) {
    fnObj3F* dst = self->vf1(arg);
    dst->m_word = *src;
}
}
