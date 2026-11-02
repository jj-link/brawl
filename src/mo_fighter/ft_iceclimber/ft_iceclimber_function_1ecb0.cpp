#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_2CF8[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
struct Prefix3C {
    unsigned char prefix[0x3C];
};

struct Prefix8 {
    unsigned char prefix[8];
};

class SlotView {
public:
    virtual void s2() = 0; virtual void s3() = 0; virtual void s4() = 0;
    virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0; virtual void s8() = 0; virtual void s9() = 0;
    virtual void s10() = 0; virtual int s11(int) = 0; virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0;
    virtual void s15() = 0; virtual void s16() = 0; virtual void s17() = 0; virtual int s18() = 0; virtual void s19() = 0;
    virtual void s20() = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0; virtual void s24() = 0;
    virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0; virtual void s28() = 0; virtual void s29() = 0;
    virtual void s30() = 0; virtual void s31() = 0; virtual void s32() = 0; virtual void s33() = 0; virtual void s34() = 0;
    virtual void s35() = 0; virtual void s36() = 0; virtual void s37() = 0; virtual Vec3f s38(unsigned int, unsigned int, bool) = 0;
    virtual void s39() = 0; virtual void s40() = 0; virtual void s41() = 0; virtual void s42() = 0; virtual void s43() = 0; virtual void s44() = 0;
    virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0; virtual void s48() = 0; virtual void s49() = 0; virtual void s50() = 0;
    virtual void s51() = 0; virtual void s52() = 0; virtual void s53() = 0; virtual void s54() = 0; virtual void s55() = 0; virtual void s56() = 0;
    virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0; virtual void s60() = 0; virtual void s61() = 0; virtual void s62() = 0;
    virtual void s63() = 0; virtual void s64() = 0; virtual void s65() = 0; virtual void s66() = 0; virtual void s67() = 0; virtual void s68() = 0;
    virtual void s69() = 0; virtual void s70() = 0; virtual void s71() = 0; virtual void s72() = 0; virtual void s73() = 0; virtual void s74() = 0;
    virtual void s75() = 0; virtual void s76() = 0; virtual void s77() = 0; virtual void s78() = 0; virtual void s79() = 0; virtual void s80() = 0;
    virtual void s81() = 0; virtual void s82() = 0; virtual void s83() = 0; virtual void s84() = 0; virtual void s85() = 0; virtual void s86() = 0;
    virtual void s87() = 0; virtual void s88() = 0; virtual void s89() = 0; virtual void s90() = 0; virtual void s91() = 0; virtual void s92() = 0;
    virtual Vec3f s93() = 0;
};

class PhysView : public Prefix8 {
public:
    virtual void s2() = 0; virtual void s3() = 0; virtual void s4() = 0;
    virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0; virtual void s8() = 0; virtual void s9() = 0;
    virtual void s10() = 0; virtual void s11() = 0; virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0;
    virtual void s15() = 0; virtual void s16() = 0; virtual void s17() = 0; virtual void s18() = 0; virtual void s19() = 0;
    virtual void s20() = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0; virtual void s24() = 0;
    virtual void s25() = 0; virtual void s26(Vec3f*, Vec3f*) = 0; virtual void s27() = 0; virtual void s28() = 0; virtual void s29() = 0;
    virtual void s30() = 0; virtual void s31() = 0; virtual void s32() = 0; virtual void s33() = 0; virtual int s34() = 0;
    virtual void s35() = 0; virtual void s36(int) = 0;
};

class CastView : public Prefix3C {
public:
    virtual void s2() = 0; virtual void s3() = 0; virtual void s4() = 0;
    virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0; virtual void s8() = 0; virtual void s9() = 0;
    virtual void s10() = 0; virtual void s11() = 0; virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0;
    virtual void s15() = 0; virtual void s16() = 0; virtual void s17() = 0; virtual void s18() = 0; virtual void s19() = 0;
    virtual void s20() = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0; virtual void s24() = 0;
    virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0; virtual void s28() = 0; virtual void s29() = 0;
    virtual void s30() = 0; virtual void s31() = 0; virtual void s32() = 0; virtual void s33() = 0; virtual void s34() = 0;
    virtual void s35() = 0; virtual void s36() = 0; virtual void s37() = 0; virtual void s38() = 0; virtual void s39() = 0;
    virtual void s40() = 0; virtual void s41() = 0; virtual void s42() = 0; virtual void s43() = 0; virtual void s44() = 0;
    virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0; virtual void s48() = 0; virtual void s49() = 0;
    virtual void s50() = 0; virtual void s51() = 0; virtual void s52() = 0; virtual void s53() = 0; virtual void s54() = 0;
    virtual void s55() = 0; virtual void s56() = 0; virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0;
    virtual void s60() = 0; virtual void s61() = 0; virtual void s62() = 0; virtual void s63() = 0; virtual void s64() = 0;
    virtual void s65() = 0; virtual void s66() = 0; virtual void s67() = 0; virtual void s68() = 0; virtual void s69() = 0;
    virtual void s70() = 0; virtual void s71() = 0; virtual void s72() = 0; virtual void s73() = 0; virtual void s74() = 0;
    virtual void s75() = 0; virtual void s76() = 0; virtual void s77() = 0; virtual void s78() = 0; virtual void s79() = 0;
    virtual void s80() = 0; virtual void s81() = 0; virtual void s82() = 0; virtual void s83() = 0; virtual void s84() = 0;
    virtual void s85() = 0; virtual void s86() = 0; virtual void s87() = 0; virtual void s88() = 0; virtual void s89() = 0;
    virtual void s90() = 0; virtual void s91() = 0; virtual void s92() = 0; virtual void s93() = 0; virtual void s94() = 0;
    virtual void s95() = 0; virtual void s96() = 0; virtual void s97() = 0; virtual void s98() = 0; virtual void s99() = 0;
    virtual void s100() = 0; virtual void s101() = 0; virtual void s102() = 0; virtual void s103() = 0; virtual void s104() = 0;
    virtual void s105() = 0; virtual void s106() = 0; virtual void s107() = 0; virtual void s108() = 0; virtual void s109() = 0;
    virtual void s110() = 0; virtual void s111() = 0; virtual void s112() = 0; virtual void s113() = 0; virtual void s114() = 0;
    virtual void s115() = 0; virtual void s116() = 0; virtual void s117() = 0; virtual void s118() = 0; virtual void s119() = 0;
    virtual void s120() = 0; virtual void s121() = 0; virtual void s122() = 0; virtual void s123() = 0; virtual void s124() = 0;
    virtual void s125() = 0; virtual void s126() = 0;
};
}

extern "C" void fn_105_1ECB0(void*, soModuleAccesser* accesser) {
    if (reinterpret_cast<SlotView*>(accesser->m_enumerationStart->m_statusModule)->s18() == 4) {
        if (static_cast<PhysView*>(accesser->m_enumerationStart->m_physicsModule)->s34() <= 0) {
            static_cast<CastView*>(__dynamic_cast(accesser->m_stageObject, 0x3C,
                                                  lbl_105_data_2CF8, lbl_105_data_3860, 0))->s126();
            return;
        }
        static_cast<PhysView*>(accesser->m_enumerationStart->m_physicsModule)->s36(1);
    }
    Vec3f sp14 = reinterpret_cast<SlotView*>(accesser->m_enumerationStart->m_linkModule)->s93();
    if (reinterpret_cast<SlotView*>(accesser->m_enumerationStart->m_linkModule)->s11(5)) {
        Vec3f sp8 = reinterpret_cast<SlotView*>(accesser->m_enumerationStart->m_linkModule)->s38(5, 0x27, false);
        static_cast<PhysView*>(accesser->m_enumerationStart->m_physicsModule)->s26(&sp14, &sp8);
    }
}
