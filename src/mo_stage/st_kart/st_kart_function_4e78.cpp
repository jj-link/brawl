#pragma force_active on
struct Ground_base { char pad[0x3c]; };
struct GData { unsigned int id; char pad[0x29]; unsigned char b2d; };
#define S(n) virtual void s##n();
class Ground : public Ground_base {
public:
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
    S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28) S(29)
    S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    S(40) S(41) S(42) S(43) S(44) S(45) S(46) S(47) S(48) S(49)
    S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59)
    S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69)
    S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87) S(88) S(89)
    S(90) S(91) S(92) S(93) S(94) S(95) S(96)
    virtual void disableHit(unsigned int, unsigned int);
    virtual void disableAttack(unsigned int);
    S(99) S(100) S(101) S(102) S(103) S(104) S(105) S(106) S(107) S(108)
    S(109) S(110) S(111) S(112) S(113) S(114) S(115)
    virtual void fn_1d8();
    virtual void fn_1dc();
    char pad1[0x118];
    GData* data;
    char pad2[1];
    unsigned char flag;
};

extern "C" void fn_49_4E78(Ground* self) {
    GData* d = self->data;
    switch (d->b2d) {
    case 1:
    case 2:
    case 3: {
        unsigned int id = d->id;
        if (id >= 0x1e && id <= 0x37) {
            self->fn_1dc();
            return;
        }
        if (id >= 0x5f || id <= 1) {
            self->fn_1d8();
            return;
        }
        if (self->flag == 1) {
            self->disableHit(0, 0);
            self->disableAttack(0);
            self->flag = 0;
        }
        return;
    }
    default:
        if (self->flag == 1) {
            self->disableHit(0, 0);
            self->disableAttack(0);
            self->flag = 0;
        }
    }
}
