#pragma force_active on
extern const float lbl_57_rodata_0[];

#define SLOT(n) virtual void unused##n();

struct A {
    unsigned char pad[0x3c];
};

struct Base : A {
    virtual ~Base();
};

struct Stage : Base {
    unsigned char pad1[0xab];
    unsigned char flag;

    SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69) SLOT(70) SLOT(71)
    SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95)
    SLOT(96) SLOT(97) SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102) SLOT(103)
    SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111)
    SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118) SLOT(119)
    SLOT(120) SLOT(121) SLOT(122) SLOT(123) SLOT(124) SLOT(125) SLOT(126) SLOT(127)
    SLOT(128) SLOT(129)

    virtual void setCameraLimitRange(float, float, float, float);
    virtual void resetCameraLimitRange();

    SLOT(132) SLOT(133) SLOT(134) SLOT(135) SLOT(136) SLOT(137) SLOT(138) SLOT(139)
    SLOT(140) SLOT(141) SLOT(142) SLOT(143) SLOT(144) SLOT(145) SLOT(146) SLOT(147)
    SLOT(148)

    virtual void fn_57_153C(float);
    virtual void fn_57_1B98(float);
    virtual void fn_57_2D34(float);
    virtual void fn_57_3628(float);
};

#undef SLOT

extern "C" void fn_57_1458(Stage* self, float value) {
    const float* c = lbl_57_rodata_0;

    if (self->flag == 1)
        self->setCameraLimitRange(c[2], c[3], c[4], c[5]);
    else
        self->resetCameraLimitRange();

    self->fn_57_153C(value);
    self->fn_57_1B98(value);
    self->fn_57_2D34(value);
    self->fn_57_3628(value);
}
