#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
extern float lbl_27_rodata_24BC;
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3();
virtual void slot4(); virtual void slot5(int, Vec2f*, Vec3f*, void*); virtual void* slot6(int); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
virtual signed char slot24(); virtual void slot25(); virtual void slot26(); virtual unsigned char slot27();
};
struct Modules { char pad00[0x14]; Object_vptr_0* status; char pad18[0x44]; Object_vptr_0* ground; char pad60[0x1c]; Object_vptr_0* energy; };
struct Self { char pad00[0xd8]; Modules* modules; };
extern "C" void fn_27_1862A4(Self* self, Object_vptr_0* target) {
    self = (Self*)target;
    Object_vptr_0* ground = self->modules->ground;
    target = (Object_vptr_0*)__dynamic_cast(self->modules->energy->slot6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    Object_vptr_0* current;
    Vec2f xy(lbl_27_rodata_24BC, lbl_27_rodata_24BC);
    int succeeded = 1;
    float value = soValueAccesser::getValueFloat((soModuleAccesser*)self, 0xC32, 0);
    if (soValueAccesser::getValueFloat((soModuleAccesser*)self, 0x3F5, 0) >= value) {
        current = self->modules->ground;
        int limit = soValueAccesser::getConstantInt((soModuleAccesser*)self, 0x5A04, 0);
        if ((int)current->slot27() < limit && ground->slot24() == -1) {
            xy.m_x = -soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xD64, 0);
            xy.m_y = lbl_27_rodata_24BC;
            ground->slot14();
            goto complete;
        }
    }
    value = soValueAccesser::getValueFloat((soModuleAccesser*)self, 0xC32, 0);
    if (soValueAccesser::getValueFloat((soModuleAccesser*)self, 0x3F5, 0) >= value) {
        Object_vptr_0* current = self->modules->ground;
        int limit = soValueAccesser::getConstantInt((soModuleAccesser*)self, 0x5A04, 0);
        if ((int)current->slot27() < limit && ground->slot24() == 1) {
            xy.m_x = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xD64, 0);
            xy.m_y = lbl_27_rodata_24BC;
            ground->slot14();
            goto complete;
        }
    }
    succeeded = 0;
complete:
    if (succeeded) {
        if (self->modules->status->slot3() == 2) {
            Vec3f out(lbl_27_rodata_24BC, lbl_27_rodata_24BC, lbl_27_rodata_24BC);
            target->slot5(6, &xy, &out, self);
        } else {
            Vec3f out(lbl_27_rodata_24BC, lbl_27_rodata_24BC, lbl_27_rodata_24BC);
            target->slot5(0, &xy, &out, self);
        }
    }
}