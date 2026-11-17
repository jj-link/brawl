#pragma fp_contract off
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on
extern "C" void* __dynamic_cast(void*,long,const void*,const void*,long);
extern char lbl_27_data_13690[]; extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_22A4; extern const float lbl_27_rodata_22A8;
extern "C" void fn_27_174C08(void*,void*,void*); extern "C" float rsqrtf__Ff(float);
struct LVec2 { float x; float y; };
struct LVec3 { float x, y, z; LVec3() {} LVec3(const LVec3& v) : x(v.x), y(v.y), z(v.z) {} };
struct LVecData { int x, y, z; };
struct LOut { int a, b; LVecData pos; int value; int zero; int padding[3]; };
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual LVec2 slot2(); virtual void slot3(u32,const void*); virtual s32 slot4(u32,const void*); virtual void slot5(s32,u32); virtual void* slot6(s32); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual f32 slot12(u32,const void*); virtual void slot13(s32); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual s32 slot17(u32,const void*); virtual void slot18(); virtual void slot19(u32,const void*); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual u32 slot38(); };
struct Self { char pad[0x14]; s32 m14; };
extern "C" void fn_27_1751A8(Self* self,soModuleAccesser* arg1) {
switch (((Object_vptr_0*)arg1->m_enumerationStart->m_workManageModule)->slot4(0x20000000,arg1->m_enumerationStart)) {
case 0: { u32 buttons=((Object_vptr_0*)arg1->m_enumerationStart->m_controllerModule)->slot38();
if ((buttons&soController::getButtonMask(static_cast<soController::PadButton>(0)))||(buttons&soController::getButtonMask(static_cast<soController::PadButton>(1)))) {
((Object_vptr_0*)arg1->m_enumerationStart->m_workManageModule)->slot5(1,0x20000000);
LVec3 zero; zero.x=lbl_27_rodata_22A4; zero.y=lbl_27_rodata_22A4; zero.z=lbl_27_rodata_22A4;
LOut out; out.a=3; out.b=0; out.pos=*(LVecData*)&zero; out.zero=0;
fn_27_174C08(self,&out,arg1);
} break; }
case 1: break;
case 2: { void* energy=((Object_vptr_0*)arg1->m_enumerationStart->m_kineticModule)->slot6(3); LVec2 v=((Object_vptr_0*)__dynamic_cast(energy,0,lbl_27_data_13690,lbl_27_data_CDF8,1))->slot2(); f32 sq=v.x*v.x+v.y*v.y; f32 f31;
if ((float)(double)nw4r::math::FAbs(sq)<=lbl_27_rodata_22A8) f31=lbl_27_rodata_22A4; else f31=sq*rsqrtf__Ff(sq);
if(self->m14!=-1&&f31<soValueAccesser::getConstantFloat(arg1,0xCD1,0)){((Object_vptr_0*)arg1->m_enumerationStart->m_effectModule)->slot13(self->m14);self->m14=-1;}
if(((Object_vptr_0*)arg1->m_enumerationStart->m_workManageModule)->slot17(0x22000010,arg1->m_enumerationStart)!=0) if(f31<((Object_vptr_0*)arg1->m_enumerationStart->m_workManageModule)->slot12(0x21000004,arg1->m_enumerationStart)) ((Object_vptr_0*)arg1->m_enumerationStart->m_statusModule)->slot3(0x49,arg1);
((Object_vptr_0*)arg1->m_enumerationStart->m_workManageModule)->slot19(0x1200003C,arg1->m_enumerationStart);
} break;
default: break;
}
}
