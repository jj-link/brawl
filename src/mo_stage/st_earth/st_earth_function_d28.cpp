#pragma force_active on
#define SLOT(n) virtual void v##n();

extern "C" {
extern char lbl_66_data_110[];
extern char lbl_66_data_120[];
struct Ground;
Ground* fn_66_F0C8(int, const char*, const char*);
void addGround__5StageFP6Ground(void*, Ground*);
}

struct GroundBase {
    char pad[0x3c];
};

struct Ground : GroundBase {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36)
    virtual void init(int, int, int);
    SLOT(38)
    virtual void setData(int);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116)
    virtual void f119(int);
};

#undef SLOT

struct Stage {
    char pad0[0x9c];
    int f9c;
    char pad1[0x1a0 - 0xa0];
    int f1a0;
    char pad2[0x278 - 0x1a4];
    int f278;
};

extern "C" void fn_66_D28(Stage* stage, int arg1) {
    Ground* g = fn_66_F0C8(5, lbl_66_data_110, lbl_66_data_120);
    if (g != 0) {
        addGround__5StageFP6Ground(stage, g);
        g->init(stage->f1a0, 0, 0);
        g->setData(stage->f9c);
        g->f119(stage->f278 + arg1 * 0x58);
    }
}
