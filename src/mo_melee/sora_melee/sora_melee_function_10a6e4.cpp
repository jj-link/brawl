#include <types.h>
#include <ft/ft_entry_manager.h>
#pragma force_active on
extern "C" s32 fn_27_1190D0(void*);
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual int slot41();
};
extern "C" bool fn_27_10A6E4(void* self, u32 id) {
 Object_vptr_3c* obj;
 if (fn_27_1190D0(*(ftEntryManager**)((char*)self + 0x154)) == 0) {
   obj = 0;
 } else if (*(s32*)((char*)(*(ftEntryManager**)((char*)self + 0x154))->getEntity(id) + 0x5c) == 0x10) {
   obj = *(Object_vptr_3c**)((char*)(*(ftEntryManager**)((char*)self + 0x154))->getEntity(id) + 0x3c);
 } else {
   obj = 0;
 }
 bool result = false;
 if (obj && obj->slot41()) result = true;
 return result;
}