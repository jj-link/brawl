#pragma force_active on
#define SLOT(n) virtual void v##n();

struct GroundBase {
    char pad[0x3c];
};

struct Ground : GroundBase {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17)
    SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36)
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void setData(void*);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45)
    SLOT(46) SLOT(47) SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79) SLOT(80) SLOT(81)
    SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92) SLOT(93)
    SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105)
    SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111)
    SLOT(112) SLOT(113)
    virtual void setInfo1(void*);
    virtual void setInfo2(void*);
};

#undef SLOT

extern "C" {
extern char lbl_81_data_0[];
Ground* fn_81_5184(int, const char*, const char*);
void addGround__5StageFP6Ground(void*, Ground*);

void fn_81_ABC(char* self, int kind) {
    char* data = lbl_81_data_0;
    Ground* ground;
    void* info;

    switch (kind) {
    case 14:
        ground = fn_81_5184(0xb, data + 0x50, data + 0x64);
        info = self + 0xb00;
        break;
    case 15:
        ground = fn_81_5184(0xc, data + 0x78, data + 0x8c);
        info = self + 0xb34;
        break;
    case 16:
        ground = fn_81_5184(0xd, data + 0xa0, data + 0xb4);
        info = self + 0xb68;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(*(void**)(self + 0x1a0), 0, 0);
        ground->setData(*(void**)(self + 0x9c));
        ground->setInfo1(self + 0x1e0);
        ground->setInfo2(info);
    }
}
}