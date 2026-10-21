#pragma force_active on

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

struct Object {
    unsigned char padding[0x3C];

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
    virtual void method220(int);
    virtual void method224(int);
    VIRTUAL_SLOT(08A)
    VIRTUAL_SLOT(08B)
    VIRTUAL_SLOT(08C)
    VIRTUAL_SLOT(08D)
    VIRTUAL_SLOT(08E)
    VIRTUAL_SLOT(08F)
    VIRTUAL_SLOT(090)
    VIRTUAL_SLOT(091)
    VIRTUAL_SLOT(092)
    VIRTUAL_SLOT(093)
    VIRTUAL_SLOT(094)
    VIRTUAL_SLOT(095)
    VIRTUAL_SLOT(096)
    VIRTUAL_SLOT(097)
    VIRTUAL_SLOT(098)
    virtual void method264(int);
};

#undef VIRTUAL_SLOTS_16
#undef VIRTUAL_SLOT

extern "C" void fn_63_1CD4(Object* self) {
    self->method220(0x1b);
    self->method224(0x1c);
    self->method264(0x1d);
    self->method264(0x1e);
    self->method264(0x1f);
    self->method264(0x20);
}
