#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct Owner { char pad[0x60]; soModuleAccesser* accesser; };
extern "C" void fn_27_492C(void*);
extern "C" Vec3f* fn_103_9594(Vec3f*, float, float, float);

extern "C" void fn_103_9478(Owner* owner) {
    fn_27_492C(owner);
    if (owner->accesser->m_enumerationStart->m_statusModule->getStatusKind() == 0x116) {
        soPostureModule* posture = &owner->accesser->getPostureModule();
        soModelModule* model = &owner->accesser->getModelModule();
        const Vec3f& rotation = posture->getRot(1);
        model->setNodeRotate(0x69, (Vec3f*)&rotation);
        soModuleAccesser* acc = owner->accesser;
        model = acc->m_enumerationStart->m_modelModule;
        Vec3f result;
        model->setNodeTranslate(0x69, fn_103_9594(&result,
            soValueAccesser::getConstantFloat(acc, 0xFC0, 0),
            soValueAccesser::getConstantFloat(acc, 0xFC1, 0),
            soValueAccesser::getConstantFloat(acc, 0xFC2, 0)));
    }
}