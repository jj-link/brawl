#pragma force_active on
extern "C" float lbl_63_rodata_C8;

#define V(n) virtual void v##n();

struct Pad {
    char pad[0x3c];
};

struct Entry {
    float timer;
    unsigned int other;
    unsigned char pad, state, count, flag;
};

struct D : Pad {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    virtual void fn(int);

    char rest[0x1c4];
    Entry entries[1];
};

#undef V

struct Arg {
    char pad[0x25];
    unsigned char index;
};

extern "C" void fn_63_8C60(D* self, const Arg* arg1) {
    int c = arg1->index;
    self->entries[c].state = 5;
    self->fn(c);

    Entry& q = self->entries[arg1->index];
    q.timer = lbl_63_rodata_C8;
    q.flag = 0;
    q.count = 0xf;
}
