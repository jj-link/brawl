#include <so/so_module_accesser.h>
#pragma force_active on

struct Fn28234Params {
    char pad0[0x14];
    float v14;
    char pad1[0xc];
    float v24;
};

struct Fn28234Holder {
    char pad[0x34];
    Fn28234Params* params;
};

extern "C" {
extern const char lbl_96_data_AAD8[], lbl_96_data_68D8[];
extern const char lbl_96_data_CEF4[], lbl_96_data_5E00[];
extern const float lbl_96_rodata_570;
extern const float lbl_96_rodata_574;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Fn28234Holder* fn_96_28234(void*);
float fn_96_28A30(Vec2f*);
void fn_96_B890(void*, const Vec2f*);
}

extern "C" void fn_96_28750(void*, soModuleAccesser* accesser) {
    void* self = __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_96_data_AAD8, lbl_96_data_68D8, 1);

    if (accesser->getWorkManageModule().getInt(0x20000001) == 2) {
        Vec3f rot = accesser->m_enumerationStart->m_modelModule->getNodeRotate(1);
        float v = accesser->getWorkManageModule().getFloat(0x21000002);
        v += fn_96_28234(self)->params->v24;
        if (v > lbl_96_rodata_574) {
            v -= lbl_96_rodata_574;
        }
        rot.m_x = v;
        accesser->m_enumerationStart->m_modelModule->setNodeRotate(1, &rot);
        accesser->getWorkManageModule().setFloat(v, 0x21000002);
        return;
    }

    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0), 0, lbl_96_data_CEF4, lbl_96_data_5E00, 1));
    Vec2f speed;
    Vec2f::copy(speed, energy->getSpeed());
    float f31 = accesser->getWorkManageModule().getFloat(0x21000000);
    accesser->getPostureModule().getLr();
    float mag = fn_96_28A30(&speed);
    if (mag > f31) {
        float f2 = mag - f31;
        speed.m_x = speed.m_x * f2 / mag;
        speed.m_y = speed.m_y * f2 / mag;
    } else {
        speed.m_x = lbl_96_rodata_570;
    }
    fn_96_B890(reinterpret_cast<unsigned char*>(energy) + 8, &speed);

    Vec3f rot = accesser->m_enumerationStart->m_modelModule->getNodeRotate(1);
    float v = accesser->getWorkManageModule().getFloat(0x21000002);
    v += fn_96_28234(self)->params->v14;
    if (v > lbl_96_rodata_574) {
        v -= lbl_96_rodata_574;
    }
    rot.m_x = v;
    accesser->m_enumerationStart->m_modelModule->setNodeRotate(1, &rot);
    accesser->getWorkManageModule().setFloat(v, 0x21000002);
}
