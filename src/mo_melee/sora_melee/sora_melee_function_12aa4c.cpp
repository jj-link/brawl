#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_12D904(void* self, bool a, bool b, int c);
void fn_27_1392D4(Fighter* self, float f1, float f2, int a, int b, int c);
void fn_27_138CBC(Fighter* self, int a, int b);
void fn_27_138458(Fighter* self, int a, int b, int c, int d);
}

extern const float lbl_27_rodata_1048;
extern const float lbl_27_rodata_1058;

struct Bits { unsigned char a:7; unsigned char b:1; };

// Dummy vtable view: virtual slot N is at vptr + 8 + 4*N.
class ModuleVT {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
    virtual u32 v17(u32);
    virtual void v18();
    virtual void v19(u32);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(int, void*);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43(int);
    virtual void v44(int);
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
    virtual void finish(); virtual void s165(); virtual void s166(); virtual void s167();
    virtual void s168(); virtual void s169(); virtual void s170(); virtual void s171();
    virtual void s172(); virtual void s173(); virtual void s174(); virtual void s175();
    virtual void s176();
    virtual void call(int, float, int);
};


extern "C" void fn_27_4254(void*, int);
class OffsetCallsBase { public: char pad[8]; };
class OffsetCalls : public OffsetCallsBase {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9();
};
static inline void setShort(Fighter* f, int value) {
    *(short*)((char*)f + 0x140) = value;
    if (*(short*)((char*)f + 0x140) > -1) *(int*)((char*)f + 0x144) = 0;
}
extern "C" void fn_27_12AA4C(Fighter* arg0) {
    { 
    fn_27_12D904(arg0, true, false, 0);
    ((Call2CC*)arg0)->call(0, lbl_27_rodata_1058, -1);
    fn_27_1392D4(arg0, lbl_27_rodata_1048, lbl_27_rodata_1048, 0, 0, 0);
    arg0->setCurry(false, -1);
    fn_27_138CBC(arg0, 0, 0);
    arg0->setSuperStar(false, -1, false);
    unsigned char* flags = (unsigned char*)arg0 + 0x138;
    unsigned int bits = *flags;
    if ((bits & 1) == 1U) {
        ((Bits*)flags)->b = 0;
        ModuleVT* cam = (ModuleVT*)arg0->m_moduleAccesser->m_enumerationStart->m_cameraModule;
        cam->v22();
    }
    fn_27_138458(arg0, 0, 1, 0, 0);
    soModuleAccesser* a = arg0->m_moduleAccesser;
    ModuleVT* wm = (ModuleVT*)a->m_enumerationStart->m_workManageModule;
    if (wm->v17(0x12000028) == 1) {
        ModuleVT* fx = (ModuleVT*)a->m_enumerationStart->m_effectModule;
        fx->v44(8);
        fx = (ModuleVT*)a->m_enumerationStart->m_effectModule;
        fx->v43(9);
        wm = (ModuleVT*)a->m_enumerationStart->m_workManageModule;
        wm->v19(0x12000028);
        ((Call48Offset*)a->m_enumerationStart->m_slowModule)->call();
    } }
    ModuleVT* st = (ModuleVT*)arg0->m_moduleAccesser->m_enumerationStart->m_statusModule;
    if (st->v16() != -1) {
        soModuleAccesser* acc = arg0->m_moduleAccesser;
        { 
    fn_27_12D904(arg0, true, false, 0);
    ((Call2CC*)arg0)->call(0, lbl_27_rodata_1058, -1);
    fn_27_1392D4(arg0, lbl_27_rodata_1048, lbl_27_rodata_1048, 0, 0, 0);
    arg0->setCurry(false, -1);
    fn_27_138CBC(arg0, 0, 0);
    arg0->setSuperStar(false, -1, false);
    unsigned char* flags = (unsigned char*)arg0 + 0x138;
    unsigned int bits = *flags;
    if ((bits & 1) == 1U) {
        ((Bits*)flags)->b = 0;
        ModuleVT* cam = (ModuleVT*)arg0->m_moduleAccesser->m_enumerationStart->m_cameraModule;
        cam->v22();
    }
    fn_27_138458(arg0, 0, 1, 0, 0);
    soModuleAccesser* a = arg0->m_moduleAccesser;
    ModuleVT* wm = (ModuleVT*)a->m_enumerationStart->m_workManageModule;
    if (wm->v17(0x12000028) == 1) {
        ModuleVT* fx = (ModuleVT*)a->m_enumerationStart->m_effectModule;
        fx->v44(8);
        fx = (ModuleVT*)a->m_enumerationStart->m_effectModule;
        fx->v43(9);
        wm = (ModuleVT*)a->m_enumerationStart->m_workManageModule;
        wm->v19(0x12000028);
        ((Call48Offset*)a->m_enumerationStart->m_slowModule)->call();
    } }
        st = (ModuleVT*)acc->m_enumerationStart->m_statusModule;
        st->v34(0x10b, acc);
        ModuleVT* ia = (ModuleVT*)acc->m_enumerationStart->m_itemManageModule;
        ia->v28();
        ModuleVT* ga = (ModuleVT*)acc->m_enumerationStart->m_generateArticleManageModule;
        ga->v2(1);
    }
    ((Call2CC*)arg0)->finish();
    arg0->m_moduleAccesser->activate();
    ((OffsetCalls*)arg0->m_moduleAccesser->m_enumerationStart->m_physicsModule)->s5();
    ((OffsetCalls*)arg0->m_moduleAccesser->m_enumerationStart->m_modelModule)->s9();
    fn_27_4254(arg0, 1);
    if (*(short*)((char*)arg0 + 0x140) != -1)
        setShort(arg0, -1);
}
