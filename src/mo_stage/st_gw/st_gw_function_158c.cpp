#include <st/stage.h>
#pragma force_active on
#define SLOT(n) virtual void v##n();
struct GroundBase { char pad[0x3c]; };
struct GroundVirtual : GroundBase {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17)
    SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36)
    virtual void startup(void*, int, int);
    SLOT(38)
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
    SLOT(112) SLOT(113) SLOT(114)
    virtual void slot115(void*);
    virtual void slot116(void*);
    virtual void slot117(void*);
    virtual void slot118(void*);
};
#undef SLOT
extern "C" {
extern char lbl_63_data_0[];
Ground* fn_63_15C80(int, const char*, const char*);
void fn_63_158C(Stage* stage, int kind) {
    char* self = (char*)stage;
    char* data = lbl_63_data_0;
    Ground* ground;
    void* info;
    switch (kind) {
    case 15:
        ground = fn_63_15C80(0x22, data + 0x310, data + 0x324);
        info = self + 0x30c;
        break;
    case 16:
        ground = fn_63_15C80(0x23, data + 0x338, data + 0x34c);
        info = self + 0x30d;
        break;
    case 17:
        ground = fn_63_15C80(0x24, data + 0x360, data + 0x374);
        info = self + 0x30e;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        GroundVirtual* g = (GroundVirtual*)ground;
        g->startup(*(void**)(self + 0x1a0), 0, 0);
        g->setData(*(void**)(self + 0x9c));
        g->slot115(self + 0x1e0);
        g->slot116(0);
        g->slot117(info);
        g->slot118(self + 0x1e4);
    }
}
}