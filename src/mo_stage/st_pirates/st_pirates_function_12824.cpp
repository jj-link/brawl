#pragma force_active on
struct Base {
    unsigned char padding0[0x3C];
};

#define SLOT(n) virtual void slot##n();

struct Dispatch : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97)
    virtual void slot98(int);
    SLOT(99)
    virtual void slot100(int);
    SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118)
    virtual void slot119();
    virtual void slot120();
};

#undef SLOT

struct Object : Dispatch {
    unsigned char padding1[0x10C];
    int field14C;
    unsigned char padding2[0x14];
    unsigned char* ptr164;
    unsigned char padding3[0x31];
    unsigned char state199;
    unsigned char state19A;
    unsigned char state19B;
};

extern "C" void fn_52_12824(Object* self) {
    if (self->state19A == 1) {
        if (*self->ptr164 <= 1) {
            self->slot118();
        } else if (self->state19B == 1) {
            self->slot98(0);
            self->state19B = 0;
        }
        self->state199 = *self->ptr164;
    } else {
        self->slot117();
        if (self->field14C != 0) {
            self->state19A = 1;
        }
    }
}
