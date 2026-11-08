#pragma force_active on
typedef unsigned char u8;
typedef float f32;

struct Vec3f {
    f32 x, y, z;
};

struct Ground_base {
    char pad[0x3c];
};

#define S(n) virtual void s##n() = 0;

class Ground : public Ground_base {
public:
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9) S(10) S(11) S(12) S(13) S(14) S(15)
    S(16) S(17) S(18) S(19) S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28) S(29) S(30) S(31)
    S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39) S(40) S(41) S(42) S(43) S(44) S(45) S(46) S(47)
    S(48) S(49) S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59) S(60) S(61) S(62) S(63)
    S(64) S(65) S(66) S(67) S(68) S(69) S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87) S(88) S(89) S(90) S(91) S(92) S(93) S(94) S(95)
    S(96) S(97) S(98) S(99) S(100) S(101) S(102) S(103) S(104) S(105) S(106) S(107) S(108) S(109) S(110) S(111)
    S(112) S(113) S(114) S(115)
    virtual void s116(f32, f32, f32) = 0;
    S(117)
    virtual u8 s118() = 0;
    S(119) S(120) S(121) S(122) S(123) S(124) S(125) S(126) S(127)
    virtual void s128(Vec3f*) = 0;
};

class Stage_base {
public:
    char pad[0x3c];
};

class Stage : public Stage_base {
public:
    Ground* getGround(int index);
};

#define PAIR_BLOCK(ia, ib)                                   \
    {                                                        \
        Ground* b;                                           \
        Ground* a = self->getGround(ia);                     \
        b = self->getGround(ib);                             \
        if (a != 0 && b != 0) {                              \
            switch (a->s118()) {                             \
            case 0:                                          \
                a->s119();                                   \
                b->s117();                                   \
                break;                                       \
            case 4:                                          \
                a->s120();                                   \
                b->s118();                                   \
                break;                                       \
            }                                                \
        }                                                    \
    }

extern "C" void fn_67_14B0(Stage* self) {
    PAIR_BLOCK(2, 0x23)
    PAIR_BLOCK(3, 0x24)
    PAIR_BLOCK(4, 0x25)
    PAIR_BLOCK(5, 0x26)
    PAIR_BLOCK(6, 0x27)
    PAIR_BLOCK(7, 0x28)
    PAIR_BLOCK(8, 0x29)
    PAIR_BLOCK(9, 0x2A)
    {
        Ground* a = self->getGround(0xA);
        Ground* b = self->getGround(0x2B);
        if (a != 0 && b != 0) {
            switch (a->s118()) {
            case 0:
                a->s119();
                b->s117();
                break;
            case 4: {
                Vec3f p;
                a->s128(&p);
                b->s116(p.x, p.y, p.z);
                a->s120();
                b->s118();
                break;
            }
            }
        }
    }
}
