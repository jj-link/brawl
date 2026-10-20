#pragma force_active on

extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" void* getJoint__11grCollisionFUs(void* collision, unsigned short index);

#define V(n) virtual void f##n(float);

struct Pre {
    char pad[0x3c];
};

struct Gimmick : Pre {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111)
    virtual void updateA(float);
    virtual void updateB(float);
    virtual void updateC(float);
};

struct FzeroGimmick : Gimmick {
    void updateA(float);
    void updateB(float);
    void updateC(float);

    char pad1[0x4c - 0x40];
    void* collision;       // 0x4c
    char pad2[0xc8 - 0x50];
    unsigned char flag_c8; // 0xc8
    char pad3[0x15c - 0xc9];
    unsigned char b_15c;   // 0x15c
    char pad4[0x178 - 0x15d];
    int x_178;             // 0x178
};

extern "C" void fn_61_6490(FzeroGimmick* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->flag_c8 != 0) {
        if (self->b_15c == 7) {
            if (self->x_178 == 0 && self->collision != 0) {
                self->x_178 = (int)getJoint__11grCollisionFUs(self->collision, 0);
            }
            self->updateB(deltaFrame);
        } else {
            self->updateA(deltaFrame);
        }
        self->updateC(deltaFrame);
    }
}
