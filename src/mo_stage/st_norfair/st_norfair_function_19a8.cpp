#pragma force_active on

#define D(n) virtual void v##n();

struct Pad {
    char p[0x3c];
};

class Ground : public Pad {
public:
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28)
    virtual void v29(int);
    D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38)
    virtual void startup(void*, int, int);
    D(40)
    virtual void v41(void*);
    D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49) D(50) D(51)
    D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59) D(60) D(61)
    D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69) D(70) D(71)
    D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79) D(80) D(81)
    D(82) D(83) D(84) D(85) D(86) D(87) D(88) D(89) D(90) D(91)
    D(92) D(93) D(94) D(95) D(96) D(97) D(98) D(99) D(100) D(101)
    D(102) D(103) D(104) D(105) D(106) D(107) D(108) D(109) D(110) D(111)
    D(112) D(113)
    virtual void v114(void*);
    D(115) D(116)
    virtual void v117(void*);
    virtual void v118(void*);
};

#undef D

struct Stage {
    char pad0[0x9c];
    void* unk9C;
    char padA0[0x100];
    void* unk1A0;
};

extern "C" {
extern char lbl_54_data_148[];
extern char lbl_54_data_158[];
Ground* fn_54_C958(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
int fn_27_2249E0(Stage*);

void fn_54_19A8(Stage* arg0, int arg1) {
    Ground* g;
    switch (arg1) {
    case 6:
        g = fn_54_C958(5, lbl_54_data_148, lbl_54_data_158);
        break;
    default:
        g = 0;
        break;
    }
    if (g) {
        addGround__5StageFP6Ground(arg0, g);
        g->startup(arg0->unk1A0, 0, 0);
        g->v41(arg0->unk9C);
        g->v117((char*)arg0 + 0x7f4);
        g->v118((char*)arg0 + 0x79c);
        g->v114((char*)arg0 + 0x798);
        g->v29(fn_27_2249E0(arg0));
    }
}
}
