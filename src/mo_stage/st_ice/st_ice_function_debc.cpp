#pragma force_active on

extern "C" const float lbl_62_rodata_178;
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

struct Base {
    unsigned char pad0[0x3c];
};

#define SLOT(n) virtual void v##n();

struct Object : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26)
    virtual void fn74(int);
    SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32)
    SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37)
    SLOT(38) SLOT(39) SLOT(40) SLOT(41) SLOT(42)
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72)
    SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77)
    SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82)
    SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92)
    SLOT(93) SLOT(94) SLOT(95)
    virtual void fn188(int, int);
    virtual void fn18c(int, int);
    virtual void fn190(int);
    SLOT(99) SLOT(100) SLOT(101) SLOT(102) SLOT(103)
    SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108)
    SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    SLOT(114) SLOT(115)
    virtual void fn1d8();

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[3];
    float timer1;
    unsigned char pad158[4];
    void* ptr_0x15c;
    unsigned char pad160[4];
    float timer2;
    unsigned char pad168[0x10];
    unsigned char* ptr_0x178;
    unsigned char byte_0x17c;
    unsigned char pad17d[7];
    float float_0x184;
    float timer3;
    unsigned char pad18c;
    unsigned char byte_0x18d;
    unsigned char pad18e[0x16];
};

#undef SLOT

extern "C" void fn_62_DEBC(Object* self, float delta) {
    float t1 = self->timer1 - delta;
    self->timer1 = t1;
    if (t1 < lbl_62_rodata_178)
        self->timer1 = lbl_62_rodata_178;

    float t3 = self->timer3 - delta;
    self->timer3 = t3;
    if (t3 < lbl_62_rodata_178)
        self->timer3 = lbl_62_rodata_178;

    switch (self->state) {
    case 0:
        self->fn74(0);
        self->fn18c(0, 0);
        self->fn190(0);
        self->byte_0x18d = 0;
        self->state = 1;
        break;

    case 1: {
        unsigned char cmd = *self->ptr_0x178;
        if (cmd == 14)
            break;
        if ((cmd == 8 && self->byte_0x17c == 0) ||
            (cmd == 9 && self->byte_0x17c == 1) ||
            (cmd == 10 && self->byte_0x17c == 2)) {
            self->fn74(1);
            self->fn188(0, 0);
        }
        self->state = 7;
        break;
    }

    case 7: {
        unsigned char cmd = *self->ptr_0x178;
        if (cmd == 11) {
            self->float_0x184 = lbl_62_rodata_178;
            self->fn18c(0, 0);
            if (self->byte_0x17c == 2) {
                self->fn1d8();
                playSE__14snd3DGeneratorF5SndIDiii((char*)self + 0x1a4, 0x1c8a, 0, 0, -1);
            }
            self->state = 0x13;
        } else if (cmd == 14) {
            self->state = 0;
        } else if ((cmd == 8 && self->byte_0x17c == 0) ||
                   (cmd == 9 && self->byte_0x17c == 1) ||
                   (cmd == 10 && self->byte_0x17c == 2)) {
            self->fn74(1);
            self->fn188(0, 0);
        } else {
            self->fn74(0);
            self->fn18c(0, 0);
        }
        break;
    }

    case 19:
        if (self->timer2 < *(float*)((char*)self->ptr_0x15c + 0x10)) {
            *self->ptr_0x178 = 14;
            self->fn74(0);
            if (self->byte_0x17c == 2) {
                self->fn190(0);
                self->byte_0x18d = 0;
            }
            self->state = 0;
        }
        break;
    }
}