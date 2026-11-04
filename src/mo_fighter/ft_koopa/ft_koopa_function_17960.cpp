#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/so_external_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" {
extern const char lbl_102_data_5D8C[], lbl_102_data_14F4[], lbl_102_data_1F48[], lbl_102_data_204C[], lbl_102_data_1718[];
extern const float lbl_102_rodata_70;
void* __dynamic_cast(void*, long, const void*, const void*, short);
soDamageModule* fn_27_14D468(void*);
void fn_102_B024(void*, const Vec2f*);
}

extern "C" void fn_102_17960(void*, soModuleAccesser* accesser) {
    const float* p = *reinterpret_cast<const float**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x30))) + 0x8c);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(accesser->m_enumerationStart->m_kineticModule->getEnergy(3), 0, lbl_102_data_5D8C, lbl_102_data_14F4, 1));
    Vec2f speed;
    __memcpy(&speed, &energy->getSpeed(), sizeof(speed));
    float result = lbl_102_rodata_70;
    if (accesser->m_enumerationStart->m_linkModule->isLinked(0) == 1) {
        gfTaskScheduler* scheduler = gfTaskScheduler::getInstance();
        gfTask* task = scheduler->getTask((u32)accesser->m_enumerationStart->m_linkModule->getNodeTaskId(0));
        StageObject* object = static_cast<StageObject*>(__dynamic_cast(task, 0x3c, lbl_102_data_1F48, lbl_102_data_204C, 0));
        if (object) {
            float stick = soExternalValueAccesser::getModuleAccesser(object)->m_enumerationStart->m_controllerModule->getStickX();
            float damage = lbl_102_rodata_70;
            void* fighter = __dynamic_cast(task, 0x3c, lbl_102_data_1718, lbl_102_data_204C, 0);
            if (fighter) damage = fn_27_14D468(fighter)->getDamage(0);
            float scale = p[5] - p[6] * damage;
            if (scale < p[7]) scale = p[7];
            result += stick * scale;
        }
    }
    float stick = accesser->m_enumerationStart->m_controllerModule->getStickX();
    float scale = p[2] - p[3] * accesser->m_enumerationStart->m_damageModule->getDamage(0);
    if (scale < p[4]) scale = p[4];
    result += stick * scale;
    if (result > p[8]) result = p[8];
    else if (result < -p[8]) result = -p[8];
    speed.m_x += result;
    if (speed.m_x > p[9]) speed.m_x = p[9];
    else if (speed.m_x < -p[9]) speed.m_x = -p[9];
    fn_102_B024(reinterpret_cast<char*>(energy) + 8, &speed);
}