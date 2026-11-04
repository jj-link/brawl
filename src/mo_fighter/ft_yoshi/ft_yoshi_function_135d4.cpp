#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on
extern "C" {
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_2C38[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct GroundSecondaryView {
    int pad[2];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void setSlot54(int a, int b);
};
extern "C" void fn_95_135D4(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
    soWorkManageModule* work = enumeration->m_workManageModule;
    soSituationModule* situation = enumeration->m_situationModule;
    soKineticModule* kinetic = enumeration->m_kineticModule;
    GroundSecondaryView* ground = static_cast<GroundSecondaryView*>(static_cast<void*>(enumeration->m_groundModule));
    float* params = *(float**)((char*)g_ftCommonDataAccesser.getData((ftKind)4) + 0x80);

    if (situation->getKind() == 0) {
        ground->setSlot54(1, 0);
        kinetic->changeKinetic(6, accesser);
        return;
    }

    float f31;
    if ((float)work->getInt(0x10000040) >= params[4]) {
        f31 = 0.0f;
    } else {
        float f1;
        if (work->getInt(0x10000040) == 0) {
            f1 = params[0];
        } else {
            f1 = work->getFloat(0x11000013);
        }
        f31 = f1;
    }

    ground->setSlot54(5, 0);
    kinetic->changeKinetic(0xA, accesser);

    char* energy = (char*)__dynamic_cast(kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1);
    float f1 = params[2];
    if (0.0f != f31) {
        *(float*)(energy + 0xC) = f31;
        if (f1 < f31) {
            f1 = f31;
        }
    }
    *(float*)(energy + 0x10) = -params[1];
    *(float*)(energy + 0x14) = params[2];
    *(float*)(energy + 0x1C) = f1;

    f31 = f31 * params[3];
    work->setFloat(f31, 0x11000013);
    work->incInt(0x10000040);
}
