#pragma force_active on
extern "C" const float lbl_57_rodata_260;

struct Vec3f {
    float x, y, z;
};

extern "C" void cmReqQuake__FiP5Vec3f(int, const Vec3f*);

struct Prefix {
    unsigned char pad0[0x3C];
};

#define SLOT(n) virtual void vf##n();

struct Object : Prefix {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26)
    virtual void setFlag(int);
    SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32)
    SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37)
    SLOT(38) SLOT(39) SLOT(40) SLOT(41) SLOT(42)
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72)
    SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77)
    SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82)
    SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92)
    SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97)
    SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102)
    SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112)
    SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117)
    SLOT(118) SLOT(119)
    virtual void setMotion(int, int, int, float*);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[0xB];
    unsigned char* command;
    unsigned char pad160[8];
    unsigned char mode;
    unsigned char pad169[3];
    float timer;
    float previousTimer;
};

#undef SLOT

extern "C" void fn_57_8D28(Object* self, float delta) {
    if (!self->command)
        return;

    self->timer -= delta;
    if (self->timer < lbl_57_rodata_260)
        self->timer = lbl_57_rodata_260;

    switch (self->state) {
    case 0:
        self->setMotion(3, 0, 1, 0);
        self->setFlag(0);
        self->state = 2;
    case 2:
        if (*self->command == 9) {
            self->setMotion(2, 0, 1, &self->timer);
            self->setFlag(1);
            self->state = 7;
        }
        break;
    case 7:
        if (*self->command == 10) {
            self->setMotion(1, 0, 1, &self->timer);
            self->previousTimer = self->timer;
            self->state = 8;
        }
        break;
    case 8:
        Vec3f position = {
            lbl_57_rodata_260,
            lbl_57_rodata_260,
            lbl_57_rodata_260
        };
        cmReqQuake__FiP5Vec3f(1, &position);
        break;
    }

    if (lbl_57_rodata_260 == self->timer) {
        switch (self->mode) {
        case 2:
            self->setMotion(0, 1, 1, 0);
            break;
        case 1:
            *self->command = 11;
            self->state = 0;
            break;
        }
    }
}
