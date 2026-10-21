#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {
class ScnMdl {
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
    virtual void vf10();
    virtual void vf11(void* p, u32 n);
};
}
}

class gfModelAnimation {
public:
    u8 m_pad[0x1c];
    void* m_target;
    void bindShapeAnim(nw4r::g3d::ScnMdl* mdl);
};

void gfModelAnimation::bindShapeAnim(nw4r::g3d::ScnMdl* mdl) {
    if (m_target) {
        mdl->vf11(m_target, 5);
    }
}
