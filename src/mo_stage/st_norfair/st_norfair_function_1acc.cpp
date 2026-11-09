#pragma force_active on

#define D(n) virtual void v##n();

struct Pad {
    char p[0x3c];
};

class Ground : public Pad {
public:
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38)
    virtual void v39(int, int, int);
    D(40)
    virtual void v41(int);
    D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49) D(50) D(51)
    D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59) D(60) D(61)
    D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69) D(70) D(71)
    D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79) D(80) D(81)
    D(82) D(83) D(84) D(85) D(86) D(87) D(88) D(89) D(90) D(91)
    D(92) D(93) D(94) D(95) D(96) D(97) D(98) D(99) D(100) D(101)
    D(102) D(103) D(104) D(105) D(106) D(107) D(108) D(109) D(110) D(111)
    D(112) D(113)
    virtual void v114(void*);
    D(115) D(116) D(117) D(118) D(119) D(120) D(121) D(122)
    virtual void v123();
    virtual void v124();
    virtual void v125(void*);
};

#undef D

struct Stage {
    char pad0[0x9c];
    int f9c;
    char padA0[0x1a0 - 0xa0];
    int f1a0;
    char pad1a4[0x774 - 0x1a4];
    char f774[0x24];
    char f798[4];
};

extern "C" {
extern char lbl_54_data_0[];
Ground* fn_54_CF40(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_54_1ACC(Stage* self, int kind) {
    Ground* ground;
    unsigned int flag;
    char* data = lbl_54_data_0;

    switch (kind) {
    case 7:
        ground = fn_54_CF40(6, data + 0x16c, data + 0x180);
        flag = 1;
        break;
    case 8:
        ground = fn_54_CF40(7, data + 0x190, data + 0x1a0);
        flag = 0;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(self, ground);
        ground->v39(self->f1a0, 0, 0);
        ground->v41(self->f9c);
        ground->v114(self->f798);
        ground->v125(self->f774);
        if (flag == 1) {
            ground->v124();
        } else {
            ground->v123();
        }
    }
}
}
