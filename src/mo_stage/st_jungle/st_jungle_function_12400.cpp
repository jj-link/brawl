#pragma force_active on

typedef unsigned char u8;

struct Parameters {
    u8 padding[0x14];
    float value;
};

struct Base {
    u8 padding[0x3C];
};

struct Self : Base {
#define SLOT(n) virtual void unused##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6)
    SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13)
    SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20)
    SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26)
    virtual void set(int);
    SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32) SLOT(33)
    SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
#undef SLOT
    virtual Parameters* getParameters();

    u8 padding1[0x150 - 0x40];
    u8 state;
    u8 padding2[0x15C - 0x151];
    u8* data;
    u8 padding3[4];
    float value;
};

extern "C" void fn_51_12400(Self* self) {
    if (self->data != 0) {
        Parameters* params = self->getParameters();
        if (params != 0) {
            switch (self->state) {
            case 0:
                self->set(1);
                self->value = params->value;
                self->state = 1;
                break;
            case 1:
                break;
            case 9: {
                u8* p = self->data;
                if (*p == 4) {
                    *p = 0;
                    self->state = 0;
                }
                break;
            }
            }
        }
    }
}
