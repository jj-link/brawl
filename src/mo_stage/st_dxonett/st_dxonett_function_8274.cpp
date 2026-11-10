#pragma force_active on

struct Base {
    unsigned char pad[0x3C];
};

#define V(n) virtual void vf##n();

struct Obj : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVis(unsigned long);
    V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35)
    V(36) V(37) V(38)
    virtual bool active();
    V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56)
    V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64)
    virtual float getFrame(unsigned long);
    V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73)
    V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
    V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91)
    V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100)
    V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108)
    V(109) V(110) V(111)
    virtual void setMotion(int, int, bool, float*);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char pad158[4];
    unsigned char* trigger2;
    unsigned char pad160[4];
    unsigned char* trigger;
    unsigned char output2;
    unsigned char output3;
    unsigned char pad16A[2];
    float value;
};

#undef V

extern "C" {
extern const float lbl_78_rodata_E8[];
void setEnableCollisionStatus__6GroundFb(Obj*, bool);

void fn_78_8274(Obj* self, float delta) {
    const float* c = lbl_78_rodata_E8;

    if (self->active() == 0)
        return;

    switch (self->state) {
    case 0:
        self->setMotion(5, 0, true, 0);
        setEnableCollisionStatus__6GroundFb(self, true);
        self->setVis(1);
        self->state = 1;
    case 1:
        if (*self->trigger == 1) {
            switch (*self->trigger2) {
            case 3:
                self->setMotion(0, 0, true, &self->value);
                self->state = 2;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        if (self->getFrame(0) > c[1])
            setEnableCollisionStatus__6GroundFb(self, false);
        if (self->getFrame(0) >= self->value) {
            *self->trigger = 0;
            self->state = 7;
        }
        break;
    case 7:
        if (*self->trigger2 == 0x64) {
            self->setMotion(5, 0, true, 0);
            self->output2 = 0;
            self->output3 = 1;
            self->timer = c[3];
            self->state = 8;
        }
        break;
    case 8: {
        int t = self->output3 - 1;
        self->output3 = t;
        if (self->output2 == 0) {
            if ((signed char)(unsigned char)t < 0) {
                self->setVis(1);
                self->output2 = 1;
                self->output3 = 1;
            }
        } else if ((signed char)(unsigned char)t < 0) {
            self->setVis(0);
            self->output2 = 0;
            self->output3 = 1;
        }
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];
        if (c[0] == self->timer)
            self->state = 0;
        break;
    }
    }
}
}
