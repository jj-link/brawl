#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <ft/ft_audience_manager.h>

#pragma force_active on

extern "C" unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);
extern "C" bool fn_27_111E00(ftOwner*);
extern "C" void fn_27_1392D4(Fighter*, float, float, int, int, int);
extern "C" void fn_27_138CBC(Fighter*, int, int);
extern "C" void fn_27_138458(Fighter*, int, int, int, int);
extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_1058;

class EffectSlots {
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
 virtual void s40(); virtual void s41(); virtual void s42();
 virtual void s43(int); virtual void s44(int);
};
class Call48 {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void call();
};
struct Call48Base { char pad[8]; };
class Call48Offset : public Call48Base {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void call();
};
class Call64 {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual void s21(); virtual void s22(); virtual void call();
};
class Call1C {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void call(int);
};
struct Call3CBase { char pad[12]; };
class Call3C : public Call3CBase {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void call(int,int,int);
};
struct LinkArg { int kind; bool flag; int value; };
class LinkCall {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void call(int, LinkArg*, int);
};

struct Bits { unsigned char a:7; unsigned char b:1; };
extern "C" void fn_27_130808(Fighter* f, int arg) {
    soModuleAccesser* a = f->m_moduleAccesser;
    int status = a->m_enumerationStart->m_statusModule->getStatusKind();
    unsigned int* data = fn_27_14554C(&g_ftCommonDataAccesser, f->getFtKind(), status);
    float damage = a->m_enumerationStart->m_workManageModule->getFloat(0x1100000e);
    int flag = a->m_enumerationStart->m_workManageModule->isFlag(0x22000011);
    f->setMetal(fn_27_111E00(f->getOwner()), lbl_27_rodata_1058, -1);
    fn_27_1392D4(f, lbl_27_rodata_1048, lbl_27_rodata_1048, 0, 0, 0);
    f->setCurry(false, -1);
    fn_27_138CBC(f, 0, 0);
    f->setSuperStar(false, -1, false);
    unsigned char* flags = (unsigned char*)f + 0x138;
    unsigned int bits = *flags;
    if ((bits & 1) == 1U) {
        ((Bits*)flags)->b = 0;
        ((Call64*)f->m_moduleAccesser->m_enumerationStart->m_cameraModule)->s22();
    }
    fn_27_138458(f, 0, 1, 0, 0);
    soModuleAccesser* b = f->m_moduleAccesser;
    if (b->m_enumerationStart->m_workManageModule->isFlag(0x12000028) == 1) {
        ((EffectSlots*)b->m_enumerationStart->m_effectModule)->s44(8);
        ((EffectSlots*)b->m_enumerationStart->m_effectModule)->s43(9);
        b->m_enumerationStart->m_workManageModule->offFlag(0x12000028);
        ((Call48Offset*)b->m_enumerationStart->m_slowModule)->call();
    }
    soModuleAccesser* c = f->m_moduleAccesser;
    c->m_enumerationStart->m_workManageModule->getFloat(0x1100000b);
    ((Call64*)c->m_enumerationStart->m_postureModule)->call();
    if (c->m_enumerationStart->m_workManageModule->isFlag(0x12000014) == 1) {
        c->m_enumerationStart->m_workManageModule->offFlag(0x12000014);
        ((Call1C*)c->m_enumerationStart->m_paramCustomizeModule)->call(0);
        soSoundModule* sound = c->m_enumerationStart->m_soundModule;
        c->m_enumerationStart->m_workManageModule->getFloat(0x11000011);
        ((Call48*)sound)->call();
    }
    if (c->m_enumerationStart->m_workManageModule->isFlag(0x12000015) == 1) {
        c->m_enumerationStart->m_workManageModule->offFlag(0x12000015);
        ((Call1C*)c->m_enumerationStart->m_paramCustomizeModule)->call(1);
        soSoundModule* sound = c->m_enumerationStart->m_soundModule;
        c->m_enumerationStart->m_workManageModule->getFloat(0x11000011);
        ((Call48*)sound)->call();
    }
    c->m_enumerationStart->m_workManageModule->setInt(0, 0x10000023);
    switch (arg) {
    case 0: case 1: case 2: case 3:
        a->m_enumerationStart->m_workManageModule->onFlag(0x12000017);
        break;
    default:
        a->m_enumerationStart->m_workManageModule->offFlag(0x12000017);
    }
    a->m_enumerationStart->m_workManageModule->setInt(arg, 0x10000028);
    a->m_enumerationStart->m_workManageModule->offFlag(0x12000036);
    LinkArg event;
    event.kind = 2;
    event.flag = false;
    event.value = arg;
    ((LinkCall*)a->m_enumerationStart->m_linkModule)->call(-1, &event, 0);
    if (f->m_moduleAccesser->m_enumerationStart->m_statusModule->getStatusKind() == 0xbc)
        ((Call3C*)f->getOwner())->call(1, 0x17, 0);
    a->m_enumerationStart->m_statusModule->changeStatusRequest(0xbd, a);
    g_ftAudienceManager->m_audience->reqHandclapDead(damage, ((*data >> 3) & 1) && flag == 0);
}
