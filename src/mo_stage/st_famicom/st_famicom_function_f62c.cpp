#pragma force_active on

extern "C" const float lbl_68_rodata_180;
extern "C" const float lbl_68_rodata_184;

#define V(n) virtual void vf##n();

struct GroundBase {
    unsigned char pad[0x3C];
};

class Ground : public GroundBase {
public:
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11)
    V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21)
    V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41)
    virtual int fn_68_2494();
    V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
    V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62)
    V(63) V(64) V(65) V(66) V(67)
    virtual void setMotionFrame(float, unsigned long);
    V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78)
    V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88)
    V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98)
    virtual void disableHit(unsigned long, unsigned long);
    virtual void disableAttack(unsigned long);
    V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110)
    V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119) V(120)
    virtual void fn_68_ECC4();
    V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129) V(130) V(131)
    V(132) V(133) V(134) V(135) V(136) V(137)
    virtual int fn_68_C9C4();
    virtual int fn_68_CA28();
    virtual int fn_68_CAF0();
    V(141) V(142) V(143)
    virtual void fn_68_ED60(int, int, int, float*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char m150;
    unsigned char pad151[0x15C - 0x151];
    float m15c;
    unsigned char pad160[0x16E - 0x160];
    unsigned char m16e;
    unsigned char pad16F[0x174 - 0x16F];
    unsigned char m174;
    unsigned char pad175[0x189 - 0x175];
    unsigned char m189;
    unsigned char pad18A[0x1AD - 0x18A];
    unsigned char m1ad;
};

extern "C" void fn_68_F62C(Ground* self) {
    if (self->m1ad == 1) {
        return;
    }
    if (self->fn_68_2494() == 0) {
        return;
    }
    if (self->fn_68_C9C4() == 0) {
        self->m150 = 0x11;
        return;
    }
    if (self->fn_68_CA28() == 0) {
        return;
    }
    if (self->fn_68_CAF0() == 0) {
        return;
    }
    switch (self->m174) {
    case 1:
        self->fn_68_ED60(1, 0, 0, &self->m15c);
        break;
    case 2:
        self->fn_68_ED60(5, 0, 0, &self->m15c);
        break;
    case 3:
        self->fn_68_ED60(9, 0, 0, &self->m15c);
        break;
    }
    self->setMotionFrame(lbl_68_rodata_180, 0);
    self->m15c = lbl_68_rodata_184;
    self->disableHit(0, 0);
    self->disableAttack(0);
    self->m189 = 0;
    self->m16e = 0;
    self->fn_68_ECC4();
    self->m150 = 0xc;
}
