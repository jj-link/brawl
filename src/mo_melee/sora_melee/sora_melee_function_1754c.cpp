#pragma force_active on
namespace nw4r { namespace g3d { class AnmObjChrRes; } }

class soAnimChr {
public:
    nw4r::g3d::AnmObjChrRes* animation;
    float getEndFrame(nw4r::g3d::AnmObjChrRes*) const;
};

class AnimProvider {
public:
    virtual void unused();
    virtual soAnimChr* getAnimation();
};

struct Object {
    unsigned char padding[0x8c];
    AnimProvider* provider;
};

extern "C" float fn_27_1754C(Object* __restrict object) {
    soAnimChr* animation = object->provider->getAnimation();
    return animation->getEndFrame(animation->animation);
}
