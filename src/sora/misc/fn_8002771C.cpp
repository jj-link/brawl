#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {

class AnmObjChrRes;

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
    virtual void vf11(AnmObjChrRes*, u32);
};

}
}

class gfModelAnimation {
public:
    void* m_resFile;
    char _spacer[4];
    void* m_anmObjVisRes;
    nw4r::g3d::AnmObjChrRes* m_anmObjChrRes;

    void bindNodeAnim(nw4r::g3d::ScnMdl* sceneModel);
};

void gfModelAnimation::bindNodeAnim(nw4r::g3d::ScnMdl* sceneModel) {
    if (m_anmObjChrRes) {
        sceneModel->vf11(m_anmObjChrRes, 0);
    }
}
