#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
#pragma opt_lifetimes off

#define V(n) virtual void slot##n();
class Object_vptr_0 {
public:
 V(0) V(1) V(2) V(3) V(4) V(5)
 virtual void* slot6(int);
 V(7) V(8) V(9) V(10) V(11) V(12)
 virtual void slot13(float, unsigned long);
 V(14) V(15) V(16) V(17) V(18) V(19) V(20)
 virtual void slot21(int, soModuleAccesser*);
};
#undef V
struct Modules {
 char pad[0x64];
 Object_vptr_0* work;
 char pad2[0x14];
 Object_vptr_0* kinetic;
};
struct Energy { char pad[8]; float x, y; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E380[], lbl_27_data_2E430[], lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2420;
}

extern "C" void fn_27_18026C(void*, soModuleAccesser* access) {
 Modules* modules = (Modules*)access->m_enumerationStart;
 Object_vptr_0* work = modules->work;
 Object_vptr_0* kinetic = modules->kinetic;
 float f = soValueAccesser::getConstantFloat(access, 0xd06, 0);
 float second = soValueAccesser::getConstantFloat(access, 0xbc5, 0);
 float product = second * f;
 kinetic->slot21(0, access);
 Energy* e2 = (Energy*)__dynamic_cast(kinetic->slot6(2), 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
 Energy* e1 = (Energy*)__dynamic_cast(kinetic->slot6(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
 Energy* e3 = (Energy*)__dynamic_cast(kinetic->slot6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
 e1->y = product;
 e3->x = lbl_27_rodata_2420;
 e3->y = lbl_27_rodata_2420;
 e2->x = lbl_27_rodata_2420;
 e2->y = lbl_27_rodata_2420;
 Vec2f a(lbl_27_rodata_2420, lbl_27_rodata_2420);
 Vec2f b(lbl_27_rodata_2420, lbl_27_rodata_2420);
 work->slot13(lbl_27_rodata_2420, 0x21000006);
}
