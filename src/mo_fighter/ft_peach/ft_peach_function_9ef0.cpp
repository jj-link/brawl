#pragma force_active on
#define PEACH_SLOT(n) virtual void slot##n();
#define PEACH_SLOTS_10(n) \
    PEACH_SLOT(n##0) PEACH_SLOT(n##1) PEACH_SLOT(n##2) \
    PEACH_SLOT(n##3) PEACH_SLOT(n##4) PEACH_SLOT(n##5) \
    PEACH_SLOT(n##6) PEACH_SLOT(n##7) PEACH_SLOT(n##8) PEACH_SLOT(n##9)

class PeachDispatch {
public:
    unsigned char padding[0x3C];

    PEACH_SLOTS_10(0)
    PEACH_SLOTS_10(1)
    PEACH_SLOTS_10(2)
    PEACH_SLOTS_10(3)
    PEACH_SLOTS_10(4)
    PEACH_SLOTS_10(5)
    PEACH_SLOTS_10(6)
    PEACH_SLOTS_10(7)
    PEACH_SLOTS_10(8)
    PEACH_SLOTS_10(9)
    PEACH_SLOTS_10(10)
    PEACH_SLOTS_10(11)
    PEACH_SLOTS_10(12)
    PEACH_SLOTS_10(13)
    PEACH_SLOTS_10(14)
    PEACH_SLOTS_10(15)
    PEACH_SLOTS_10(16)
    PEACH_SLOTS_10(17)
    PEACH_SLOT(180)
    PEACH_SLOT(181)
    PEACH_SLOT(182)
    PEACH_SLOT(183)
    PEACH_SLOT(184)
    PEACH_SLOT(185)
    virtual void method();
};

#undef PEACH_SLOTS_10
#undef PEACH_SLOT

extern "C" void fn_103_9EF0(PeachDispatch* self) {
    self->method();
}
