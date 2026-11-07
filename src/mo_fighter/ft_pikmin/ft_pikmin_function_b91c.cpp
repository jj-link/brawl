#include <so/so_external_value_accesser.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void* slot1(int);
 virtual StageObject** slot2(int);
 virtual int slot3();
 virtual Vec3f slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual float slot9();
};
struct TargetBase { char pad[0x3c]; };
class Target : public TargetBase {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
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
 virtual void v16();
 virtual void v17();
 virtual void v18();
 virtual void v19();
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
 virtual void v34();
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual void v39();
 virtual void v40();
 virtual void v41();
 virtual void v42();
 virtual void v43();
 virtual void v44();
 virtual void v45();
 virtual void v46();
 virtual void v47();
 virtual void v48();
 virtual void v49();
 virtual void v50();
 virtual void v51();
 virtual void v52();
 virtual void v53();
 virtual void v54();
 virtual void v55();
 virtual void v56();
 virtual void v57();
 virtual void v58();
 virtual void v59();
 virtual void v60();
 virtual void v61();
 virtual void v62();
 virtual void v63();
 virtual void v64();
 virtual void v65();
 virtual void v66();
 virtual void v67();
 virtual void v68();
 virtual void v69();
 virtual void v70();
 virtual void v71();
 virtual void v72();
 virtual void v73();
 virtual void v74();
 virtual void v75();
 virtual void v76();
 virtual void v77();
 virtual void v78();
 virtual void v79();
 virtual void v80();
 virtual void v81();
 virtual void v82();
 virtual void v83();
 virtual void v84();
 virtual void v85();
 virtual void v86();
 virtual void v87();
 virtual void v88();
 virtual void v89();
 virtual void v90();
 virtual void v91();
 virtual void v92();
 virtual void v93();
 virtual void v94();
 virtual void v95();
 virtual void v96();
 virtual void v97();
 virtual void v98();
 virtual void v99();
 virtual void v100();
 virtual void v101();
 virtual void v102();
 virtual void v103();
 virtual void v104();
 virtual void v105();
 virtual void v106();
 virtual void v107();
 virtual void v108();
 virtual void changeStatus(int);
};
struct Bits { char pad[12]; unsigned int value : 5; unsigned int rest : 27; };
extern "C" {
void fn_113_BB50(void*);
Object_vptr_0* fn_113_24550(void*);
void fn_113_B7F0(Vec2f*, const Vec3f*);
int fn_113_100F0(void*, float);
void fn_113_24D3C(void*, Target*, Vec2f*);
void fn_113_24D34(void*, Target*, float);
void fn_113_25330(void*, Target*);
void fn_113_24D48(void*, Target*, Vec2f*);
void fn_113_25324(void*, Target*, int);
void fn_113_25120(void*, Target*, unsigned int);
unsigned int fn_113_2531C(void*, Target*);
void fn_113_24558(void*, void*);
extern const float lbl_113_rodata_C;
}
extern "C" void fn_113_B91C(unsigned char* self, int status) {
 fn_113_BB50(self);
 Object_vptr_0* list = fn_113_24550(self + 0x1fd08);
 int count = list->slot3();
 if (count > 0) {
  Vec3f pos = (*(soModuleAccesser**)(self + 0x60))->getPostureModule().getPos();
  Vec2f pos2;
  fn_113_B7F0(&pos2, &pos);
  int kind = fn_113_100F0(*(void**)(self + 0x60), lbl_113_rodata_C);
  Object_vptr_0* obj = (Object_vptr_0*)(self + 0x1fe8c);
  Bits* bits = (Bits*)obj->slot1(0);
  bits->value = kind;
  float lr = (*(Object_vptr_0**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0xc))->slot9();
  for (int i = 0; i < count; ++i) {
   Target* target = (Target*)*list->slot2(i);
   if (soExternalValueAccesser::getStatusKind((StageObject*)target) == 0x33) {
    fn_113_24D3C(self + 0x1fd08, target, &pos2);
    fn_113_24D34(self + 0x1fd08, target, lr);
    fn_113_25330(self + 0x1fd08, target);
    fn_113_24D48(self + 0x1fd08, target, &pos2);
    fn_113_25324(self + 0x1fd08, target, kind);
    fn_113_25120(self + 0x1fd08, target, 0x12000004);
    if (status == 0) {
     if (fn_113_2531C(self + 0x1fd08, target) == 1)
      target->changeStatus(status);
     else
      target->changeStatus(10);
    } else {
     target->changeStatus(status);
    }
   }
  }
  fn_113_24558(self + 0x1fd08, self + 0x1fe8c);
 }
}