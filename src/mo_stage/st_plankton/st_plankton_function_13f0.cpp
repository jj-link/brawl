#pragma force_active on

struct Stage {
    char pad0[0x9c];
    void* field9c;
    char pada0[0x100];
    void* field1a0;
    char pad1a4[0x48];
    char field1ec[0x1a8];
    char field394[0xfc];
    char field490[8][0x20];
};

struct GroundPrefix {
    char pad[0x3c];
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
    virtual void setup(void*, int, int);
    SLOT(38)
    virtual void bind(void*);
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
    SLOT(116) SLOT(117) SLOT(118) SLOT(119)
    SLOT(120) SLOT(121)
    virtual void ptr1(void*);
    virtual void ptr2(void*);
    virtual void ptr3(void*);
#undef SLOT
};

extern "C" {
extern char lbl_74_data_26C[];
extern char lbl_74_data_270[];

Ground* fn_74_B468(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_74_13F0(Stage* stage) {
    Ground* ground;
    for (unsigned int i = 0; i != 8; ++i) {
        ground = fn_74_B468(1, lbl_74_data_26C, lbl_74_data_270);
        if (!ground)
            break;

        addGround__5StageFP6Ground(stage, ground);
        ground->setup(stage->field1a0, 0, 0);
        ground->bind(stage->field9c);
        ground->ptr1(stage->field394);
        ground->ptr2(stage->field1ec);
        ground->ptr3(stage->field490[(unsigned char)i]);
    }
}
}
