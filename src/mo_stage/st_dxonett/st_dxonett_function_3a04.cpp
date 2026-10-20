#pragma force_active on
struct ObjectBase {
    unsigned char padding[0x3C];
};

#define VIRTUAL_TEN(n) \
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

struct Object : ObjectBase {
    VIRTUAL_TEN(0)
    VIRTUAL_TEN(1)
    VIRTUAL_TEN(2)
    VIRTUAL_TEN(3)
    VIRTUAL_TEN(4)
    VIRTUAL_TEN(5)
    VIRTUAL_TEN(6)
    VIRTUAL_TEN(7)
    VIRTUAL_TEN(8)
    VIRTUAL_TEN(9)
    VIRTUAL_TEN(10)
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void update();

    unsigned char padding1[0x10C];
    int state;
    unsigned char padding2[0x14];
    unsigned char flag;
};

#undef VIRTUAL_TEN

extern "C" void fn_78_3A04(Object* self) {
    if (self->flag != 1) {
        self->update();
        if (self->state != 0) {
            self->flag = 1;
        }
    }
}
