#pragma force_active on
extern "C" void update__9grGimmickFf(void*, float);

#define UNUSED_VIRTUALS(n) \
    virtual void unused##n##a(); \
    virtual void unused##n##b(); \
    virtual void unused##n##c(); \
    virtual void unused##n##d(); \
    virtual void unused##n##e(); \
    virtual void unused##n##f(); \
    virtual void unused##n##g(); \
    virtual void unused##n##h(); \
    virtual void unused##n##i(); \
    virtual void unused##n##j();

struct Halberd {
    unsigned char padding0[0x3C];
    UNUSED_VIRTUALS(0)
    UNUSED_VIRTUALS(1)
    UNUSED_VIRTUALS(2)
    UNUSED_VIRTUALS(3)
    UNUSED_VIRTUALS(4)
    UNUSED_VIRTUALS(5)
    UNUSED_VIRTUALS(6)
    UNUSED_VIRTUALS(7)
    UNUSED_VIRTUALS(8)
    UNUSED_VIRTUALS(9)
    UNUSED_VIRTUALS(10)
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void updateFirst(float);
    virtual void updateSecond(float);
    unsigned char padding1[0x88];
    unsigned char active;
};

#undef UNUSED_VIRTUALS

extern "C" void fn_57_D2F4(Halberd* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
    }
}
