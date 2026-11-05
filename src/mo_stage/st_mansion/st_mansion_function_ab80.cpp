#pragma force_active on

extern "C" const float lbl_47_rodata_E8;

struct Base {
    unsigned char pad[0x3c];
};

#define SLOT(n) virtual void v##n();

struct Object : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26)
    virtual void setVisible(bool);
    SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32)
    SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37)
    SLOT(38) SLOT(39) SLOT(40) SLOT(41) SLOT(42)
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65)
    virtual void setMotionFrame(float, unsigned long);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char pad158[4];
    unsigned char* selector;
    unsigned char* phase;
    unsigned char pad164[9];
    unsigned char state2;
};

#undef SLOT

extern "C" void fn_47_AB80(Object* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_47_rodata_E8)
        self->timer = lbl_47_rodata_E8;

    switch (self->state) {
    case 0:
        self->setVisible(false);
        self->state = 2;
        break;
    case 2:
        if (*self->selector == 2) {
            switch (self->state2) {
            case 3:
                self->setVisible(false);
                break;
            case 2:
                self->setVisible(true);
                break;
            }
            self->state = 4;
        }
        break;
    case 4:
        if (*self->selector == 3) {
            switch (self->state2) {
            case 3:
                self->setVisible(true);
                break;
            case 2:
                self->setVisible(false);
                break;
            }
        } else if (*self->selector == 2) {
            switch (self->state2) {
            case 2: {
                int v = *self->phase;
                if (v >= 4 || v < 1)
                    self->setMotionFrame(lbl_47_rodata_E8, 0);
                break;
            }
            }
        } else if (*self->selector != 4) {
            if (*self->selector == 0)
                self->state = 0;
        }
        break;
    }
}