#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1392D4(Fighter* self, float f1, float f2, int a, int b, int c);
void fn_27_138458(Fighter* self, int a, int b, int c, int d);
}

extern const float lbl_27_rodata_1048;
extern const float lbl_27_rodata_1058;

class Call3CBase { public: char pad[0x3C]; };
class Call2CC : public Call3CBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63();
    virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
    virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83();
    virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87();
    virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103();
    virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107();
    virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123();
    virtual void s124(); virtual void s125(); virtual void s126(); virtual void s127();
    virtual void s128(); virtual void s129(); virtual void s130(); virtual void s131();
    virtual void s132(); virtual void s133(); virtual void s134(); virtual void s135();
    virtual void s136(); virtual void s137(); virtual void s138(); virtual void s139();
    virtual void s140(); virtual void s141(); virtual void s142(); virtual void s143();
    virtual void s144(); virtual void s145(); virtual void s146(); virtual void s147();
    virtual void s148(); virtual void s149(); virtual void s150(); virtual void s151();
    virtual void s152(); virtual void s153(); virtual void s154(); virtual void s155();
    virtual void s156(); virtual void s157(); virtual void s158(); virtual void s159();
    virtual void s160(); virtual void s161(); virtual void s162(); virtual void s163();
    virtual void s164(); virtual void s165(); virtual void s166(); virtual void s167();
    virtual void s168(); virtual void s169(); virtual void s170(); virtual void s171();
    virtual void s172(); virtual void s173(); virtual void s174(); virtual void s175();
    virtual void s176();
    virtual void call(int, float, int);
};

class Call48Base { public: char pad[8]; };
class Call48Offset : public Call48Base {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void call();
};

// Work manage module (+0x64). Slot k is at vptr + 8 + 4*k.
class WorkMgr {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void v5(u32, u32);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void v12(u32);
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual u32 v17(u32);
    virtual void s18();
    virtual void v19(u32);
};

class WorkMgr2 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void v12(u32, const void*);
};

// Posture (+0xC), param customize (+0xC4), sound (+0x50)
class ModC {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void v5(u32);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void v16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
    virtual void v23();
};

// Collision hit (+0x20)
class ModD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void v19(u32, u32);
};

// Effect (+0x88)
class ModE {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42();
    virtual void v43(u32);
    virtual void v44(u32);
};

extern "C" void fn_27_12D450(Fighter* arg0) {
    soModuleAccesser* acc = arg0->m_moduleAccesser;

    if (soValueAccesser::getConstantInt(acc, 0x59EB, 0) == 0) {
        fn_27_1392D4(arg0, lbl_27_rodata_1048, lbl_27_rodata_1048, 0, 0, 0);
    }
    if (soValueAccesser::getConstantInt(acc, 0x59EC, 0) == 0) {
        ((Call2CC*)arg0)->call(0, lbl_27_rodata_1058, -1);
    }
    if (soValueAccesser::getConstantInt(acc, 0x59ED, 0) == 0) {
        arg0->setCurry(false, -1);
    }
    if (soValueAccesser::getConstantInt(acc, 0x59EE, 0) == 0) {
        fn_27_138458(arg0, 0, 1, 0, 0);
    }
    if (soValueAccesser::getConstantInt(acc, 0x59EF, 0) == 0) {
        soModuleAccesser* a = arg0->m_moduleAccesser;
        if (((WorkMgr*)a->m_enumerationStart->m_workManageModule)->v17(0x12000028) == 1) {
            ((ModE*)a->m_enumerationStart->m_effectModule)->v44(8);
            ((ModE*)a->m_enumerationStart->m_effectModule)->v43(9);
            ((WorkMgr*)a->m_enumerationStart->m_workManageModule)->v19(0x12000028);
            ((Call48Offset*)a->m_enumerationStart->m_slowModule)->call();
        }
    }
    if (soValueAccesser::getConstantInt(acc, 0x59F0, 0) == 0) {
        soModuleAccesser* b = arg0->m_moduleAccesser;
        ((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v12(0x1100000B);
        ((ModC*)b->m_enumerationStart->m_postureModule)->v23();
        if (((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v17(0x12000014) == 1) {
            ((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v19(0x12000014);
            ((ModC*)b->m_enumerationStart->m_paramCustomizeModule)->v5(0);
            const soModuleEnumeration* en = b->m_enumerationStart;
            ModC* snd = (ModC*)en->m_soundModule;
            ((WorkMgr2*)en->m_workManageModule)->v12(0x11000011, en);
            snd->v16();
        }
        if (((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v17(0x12000015) == 1) {
            ((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v19(0x12000015);
            ((ModC*)b->m_enumerationStart->m_paramCustomizeModule)->v5(1);
            const soModuleEnumeration* en = b->m_enumerationStart;
            ModC* snd = (ModC*)en->m_soundModule;
            ((WorkMgr2*)en->m_workManageModule)->v12(0x11000011, en);
            snd->v16();
        }
        ((WorkMgr*)b->m_enumerationStart->m_workManageModule)->v5(0, 0x10000023);
    }
    if (soValueAccesser::getConstantInt(acc, 0x59F1, 0) == 0) {
        arg0->setSuperStar(false, -1, false);
    }
    ((ModD*)acc->m_enumerationStart->m_collisionHitModule)->v19(3, 0);
}
