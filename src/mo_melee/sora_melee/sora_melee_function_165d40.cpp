#include <so/so_value_accesser.h>
#pragma force_active on
struct MyVector { float x,y,z; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual int slot3();
 virtual void slot4(); virtual void slot5();
 virtual Object_vptr_0* slot6(int);
 virtual void slot7(); virtual void slot8(MyVector*);
 virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(int);
};
struct GroundBase { char pad[8]; };
class Ground : public GroundBase {
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
 virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual float s90(int);
};
extern float lbl_27_rodata_2040;
extern "C" void fn_27_165D40(void*, soModuleAccesser* a, int kind) {
 switch (kind) {
 case 4: case 10: case 0x26: case 0x89: case 0x8c: break;
 default:
  if (((Object_vptr_0*)a->m_enumerationStart->m_situationModule)->slot3() == 0) {
   Object_vptr_0* energy = ((Object_vptr_0*)a->m_enumerationStart->m_kineticModule)->slot6(2);
   energy->slot2();
   float value = soValueAccesser::getConstantFloat(a, 0xc35, 0);
   float f = ((Ground*)a->m_enumerationStart->m_groundModule)->s90(0);
   if (f < lbl_27_rodata_2040)
    value += (lbl_27_rodata_2040 - value) * (lbl_27_rodata_2040 - f);
   MyVector v = { value, lbl_27_rodata_2040, lbl_27_rodata_2040 };
   energy->slot8(&v);
  }
 }
 ((Object_vptr_0*)a->m_enumerationStart->m_cameraModule)->slot41(0);
}