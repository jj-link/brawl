#include <ft/ft_manager.h>
#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <types.h>
#pragma force_active on

extern "C" {
float fn_27_192278(void*, unsigned long);
void fn_27_3999D4(void*, unsigned int, int, int, Vec3f*, int, int, float, float);
extern const float lbl_27_rodata_7D80;
}

namespace {
class TeamValue {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getValue();
};

class TeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual TeamValue* getValue();
};

struct VCallPad {
    char pad[0x3C];
};

#define VSLOT(n) virtual int slot##n();

struct VCall : VCallPad {
    VSLOT(0) VSLOT(1) VSLOT(2) VSLOT(3) VSLOT(4) VSLOT(5) VSLOT(6) VSLOT(7) VSLOT(8) VSLOT(9)
    VSLOT(10) VSLOT(11) VSLOT(12) VSLOT(13) VSLOT(14) VSLOT(15) VSLOT(16) VSLOT(17) VSLOT(18) VSLOT(19)
    VSLOT(20) VSLOT(21) VSLOT(22) VSLOT(23) VSLOT(24) VSLOT(25) VSLOT(26) VSLOT(27) VSLOT(28) VSLOT(29)
    VSLOT(30) VSLOT(31) VSLOT(32) VSLOT(33) VSLOT(34) VSLOT(35) VSLOT(36) VSLOT(37) VSLOT(38) VSLOT(39)
    VSLOT(40) VSLOT(41) VSLOT(42) VSLOT(43) VSLOT(44) VSLOT(45) VSLOT(46) VSLOT(47) VSLOT(48) VSLOT(49)
    VSLOT(50) VSLOT(51) VSLOT(52) VSLOT(53) VSLOT(54) VSLOT(55) VSLOT(56) VSLOT(57) VSLOT(58) VSLOT(59)
    VSLOT(60) VSLOT(61) VSLOT(62) VSLOT(63) VSLOT(64) VSLOT(65) VSLOT(66) VSLOT(67) VSLOT(68) VSLOT(69)
    VSLOT(70) VSLOT(71) VSLOT(72) VSLOT(73) VSLOT(74) VSLOT(75) VSLOT(76) VSLOT(77) VSLOT(78) VSLOT(79)
    VSLOT(80) VSLOT(81) VSLOT(82) VSLOT(83) VSLOT(84) VSLOT(85) VSLOT(86) VSLOT(87) VSLOT(88) VSLOT(89)
    VSLOT(90) VSLOT(91) VSLOT(92) VSLOT(93) VSLOT(94) VSLOT(95) VSLOT(96) VSLOT(97) VSLOT(98) VSLOT(99)
    VSLOT(100) VSLOT(101) VSLOT(102) VSLOT(103) VSLOT(104) VSLOT(105) VSLOT(106) VSLOT(107) VSLOT(108) VSLOT(109)
    VSLOT(110) VSLOT(111) VSLOT(112) VSLOT(113) VSLOT(114) VSLOT(115) VSLOT(116) VSLOT(117) VSLOT(118) VSLOT(119)
    VSLOT(120) VSLOT(121) VSLOT(122) VSLOT(123) VSLOT(124) VSLOT(125) VSLOT(126) VSLOT(127) VSLOT(128) VSLOT(129)
    VSLOT(130) VSLOT(131) VSLOT(132) VSLOT(133) VSLOT(134) VSLOT(135) VSLOT(136) VSLOT(137) VSLOT(138) VSLOT(139)
    VSLOT(140) VSLOT(141) VSLOT(142) VSLOT(143) VSLOT(144) VSLOT(145) VSLOT(146) VSLOT(147) VSLOT(148) VSLOT(149)
    VSLOT(150) VSLOT(151) VSLOT(152) VSLOT(153) VSLOT(154) VSLOT(155) VSLOT(156) VSLOT(157) VSLOT(158) VSLOT(159)
    VSLOT(160) VSLOT(161) VSLOT(162) VSLOT(163) VSLOT(164) VSLOT(165) VSLOT(166) VSLOT(167) VSLOT(168) VSLOT(169)
    VSLOT(170) VSLOT(171) VSLOT(172) VSLOT(173) VSLOT(174) VSLOT(175) VSLOT(176) VSLOT(177) VSLOT(178) VSLOT(179)
    VSLOT(180) VSLOT(181) VSLOT(182) VSLOT(183) VSLOT(184) VSLOT(185) VSLOT(186)
};

struct ParamsCopy {
    char pad[0x1A4];
    float f;
    int i;
    char rest[0x138];
};
}

extern "C" int fn_27_395E34(void* unused, void* p1, soModuleAccesser* accesser, int p3) {
    float lr = accesser->m_enumerationStart->m_postureModule->getLr();

    Vec3f pos;
    Vec3f offset;
    offset.m_x = lbl_27_rodata_7D80;
    offset.m_y = lbl_27_rodata_7D80;
    offset.m_z = lbl_27_rodata_7D80;
    float scale = accesser->m_enumerationStart->m_postureModule->getScale();
    offset.m_x = scale * fn_27_192278(accesser, 0xfa5);
    offset.m_y = scale * fn_27_192278(accesser, 0xfa6);

    Vec3f nodePos = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, false);
    pos = nodePos;
    pos.m_x += offset.m_x * lr;
    pos.m_y += offset.m_y;
    pos.m_z = accesser->m_enumerationStart->m_groundModule->getZ();

    ftManager* manager = g_ftManager;
    int linkTask = accesser->m_enumerationStart->m_linkModule->getNodeTaskId(0);
    int entryId = manager->getEntryIdFromTaskId(linkTask, 0);
    Fighter* fighter = manager->getFighter(entryId, -1);
    int kind = reinterpret_cast<VCall*>(fighter)->slot186();
    ParamsCopy params = *reinterpret_cast<const ParamsCopy*>(g_ftCommonDataAccesser.getParam(static_cast<ftKind>(kind)));

    float paramF = params.f;
    TeamModule* team = static_cast<TeamModule*>(accesser->m_enumerationStart->m_teamModule);
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    float lr2 = accesser->m_enumerationStart->m_postureModule->getLr();
    int teamValue = team->getValue()->getValue();
    fn_27_3999D4(p1, taskId, p3, teamValue, &pos, params.i, 0, lr2, paramF);

    int value = reinterpret_cast<VCall*>(p1)->slot119();
    accesser->m_enumerationStart->m_workManageModule->setInt(value, 0x20000004);
    return 0;
}
