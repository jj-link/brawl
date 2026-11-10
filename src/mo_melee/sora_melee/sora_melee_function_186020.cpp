#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern float lbl_27_rodata_24B8;

class Vt {
public:
    virtual void m1(); virtual void m2(); virtual void m3();
    virtual int m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10();
    virtual void m11(float v);
    virtual void m12(); virtual void m13();
    virtual void m14(unsigned long id, float v);
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(unsigned long id);
    virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25();
    virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30();
    virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40();
    virtual float m41(unsigned long id);
    virtual void m42(); virtual void m43();
    virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    virtual void m49(unsigned long a, int b, int c, int d, float x, float y, float z);
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101(); virtual void m102(); virtual void m103(); virtual void m104();
    virtual void m105(); virtual void m106(); virtual void m107(); virtual void m108(); virtual void m109();
    virtual void m110(); virtual void m111(); virtual void m112(); virtual void m113(); virtual void m114();
    virtual void m115(); virtual void m116(); virtual void m117(); virtual void m118(); virtual void m119();
    virtual void m120(); virtual void m121(); virtual void m122(); virtual void m123(); virtual void m124();
    virtual void m125(); virtual void m126(); virtual void m127(); virtual void m128(); virtual void m129();
    virtual void m130(); virtual void m131(); virtual void m132(); virtual void m133(); virtual void m134();
    virtual void m135(); virtual void m136(); virtual void m137(); virtual void m138(); virtual void m139();
    virtual void m140(); virtual void m141(); virtual void m142(); virtual void m143(); virtual void m144();
    virtual void m145(); virtual void m146(); virtual void m147(); virtual void m148(); virtual void m149();
    virtual void m150(); virtual void m151(); virtual void m152(); virtual void m153(); virtual void m154();
    virtual void m155(); virtual void m156(); virtual void m157(); virtual void m158(); virtual void m159();
    virtual void m160(); virtual void m161(); virtual void m162(); virtual void m163(); virtual void m164();
    virtual void m165(); virtual void m166(); virtual void m167(); virtual void m168(); virtual void m169();
    virtual void m170(); virtual void m171(); virtual void m172(); virtual void m173(); virtual void m174();
    virtual void m175(); virtual void m176(); virtual void m177(); virtual void m178(); virtual void m179();
    virtual void m180(); virtual void m181(); virtual void m182(); virtual void m183(); virtual void m184();
    virtual void m185(); virtual void m186();
    virtual int m187();
};

// vtable pointer sits at offset 0x8 of the object.
struct Pad8 { char pad[8]; };
class DmgModule : public Pad8 {
public:
    virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18();
    virtual float m19(unsigned long id);
};

#define V(n) virtual void v##n();

// vtable pointer sits at offset 0x3c of the object.
struct Pad3c { char pad[0x3c]; };
class Model : public Pad3c {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42)
    virtual void mStage();   // slot 43 -> vtable offset 0xb4
    V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53)
    V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
    V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73)
    V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83)
    V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93)
    V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103)
    V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111) V(112) V(113)
    V(114) V(115) V(116) V(117) V(118) V(119) V(120) V(121) V(122) V(123)
    V(124) V(125) V(126) V(127) V(128) V(129) V(130) V(131) V(132) V(133)
    V(134) V(135) V(136) V(137) V(138) V(139) V(140) V(141) V(142) V(143)
    V(144) V(145) V(146) V(147) V(148) V(149) V(150) V(151) V(152) V(153)
    V(154) V(155) V(156) V(157) V(158) V(159) V(160) V(161) V(162) V(163)
    V(164) V(165) V(166) V(167) V(168) V(169) V(170) V(171) V(172) V(173)
    V(174) V(175) V(176) V(177) V(178) V(179) V(180) V(181) V(182) V(183)
    V(184) V(185)
    virtual int mState();    // slot 186 -> vtable offset 0x2f0
};

#undef V

extern "C" void fn_27_186020(void* self, soModuleAccesser* a) {
    Vt* posture = (Vt*)a->m_enumerationStart->m_postureModule;
    float t = ((Vt*)a->m_enumerationStart->m_linkModule)->m41(0);
    posture->m11(-t);
    ((Vt*)a->m_enumerationStart->m_postureModule)->m20();
    Model* model = (Model*)*(void**)((char*)a + 8);
    model->mStage();
    Model* p = (Model*)__dynamic_cast(*(void**)((char*)a + 8), 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    if (p->mState() == 5 || p->mState() == 0x12 || p->mState() == 0x25) {
        ((Vt*)a->m_enumerationStart->m_workManageModule)->m19(0x22000010);
    }
    float f30 = soValueAccesser::getConstantFloat(a, 0xdb2, 0);
    float f31 = ((DmgModule*)a->m_enumerationStart->m_damageModule)->m19(0);
    f31 = f31 * soValueAccesser::getConstantFloat(a, 0xd60, 0);
    float c5f = soValueAccesser::getConstantFloat(a, 0xd5f, 0);
    f31 = c5f + f31;
    float tmp = f30 * soValueAccesser::getConstantFloat(a, 0xd61, 0);
    f30 = tmp + f31;
    ((Vt*)a->m_enumerationStart->m_workManageModule)->m14(0x21000004, f30);
    f31 = f30 * soValueAccesser::getConstantFloat(a, 0xd62, 0);
    ((Vt*)a->m_enumerationStart->m_workManageModule)->m14(0x21000005, f31);
    if (((Vt*)a->m_enumerationStart->m_situationModule)->m4() == 2) {
        f30 = f31;
    }
    float k = lbl_27_rodata_24B8;
    float c63 = soValueAccesser::getConstantFloat(a, 0xd63, 0);
    ((Vt*)a->m_enumerationStart->m_controllerModule)->m49(0, -1, 0, 0, f30, k, c63);
}
