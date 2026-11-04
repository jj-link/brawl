#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#pragma force_active on

// Classes this function calls through, from the game's vtables. Keep every method in this order so
// the vtable offsets come out the same; declare parameters and return types as the code needs.

class Class_64C0 {
public:
    virtual void fn_123_FC80();  // offset 0x8
    virtual void fn_123_F0B0();  // offset 0xc
    virtual void fn_123_FC7C();  // offset 0x10
    virtual void fn_123_F1D0();  // offset 0x14
    virtual void fn_123_FC78();  // offset 0x18
    virtual void fn_123_FC74();  // offset 0x1c
    virtual void fn_123_FC70();  // offset 0x20
    virtual void fn_123_F258();  // offset 0x24
    virtual void fn_123_FC6C();  // offset 0x28
    virtual void fn_123_FC64();  // offset 0x2c
};

class Class_66D0 {
public:
    virtual void fn_123_10598();  // offset 0x8
    virtual void fn_123_10020();  // offset 0xc
    virtual void fn_123_1040C();  // offset 0x10
    virtual void fn_123_100E4();  // offset 0x14
    virtual void fn_123_FC78();  // offset 0x18
    virtual void fn_123_FC74();  // offset 0x1c
    virtual void fn_123_FC70();  // offset 0x20
    virtual void fn_123_FCC0();  // offset 0x24
    virtual void fn_123_FC6C();  // offset 0x28
    virtual void fn_123_FC64();  // offset 0x2c
};

class Class_6750 {
public:
    virtual void fn_123_107F0();  // offset 0x8
    virtual void fn_123_10630();  // offset 0xc
    virtual void fn_123_FC7C();  // offset 0x10
    virtual void fn_123_FCC4();  // offset 0x14
    virtual void fn_123_FC78();  // offset 0x18
    virtual void fn_123_FC74();  // offset 0x1c
    virtual void fn_123_FC70();  // offset 0x20
    virtual void fn_123_FCC0();  // offset 0x24
    virtual void fn_123_FC6C();  // offset 0x28
    virtual void fn_123_FC64();  // offset 0x2c
};

class Class_67C8 {
public:
    virtual void fn_123_1099C();  // offset 0x8
    virtual void fn_123_10888();  // offset 0xc
    virtual void fn_123_FC7C();  // offset 0x10
    virtual void fn_123_FCC4();  // offset 0x14
    virtual void fn_123_FC78();  // offset 0x18
    virtual void fn_123_FC74();  // offset 0x1c
    virtual void fn_123_FC70();  // offset 0x20
    virtual void fn_123_FCC0();  // offset 0x24
    virtual void fn_123_FC6C();  // offset 0x28
    virtual void fn_123_FC64();  // offset 0x2c
};

class Class_6ED4 {
public:
    virtual void fn_123_6E08();  // offset 0x8
    virtual void fn_123_12DA8();  // offset 0xc
    virtual void fn_123_13F2C();  // offset 0x10
    virtual void fn_123_13F28();  // offset 0x14
    virtual void fn_123_13F24();  // offset 0x18
    virtual void fn_123_13F20();  // offset 0x1c
    virtual void fn_123_13F18();  // offset 0x20
    virtual void fn_123_13F60();  // offset 0x24
    virtual void fn_123_13F58();  // offset 0x28
    virtual void fn_123_13F50();  // offset 0x2c
};

class Class_70AC {
public:
    virtual void fn_123_6E08();  // offset 0x8
    virtual void fn_123_12D4C();  // offset 0xc
    virtual void fn_123_14120();  // offset 0x10
    virtual void fn_123_14118();  // offset 0x14
    virtual void fn_123_14110();  // offset 0x18
    virtual void fn_123_14108();  // offset 0x1c
    virtual void fn_123_14100();  // offset 0x20
    virtual void fn_123_140F8();  // offset 0x24
    virtual void fn_123_140F0();  // offset 0x28
    virtual void fn_123_140E8();  // offset 0x2c
};

extern "C" {
extern const char lbl_123_data_1708[], lbl_123_data_1760[], lbl_123_data_7194[];
extern const float lbl_123_rodata_70;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA1F4(void*);
void fn_27_894D4(void*, unsigned int);
Vec3f* fn_123_12FF0(Vec3f*, float, float, float);
Vec3f* fn_123_13A1C(Vec3f*, const Vec3f*);
void fn_123_9574(Vec2f&, const Vec2f&);
float randf__Fv();
}

#define SONIC_ACCESS(p) (*reinterpret_cast<soModuleAccesser**>(reinterpret_cast<char*>(p) + 0x60))

extern "C" void fn_123_135D0(void* self, int state, void* a3, void* a4, soModuleAccesser* accesser) {
    soModuleAccesser* access;
    soKineticEnergy* energy;
    fn_27_1DA1F4(self);
    if (state == 1) {
        energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            SONIC_ACCESS(self)->getKineticModule().getEnergy(0), 0,
            lbl_123_data_1708, lbl_123_data_1760, 1));
        access = SONIC_ACCESS(self);

        float y4 = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        Vec2f v0;
        v0.m_x = lbl_123_rodata_70;
        v0.m_y = y4;
        Vec3f zero3;
        energy->resetEnergy(0, &v0,
            fn_123_12FF0(&zero3, lbl_123_rodata_70, lbl_123_rodata_70, lbl_123_rodata_70),
            access);

        float y5 = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        Vec2f v1;
        v1.m_x = lbl_123_rodata_70;
        v1.m_y = y5;
        fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x10), v1);

        float y6 = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
        Vec2f v2;
        v2.m_x = lbl_123_rodata_70;
        v2.m_y = y6;
        fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x18), v2);

        fn_27_894D4(&SONIC_ACCESS(self)->getKineticModule(), 0);
        soKineticEnergy* energy2 = static_cast<soKineticEnergy*>(__dynamic_cast(
            SONIC_ACCESS(self)->getKineticModule().getEnergy(1), 0,
            lbl_123_data_7194, lbl_123_data_1760, 1));

        float value = soValueAccesser::getConstantFloat(accesser, 0xfa7, 0)
            + randf__Fv() * (soValueAccesser::getConstantFloat(accesser, 0xfa8, 0)
                             - soValueAccesser::getConstantFloat(accesser, 0xfa7, 0));

        float lr = SONIC_ACCESS(self)->getPostureModule().getLr();
        int sign = lr < lbl_123_rodata_70 ? -1 : 1;
        float scaled = value * (float)sign;
        Vec3f v3(lbl_123_rodata_70, lbl_123_rodata_70, scaled);
        fn_123_13A1C(reinterpret_cast<Vec3f*>(reinterpret_cast<char*>(energy2) + 8), &v3);
        fn_27_894D4(&SONIC_ACCESS(self)->getKineticModule(), 1);
    }
    if (state == 3) {
        energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            SONIC_ACCESS(self)->getKineticModule().getEnergy(0), 0,
            lbl_123_data_1708, lbl_123_data_1760, 1));
        access = SONIC_ACCESS(self);

        float y9 = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
        Vec2f v0;
        v0.m_x = lbl_123_rodata_70;
        v0.m_y = y9;
        Vec3f zero3;
        energy->resetEnergy(0, &v0,
            fn_123_12FF0(&zero3, lbl_123_rodata_70, lbl_123_rodata_70, lbl_123_rodata_70),
            access);

        float y5 = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        Vec2f v1;
        v1.m_x = lbl_123_rodata_70;
        v1.m_y = y5;
        fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x10), v1);

        float y6 = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
        Vec2f v2;
        v2.m_x = lbl_123_rodata_70;
        v2.m_y = y6;
        fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x18), v2);

        fn_27_894D4(&SONIC_ACCESS(self)->getKineticModule(), 0);
        soKineticEnergy* energy2 = static_cast<soKineticEnergy*>(__dynamic_cast(
            SONIC_ACCESS(self)->getKineticModule().getEnergy(1), 0,
            lbl_123_data_7194, lbl_123_data_1760, 1));

        float lr = SONIC_ACCESS(self)->getPostureModule().getLr();
        int sign = lr < lbl_123_rodata_70 ? -1 : 1;
        float f31 = (float)sign;
        float k = soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
        float value = k * f31;
        Vec3f v3(lbl_123_rodata_70, lbl_123_rodata_70, value);
        fn_123_13A1C(reinterpret_cast<Vec3f*>(reinterpret_cast<char*>(energy2) + 8), &v3);
        fn_27_894D4(&SONIC_ACCESS(self)->getKineticModule(), 1);
    }
}
