#pragma force_active on
extern "C" void update__9grGimmickFf(void*, float);

struct EarthBase {
    unsigned char padding[0x3C];
};

struct Earth : EarthBase {
#define D(n) virtual void d##n();
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)
    D(48) D(49) D(50) D(51) D(52) D(53) D(54) D(55)
    D(56) D(57) D(58) D(59) D(60) D(61) D(62) D(63)
    D(64) D(65) D(66) D(67) D(68) D(69) D(70)
#undef D
    virtual void noFloat();
#define E(n) virtual void e##n();
    E(72) E(73) E(74) E(75) E(76) E(77) E(78) E(79)
    E(80) E(81) E(82) E(83) E(84) E(85) E(86) E(87)
    E(88) E(89) E(90) E(91) E(92) E(93) E(94) E(95)
    E(96) E(97) E(98) E(99) E(100) E(101) E(102) E(103)
    E(104) E(105) E(106) E(107) E(108) E(109) E(110) E(111)
#undef E
    virtual void f1(float);
    virtual void f2(float);
    virtual void f3(float);
    virtual void f4(float);

    unsigned char pad[0x2C];
    unsigned char flag;
    unsigned char pad2[0x5B];
    unsigned char active;
};

extern "C" void fn_66_F220(Earth* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->f2(deltaFrame);
        self->f1(deltaFrame);
        self->f3(deltaFrame);
        self->f4(deltaFrame);
        self->flag = self->flag & ~2;
        self->noFloat();
    }
}
