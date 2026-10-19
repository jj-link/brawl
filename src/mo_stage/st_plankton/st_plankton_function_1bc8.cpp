#pragma force_active on
struct Base {
    char pad[0x3C];
};

struct Entry {
    float value;
    char pad[0x18];
    unsigned char state;
    char tail[3];
};

struct Object : Base {
#define SLOT(n) virtual void unused##n();
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
    SLOT(136) SLOT(137) SLOT(138) SLOT(139) SLOT(140) SLOT(141) SLOT(142) SLOT(143)
    SLOT(144) SLOT(145) SLOT(146) SLOT(147)
#undef SLOT

    virtual void first(float);
    virtual void gap1();
    virtual void gap2();
    virtual void second(float);

    char gap[0x450];
    Entry entries[8];
};

extern "C" void fn_74_1BC8(Object* self) {
    for (unsigned int i = 0; i < 8; ++i) {
        Entry* entry = &self->entries[(unsigned char)i];
        if (entry->state == 1) {
            self->first(entry->value);
            self->second(entry->value);
            entry->state = 2;
        }
    }
}
