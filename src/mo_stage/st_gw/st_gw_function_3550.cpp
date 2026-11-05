#pragma force_active on

struct GroundBase {
    unsigned char pad[0x3C];
};

struct GwStageParam {
    unsigned char pad[0x2C];
    float chance;
};

struct Ground : GroundBase {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVis(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual GwStageParam* getParam();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65)
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    V(108) V(109) V(110) V(111) V(112) V(113)
    virtual void setMotion(int, int, int, float*);
    V(115) V(116)
    virtual void fn_63_3924(float);
    virtual void fn_63_3980(float);
    V(119) V(120)
    virtual void fn_63_3920();
    virtual void fn_63_391C();
#undef V

    unsigned char pad40[0x24];
    float speed;
    unsigned char pad68[0xE8];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* trigger;
    unsigned char triggerValue;
    unsigned char pad15D[3];
    float previousFrame;
    float endFrame;
    unsigned char pad168[0xC];
    unsigned char flag174;
    unsigned char pad175[3];
    float value178;
    unsigned char pad17C[8];
    unsigned char* flagPtr;
    unsigned char pad188[4];
    unsigned char flag18C;
    unsigned char flag18D;
};

extern "C" {
void fn_63_2C98(Ground*, float);
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
float randf__Fv();
extern const float lbl_63_rodata_48;
extern const float lbl_63_rodata_4C;

void fn_63_3550(Ground* self, float delta) {
    fn_63_2C98(self, delta);
    GwStageParam* param = self->getParam();
    if (param != 0) {
        self->timer -= delta;
        if (self->timer < lbl_63_rodata_48)
            self->timer = lbl_63_rodata_48;

        switch (self->state) {
        case 0:
            self->setMotion(0, 0, 1, &self->endFrame);
            self->setMotionFrame(self->endFrame, 0);
            self->setVis(0);
            setEnableCollisionStatus__6GroundFb(self, false);
            self->fn_63_391C();
            if (self->triggerValue != 0)
                self->flag18C = 0;
            self->flag174 = 0;
            self->value178 = lbl_63_rodata_48;
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == self->triggerValue) {
                if (self->flag18C == 1) {
                    self->setMotion(1, 0, 1, 0);
                    self->flag18C = 0;
                    self->previousFrame = lbl_63_rodata_48;
                } else {
                    self->setMotion(0, 1, 1, &self->endFrame);
                    self->setMotionFrame(self->endFrame, 0);
                    self->previousFrame = self->endFrame;
                    self->speed *= lbl_63_rodata_4C;
                }
                self->fn_63_3920();
                if (randf__Fv() < param->chance)
                    self->flag18D = 1;
                self->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            if (*self->trigger != self->triggerValue) {
                if (self->flagPtr != 0)
                    *self->flagPtr += 1;
                self->setMotion(0, 0, 1, &self->endFrame);
                if (self->speed < lbl_63_rodata_48)
                    self->speed *= lbl_63_rodata_4C;
                self->fn_63_3980(delta);
                self->flag18D = 0;
                self->state = 4;
            } else {
                if (self->getMotionFrame(0) > self->previousFrame) {
                    self->setMotion(1, 0, 0, 0);
                } else {
                    self->previousFrame = self->getMotionFrame(0);
                }
                self->setVis(1);
                setEnableCollisionStatus__6GroundFb(self, true);
                self->fn_63_3924(delta);
            }
            break;
        case 4:
            if (self->getMotionFrame(0) >= self->endFrame)
                self->state = 0;
            break;
        }
    }
}
}