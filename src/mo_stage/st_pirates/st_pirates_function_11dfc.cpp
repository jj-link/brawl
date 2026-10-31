#pragma force_active on

extern "C" {
extern const float lbl_52_rodata_310;
extern const float lbl_52_rodata_314;
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void stopSE__14snd3DGeneratorFll(void*, long, long);
}

struct PB {
    unsigned char pad[0x3C];
};

#define V(n) virtual void vf##n();

struct PO : PB {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVis(int);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual int active();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65) V(66)
    virtual float getFrame(int);
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    V(108) V(109) V(110) V(111) V(112) V(113) V(114)
    virtual void setMotion(int, int, int, float*);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char pad158[8];
    unsigned char* trigger;
    unsigned char pad164[4];
    float previous;
    float end;
    unsigned char sound[8];
    int handle;
};

#undef V

extern "C" void fn_52_11DFC(PO* self, float delta) {
    if (!self->active())
        return;

    self->timer -= delta;
    if (self->timer < lbl_52_rodata_310)
        self->timer = lbl_52_rodata_310;

    switch (self->state) {
    case 0:
        self->setMotion(3, 0, 1, 0);
        self->setVis(0);
        self->state = 1;
        break;
    case 1:
        if (*self->trigger == 6) {
            self->setMotion(0, 0, 1, &self->end);
            self->setVis(1);
            self->handle = playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b9e, 0, (int)self->end, -1);
            self->state = 3;
        }
        break;
    case 3:
        if (self->getFrame(0) >= self->end) {
            self->setMotion(1, 0, 1, &self->end);
            self->state = 6;
        }
        break;
    case 6:
        if (self->getFrame(0) >= self->end) {
            self->setMotion(2, 0, 1, &self->end);
            if (self->handle != -1)
                stopSE__14snd3DGeneratorFll(self->sound, self->handle, (int)self->end);
            self->handle = -1;
            self->timer = lbl_52_rodata_314;
            self->state = 7;
        }
        break;
    case 7:
        if (lbl_52_rodata_310 == self->timer) {
            self->setMotion(0, 0, 1, &self->end);
            self->setVis(1);
            self->handle = playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b9e, 0, (int)self->end, -1);
            self->state = 9;
        }
        break;
    case 9:
        if (self->getFrame(0) >= self->end) {
            self->setMotion(1, 1, 1, &self->end);
            self->state = 4;
            self->previous = lbl_52_rodata_310;
        }
        break;
    case 4:
        if (*self->trigger != 6 && self->getFrame(0) < self->previous) {
            self->setMotion(2, 0, 1, &self->end);
            if (self->handle != -1)
                stopSE__14snd3DGeneratorFll(self->sound, self->handle, (int)self->end);
            self->handle = -1;
            self->state = 10;
        } else {
            self->previous = self->getFrame(0);
        }
        break;
    case 10:
        if (self->getFrame(0) >= self->end)
            self->state = 0;
        break;
    }
}
