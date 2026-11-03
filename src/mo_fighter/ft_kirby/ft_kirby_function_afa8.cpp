#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
void fn_27_12BAF8(void* object, int param);
int fn_27_111E30(void* owner);
int getPlayerNo__9ftManagerFi(ftManager* manager, int entryId);
void fn_96_1C8A0(void* self, int a, int b, int c, bool d);
}

#define V(n) virtual void v##n();
#define DUMMY(n) virtual void d##n() = 0;

struct KWorkModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    virtual void setInt(int value, unsigned int index) = 0;
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11) DUMMY(12)
    DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18)
    virtual void offFlag(unsigned int flag) = 0;
};

struct KSubModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4) DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    DUMMY(20) DUMMY(21) DUMMY(22) DUMMY(23) DUMMY(24) DUMMY(25) DUMMY(26) DUMMY(27) DUMMY(28) DUMMY(29)
    DUMMY(30) DUMMY(31) DUMMY(32) DUMMY(33) DUMMY(34) DUMMY(35) DUMMY(36) DUMMY(37) DUMMY(38)
    virtual void fnA4(int value) = 0;
};

struct KModules {
    char pad0[0x64];
    KWorkModule* work;
    char pad1[0x88 - 0x68];
    KSubModule* sub;
};

struct KAccesser {
    char pad[0xD8];
    KModules* modules;
};

struct KFighterBase {
    char pad[0x3c];
};

class KFighter : public KFighterBase {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139)
    V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147) V(148) V(149)
    V(150) V(151) V(152) V(153) V(154) V(155) V(156) V(157) V(158) V(159)
    V(160) V(161) V(162) V(163) V(164) V(165) V(166) V(167) V(168) V(169)
    V(170) V(171) V(172) V(173) V(174) V(175) V(176) V(177) V(178) V(179)
    V(180) V(181) V(182) V(183) V(184)
    virtual void* getOwner();
    char pad2[0x60 - 0x40];
    KAccesser* accesser;
    char pad3[0x10C - 0x64];
    int entryId;
};

#undef V
#undef DUMMY

extern "C" void fn_96_AFA8(KFighter* self, int param) {
    fn_27_12BAF8(self, param);
    KAccesser* accesser = self->accesser;
    KWorkModule* work = accesser->modules->work;
    work->offFlag(0x12000042);
    work->offFlag(0x12000043);
    work->setInt(-1, 0x10000048);
    work->setInt(-1, 0x10000049);
    accesser->modules->sub->fnA4(0x1a);
    int entryId = self->entryId;
    ftManager* manager = g_ftManager;
    int owner = fn_27_111E30(self->getOwner());
    int playerNo = getPlayerNo__9ftManagerFi(manager, entryId);
    fn_96_1C8A0((char*)self + 0x1B72C, -1, playerNo, owner, false);
}
