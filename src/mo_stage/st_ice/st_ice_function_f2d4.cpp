#pragma force_active on
#define ICE_SLOT(n) virtual void reserved##n();

struct IceBase {
    unsigned char padding[0x3C];
};

struct Ice : IceBase {
    ICE_SLOT(0) ICE_SLOT(1) ICE_SLOT(2) ICE_SLOT(3) ICE_SLOT(4) ICE_SLOT(5) ICE_SLOT(6) ICE_SLOT(7)
    ICE_SLOT(8) ICE_SLOT(9) ICE_SLOT(10) ICE_SLOT(11) ICE_SLOT(12) ICE_SLOT(13) ICE_SLOT(14) ICE_SLOT(15)
    ICE_SLOT(16) ICE_SLOT(17) ICE_SLOT(18) ICE_SLOT(19) ICE_SLOT(20) ICE_SLOT(21) ICE_SLOT(22) ICE_SLOT(23)
    ICE_SLOT(24) ICE_SLOT(25) ICE_SLOT(26) ICE_SLOT(27) ICE_SLOT(28) ICE_SLOT(29) ICE_SLOT(30) ICE_SLOT(31)
    ICE_SLOT(32) ICE_SLOT(33) ICE_SLOT(34) ICE_SLOT(35) ICE_SLOT(36) ICE_SLOT(37) ICE_SLOT(38) ICE_SLOT(39)
    ICE_SLOT(40) ICE_SLOT(41) ICE_SLOT(42) ICE_SLOT(43) ICE_SLOT(44) ICE_SLOT(45) ICE_SLOT(46) ICE_SLOT(47)
    ICE_SLOT(48) ICE_SLOT(49) ICE_SLOT(50) ICE_SLOT(51) ICE_SLOT(52) ICE_SLOT(53) ICE_SLOT(54) ICE_SLOT(55)
    ICE_SLOT(56) ICE_SLOT(57) ICE_SLOT(58) ICE_SLOT(59) ICE_SLOT(60) ICE_SLOT(61) ICE_SLOT(62) ICE_SLOT(63)
    ICE_SLOT(64) ICE_SLOT(65) ICE_SLOT(66) ICE_SLOT(67) ICE_SLOT(68) ICE_SLOT(69) ICE_SLOT(70) ICE_SLOT(71)
    ICE_SLOT(72) ICE_SLOT(73) ICE_SLOT(74) ICE_SLOT(75) ICE_SLOT(76) ICE_SLOT(77) ICE_SLOT(78) ICE_SLOT(79)
    ICE_SLOT(80) ICE_SLOT(81) ICE_SLOT(82) ICE_SLOT(83) ICE_SLOT(84) ICE_SLOT(85) ICE_SLOT(86) ICE_SLOT(87)
    ICE_SLOT(88) ICE_SLOT(89) ICE_SLOT(90) ICE_SLOT(91) ICE_SLOT(92) ICE_SLOT(93) ICE_SLOT(94) ICE_SLOT(95)
    ICE_SLOT(96) ICE_SLOT(97) ICE_SLOT(98) ICE_SLOT(99) ICE_SLOT(100) ICE_SLOT(101) ICE_SLOT(102) ICE_SLOT(103)
    ICE_SLOT(104) ICE_SLOT(105) ICE_SLOT(106) ICE_SLOT(107) ICE_SLOT(108) ICE_SLOT(109) ICE_SLOT(110) ICE_SLOT(111)

    virtual void updateFirst(float);
    virtual void updateSecond(float);
    virtual void updateThird(float);

    unsigned char padding1[0x88];
    unsigned char active;
};

#undef ICE_SLOT

extern "C" void update__9grGimmickFf(void*, float);

extern "C" void fn_62_F2D4(Ice* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
        self->updateThird(deltaFrame);
    }
}
