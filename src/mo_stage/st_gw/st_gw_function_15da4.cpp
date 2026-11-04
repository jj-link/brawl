#pragma force_active on

struct GroundBase {
    unsigned char pad[0x3C];
};

struct Ground : GroundBase {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVis(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual int checkStatus();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65) V(66)
    virtual float getMotionFrame(unsigned long);
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    V(108) V(109) V(110) V(111) V(112) V(113)
    virtual void setMotion(int, int, int, float*);
#undef V

    unsigned char pad40[0x24];
    float value64;
    unsigned char pad68[0xE8];
    unsigned char state;
    unsigned char pad151[3];
    float timer154;
    unsigned char* trigger;
    unsigned char triggerValue;
    unsigned char pad15D[3];
    float timer160;
    float value164;
    unsigned char pad168[0xC];
    unsigned char* flagPtr;
};

extern "C" {
void fn_63_2C98(Ground*, float);
extern const float lbl_63_rodata_208;
extern const float lbl_63_rodata_20C;
}

extern "C" void fn_63_15DA4(Ground* self, float delta) {
    fn_63_2C98(self, delta);
    if (self->checkStatus()) {
        self->timer154 -= delta;
        if (self->timer154 < lbl_63_rodata_208)
            self->timer154 = lbl_63_rodata_208;
        self->timer160 -= delta;
        if (self->timer160 < lbl_63_rodata_208)
            self->timer160 = lbl_63_rodata_208;

        switch (self->state) {
        case 0:
            self->setMotion(2, 0, 1, 0);
            self->setVis(0);
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == self->triggerValue)
                self->state = 3;
            break;
        case 3:
            if (*self->trigger != self->triggerValue) {
                self->state = 0;
                break;
            }
            if (*self->flagPtr == 0xC) {
                self->setMotion(0, 0, 1, &self->timer160);
                self->setVis(1);
                self->state = 6;
            }
            break;
        case 6:
            if (*self->trigger != self->triggerValue) {
                self->setMotion(1, 0, 0, &self->value164);
                if (self->value64 < lbl_63_rodata_208)
                    self->value64 *= lbl_63_rodata_20C;
                self->state = 4;
            } else if (lbl_63_rodata_208 == self->timer160) {
                self->setMotion(2, 0, 1, 0);
                self->setVis(0);
                *self->flagPtr = 0xB;
                self->state = 3;
            }
            break;
        case 4:
            if (self->getMotionFrame(0) >= self->value164)
                self->state = 0;
            break;
        }
    }
}
