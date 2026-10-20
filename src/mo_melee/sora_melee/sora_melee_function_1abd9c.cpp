#include <types.h>
#pragma force_active on

struct soGeneralWorkCopyData {
    u32 m_a;
    u32 m_b;
};

class soGeneralWorkCopyObj {
public:
    virtual void vf0();
    virtual soGeneralWorkCopyData* vf1(void* arg);
};

extern "C" void fn_27_1ABD9C(soGeneralWorkCopyObj* obj, const soGeneralWorkCopyData* src, void* arg) {
    soGeneralWorkCopyData* dst = obj->vf1(arg);
    dst->m_a = src->m_a;
    dst->m_b = src->m_b;
}
