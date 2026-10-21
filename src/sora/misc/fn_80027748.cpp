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
    virtual void vf13(void* a, u32 b);
};
}
}

class gfModelAnimation {
public:
    u8 m_pad[8];
    void* m_anim;
    void bindVisibleAnim(nw4r::g3d::ScnMdl* mdl);
};

void gfModelAnimation::bindVisibleAnim(nw4r::g3d::ScnMdl* mdl) {
    if (m_anim != 0) {
        mdl->vf13(m_anim, 1);
    }
}
