#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_70_rodata_4;
extern "C" void* getData__9gfArchiveF11ARCNodeTypeiUs(
    void*, int, int, unsigned short);

struct Base {
    unsigned char pad0[0x3c];
};

struct Stage : Base {
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
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
    SLOT(128) SLOT(129) SLOT(130) SLOT(131) SLOT(132) SLOT(133) SLOT(134) SLOT(135)
    SLOT(136)
#undef SLOT
    virtual void set(int, unsigned int);

    unsigned char pad40[0x160];
    void* archive;
    unsigned char pad1a4[0x34];
    unsigned char type;
    unsigned char mode;
    unsigned char pad1da[0xae];
    void* data;
    int a;
    int b;
};

extern "C" void fn_70_9F0(Stage* self) {
    if (self->a != 0 && self->b != 0) {
        unsigned int value =
            (unsigned int)(lbl_70_rodata_4 * randf__Fv());
        value = value > 0 ? value : 0;
        unsigned int index = value < 4 ? value : 4;

        switch (self->type) {
        case 1:
            index += 5;
            break;
        case 2:
            index += 10;
            break;
        case 3:
            index += 15;
            break;
        case 4:
            index += 20;
            break;
        }

        self->data = getData__9gfArchiveF11ARCNodeTypeiUs(
            self->archive, 2, 30, 0xfffe);

        self->set(0, index);
        self->set(1, index);
        self->set(2, index);
        self->set(3, index);
        self->set(4, index);
        self->set(5, index);
        self->set(6, index);
        self->set(7, index);

        switch (self->mode) {
        case 0:
        case 1:
            self->set(8, index);
            break;
        }
    }
}
