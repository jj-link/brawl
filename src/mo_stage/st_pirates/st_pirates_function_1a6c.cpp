#pragma force_active on
struct GroundPrefix { char pad_0000[0x3c]; };

struct Ground : GroundPrefix {
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36)
    virtual void slot37(void*, int, int);
    SLOT(38)
    virtual void slot39(void*);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71)
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
    SLOT(112) SLOT(113) SLOT(114) SLOT(115)
    SLOT(116) SLOT(117) SLOT(118)
    virtual void slot119(void*);
    virtual void slot120(void*);
    virtual void slot121(int);
#undef SLOT
};

struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
};

extern "C" {
extern char lbl_52_data_0[];
Ground* fn_52_12D6C(int, char*, char*);
Ground* fn_52_131FC(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_52_1A6C(Stage* stage, int kind) {
    Ground* ground;
    char* arg1;
    char* arg2;
    int arg3;
    char* data = lbl_52_data_0;

    switch (kind) {
    case 29:
        ground = fn_52_12D6C(0x28, data + 0x3cc, data + 0x3d8);
        arg1 = (char*)stage + 0x4e4;
        arg2 = (char*)stage + 0x609;
        arg3 = 0;
        break;
    case 30:
        ground = fn_52_12D6C(0x28, data + 0x3cc, data + 0x3f0);
        arg1 = (char*)stage + 0x4e4;
        arg2 = (char*)stage + 0x60a;
        arg3 = 1;
        break;
    case 31:
        ground = fn_52_131FC(0x28, data + 0x3cc, data + 0x408);
        arg1 = (char*)stage + 0x514;
        arg2 = (char*)stage + 0x60b;
        arg3 = 2;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->slot37(stage->field_01a0, 0, 0);
        ground->slot39(stage->field_009c);
        ground->slot119(arg1);
        ground->slot120(arg2);
        ground->slot121(arg3);
    }
}
}
