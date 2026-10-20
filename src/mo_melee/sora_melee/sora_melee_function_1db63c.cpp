#pragma force_active on
struct Base {
    unsigned char padding[0x3C];
};

#define DECLARE_TEN(n) \
    virtual void unused##n##0(); \
    virtual void unused##n##1(); \
    virtual void unused##n##2(); \
    virtual void unused##n##3(); \
    virtual void unused##n##4(); \
    virtual void unused##n##5(); \
    virtual void unused##n##6(); \
    virtual void unused##n##7(); \
    virtual void unused##n##8(); \
    virtual void unused##n##9();

struct Object : Base {
    DECLARE_TEN(0)
    DECLARE_TEN(1)
    DECLARE_TEN(2)
    DECLARE_TEN(3)
    DECLARE_TEN(4)
    DECLARE_TEN(5)
    DECLARE_TEN(6)
    DECLARE_TEN(7)
    DECLARE_TEN(8)
    DECLARE_TEN(9)
    DECLARE_TEN(10)
    DECLARE_TEN(11)
    DECLARE_TEN(12)
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void reset(int);

    unsigned char padding1[0x64];
    unsigned char flags;
    unsigned char padding2[3];
    unsigned int value;
};

#undef DECLARE_TEN

extern "C" void fn_27_1DB63C(Object* self) {
    self->value = 0;
    self->flags &= ~0x20;
    self->reset(0);
}
