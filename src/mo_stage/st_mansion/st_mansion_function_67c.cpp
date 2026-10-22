#pragma force_active on
struct GroundPrefix {
    char pad_0000[0x3c];
};

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
    virtual void init(int, int, int);
    SLOT(38)
    virtual void bind(int);
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
    SLOT(116) SLOT(117)
    virtual void a(char*);
    virtual void b(char*);
    virtual void c(char*);
    virtual void d(int);
#undef SLOT
};

struct Stage {
    char pad_0000[0x9c];
    int field_009c;
    char pad_00a0[0x100];
    int field_01a0;
};

extern "C" {
extern char lbl_47_data_0[];
Ground* fn_47_B8F8(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_47_67C(Stage* stage, int kind) {
    Ground* ground;
    char* arg1;
    char* arg2;
    int count;
    char* data = lbl_47_data_0;

    switch (kind) {
    case 2:
        ground = fn_47_B8F8(3, data + 0x70, data + 0x88);
        arg1 = (char*)stage + 0x250;
        arg2 = (char*)stage + 0x268;
        count = 4;
        break;
    case 3:
        ground = fn_47_B8F8(4, data + 0xa0, data + 0xb8);
        arg1 = (char*)stage + 0x25c;
        arg2 = (char*)stage + 0x269;
        count = 5;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->init(stage->field_01a0, 0, 0);
        ground->bind(stage->field_009c);
        ground->a(arg1);
        ground->b((char*)stage + 0x1d8);
        ground->c(arg2);
        ground->d(count);
    }
}
}
