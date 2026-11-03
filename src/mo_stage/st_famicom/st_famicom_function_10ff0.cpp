#pragma force_active on

extern "C" const float lbl_68_rodata_198[];
extern "C" float randf__Fv();

struct Parameters {
    unsigned char pad00[0x30];
    float speed;
    float value34;
    unsigned char pad38[0x40 - 0x38];
    float scale40;
    float scale44;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Pair {
    Vec3f a;
    Vec3f b;
};

struct GroundEntry {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    unsigned char f18;
    unsigned char pad19[0x28 - 0x19];
};

struct GroundBase {
    unsigned char pad[0x3C];
};

#define V(n) virtual void vf##n();

class Ground : public GroundBase {
public:
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    virtual Parameters* fn_68_2494();
    V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139)
    V(140) V(141) V(142) V(143)
    virtual void fn_68_10634(int, int, int, float*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char m150;
    unsigned char pad151[0x15C - 0x151];
    float m15c;
    unsigned char pad160[0x164 - 0x160];
    float m164;
    float m168;
    unsigned char m16c;
    unsigned char pad16D[0x174 - 0x16D];
    unsigned char m174;
    unsigned char m175;
    unsigned char pad176[0x178 - 0x176];
    GroundEntry* m178;
    Pair* m17c;
};

extern "C" void fn_68_10FF0(Ground* self) {
    const float* c = lbl_68_rodata_198;
    Parameters* p = self->fn_68_2494();
    if (p == 0) {
        return;
    }

    switch (self->m174) {
    case 1:
        self->m164 = p->speed;
        break;
    case 2:
        self->m164 = p->speed * p->scale40;
        break;
    case 3:
        self->m164 = p->speed * p->scale44;
        break;
    default:
        self->m164 = c[1];
        break;
    }
    self->m168 = p->value34;

    if (randf__Fv() > c[11]) {
        Pair* pr = self->m17c;
        GroundEntry* e = self->m178 + self->m175;
        e->f00 = pr->a.x;
        e->f04 = pr->a.y;
        e->f08 = pr->a.z;
        GroundEntry* e2 = self->m178 + self->m175;
        e2->f04 -= c[15];
        GroundEntry* e3 = self->m178 + self->m175;
        e3->f08 -= c[5];
        GroundEntry* e4 = self->m178 + self->m175;
        e4->f18 = 1;
        GroundEntry* e5 = self->m178 + self->m175;
        e5->f0C = c[1];
        e5->f10 = c[1];
        e5->f14 = c[1];
    } else {
        Pair* pr = self->m17c;
        GroundEntry* e = self->m178 + self->m175;
        e->f00 = pr->b.x;
        e->f04 = pr->b.y;
        e->f08 = pr->b.z;
        GroundEntry* e2 = self->m178 + self->m175;
        e2->f04 -= c[15];
        GroundEntry* e3 = self->m178 + self->m175;
        e3->f08 -= c[5];
        GroundEntry* e4 = self->m178 + self->m175;
        e4->f18 = 0;
        GroundEntry* e5 = self->m178 + self->m175;
        e5->f0C = c[1];
        e5->f10 = c[2];
        e5->f14 = c[1];
    }

    switch (self->m174) {
    case 1:
        self->fn_68_10634(2, 1, 0, &self->m15c);
        break;
    case 2:
        self->fn_68_10634(6, 1, 0, &self->m15c);
        break;
    case 3:
        self->fn_68_10634(10, 1, 0, &self->m15c);
        break;
    }
    self->m16c = 1;
    self->m150 = 4;
}
