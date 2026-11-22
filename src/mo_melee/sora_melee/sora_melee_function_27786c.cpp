#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/collision/so_collision_attack_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on
struct FlagBits { unsigned int a:4, b:2, c:1, rest:25; };
struct PaddedData { char prefix[36]; float a,b,c; char padding[56]; PaddedData(float value) { a=value; b=value; c=value; } };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(const void*);
 virtual void slot11(); virtual void slot12(); virtual int slot13(); virtual int slot14();
 virtual int slot15(); virtual int slot16(); virtual void slot17(); virtual void slot18();
 virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22();
 virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26();
 virtual int slot27(); virtual int slot28();
};
struct AttackStorage : Object_vptr_0 {
 void* calc; unsigned int flags; char parts[0x90];
 void* groupVptr; void* groupCalc; FlagBits groupFlags; char groups[0x78];
 void* absoluteVptr; char impl[0xA0];
};
struct HitStorage : Object_vptr_0 {
 void* calc; unsigned int flags; char parts[0x68];
 void* groupVptr; void* groupCalc; FlagBits groupFlags; char groups[0x78];
 void* hitGroupVptr; void* hitGroupCalc; FlagBits hitGroupFlags; char hitGroups[0x38];
 char impl[0x68];
};
struct OtherStorage { void* vptr; void* calc; FlagBits flags; char elements[0xA0]; };
extern "C" char lbl_27_data_B620[];
struct GlobalObject { void* vtable; GlobalObject() { vtable=0; vtable=lbl_27_data_B620; } };
extern "C" {
extern char lbl_27_data_564E0[], lbl_27_data_560B4[], lbl_27_data_3E748[];
extern char lbl_27_data_46F8[], lbl_27_data_125F0[], lbl_27_data_39430[];
extern char lbl_27_data_1E0A0[], lbl_27_data_1A108[], lbl_27_data_B620[];
extern char lbl_27_bss_598[], lbl_27_bss_444[], lbl_27_bss_5FF4[], lbl_27_bss_63B0[];
extern GlobalObject lbl_27_bss_108C;
extern signed char lbl_27_bss_1088;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern const float lbl_27_rodata_4520[];
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __ct__21soCollisionAttackPartFQ211soCollision8Categoryb(void*, soCollision::Category, bool);
void* __ct__21soCollisionAttackPartFv(void*);
void* __dt__21soCollisionAttackPartFv(void*, s16);
void* __ct__18soCollisionHitPartFQ211soCollision8CategoryUl(void*, soCollision::Category, u32);
void* __ct__18soCollisionHitPartFv(void*);
void* __dt__18soCollisionHitPartFv(void*, s16);
void __ct__16soCollisionGroupFv(void*);
void __ct__19soCollisionHitGroupFv(void*);
void* __dt__19soCollisionHitGroupFv(void*, s16);
void* fn_27_37D3C(void*, s16);
void* fn_27_D3188(void*);
void* fn_27_86D4C(void*, s16);
void fn_27_7DC10(void*);
void __register_global_object(GlobalObject&, void*, void*);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, int, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}
class AbsoluteArrayStorage {
 void* table;
public:
 AbsoluteArrayStorage() : table(lbl_27_data_125F0) {}
};
extern "C" void* fn_27_27786C(char* self, char* arg1) {
 int category;
 const float* rodata=lbl_27_rodata_4520;
 AttackStorage* attack;
 soEventObserverRegistrationDesc* desc;
 int taskId;
 OtherStorage* other;
 int one=1;
 fn_27_262728(self,arg1,lbl_27_data_564E0,self+0x47C,self+0x658,self+0x76C,lbl_27_bss_598,lbl_27_bss_444);
 *(void**)(self+0x3C)=lbl_27_data_560B4;
 *(void**)(self+0x40)=lbl_27_data_560B4+0x64;
 *(void**)(self+0x48)=lbl_27_data_560B4+0x70;
 *(void**)(self+0x54)=lbl_27_data_560B4+0x84;
 *(void**)(self+0x64)=lbl_27_data_560B4+0xDC;
 taskId=*(int*)(self+0x28);
 category=(*(unsigned int*)(self+0x2C)>>7)&0xFF;
 attack=(AttackStorage*)(self+0x358);
 desc=lbl_27_data_54C60;
 {
 soCollisionAttackPart part((soCollision::Category)6,false);
 *(void**)attack=lbl_27_data_3E748;
 attack->calc=lbl_27_data_3E748+0x48;
 attack->flags &= 0x01FFFFFF;
 __construct_array(attack->parts,(void(*)(void*))__ct__21soCollisionAttackPartFv,(void(*)(void*))__dt__21soCollisionAttackPartFv,0x90,1);
 int count=resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&attack->calc,1,attack->slot4(),attack->slot14(),attack->slot13(),attack->slot27(),attack->slot28());
 for(int i=0;i<count;++i) attack->slot10(&part);
 }
 attack->groupVptr=lbl_27_data_46F8;
 attack->groupCalc=lbl_27_data_46F8+0x48;
 attack->groupFlags.a=0; attack->groupFlags.b=one; attack->groupFlags.c=0;
 __construct_array(attack->groups,(void(*)(void*))__ct__16soCollisionGroupFv,(void(*)(void*))fn_27_37D3C,0x78,1);
 postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&attack->groupCalc,1,1);
 PaddedData data(rodata[1]);
 soArray<soCollisionAttackAbsolute>* absolutes=(soArray<soCollisionAttackAbsolute>*)new (&attack->absoluteVptr) AbsoluteArrayStorage;
 new(attack->impl) soCollisionAttackModuleImpl((soModuleAccesser*)(self+0xA8),taskId,(gfTask::Category)category,(soArray<soCollisionAttackPart>*)attack,(soArray<soCollisionGroup>*)&attack->groupVptr,absolutes,desc,true);
 soEventObserverRegistrationDesc* hitDesc;
 HitStorage* hit;
 int hitCategory;
 int hitId;
 hitDesc=lbl_27_data_54C60;
 hit=(HitStorage*)(self+0x51C);
 hitId=*(int*)(self+0x28);
 hitCategory=(*(unsigned int*)(self+0x2C)>>7)&0xFF;
 {
 soCollisionHitPart part((soCollision::Category)6,0x3FF);
 *(void**)hit=lbl_27_data_39430;
 hit->calc=lbl_27_data_39430+0x48;
 hit->flags &= 0x01FFFFFF;
 __construct_array(hit->parts,(void(*)(void*))__ct__18soCollisionHitPartFv,(void(*)(void*))__dt__18soCollisionHitPartFv,0x68,1);
 int count=resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&hit->calc,1,hit->slot4(),hit->slot14(),hit->slot13(),hit->slot27(),hit->slot28());
 for(int j=0;j<count;++j) hit->slot10(&part);
 }
 hit->groupVptr=lbl_27_data_46F8;
 hit->groupCalc=lbl_27_data_46F8+0x48;
 hit->groupFlags.a=0; hit->groupFlags.b=one; hit->groupFlags.c=0;
 __construct_array(hit->groups,(void(*)(void*))__ct__16soCollisionGroupFv,(void(*)(void*))fn_27_37D3C,0x78,1);
 postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&hit->groupCalc,1,1);
 hit->hitGroupVptr=lbl_27_data_1E0A0;
 hit->hitGroupCalc=lbl_27_data_1E0A0+0x48;
 hit->hitGroupFlags.a=0; hit->hitGroupFlags.b=one; hit->hitGroupFlags.c=0;
 __construct_array(hit->hitGroups,(void(*)(void*))__ct__19soCollisionHitGroupFv,(void(*)(void*))__dt__19soCollisionHitGroupFv,0x38,1);
 postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&hit->hitGroupCalc,1,1);
 new(hit->impl) soCollisionHitModuleImpl((soModuleAccesser*)(self+0xA8),hitId,(gfTask::Category)hitCategory,(soArray<soCollisionHitPart>*)hit,(soArray<soCollisionGroup>*)&hit->groupVptr,(soArray<soCollisionHitGroup>*)&hit->hitGroupVptr,hitDesc,true);
 soEventObserverRegistrationDesc* otherDesc=lbl_27_data_54C60;
 other=(OtherStorage*)(self+0x6C0);
 other->vptr=lbl_27_data_1A108;
 other->calc=lbl_27_data_1A108+0x48;
 other->flags.a=0; other->flags.b=one; other->flags.c=0;
 __construct_array(other->elements,(void(*)(void*))fn_27_D3188,(void(*)(void*))fn_27_86D4C,0xA0,1);
 postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&other->calc,1,1);
 if(lbl_27_bss_1088==0) {
  GlobalObject* object=new (&lbl_27_bss_108C) GlobalObject;
  __register_global_object(*object,(void*)fn_27_7DC10,lbl_27_bss_63B0);
  lbl_27_bss_1088=1;
 }
 fn_27_26F06C((char*)other+0xAC,self+0xA8,other,lbl_27_bss_5FF4,&lbl_27_bss_108C,otherDesc);
 fn_27_26320C(self);
 fn_27_2632F4(self,*(int*)(arg1+0xC),rodata[7],rodata[0]);
 return self;
}