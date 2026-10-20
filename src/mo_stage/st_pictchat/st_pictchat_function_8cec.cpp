#pragma force_active on
#define UNUSED_SLOT(n) virtual void unused##n();
#define UNUSED_TEN(n) \
    UNUSED_SLOT(n##0) UNUSED_SLOT(n##1) UNUSED_SLOT(n##2) \
    UNUSED_SLOT(n##3) UNUSED_SLOT(n##4) UNUSED_SLOT(n##5) \
    UNUSED_SLOT(n##6) UNUSED_SLOT(n##7) UNUSED_SLOT(n##8) UNUSED_SLOT(n##9)

struct PictChatBase {
    unsigned char padding[0x3C];
};

struct PictChat : PictChatBase {
    UNUSED_TEN(0)
    UNUSED_TEN(1)
    UNUSED_TEN(2)
    UNUSED_TEN(3)
    UNUSED_TEN(4)
    UNUSED_TEN(5)
    UNUSED_TEN(6)
    UNUSED_TEN(7)
    UNUSED_TEN(8)
    UNUSED_TEN(9)
    UNUSED_TEN(10)
    UNUSED_TEN(11)
    UNUSED_TEN(12)
    UNUSED_SLOT(130)
    UNUSED_SLOT(131)
    UNUSED_SLOT(132)
    UNUSED_SLOT(133)
    UNUSED_SLOT(134)
    UNUSED_SLOT(135)
    UNUSED_SLOT(136)
    UNUSED_SLOT(137)
    UNUSED_SLOT(138)
    virtual void initializeSlot(unsigned char);

    unsigned char padding[0x241];
    unsigned char initialized;
};

#undef UNUSED_TEN
#undef UNUSED_SLOT

extern "C" void fn_73_8CEC(PictChat* self) {
    if (self->initialized != 1) {
        for (unsigned int i = 0; i < 4; ++i) {
            self->initializeSlot((unsigned char)i);
        }
        self->initialized = 1;
    }
}
