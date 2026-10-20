#pragma force_active on
#define DECLARE_VIRTUAL_SLOTS(prefix) \
    virtual void prefix##0();  \
    virtual void prefix##1();  \
    virtual void prefix##2();  \
    virtual void prefix##3();  \
    virtual void prefix##4();  \
    virtual void prefix##5();  \
    virtual void prefix##6();  \
    virtual void prefix##7();  \
    virtual void prefix##8();  \
    virtual void prefix##9();  \
    virtual void prefix##10(); \
    virtual void prefix##11(); \
    virtual void prefix##12(); \
    virtual void prefix##13(); \
    virtual void prefix##14(); \
    virtual void prefix##15();

struct GreenHillBase {
    unsigned char padding[0x3C];

    DECLARE_VIRTUAL_SLOTS(reserved0_)
    DECLARE_VIRTUAL_SLOTS(reserved1_)
    DECLARE_VIRTUAL_SLOTS(reserved2_)
    DECLARE_VIRTUAL_SLOTS(reserved3_)
    DECLARE_VIRTUAL_SLOTS(reserved4_)
    DECLARE_VIRTUAL_SLOTS(reserved5_)
    DECLARE_VIRTUAL_SLOTS(reserved6_)

    virtual void updateFirst(float deltaFrame);
    virtual void updateSecond(float deltaFrame);
};

#undef DECLARE_VIRTUAL_SLOTS

struct GreenHill : GreenHillBase {
    unsigned char padding40[0x88];
    unsigned char active;
};

extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

extern "C" void fn_72_C1D4(GreenHill* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
    }
}
