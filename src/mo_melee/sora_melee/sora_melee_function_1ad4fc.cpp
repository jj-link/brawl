#include <types.h>
#pragma force_active on

struct soDummyResult {
    s32 m_a;
    void* m_ptr;
};

struct soDummyBase {
    virtual void vf0();
    virtual soDummyResult* vf1();
};

class soOuter {
public:
    u8 m_pad[0x10];
    soDummyBase m_base;
};

extern "C" void* fn_27_1AD4FC(soOuter* self) {
    return self->m_base.vf1()->m_ptr;
}
