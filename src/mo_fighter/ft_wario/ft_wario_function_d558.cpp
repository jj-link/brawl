#pragma force_active on
struct Event { int kind; bool flag; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual int slot9(int); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(int, Event*);
};
struct FighterBase { char pad[0x3c]; };
struct Fighter : FighterBase {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
 virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
 virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
 virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39(); virtual int kind();
};
struct Modules { char pad[0x54]; Object_vptr_0* obj; };
struct Access { char pad[8]; Fighter* fighter; char pad2[0xcc]; Modules* modules; };
struct Param { char pad[8]; float low; float high; };
struct Data { void* pad; Param* params; };
struct Input { char pad[0xc]; float value; };
extern "C" {
extern char lbl_110_data_5F8[], lbl_110_data_212C[], lbl_110_data_62B8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Data* fn_110_8C60(void*);
Data* fn_110_1EF78(void*);
int fn_110_D558(void*, Access* a, Input* input) {
 Object_vptr_0* obj = a->modules->obj;
 if (!obj->slot9(6)) return 0;
 Fighter* fighter = a->fighter;
 Param* p;
 if (fighter->kind() == 0x15)
  p = fn_110_8C60(__dynamic_cast(fighter, 0x3c, lbl_110_data_5F8, lbl_110_data_212C, short(1)))->params;
 else
  p = fn_110_1EF78(__dynamic_cast(fighter, 0x3c, lbl_110_data_62B8, lbl_110_data_212C, short(1)))->params;
 if (input->value <= p->high) return 1;
 if (input->value < p->low) {
  Event event;
  event.kind = 0x459;
  event.flag = false;
  obj->slot15(6, &event);
  return 1;
 }
 return 0;
}
}