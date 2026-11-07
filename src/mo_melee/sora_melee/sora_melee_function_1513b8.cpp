#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
virtual void slot36(); virtual void slot37(); virtual void slot38(int, float);
};
struct Mid { char pad[0x88]; Object_vptr_0* obj; };
struct Owner { char pad[0xd8]; Mid* mid; };
struct Arg { char pad[0x30]; unsigned int flags; };
extern const float lbl_27_rodata_1E58;
extern "C" void fn_27_1513B8(void* self, Owner* owner, int x, Arg* arg) {
 switch (arg->flags & 31) {
 case 5: owner->mid->obj->slot38(x + 3, lbl_27_rodata_1E58); return;
 case 3: owner->mid->obj->slot38(x + 7, lbl_27_rodata_1E58); return;
 case 19: owner->mid->obj->slot38(x + 11, lbl_27_rodata_1E58); return;
 case 21: owner->mid->obj->slot38(x + 15, lbl_27_rodata_1E58); return;
 default: owner->mid->obj->slot38(2, lbl_27_rodata_1E58); return;
 case 9: case 10: return;
 }
}