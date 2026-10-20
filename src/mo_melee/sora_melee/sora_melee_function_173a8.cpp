#include <types.h>
#pragma force_active on

namespace nw4r { namespace g3d { class AnmObjChrRes; } }

class soAnimChr {
public:
    nw4r::g3d::AnmObjChrRes* m_anmChrRes;
    float m_animFrame;
    float m_startFrame;
    float m_saveFrame;
    float m_rate;
    float m_frameAhead;
    u8 m_loopFlag : 1;
    u8 m_reverseFlag : 1;
    void setFrame(float frame);
};

class AnimHolder {
public:
    virtual ~AnimHolder();
    virtual soAnimChr* getAnimChr(int index);
};

struct NVBase {
    u32 a;
    u32 b;
};

class ChainObj : public NVBase {
public:
    virtual ~ChainObj();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void doNotify();
};

struct ChainMid {
    u32 pad;
    ChainObj* obj;
};

struct FakeAccesser {
    u8 pad[0xd8];
    ChainMid* mid;
};

struct Owner {
    u8 pad[0x8c];
    AnimHolder* animHolder;
    u8 pad2[0x168 - 0x90];
    FakeAccesser* accesser;
};

extern "C" void fn_27_173A8(Owner* self, int index, float frame) {
    soAnimChr* anim = self->animHolder->getAnimChr(index);
    anim->setFrame(frame);
    anim = self->animHolder->getAnimChr(index);
    if (anim->m_anmChrRes != NULL) {
        self->accesser->mid->obj->doNotify();
    }
}
