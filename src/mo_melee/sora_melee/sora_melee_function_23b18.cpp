#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern const float lbl_27_rodata_388;
class Object_vptr_0 { public: virtual void slot0(); virtual float* slot1(); };
class Object_vptr_0_with_arg { public: virtual void slot0(); virtual float* slot1(int); };
struct Self { char pad[0x5c]; Object_vptr_0* mod; };
extern "C" void fn_27_23B18(Self* self, int arg) {
    Vec3f a(lbl_27_rodata_388, lbl_27_rodata_388, lbl_27_rodata_388);
    float* p = self->mod->slot1();
    *(Vec3f*)&p[0] = a;
    *(Vec3f*)&p[6] = *(Vec3f*)&p[3] = a;
    Vec3f b(lbl_27_rodata_388, lbl_27_rodata_388, lbl_27_rodata_388);
    Object_vptr_0* m = self->mod;
    float* q = ((Object_vptr_0_with_arg*)m)->slot1(arg);
    *(Vec3f*)&q[9] = b;
}