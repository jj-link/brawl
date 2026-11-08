#pragma force_active on

struct Ground {
    char pad[0x3c];
#define V(n) virtual void v##n();
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    virtual void startup(void*, int, int);
    V(40)
    virtual void setNode(void*);
    V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117)
    virtual void setA(void*);
    virtual void setB(void*);
    virtual void setC(void*);
#undef V
};

struct Stage {
    char pad0[0x9c];
    void* at9c;
    char padA0[0x100];
    void* at1a0;
    char pad1A4[0x3c];
    char at1e0[0xb5];
    char at295[0x1b];
    char at2b0[1];
};

extern "C" {
extern char lbl_71_data_1C[];
extern char lbl_71_data_30[];
Ground* fn_71_5F88(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_71_77C(Stage* s) {
    Ground* g = fn_71_5F88(0, lbl_71_data_1C, lbl_71_data_30);
    if (g) {
        addGround__5StageFP6Ground(s, g);
        g->startup(s->at1a0, 0, 0);
        g->setNode(s->at9c);
        g->setA((char*)s + 0x1e0);
        g->setB((char*)s + 0x295);
        g->setC((char*)s + 0x2b0);
    }
}
}
