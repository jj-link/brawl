#pragma force_active on

struct Animation {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void setFrame(double);
};

struct gfModelAnimation {
    char pad[8];
    Animation* animation8;
    Animation* animationC;
    Animation* animation10;
    Animation* animation14;
    Animation* animation18;
    Animation* animation1C;
};

extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation* self, double frame) {
    if (self->animationC)
        self->animationC->setFrame(frame);
    if (self->animation8)
        self->animation8->setFrame(frame);
    if (self->animation10)
        self->animation10->setFrame(frame);
    if (self->animation14)
        self->animation14->setFrame(frame);
    if (self->animation18)
        self->animation18->setFrame(frame);
    if (self->animation1C)
        self->animation1C->setFrame(frame);
}
