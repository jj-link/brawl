#pragma force_active on

#define V(n) virtual void v##n();
#define V0_9 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
#define V10_19 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
#define V20_29 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
#define V30_39 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
#define V40_49 V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
#define V50_59 V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
#define V60_69 V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
#define V70_79 V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
#define V80_89 V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)

struct Motion {
    V0_9
    virtual void setRate(float);
    V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
    virtual void update();
};

struct Posture {
    V0_9 V10_19 V20_29 V30_39
    virtual float getScale(int);
};

struct Ground {
    V0_9 V10_19 V20_29 V30_39 V40_49
    V50_59 V60_69 V70_79 V80_89
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98)
    virtual void setMode(int);
};

struct Work {
    V(0) V(1) V(2) V(3) V(4)
    virtual void setInt(int, unsigned int);
};

struct Owner {
    char pad[0x3c];
    V0_9 V10_19 V20_29 V30_39
    V(40) V(41) V(42)
    virtual void update();
};

#undef V0_9
#undef V10_19
#undef V20_29
#undef V30_39
#undef V40_49
#undef V50_59
#undef V60_69
#undef V70_79
#undef V80_89
#undef V

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
extern "C" float lbl_27_rodata_24C8;

extern "C" void fn_27_1871DC(void*, char* p) {
    char* modules = *(char**)(p + 0xd8);
    Motion* motion = *(Motion**)(modules + 0xc);
    Posture* posture = *(Posture**)(modules + 0x54);

    motion->setRate(lbl_27_rodata_24C8 * posture->getScale(0));
    (*(Motion**)(*(char**)(p + 0xd8) + 0xc))->update();
    (*(Owner**)(p + 8))->update();

    Ground* ground = *(Ground**)(*(char**)(p + 0xd8) + 8);
    int mode = 0;
    switch (getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        p, 0x5a98, 0)) {
    case 1:
        mode = 4;
        break;
    }

    ground->setMode(mode);
    (*(Work**)(*(char**)(p + 0xd8) + 0x64))->setInt(0x1b1, 0x20000000);
}
