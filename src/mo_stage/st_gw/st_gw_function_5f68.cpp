#pragma force_active on
struct Object_vptr_0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned char* slot3(unsigned char);
};
struct Ground_base { char pad[0x3c]; };
struct Ground : Ground_base {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVisibility(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    virtual int checkStatus();
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
#undef V
    char pad40[0x24];
    float speed;
    char pad68[0xe8];
    unsigned char state;
    char pad151[3];
    float timer;
    unsigned char* trigger;
    unsigned char triggerValue;
    char pad15d[3];
    float previousFrame;
    float endFrame;
    char pad168[0x10];
    unsigned char* index;
    unsigned char* flag;
    Object_vptr_0* object;
    unsigned long offset;
};
extern "C" {
extern const float lbl_63_rodata_98;
extern const float lbl_63_rodata_9C;
void fn_63_5F68(Ground* self, float delta) {
    if (self->object && self->checkStatus()) {
        self->timer -= delta;
        if (self->timer < lbl_63_rodata_98)
            self->timer = lbl_63_rodata_98;
        switch (self->state) {
        case 0:
            self->setMotion(0, 0, 1, &self->endFrame);
            self->setMotionFrame(self->endFrame, 0);
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == self->triggerValue) {
                self->setMotion(0, 1, 1, &self->endFrame);
                self->setMotionFrame(self->endFrame, 0);
                self->previousFrame = self->endFrame;
                if (self->speed > lbl_63_rodata_98)
                    self->speed *= lbl_63_rodata_9C;
                self->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            if (*self->trigger != self->triggerValue) {
                self->setMotion(0, 0, 1, &self->endFrame);
                if (self->speed < lbl_63_rodata_98)
                    self->speed *= lbl_63_rodata_9C;
                self->state = 4;
            } else {
                if (self->getMotionFrame(0) > self->previousFrame)
                    self->setMotion(1, 0, 0, 0);
                else
                    self->previousFrame = self->getMotionFrame(0);
                switch (*self->flag) {
                case 1: {
                    unsigned char* p = self->object->slot3(*self->index);
                    if (p && p[self->offset] == 1)
                        self->setVisibility(1);
                    break;
                }
                case 0:
                    self->setVisibility(0);
                    break;
                }
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