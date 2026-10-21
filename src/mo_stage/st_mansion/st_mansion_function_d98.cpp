#pragma force_active on

struct Pad {
    char p[0x3c];
};

#define V(n) virtual void v##n();

class Ground : public Pad {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36)
    virtual void startup(void*, int, int);
    V(38)
    virtual void setValue(void*);
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
    V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
    V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
    V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95)
    V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103)
    V(104) V(105) V(106) V(107) V(108) V(109) V(110)
    V(111) V(112) V(113) V(114)
    virtual void set115(void*);
    virtual void set116(void*);
    virtual void set117(void*);
};

#undef V

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x100];
    void* archive;
};

extern "C" Ground* fn_47_AD50(int, const char*, const char*);
extern char lbl_47_data_2A0[];
extern char lbl_47_data_2B4[];
extern "C" void addGround__5StageFP6Ground(Stage*, Ground*);

extern "C" void fn_47_D98(Stage* stage, int type) {
    Ground* ground;
    switch (type) {
    case 15:
        ground = fn_47_AD50(2, lbl_47_data_2A0, lbl_47_data_2B4);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->archive, 0, 0);
        ground->setValue(stage->value);
        ground->set115((char*)stage + 0x1f0);
        ground->set116((char*)stage + 0x24c);
        ground->set117((char*)stage + 0x218);
    }
}
