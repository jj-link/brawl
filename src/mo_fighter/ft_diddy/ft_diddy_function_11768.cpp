#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>

#pragma force_active on

extern "C" {
extern const float lbl_115_rodata_C0;
extern const char lbl_115_data_7524[], lbl_115_data_7444[], lbl_115_data_2760[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_115_C8BC(float*, const float*);
void fn_115_12240(void*, soModuleAccesser*);
void fn_115_12E60(void*, soModuleAccesser*);
void fn_115_12928(void*, soModuleAccesser*);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
};

extern "C" void fn_115_11768(void* self, soModuleAccesser* a) {
    const float* constants = &lbl_115_rodata_C0;
    switch (a->getStatusModule().getStatusKind()) {
    case 0x116:
        if (a->getWorkManageModule().isFlag(0x22000012)) {
            soKineticEnergy* e = static_cast<soKineticEnergy*>(__dynamic_cast(
                a->getKineticModule().getEnergy(3), 0,
                lbl_115_data_7444, lbl_115_data_2760, 1));
            float zero = constants[2];
            float v[2] = {zero, zero};
            e->resetEnergy(
                0x16, reinterpret_cast<Vec2f*>(v),
                fn_115_8EF8(&Vec3f(), zero, zero, zero),
                a);

            float zero1 = constants[2];
            float v1[2] = {zero1, zero1};
            fn_115_C8BC(reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x10), v1);
            float zero2 = constants[2];
            float v2[2] = {zero2, zero2};
            fn_115_C8BC(reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x18), v2);
            float zero3 = constants[2];
            float v3[2] = {zero3, zero3};
            fn_115_C8BC(reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x20), v3);
            float v4[2] = {constants[0], constants[2]};
            fn_115_C8BC(reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x28), v4);
            *(reinterpret_cast<unsigned char*>(e) + 5) |= 0x80;

            e = static_cast<soKineticEnergy*>(__dynamic_cast(
                a->getKineticModule().getEnergy(1), 0,
                lbl_115_data_7524, lbl_115_data_2760, 1));
            zero = constants[2];
            float v5[2] = {zero, zero};
            e->resetEnergy(
                0, reinterpret_cast<Vec2f*>(v5),
                fn_115_8EF8(&Vec3f(), zero, zero, zero),
                a);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x14) =
                soValueAccesser::getConstantFloat(a, 0xfbd, 0);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x1c) =
                soValueAccesser::getConstantFloat(a, 0xfbd, 0);
            *(reinterpret_cast<unsigned char*>(e) + 5) |= 0x80;

            a->getWorkManageModule().offFlag(0x22000012);
            a->getWorkManageModule().onFlag(0x22000014);
            soEffectModule& effect = a->getEffectModule();
            int id = effect.reqFollow(
                static_cast<EfID>(0xf90001), 0x12,
                fn_115_8EF8(&Vec3f(), constants[2], constants[2], constants[2]),
                fn_115_8EF8(&Vec3f(), constants[2], constants[2], constants[2]),
                constants[1], false, 6, 0, -1);
            a->getWorkManageModule().setInt(id, 0x20000001);
            a->getWorkManageModule().onFlag(0x2200001a);
        }
        break;

    case 0x12c: {
        soWorkManageModule& work = a->getWorkManageModule();
        soValueAccesser::getConstantInt(a, 0x5dc4, 0);
        work.getInt(0x20000000);
    }
    case 0x12d: {
        soKineticEnergy* e = static_cast<soKineticEnergy*>(__dynamic_cast(
            a->getKineticModule().getEnergy(1), 0,
            lbl_115_data_7524, lbl_115_data_2760, 1));
        if (e->getSpeed().m_y <= constants[2]) {
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x14) =
                soValueAccesser::getConstantFloat(a, 0xfbd, 0);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x1c) =
                soValueAccesser::getConstantFloat(a, 0xfbd, 0);
        } else {
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x14) =
                soValueAccesser::getConstantFloat(a, 0xfbe, 0);
            *reinterpret_cast<float*>(reinterpret_cast<char*>(e) + 0x1c) =
                soValueAccesser::getConstantFloat(a, 0xfbe, 0);
        }
        break;
    }

    case 0x12e:
        if (a->getWorkManageModule().isFlag(0x22000012)) {
            float value = soValueAccesser::getConstantFloat(a, 0xfce, 0);
            soKineticEnergy* e = static_cast<soKineticEnergy*>(__dynamic_cast(
                a->getKineticModule().getEnergy(1), 0,
                lbl_115_data_7524, lbl_115_data_2760, 1));
            float zero = constants[2];
            e->resetEnergy(
                0, &Vec2f(zero, value),
                fn_115_8EF8(&Vec3f(), zero, zero, zero),
                a);
            a->getWorkManageModule().offFlag(0x22000012);
        }
        break;
    }

    if (a->getWorkManageModule().isFlag(0x22000014)) {
        fn_115_12240(self, a);
        fn_115_12E60(self, a);
        fn_115_12928(self, a);
    }
    a->getAreaModule().setWhole(0);
}
