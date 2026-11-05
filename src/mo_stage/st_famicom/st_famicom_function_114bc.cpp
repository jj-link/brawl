#pragma force_active on
extern "C" const float lbl_68_rodata_198[];
#define V(n) virtual void vf##n();
struct Ground_base { char pad[0x3c]; };
struct GroundEntry {
    char pad00[0xc];
    float f0c, f10, f14;
    unsigned char f18;
    char pad19[7];
    float f20;
    char pad24[4];
};
class Ground : public Ground_base {
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
    virtual void fn_68_105A4();
    V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137)
    virtual int fn_68_C9C4();
    V(139) V(140) V(141) V(142) V(143)
    virtual void fn_68_10634(int, int, int, float*);
    unsigned char pad40[0x150 - 0x40];
    unsigned char m150;
    unsigned char pad151[0x15c - 0x151];
    float m15c;
    unsigned char pad160[0x168 - 0x160];
    float m168;
    unsigned char pad16c[1];
    unsigned char m16d;
    unsigned char pad16e[0x174 - 0x16e];
    unsigned char m174, m175;
    unsigned char pad176[2];
    GroundEntry* m178;
    unsigned char pad17c[0x189 - 0x17c];
    unsigned char m189;
    unsigned char pad18a[0x1ad - 0x18a];
    unsigned char m1ad;
    unsigned char pad1ae[0x1c0 - 0x1ae];
    unsigned char m1c0;
};
extern "C" void fn_68_114BC(Ground* self) {
    const float* c = lbl_68_rodata_198;
    if (self->m1ad == 1) return;
    if (self->fn_68_2494() == 0) return;
    if (self->fn_68_C9C4() == 0) {
        self->m150 = 0x11;
        return;
    }
    switch (self->m174) {
    case 1: self->fn_68_10634(2, 1, 0, &self->m15c); break;
    case 2: self->fn_68_10634(6, 1, 0, &self->m15c); break;
    case 3: self->fn_68_10634(10, 1, 0, &self->m15c); break;
    }
    self->m1c0 = 0;
    self->disableHit(0, 0);
    self->disableAttack(0);
    self->m189 = 0;
    self->fn_68_105A4();
    self->m168 = c[10];
    self->m16d = 0;
    GroundEntry* e = self->m178 + self->m175;
    float v = e->f20;
    if (v >= c[1] && v <= c[0]) {
        if (v < c[11]) {
            e->f18 = 1;
            GroundEntry* e2 = self->m178 + self->m175;
            e2->f0c = c[1];
            e2->f10 = c[1];
            e2->f14 = c[1];
            self->m16d = 1;
        } else if (v > c[12]) {
            e->f18 = 0;
            GroundEntry* e3 = self->m178 + self->m175;
            e3->f0c = c[1];
            e3->f10 = c[2];
            e3->f14 = c[1];
            self->m16d = 1;
        }
    }
    self->m150 = 4;
}