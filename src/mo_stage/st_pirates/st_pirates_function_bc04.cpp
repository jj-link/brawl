#pragma force_active on

extern float* g_soWorld;
extern "C" const float lbl_52_rodata_1B8[];

struct Prefix {
    unsigned char pad0[0x3C];
};

#define SLOT(n) virtual void vf##n();

struct Object : Prefix {
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28)
    virtual void setVisibility(unsigned long);
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    virtual void setMotionFrame(float, unsigned long);
    SLOT(69) SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78)
    SLOT(79) SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88)
    SLOT(89) SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98)
    SLOT(99) SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108)
    SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118)
    virtual void fn_52_C240(int, int, int, float*);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[7];
    float* ref158;
    unsigned char pad15C[4];
    unsigned char flag160;
    unsigned char counter161;
    unsigned char pad162[6];
    unsigned char* command;
    unsigned char saved16C;
    unsigned char flag16D;
    unsigned char pad16E[2];
    float timer;
    unsigned char flag174;
    unsigned char pad175[0xF];
    unsigned char flag184;
};

#undef SLOT

extern "C" void fn_52_BC04(Object* self, float delta) {
    const float* k = lbl_52_rodata_1B8;
    if (self->command != 0) {
        self->timer -= delta;
        if (self->timer < k[0]) {
            self->timer = k[0];
        }

        switch (self->state) {
        case 0:
            self->fn_52_C240(1, 0, 1, 0);
            self->setVisibility(0);
            g_soWorld[0] = k[1];
            g_soWorld[1] = k[1];
            self->flag174 = 0;
            self->state = 1;
            /* fallthrough */
        case 1:
            if (self->flag160 == 1) {
                unsigned int r30 = 1;
                int r29 = 1;
                switch (self->flag16D) {
                case 0: {
                    int c = self->counter161 - 1;
                    self->counter161 = c;
                    switch ((unsigned char)c) {
                    case 0:
                        self->state = 0;
                        break;
                    case 1:
                        if (*self->ref158 > k[2]) {
                            g_soWorld[0] = k[3];
                            g_soWorld[1] = k[3];
                            self->flag174 = 1;
                        } else {
                            g_soWorld[0] = k[1];
                            g_soWorld[1] = k[1];
                            self->flag174 = 0;
                        }
                        break;
                    }
                    break;
                }
                }
                if (*self->command != self->saved16C) {
                    switch (*self->command) {
                    case 6:
                        self->counter161 = 3;
                        r30 = 0;
                        self->setVisibility(1);
                        break;
                    }
                    if (r30 != 1) {
                        r29 = 0;
                    }
                    self->saved16C = *self->command;
                }
                if (r30 != 1) {
                    self->fn_52_C240(r30, r29, 1, &self->timer);
                    self->setMotionFrame(k[4] - *self->ref158, 0);
                    self->flag184 = 0;
                }
            } else {
                switch (self->counter161) {
                case 1:
                    if (*self->ref158 > k[2]) {
                        g_soWorld[0] = k[3];
                        g_soWorld[1] = k[3];
                        self->flag174 = 1;
                    } else {
                        g_soWorld[0] = k[1];
                        g_soWorld[1] = k[1];
                        self->flag174 = 0;
                    }
                    break;
                }
            }
            break;
        }
    }
}
