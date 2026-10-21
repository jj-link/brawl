#pragma force_active on

typedef unsigned int u32;

class AnimationObject {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setUpdateRate(float rate);
};

struct gfModelAnimation {
    char pad[8];
    AnimationObject* visibility;
    AnimationObject* character;
    AnimationObject* texturePattern;
    AnimationObject* textureSrt;
    AnimationObject* materialColor;
};

struct ModelOwner {
    char pad[0x14];
    gfModelAnimation* animation;
};

extern "C" void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*, float);

extern "C" void fn_800B7F38(ModelOwner* self, u32 flags, float rate) {
    if (flags == 0x1F) {
        setUpdateRate__16gfModelAnimationFf(self->animation, rate);
        return;
    }

    if (flags & 1)
        self->animation->character->setUpdateRate(rate);
    if (flags & 2)
        self->animation->visibility->setUpdateRate(rate);
    if (flags & 4)
        self->animation->texturePattern->setUpdateRate(rate);
    if (flags & 8)
        self->animation->textureSrt->setUpdateRate(rate);
    if (flags & 0x10)
        self->animation->materialColor->setUpdateRate(rate);
}
