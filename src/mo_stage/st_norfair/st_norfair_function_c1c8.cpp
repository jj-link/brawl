#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct NorfairBase {
    unsigned char padding[0x3C];
};

#define RESERVED_VIRTUALS(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

struct Norfair : NorfairBase {
    RESERVED_VIRTUALS(slot00)
    RESERVED_VIRTUALS(slot01)
    RESERVED_VIRTUALS(slot02)
    RESERVED_VIRTUALS(slot03)
    RESERVED_VIRTUALS(slot04)
    RESERVED_VIRTUALS(slot05)
    RESERVED_VIRTUALS(slot06)
    RESERVED_VIRTUALS(slot07)
    RESERVED_VIRTUALS(slot08)
    RESERVED_VIRTUALS(slot09)
    RESERVED_VIRTUALS(slot10)
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void updateFirst(float);
    virtual void updateSecond(float);

    unsigned char padding1[0x88];
    unsigned char active;
};

#undef RESERVED_VIRTUALS

extern "C" void fn_54_C1C8(Norfair* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
    }
}
