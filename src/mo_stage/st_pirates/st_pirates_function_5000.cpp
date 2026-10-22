#pragma force_active on
struct B { unsigned char p[0x3C]; };
struct S : B {
#define V(n) virtual void v##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
V(60) V(61) V(62) V(63) V(64) V(65) V(66)
    virtual float f67(int);
    V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    virtual void f98(int);
    V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118)
    virtual void f119();
    virtual void f120();
    unsigned char p2[0x10C];
    int g;
    unsigned char p3[0x2C];
    unsigned char kind;
    unsigned char p4[7];
    unsigned char a;
    unsigned char b;
};
extern "C" const float lbl_52_rodata_E8[];
extern "C" void fn_52_5000(S* s) {
    const float* c = lbl_52_rodata_E8;
    if (s->a == 1) {
        float f = s->f67(0);
        unsigned r = 0;
        switch (s->kind) {
        case 18: break;
        case 16:
            if (f < c[1]) r = 1;
            else if (f < c[2]) r = 0;
            else r = 1;
            break;
        case 17:
            if (f < c[3]) r = 1; else r = 0;
            break;
        case 19:
            if (f < c[4]) r = 0; else r = 1;
            break;
        default: r = 1;
        }
        if (r == 1) { s->f120(); return; }
        if (s->b == 1) { s->f98(0); s->b = 0; }
    } else {
        s->f119();
        if (s->g != 0) s->a = 1;
    }
}
