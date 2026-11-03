#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <st/stage.h>
#pragma force_active on

struct Enemy : StageObject {
    char pad[0xdc - 0x64];
    soModuleAccesser accesser;
};

extern "C" {
extern Stage* lbl_27_bss_5668;
extern const float lbl_41_rodata_18;
extern const float lbl_41_rodata_30;
}

extern "C" void fn_41_5970(Enemy* self, int unused, EfID effect) {
    soModelModule* model = self->accesser.m_enumerationStart->m_modelModule;
    Vec3f pos = model->getNodeGlobalPosition(
        soValueAccesser::getValueInt(&self->accesser, 0x59e6, 0), false);
    soValueAccesser::getConstantFloat(&self->accesser, 0xbe5, 0);
    bool flag = false;
    float angle = self->accesser.m_enumerationStart->m_effectModule->getDeadEffectRotZ(&pos, &flag);
    float scale = lbl_27_bss_5668->getEnemyDeadEffectSizeRate();
    if (flag == true) {
        scale *= soValueAccesser::getConstantFloat(&self->accesser, 0xbe6, 0);
    }
    Vec3f rot;
    rot.m_x = lbl_41_rodata_18;
    rot.m_y = lbl_41_rodata_18;
    rot.m_z = lbl_41_rodata_30 * angle;
    self->accesser.m_enumerationStart->m_effectModule->req(effect, &pos, &rot, scale, 0, -1);
}