#pragma force_active on

#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct VectorPair {
    u32 first;
    u32 second;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, Vec2f*, Vec3f*, soModuleAccesser*);
    virtual Object_vptr_0* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual VectorPair slot13(const short&);
};

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_89DAC(int, soModuleAccesser*);
extern char lbl_27_data_13690[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7458;
}

inline void setSpeed(char* energy, const Vec2f& value) {
    *reinterpret_cast<float*>(energy + 0x08) = value.m_x;
    *reinterpret_cast<float*>(energy + 0x0c) = value.m_y;
}

inline void setAccel(char* energy, const Vec2f& value) {
    *reinterpret_cast<float*>(energy + 0x20) = value.m_x;
    *reinterpret_cast<float*>(energy + 0x24) = value.m_y;
}

extern "C" void fn_27_30FC50(void*, soModuleAccesser* accesser) {
    int state = ((WorkModule*)accesser->m_enumerationStart->m_workManageModule)->slot4(0x20000000);
    ((WorkModule*)accesser->m_enumerationStart->m_workManageModule)->slot5(state, 0x20000001);

    switch (state) {
    case 0: {
        int value = soValueAccesser::getConstantInt(accesser, 0x5dc1, 0);
        ((WorkModule*)accesser->m_enumerationStart->m_workManageModule)->slot5(value, 0x20000002);

        short one = 1;
        VectorPair copy;
        VectorPair pair = ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot13(one);
        copy = pair;
        float* speed = (float*)&copy;
        speed[0] = speed[0] / soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);

        if (((Object_vptr_0*)accesser->m_enumerationStart->m_situationModule)->slot3() == 2) {
            Object_vptr_0* energy = (Object_vptr_0*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(3),
                0, lbl_27_data_13690, lbl_27_data_CDF8, 1);

            Vec2f v2;
            Vec3f v3;
            float zero = lbl_27_rodata_7458;
            float x = speed[0];
            v2.m_x = x;
            v3.m_x = zero;
            v3.m_y = zero;
            v3.m_z = zero;
            v2.m_y = zero;
            energy->slot5(6, &v2, &v3, accesser);

            setAccel((char*)energy,
                Vec2f(soValueAccesser::getConstantFloat(accesser, 0xfa7, 0),
                      lbl_27_rodata_7458));
            *((u8*)energy + 5) |= 0x80;

            char* gravity = (char*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(1),
                0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
            *(float*)(gravity + 0x0c) = lbl_27_rodata_7458;
            *(float*)(gravity + 0x10) = lbl_27_rodata_7458;
            *((u8*)gravity + 5) |= 0x80;
        } else {
            char* energy = (char*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(3),
                0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
            setSpeed(energy, Vec2f(speed[0], lbl_27_rodata_7458));
        }

        fn_27_89DAC(2, accesser);
        fn_27_89DAC(0, accesser);
        break;
    }

    case 2: {
        int value = soValueAccesser::getConstantInt(accesser, 0x5dc2, 0);
        ((WorkModule*)accesser->m_enumerationStart->m_workManageModule)->slot5(value, 0x20000002);

        if (((Object_vptr_0*)accesser->m_enumerationStart->m_situationModule)->slot3() == 2) {
            char* energy = (char*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(3),
                0, lbl_27_data_13690, lbl_27_data_CDF8, 1);

            setAccel(energy,
                Vec2f(soValueAccesser::getConstantFloat(accesser, 0xfac, 0),
                      lbl_27_rodata_7458));

            float lr = ((Object_vptr_0*)accesser->m_enumerationStart->m_postureModule)->slot9();
            float speed = soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
            speed *= lr;
            setSpeed(energy, Vec2f(speed, lbl_27_rodata_7458));
            *((u8*)energy + 5) |= 0x80;

            char* gravity = (char*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(1),
                0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
            *(float*)(gravity + 0x10) = lbl_27_rodata_7458;
        } else {
            char* energy = (char*)__dynamic_cast(
                ((Object_vptr_0*)accesser->m_enumerationStart->m_kineticModule)->slot6(3),
                0, lbl_27_data_13690, lbl_27_data_CDF8, 1);

            setAccel(energy,
                Vec2f(soValueAccesser::getConstantFloat(accesser, 0xfaa, 0),
                      lbl_27_rodata_7458));

            float lr = ((Object_vptr_0*)accesser->m_enumerationStart->m_postureModule)->slot9();
            float speed = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
            speed *= lr;
            setSpeed(energy, Vec2f(speed, lbl_27_rodata_7458));
            *((u8*)energy + 5) |= 0x80;
        }

        fn_27_89DAC(0, accesser);
        break;
    }

    default:
        break;
    }
}
