#include <ft/ft_common_data_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
#pragma always_inline on
#pragma inline_depth(8)

struct ZeldaSpeed {
    float m_x;
    float m_y;
};

class Situation {
public:
    virtual ~Situation();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind(void*);
};

class Object_vptr_0 {
public:
    virtual void fn_104_7930();
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
    virtual int slot17(int);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual ZeldaSpeed getSumSpeed(const short&);
};

class StopEnergy {
public:
    virtual void v0();
    virtual void v1();
    virtual ZeldaSpeed getSpeed();
};

struct Modules {
    char pad0[0x14];
    Situation* situation;
    char pad1[0x4C];
    Object_vptr_0* module;
    char pad2[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
extern const char lbl_104_data_72B4[];
extern const float lbl_104_rodata_50;
extern const float lbl_104_rodata_54;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_104_CDE4(ZeldaSpeed*, const ZeldaSpeed*);
void* __memcpy(void*, const void*, unsigned long);
}

inline Situation* getSituation(Modules* modules, Kinetic*& kinetic) {
    Situation* situation = modules->situation;
    kinetic = modules->kinetic;
    return situation;
}

extern "C" void fn_104_EC4C(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Object_vptr_0* module = modules->module;
    Kinetic* kinetic;

    if (getSituation(modules, kinetic)->getKind(modules) != 0) {
        char* stop = (char*)__dynamic_cast(
            kinetic->getEnergy(3), 0,
            lbl_104_data_7138, lbl_104_data_2404, 1);
        char* gravity = (char*)__dynamic_cast(
            kinetic->getEnergy(1), 0,
            lbl_104_data_72B4, lbl_104_data_2404, 1);

        short mask = 1;
        ZeldaSpeed result;
        ZeldaSpeed speed = kinetic->getSumSpeed(mask);
        __memcpy(&result, &speed, sizeof(result));

        if (module->slot17(0x22000011)) {
            char* data = (char*)g_ftCommonDataAccesser.getData(
                static_cast<ftKind>(13));
            char* data84 = *(char**)(data + 0x84);
            char* params = (char*)g_ftCommonDataAccesser.getParam(
                static_cast<ftKind>(13));

            *(float*)(gravity + 0xC) = result.m_y;
            gravity[5] |= 0x80;

            float limit = *(float*)(params + 0x7C) *
                          *(float*)(data84 + 0x24);
            if (result.m_x < -limit) {
                result.m_x = -limit;
            } else if (result.m_x > limit) {
                result.m_x = limit;
            }

            result.m_y = lbl_104_rodata_50;
            *(ZeldaSpeed*)(stop + 8) = result;
        } else {
            ZeldaSpeed current = ((StopEnergy*)stop)->getSpeed();
            result.m_x = current.m_x;
            double y = current.m_y;
            result.m_y = (float)y - (float)y / lbl_104_rodata_54;
            fn_104_CDE4((ZeldaSpeed*)(stop + 8), &result);
        }
    }
}
