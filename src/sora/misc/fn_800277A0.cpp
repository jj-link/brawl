#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {

class AnmObjTexSrtRes;

class ScnMdl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void bindTexSrt(AnmObjTexSrtRes* obj, u32 flag);
    virtual void v12();
};

}
}

class gfModelAnimation {
public:
    void* m_resFile;
    char _spacer[4];
    void* m_anmObjVisRes;
    void* m_anmObjChrRes;
    void* m_anmObjTexPatRes;
    nw4r::g3d::AnmObjTexSrtRes* m_anmObjTexSrtRes;
    void* m_anmObjMatClrRes;
    void* m_anmObjShpRes;
};

extern "C" {
void bindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(gfModelAnimation* this_, nw4r::g3d::ScnMdl* sceneModel) {
    if (this_->m_anmObjTexSrtRes)
        sceneModel->bindTexSrt(this_->m_anmObjTexSrtRes, 4);
}
}
