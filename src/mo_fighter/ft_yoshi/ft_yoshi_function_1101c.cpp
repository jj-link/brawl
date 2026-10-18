#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_98;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct VisibilityView {
    virtual void v0();
    virtual void v1();
    virtual void set(int, int);
};

struct EffectView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void reqCommon(int, float);
};

struct YoshiEnergyView {
    unsigned char pad[0x30];
    bool flag;
};

extern "C" void fn_95_1101C(void*, soModuleAccesser* accesser) {
    soSituationModule* situation = accesser->m_enumerationStart->m_situationModule;
    soKineticModule* kinetic = accesser->m_enumerationStart->m_kineticModule;
    soGroundModule* ground = accesser->m_enumerationStart->m_groundModule;

    YoshiEnergyView* energy = static_cast<YoshiEnergyView*>(__dynamic_cast(
        kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1));

    if (situation->getKind() == 0) {
        ground->setCorrect(soGroundShapeImpl::Correct_Ground, 0);
        kinetic->changeKinetic(100, accesser);
    } else {
        ground->setCorrect(soGroundShapeImpl::Correct_Air, 0);
        kinetic->changeKinetic(101, accesser);
    }

    energy->flag = true;
    reinterpret_cast<VisibilityView*>(
        accesser->m_enumerationStart->m_visibilityModule)->set(1, 1);
    reinterpret_cast<EffectView*>(
        accesser->m_enumerationStart->m_effectModule)->reqCommon(35, lbl_95_rodata_98);
    accesser->m_enumerationStart->m_workManageModule->setInt(-1, 0x20000008);
}
