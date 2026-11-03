#pragma force_active on

extern "C" const float lbl_68_rodata_148[];

#define V(n) virtual void vf##n();

struct GroundBase {
    unsigned char pad[0x3C];
};

struct GroundEntry {
    unsigned char _00[0xC];
    float f0C;
    float f10;
    float f14;
    unsigned char f18;
    unsigned char _19[0x20 - 0x19];
    float f20;
    unsigned char _24[0x28 - 0x24];
};

class Ground : public GroundBase {
public:
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    virtual int fn_68_2494();
    V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98)
    virtual void disableHit(unsigned long, unsigned long);
    virtual void disableAttack(unsigned long);
    V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120)
    virtual void fn_68_ECC4();
    V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137)
    virtual int fn_68_C9C4();
    V(139) V(140) V(141) V(142) V(143)
    virtual void fn_68_ED60(int, int, int, float*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char m150;
    unsigned char pad151[0x158 - 0x151];
    unsigned char m158;
    unsigned char pad159[0x15C - 0x159];
    float m15c;
    unsigned char pad160[0x168 - 0x160];
    float m168;
    unsigned char pad16C[0x16D - 0x16C];
    unsigned char m16d;
    unsigned char pad16E[0x174 - 0x16E];
    unsigned char m174;
    unsigned char m175;
    unsigned char pad176[0x178 - 0x176];
    GroundEntry* m178;
    unsigned char pad17C[0x1AD - 0x17C];
    unsigned char m1ad;
};

extern "C" void fn_68_FC1C(Ground* self) {
    const float* c = lbl_68_rodata_148;
    if (self->m1ad == 1) {
        return;
    }
    if (self->fn_68_2494() == 0) {
        return;
    }
    if (self->fn_68_C9C4() == 0) {
        switch (self->m158) {
        case 1:
        case 5:
        case 9:
            break;
        default:
            self->m150 = 0x11;
            return;
        }
    }
    switch (self->m174) {
    case 1:
        self->fn_68_ED60(2, 1, 0, &self->m15c);
        break;
    case 2:
        self->fn_68_ED60(6, 1, 0, &self->m15c);
        break;
    case 3:
        self->fn_68_ED60(10, 1, 0, &self->m15c);
        break;
    }
    self->disableHit(0, 0);
    self->disableAttack(0);
    self->fn_68_ECC4();
    self->m168 = c[17];
    self->m16d = 0;
    GroundEntry* e = self->m178 + self->m175;
    float v = e->f20;
    if (v >= c[0] && v <= c[3]) {
        if (v < c[11]) {
            e->f18 = 1;
            GroundEntry* e2 = self->m178 + self->m175;
            e2->f0C = c[0];
            e2->f10 = c[0];
            e2->f14 = c[0];
            self->m16d = 1;
        } else if (v > c[12]) {
            e->f18 = 0;
            GroundEntry* e3 = self->m178 + self->m175;
            e3->f0C = c[0];
            e3->f10 = c[1];
            e3->f14 = c[0];
            self->m16d = 1;
        }
    }
    self->m150 = 4;
}
