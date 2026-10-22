#pragma force_active on

struct Base {
    unsigned char padding[0x3C];
};

#define VIRTUAL_SLOT(n) virtual void unused##n();
#define VIRTUAL_SLOTS_16(n) \
    VIRTUAL_SLOT(n##0) VIRTUAL_SLOT(n##1) \
    VIRTUAL_SLOT(n##2) VIRTUAL_SLOT(n##3) \
    VIRTUAL_SLOT(n##4) VIRTUAL_SLOT(n##5) \
    VIRTUAL_SLOT(n##6) VIRTUAL_SLOT(n##7) \
    VIRTUAL_SLOT(n##8) VIRTUAL_SLOT(n##9) \
    VIRTUAL_SLOT(n##A) VIRTUAL_SLOT(n##B) \
    VIRTUAL_SLOT(n##C) VIRTUAL_SLOT(n##D) \
    VIRTUAL_SLOT(n##E) VIRTUAL_SLOT(n##F)

struct Object : Base {
    VIRTUAL_SLOTS_16(00)
    VIRTUAL_SLOTS_16(01)
    VIRTUAL_SLOTS_16(02)
    VIRTUAL_SLOTS_16(03)
    VIRTUAL_SLOTS_16(04)
    VIRTUAL_SLOTS_16(05)
    VIRTUAL_SLOTS_16(06)
    VIRTUAL_SLOTS_16(07)
    VIRTUAL_SLOT(080)
    VIRTUAL_SLOT(081)
    VIRTUAL_SLOT(082)
    VIRTUAL_SLOT(083)
    VIRTUAL_SLOT(084)
    VIRTUAL_SLOT(085)
    VIRTUAL_SLOT(086)
    virtual void method224(int);
    VIRTUAL_SLOT(088)
    VIRTUAL_SLOT(089)
    VIRTUAL_SLOT(08A)
    VIRTUAL_SLOT(08B)
    virtual void method238();
    virtual void method23C(int);
    virtual void method240(int);
    virtual void method244(int);
    virtual void method248(int);
    virtual void method24C(int);
    virtual void method250();
    virtual void method254(int);
};

#undef VIRTUAL_SLOTS_16
#undef VIRTUAL_SLOT

extern "C" void fn_63_C7C(Object* self) {
    self->method224(0x21);
    self->method238();
    self->method23C(0x0B);
    self->method23C(0x0C);
    self->method23C(0x0D);
    self->method23C(0x0E);
    self->method240(0x0A);
    self->method244(0x08);
    self->method248(0x09);
    self->method24C(0x0F);
    self->method24C(0x10);
    self->method24C(0x11);
    self->method250();
    self->method254(0x02);
    self->method254(0x03);
    self->method254(0x04);
    self->method254(0x05);
    self->method254(0x06);
    self->method254(0x07);
}
