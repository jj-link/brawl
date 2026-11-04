#include <so/so_module_accesser.h>
#pragma force_active on
extern float lbl_27_rodata_644C;
extern float lbl_27_rodata_6458;
struct Base { char pad[0x3c]; };
class Self : public Base {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
 virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
 virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
 virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
 char pad2[0x20];
 soModuleAccesser* accesser;
};
extern "C" void fn_27_1DA868(Self*);
extern "C" void fn_27_2ED9DC(Self* self, float a, float b) {
 soModuleAccesser* acc = self->accesser;
 Vec3f pos = acc->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, false);
 pos.m_z = acc->m_enumerationStart->m_groundModule->getZ();
 pos.m_x += b * a;
 acc->m_enumerationStart->m_postureModule->init(&pos, a);
 fn_27_1DA868(self);
 soWorkManageModule* work = acc->m_enumerationStart->m_workManageModule;
 float v = a > lbl_27_rodata_644C ? lbl_27_rodata_644C : lbl_27_rodata_6458;
 work->setFloat(v, 0x11000001);
 self->s43();
 acc->m_enumerationStart->m_statusModule->changeStatusForce(0, acc);
}