#pragma force_active on
struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
};

struct Ground_base { char pad[0x3c]; };

#define SLOT(n) virtual void slot##n();
class Ground : public Ground_base {
public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36)
    virtual void startup(void* archive, unsigned long a, int b);
    SLOT(38)
    virtual void fn_88_B1C(void* p);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    virtual void slot114(void* p);
    virtual void slot115(void* p);
    virtual void slot116(void* p);
    virtual void slot117(void* p);
    virtual void slot118(void* p);
    virtual void slot119(void* p);
    virtual void slot120(void* p);
    virtual void slot121(void* p);
};
#undef SLOT

extern "C" {
extern char lbl_88_data_0[];
Ground* fn_88_651C(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_88_DE0(Stage* stage, int kind) {
    Ground* ground;
    void* arg1;
    void* arg2;
    void* arg3;
    char* data = lbl_88_data_0;

    switch (kind) {
    case 7:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0xe0);
        arg1 = (char*)stage + 0x3f8;
        arg2 = (char*)stage + 0x440;
        arg3 = (char*)stage + 0x594;
        break;
    case 8:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0xf0);
        arg1 = (char*)stage + 0x404;
        arg2 = (char*)stage + 0x470;
        arg3 = (char*)stage + 0x598;
        break;
    case 9:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0x100);
        arg1 = (char*)stage + 0x410;
        arg2 = (char*)stage + 0x4a0;
        arg3 = (char*)stage + 0x59c;
        break;
    case 10:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0x110);
        arg1 = (char*)stage + 0x41c;
        arg2 = (char*)stage + 0x4d0;
        arg3 = (char*)stage + 0x5a0;
        break;
    case 11:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0x120);
        arg1 = (char*)stage + 0x428;
        arg2 = (char*)stage + 0x500;
        arg3 = (char*)stage + 0x5a4;
        break;
    case 12:
        ground = fn_88_651C(0x1e, data + 0xd4, data + 0x130);
        arg1 = (char*)stage + 0x434;
        arg2 = (char*)stage + 0x530;
        arg3 = (char*)stage + 0x5a8;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->field_01a0, 0, 0);
        ground->fn_88_B1C(stage->field_009c);
        ground->slot114(arg1);
        ground->slot115(arg2);
        ground->slot116((char*)stage + 0x578);
        ground->slot117((char*)stage + 0x560);
        ground->slot118(arg3);
        ground->slot119((char*)stage + 0x5b0);
        ground->slot120((char*)stage + 0x584);
        ground->slot121((char*)stage + 0x590);
    }
}
}
