#include <it/it_manager.h>
#include <ft/ft_owner.h>
#pragma force_active on

class Class_83BC {
public:
    virtual void fn_115_672C();
    virtual void fn_115_15440();
    virtual void fn_115_17334();
    virtual void fn_115_1732C();
    virtual void fn_115_17324();
    virtual void fn_115_1731C(int, unsigned int);
    virtual void fn_115_17314();
    virtual void fn_115_1730C();
    virtual void fn_115_17304();
    virtual void fn_115_172FC();
    virtual void fn_115_172F4();
    virtual void fn_115_172EC();
    virtual void fn_115_172E4();
    virtual void fn_115_172DC();
    virtual void fn_115_1728C();
    virtual void fn_115_172D4();
    virtual void fn_115_172C4();
    virtual bool fn_115_172B4(unsigned int);
    virtual void fn_115_172A4(unsigned int);
    virtual void fn_115_17294(unsigned int);
};

class Class_A860 {
public:
    virtual void fn_115_1B904();
    virtual void fn_115_1B73C();
    virtual void fn_115_1B748();
    virtual void fn_115_1B810();
    virtual void fn_115_1B85C();
    virtual void fn_115_1B864();
    virtual void fn_115_1B86C();
    virtual void fn_115_1B874();
    virtual void fn_115_1B87C();
    virtual void fn_115_1B888();
    virtual void fn_115_1B890();
    virtual void fn_115_1B898();
    virtual void fn_115_1B8A0();
    virtual void fn_115_1B8A4(int, unsigned int, unsigned int);
    virtual void fn_115_1B8A8();
    virtual void fn_115_1B8AC();
    virtual void fn_115_1B8B0();
    virtual void fn_115_1B8BC();
    virtual void fn_115_1B8C0();
    virtual void fn_115_11408();
};

extern "C" {
extern const char lbl_115_data_2984[], lbl_115_data_3200[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_115_E7B0(void*, soModuleAccesser* accesser)
{
    if (accesser->getWorkManageModule().isFlag(0x22000015)) {
        if (accesser->getWorkManageModule().isFlag(0x22000013)) {
            int taskId = accesser->m_stageObject->m_taskId;
            itManager* manager = itManager::getInstance();
            BaseItem* item = manager->createItem((itKind)2, 0, taskId, 0, 0, 0xFFFF, 0, 0xFFFF);
            if (item) {
                item->have(accesser->m_stageObject->m_taskId, 0x39, -1);
                if (item->isHaved() == true) {
                    accesser->getWorkManageModule().setInt(item->m_instanceId, 0x20000000);
                    accesser->getWorkManageModule().onFlag(0x22000014);
                    static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3C, lbl_115_data_2984, lbl_115_data_3200, 1))->getOwner()->addLogInt(1, 0x1D, 0);
                }
            }
            accesser->getWorkManageModule().offFlag(0x22000013);
        }
    }
}
