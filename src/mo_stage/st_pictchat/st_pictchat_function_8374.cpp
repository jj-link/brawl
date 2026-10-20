#pragma force_active on
#define SLOT(n) virtual void slot##n();
#define TEN_SLOTS(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Base {
    unsigned char pad0[0x3c];
    TEN_SLOTS(0)
    TEN_SLOTS(1)
    TEN_SLOTS(2)
    TEN_SLOTS(3)
    TEN_SLOTS(4)
    TEN_SLOTS(5)
    TEN_SLOTS(6)
    TEN_SLOTS(7)
    TEN_SLOTS(8)
    TEN_SLOTS(9)
    TEN_SLOTS(10)
    TEN_SLOTS(11)
    SLOT(120) SLOT(121) SLOT(122) SLOT(123) SLOT(124)
    virtual void update();
    SLOT(126) SLOT(127) SLOT(128) SLOT(129)
    SLOT(130) SLOT(131) SLOT(132) SLOT(133)
    SLOT(134) SLOT(135) SLOT(136) SLOT(137)
    virtual void finish();
};

#undef TEN_SLOTS
#undef SLOT

struct Object : Base {
    unsigned char pad40[0x10c];
    int value;
    unsigned char state;
    unsigned char pad151[0x12f];
    unsigned char flag;
};

extern "C" void fn_73_8374(Object* self) {
    if (self->flag == 1) {
        switch (self->state) {
        case 3:
            self->finish();
            break;
        }
    } else {
        self->update();
        if (self->value != 0) {
            self->flag = 1;
        }
    }
}
