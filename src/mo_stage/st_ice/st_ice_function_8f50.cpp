#pragma force_active on

extern "C" void update__9grGimmickFf(void*, float);
extern "C" const float lbl_62_rodata_F8;

struct Base {
    unsigned char pad[0x3C];
};

#define SLOT(n) virtual void reserved##n();

struct Ground : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70)
    virtual void updateG3dProcCalcWorld();
    SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83)
    SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91)
    SLOT(92) SLOT(93) SLOT(94) SLOT(95)
    SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103)
    SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111)
    virtual void call1C8(float);
    virtual void call1CC(float);
    virtual void call1D0(float);
    virtual void call1D4(float);
#undef SLOT

    unsigned char pad40[0x2C];
    unsigned char unk6C;
    unsigned char pad6D[0x5B];
    unsigned char unkC8;
    unsigned char padC9[0x8B];
    float unk154;
    float pad158;
    float unk15C;
};

extern "C" void fn_62_8F50(Ground* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    self->unk154 -= deltaFrame;
    if (self->unk154 < lbl_62_rodata_F8) {
        self->unk154 = lbl_62_rodata_F8;
    }
    self->unk15C -= deltaFrame;
    if (self->unk15C < lbl_62_rodata_F8) {
        self->unk15C = lbl_62_rodata_F8;
    }
    if (self->unkC8) {
        self->call1C8(deltaFrame);
        self->call1CC(deltaFrame);
        self->call1D0(deltaFrame);
        self->call1D4(deltaFrame);
        self->unk6C &= ~2;
        self->updateG3dProcCalcWorld();
    }
}
