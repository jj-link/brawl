#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct GimmickPrefix {
    unsigned char padding[0x3C];
};

#define VIRTUAL_SLOTS(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9(); \
    virtual void prefix##A(); \
    virtual void prefix##B(); \
    virtual void prefix##C(); \
    virtual void prefix##D(); \
    virtual void prefix##E(); \
    virtual void prefix##F();

struct Gimmick : GimmickPrefix {
    VIRTUAL_SLOTS(unused0)
    VIRTUAL_SLOTS(unused1)
    VIRTUAL_SLOTS(unused2)
    VIRTUAL_SLOTS(unused3)
    VIRTUAL_SLOTS(unused4)
    VIRTUAL_SLOTS(unused5)
    VIRTUAL_SLOTS(unused6)

    virtual void first(float);
    virtual void second(float);

    unsigned char padding40[0x88];
    unsigned char active;
};

#undef VIRTUAL_SLOTS

extern "C" void fn_74_B640(Gimmick* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->first(deltaFrame);
        self->second(deltaFrame);
    }
}
