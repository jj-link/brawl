#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, u32);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13(float, u32);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Accesser { char pad[8]; void* object; char pad1[0xd8-0xc]; Modules* modules; };
struct Params { char pad[0x34]; int* value; };
extern const char lbl_27_data_7F450[];
extern const char lbl_27_data_248[];
extern float lbl_27_rodata_64D8;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" Params* fn_27_2F3AA4(void*);
extern "C" void fn_27_2F3D80(void*, Accesser* accesser) {
 Object_vptr_0* work = accesser->modules->work;
 accesser->modules->work->slot5(*fn_27_2F3AA4(__dynamic_cast(accesser->object, 0x3c, lbl_27_data_7F450, lbl_27_data_248, 1))->value, 0x10000005);
 work->slot13(lbl_27_rodata_64D8, 0x11000002);
}