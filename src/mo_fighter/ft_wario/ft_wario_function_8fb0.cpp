#pragma force_active on
#define VIRTUAL_SLOT(n) virtual void slot##n();
#define VIRTUAL_TEN(n) \
    VIRTUAL_SLOT(n##0) VIRTUAL_SLOT(n##1) \
    VIRTUAL_SLOT(n##2) VIRTUAL_SLOT(n##3) \
    VIRTUAL_SLOT(n##4) VIRTUAL_SLOT(n##5) \
    VIRTUAL_SLOT(n##6) VIRTUAL_SLOT(n##7) \
    VIRTUAL_SLOT(n##8) VIRTUAL_SLOT(n##9)

struct Wario {
    unsigned char pad[0x3C];

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
    VIRTUAL_TEN(11)
    VIRTUAL_TEN(12)
    VIRTUAL_TEN(13)
    VIRTUAL_TEN(14)
    VIRTUAL_TEN(15)
    VIRTUAL_SLOT(160)
    VIRTUAL_SLOT(161)
    VIRTUAL_SLOT(162)
    VIRTUAL_SLOT(163)
    VIRTUAL_SLOT(164)
    virtual void first(void*);
    VIRTUAL_SLOT(166)
    VIRTUAL_SLOT(167)
    VIRTUAL_SLOT(168)
    VIRTUAL_SLOT(169)
    VIRTUAL_SLOT(170)
    VIRTUAL_SLOT(171)
    virtual void second(void*, int);
};

#undef VIRTUAL_TEN
#undef VIRTUAL_SLOT

extern "C" void fn_110_8FB0(Wario* self, void* arg1, void* arg2) {
    self->first(arg2);
    self->second(arg1, 0x130);
}
