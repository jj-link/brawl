#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <it/it_manager.h>
#include <it/item.h>
#include <math.h>

extern "C" {
extern const float lbl_117_rodata_7C;
extern const float lbl_117_rodata_80[];
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
void fn_27_28E108(BaseItem*, float, Vec3f*, float);
}

// Create and then launch the item requested by Dedede's status work flags.
extern "C" void fn_117_10778(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000000) != 3)
        return;
    if (accesser->getWorkManageModule().isFlag(0x22000012) &&
        accesser->getWorkManageModule().getInt(0x20000000) == 3) {
        int taskId = accesser->m_stageObject->m_taskId;
        BaseItem* item = itManager::getInstance()->createItem(
            static_cast<itKind>(9), 0, taskId, 0, 0, 0xFFFF, 0, 0xFFFF);
        if (item) {
            item->have(accesser->m_stageObject->m_taskId, 0x36, -1);
            if (item->isHaved() == true) {
                accesser->getWorkManageModule().setInt(item->m_instanceId, 0x20000001);
                accesser->getWorkManageModule().onFlag(0x22000017);
            }
        }
        accesser->getWorkManageModule().offFlag(0x22000011);
        accesser->getWorkManageModule().offFlag(0x22000012);
    }
    if (accesser->getWorkManageModule().isFlag(0x22000013)) {
        if (accesser->getWorkManageModule().isFlag(0x22000017)) {
            soGroundModule* ground;
            int instanceId = accesser->getWorkManageModule().getInt(0x20000001);
            BaseItem* item = itManager::getInstance()->getItemFromInstanceId(instanceId);
            float speed;
            if (accesser->getWorkManageModule().isFlag(0x22000014)) {
                float multiplier = soValueAccesser::getConstantFloat(accesser, 0xFAB, 0);
                speed = soValueAccesser::getConstantFloat(accesser, 0xFAA, 0);
                speed *= multiplier;
            } else {
                speed = soValueAccesser::getConstantFloat(accesser, 0xFAA, 0);
            }
            float vertical;
            float angle = lbl_117_rodata_7C * accesser->getWorkManageModule().getFloat(0x21000004);
            float lr = accesser->getPostureModule().getLr();
            ground = accesser->m_enumerationStart->m_groundModule;
            vertical = static_cast<float>(sin(angle));
            float horizontal = static_cast<float>(cos(angle));
            Vec3f velocity;
            fn_117_92AC(&velocity, lr * (speed * horizontal), speed * vertical, ground->getZ());
            if (item)
                fn_27_28E108(item, lr, &velocity, lbl_117_rodata_80[0]);
        }
        accesser->getWorkManageModule().offFlag(0x22000017);
        accesser->getWorkManageModule().offFlag(0x22000013);
    }
}
