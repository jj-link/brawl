#pragma opt_propagation off
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_B8;

void* __dynamic_cast(void*, long, const void*, const void*, short);

struct Vec2f_95 {
    float x, y;
};

void fn_95_DF08(Vec2f_95*, const Vec2f_95*);
}

struct SituationView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};

struct VisibilityView {
    virtual void v0();
    virtual void v1();
    virtual void set(int, int);
};

extern "C" void fn_95_121EC(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    SituationView* situation =
        reinterpret_cast<SituationView*>(modules->m_situationModule);
    soKineticModule* kinetic = modules->m_kineticModule;
    soGroundModule* ground = modules->m_groundModule;

    if (situation->getKind() != 2) {
        ground->setCorrect(soGroundShapeImpl::Correct_Ground, 0);
        kinetic->changeKinetic(100, accesser);

        float speed = work->getFloat(0x21000007);
        void* energy = __dynamic_cast(
            kinetic->getEnergy(3), 0,
            lbl_95_data_7A88, lbl_95_data_2C38, 1);

        Vec2f_95 value = {speed, lbl_95_rodata_B8};
        fn_95_DF08(
            reinterpret_cast<Vec2f_95*>(static_cast<char*>(energy) + 0x10),
            &value);
    } else {
        ground->setCorrect(soGroundShapeImpl::Correct_Air, 0);
    }

    reinterpret_cast<VisibilityView*>(
        accesser->m_enumerationStart->m_visibilityModule)->set(1, 1);
    work->setInt(-1, 0x20000008);
}
