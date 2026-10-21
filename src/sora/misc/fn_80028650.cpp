#pragma force_active on

struct Animation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setUpdateRate(float);
};

struct gfModelAnimation {
    char pad[8];
    Animation* anim8;
    Animation* animC;
    Animation* anim10;
    Animation* anim14;
    Animation* anim18;
    Animation* anim1C;
};

extern "C" void setUpdateRate__16gfModelAnimationFf(gfModelAnimation* self, float rate) {
    if (self->animC) self->animC->setUpdateRate(rate);
    if (self->anim8) self->anim8->setUpdateRate(rate);
    if (self->anim10) self->anim10->setUpdateRate(rate);
    if (self->anim14) self->anim14->setUpdateRate(rate);
    if (self->anim18) self->anim18->setUpdateRate(rate);
    if (self->anim1C) self->anim1C->setUpdateRate(rate);
}
