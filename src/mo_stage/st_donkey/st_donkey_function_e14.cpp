#pragma force_active on
struct GroundPrefix {
    char pad_0000[0x3c];
};

struct Ground : GroundPrefix {
#define SLOT(n) virtual void slot##n();
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38)
    virtual void init(void*, int, int);
    SLOT(40)
    virtual void setData(void*);
    SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65)
    SLOT(66) SLOT(67) SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72) SLOT(73)
    SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79) SLOT(80) SLOT(81)
    SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97)
    SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105)
    SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    SLOT(114) SLOT(115) SLOT(116)
    virtual void setPos117(void*);
    virtual void setPos118(void*);
    virtual void setIndex(int);
#undef SLOT
};

struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
};

extern "C" {
extern char lbl_50_data_0[];
Ground* fn_50_38CC(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_50_E14(Stage* stage, int kind) {
    Ground* ground;
    void* arg1;
    void* arg2;
    int arg3;
    char* data = lbl_50_data_0;

    switch (kind) {
    case 15:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x1c8);
        arg1 = (char*)stage + 0x220;
        arg2 = (char*)stage + 0x400;
        arg3 = 7;
        break;
    case 16:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x1d8);
        arg1 = (char*)stage + 0x22c;
        arg2 = (char*)stage + 0x400;
        arg3 = 6;
        break;
    case 17:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x1e8);
        arg1 = (char*)stage + 0x238;
        arg2 = (char*)stage + 0x400;
        arg3 = 5;
        break;
    case 18:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x1f8);
        arg1 = (char*)stage + 0x244;
        arg2 = (char*)stage + 0x400;
        arg3 = 4;
        break;
    case 19:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x208);
        arg1 = (char*)stage + 0x250;
        arg2 = (char*)stage + 0x400;
        arg3 = 3;
        break;
    case 20:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x218);
        arg1 = (char*)stage + 0x25c;
        arg2 = (char*)stage + 0x400;
        arg3 = 2;
        break;
    case 21:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x228);
        arg1 = (char*)stage + 0x268;
        arg2 = (char*)stage + 0x404;
        arg3 = 7;
        break;
    case 22:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x23c);
        arg1 = (char*)stage + 0x274;
        arg2 = (char*)stage + 0x404;
        arg3 = 6;
        break;
    case 23:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x250);
        arg1 = (char*)stage + 0x280;
        arg2 = (char*)stage + 0x404;
        arg3 = 5;
        break;
    case 24:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x264);
        arg1 = (char*)stage + 0x28c;
        arg2 = (char*)stage + 0x404;
        arg3 = 4;
        break;
    case 25:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x278);
        arg1 = (char*)stage + 0x298;
        arg2 = (char*)stage + 0x404;
        arg3 = 3;
        break;
    case 26:
        ground = fn_50_38CC(4, data + 0x1b8, data + 0x28c);
        arg1 = (char*)stage + 0x2a4;
        arg2 = (char*)stage + 0x404;
        arg3 = 2;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->init(stage->field_01a0, 0, 0);
        ground->setData(stage->field_009c);
        ground->setPos117(arg1);
        ground->setIndex(arg3);
        ground->setPos118(arg2);
    }
}
}
