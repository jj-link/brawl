#pragma force_active on
struct Stage {
    char pad0[0x9C];
    void* unk9C;
    char padA0[0x1C];
    void* unkBC;
    char padC0[0xE0];
    void* unk1A0;
    char pad1A4[0x34];
    char unk1D8[8];
    char unk1E0[4];
    char unk1E4[1];
};

#define D(n) virtual void v##n();

struct Ground {
    char pad[0x3C];
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32) D(33) D(34) D(35) D(36)
    virtual void startup(void*, int, int);
    D(38)
    virtual void setValue(void*);
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)
    D(48) D(49) D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59)
    D(60) D(61) D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69)
    D(70) D(71) D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79)
    D(80) D(81) D(82) D(83) D(84) D(85) D(86) D(87) D(88) D(89)
    D(90) D(91) D(92) D(93) D(94) D(95) D(96) D(97) D(98) D(99)
    D(100) D(101) D(102) D(103) D(104) D(105) D(106) D(107) D(108) D(109)
    D(110) D(111) D(112) D(113) D(114)
    virtual void v115(void*);
    virtual void v116(void*);
    virtual void v117(void*);
    virtual void v118(int);
};

#undef D

extern "C" {
Ground* fn_61_23DC(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
extern char lbl_61_data_194[];
extern char lbl_61_data_1A8[];
}

extern "C" void fn_61_C2C(Stage* arg0, int arg1) {
    Ground* ground;

    switch (arg1) {
    case 0xA:
        ground = fn_61_23DC(5, lbl_61_data_194, lbl_61_data_1A8);
        break;
    default:
        ground = 0;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(arg0, ground);
        ground->startup(arg0->unk1A0, 0, 0);
        ground->setValue(arg0->unk9C);
        ground->v115(&arg0->unk1E0);
        ground->v116(&arg0->unk1D8);
        ground->v117(&arg0->unk1E4);
        ground->v118((int)arg0->unkBC);
    }
}
