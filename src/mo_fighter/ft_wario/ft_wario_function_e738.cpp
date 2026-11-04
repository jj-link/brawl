#pragma peephole on
#pragma optimization_level 1
#pragma scheduling off
#pragma opt_propagation off
#pragma opt_common_subs on
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_110_data_5F8[];
extern const unsigned char lbl_110_data_212C[];
extern const unsigned char lbl_110_data_62B8[];
extern const unsigned char lbl_110_data_6908[];
extern const unsigned char lbl_110_data_168C[];
extern const float lbl_110_rodata_60;
extern const float lbl_110_rodata_64;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_110_8C60(StageObject*);
void* fn_110_1EF78(StageObject*);
}

struct Params {
    char pad[0x10];
    float scale;
};

struct ParamRef {
    char pad[8];
    Params* params;
};

struct EnergyView {
    char pad[0x3c];
    float value;
};

extern "C" void fn_110_E738(void*, soModuleAccesser* accesser) {
    soControllerModule* controller =
        accesser->m_enumerationStart->m_controllerModule;
    soKineticModule* kinetic =
        accesser->m_enumerationStart->m_kineticModule;
    soPostureModule* posture =
        accesser->m_enumerationStart->m_postureModule;
    StageObject* object = accesser->m_stageObject;
    Params* params;

    if (object->soGetSubKind() == 0x15) {
        params = ((ParamRef*)fn_110_8C60((StageObject*)__dynamic_cast(
            object, 0x3c, lbl_110_data_5F8, lbl_110_data_212C, 1)))->params;
    } else {
        params = ((ParamRef*)fn_110_1EF78((StageObject*)__dynamic_cast(
            object, 0x3c, lbl_110_data_62B8, lbl_110_data_212C, 1)))->params;
    }

    kinetic->changeKinetic(0x12, accesser);
    float stick = controller->getStickX();
    float lr = posture->getLr();
    int lrSign = lr < lbl_110_rodata_60 ? -1 : 1;
    float direction = (float)lrSign;
    int stickSign = stick < lbl_110_rodata_60 ? -1 : 1;
    float stickDirection = (float)stickSign;

    float result;
    if (stickDirection == direction) {
        result = params->scale * stick;
    } else {
        result = lbl_110_rodata_60;
    }

    stick = lbl_110_rodata_64 * result;
    EnergyView* energy = (EnergyView*)__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_110_data_6908, lbl_110_data_168C, 1);
    energy->value = -stick;
}
