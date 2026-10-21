#pragma force_active on

extern "C" void update__9grGimmickFf(void*, float);

struct EarthBase {
    unsigned char pad[0x3C];
};

struct Earth : EarthBase {
#define SLOT(n) virtual void unused##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70)
    virtual void reset();
    SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83)
    SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91)
    SLOT(92) SLOT(93) SLOT(94) SLOT(95)
    SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103)
    SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111)
#undef SLOT

    virtual void update1(float);
    virtual void update2(float);
    virtual void update3(float);
    virtual void update4(float);
    virtual void update5(float);
    virtual void update6(float);

    unsigned char pad40[0x2C];
    unsigned char flags;
    unsigned char pad6D[0x5B];
    unsigned char active;
    unsigned char padC9[0x254];
    unsigned char pending;
};

extern "C" void fn_66_3C60(Earth* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->update1(deltaFrame);
        self->update3(deltaFrame);
        self->update2(deltaFrame);
        self->update5(deltaFrame);
        self->update4(deltaFrame);
        self->update6(deltaFrame);
        if (self->pending == 1) {
            self->reset();
            self->pending = 0;
            self->flags &= ~2;
        }
    }
}
