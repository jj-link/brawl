#pragma force_active on

struct GroundData {
    char pad0[0x68];
    float f68;
};

struct State {
    unsigned char mode;
    char pad[3];
    float value4;
};

struct GroundBase {
    char pad0[0x3c];
};

struct Ground : GroundBase {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVisibility(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual GroundData* getStageData();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70)
    V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80)
    V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90)
    V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100)
    V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110)
    V(111) V(112) V(113) V(114) V(115)
    virtual void fn_81_545C(float);
#undef V

    char pad1[0x2c];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    char pad2[0xe3];
    unsigned char phase;
    char pad3[3];
    float timer;
    char pad4[4];
    float* params;
    char pad5[4];
    State* state;
    unsigned char choice;
};

extern "C" {
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
float randf__Fv();
extern const float lbl_81_rodata_C0;
extern const float lbl_81_rodata_C4;

void fn_81_52AC(Ground* self, float delta) {
    GroundData* d = self->getStageData();
    if (d) {
        self->timer -= delta;
        if (self->timer < lbl_81_rodata_C0)
            self->timer = lbl_81_rodata_C0;

        switch (self->phase) {
        case 0:
            self->setVisibility(0);
            setEnableCollisionStatus__6GroundFb(self, false);
            self->phase = 1;
            break;
        case 1:
            if (self->state->mode == 10)
                break;
            if (randf__Fv() < lbl_81_rodata_C4) {
                self->state->value4 = self->params[0] - d->f68;
                self->choice = 1;
            } else {
                self->state->value4 = self->params[3] + d->f68;
                self->choice = 0;
            }
            self->phase = 2;
            break;
        case 2:
            if (self->state->mode == 10) {
                self->phase = 0;
                break;
            }
            if (!self->enabled) {
                self->setVisibility(1);
                setEnableCollisionStatus__6GroundFb(self, true);
            }
            self->fn_81_545C(delta);
            break;
        }
    }
}
}
