#pragma force_active on
#include <so/work/so_work_manage_module_impl.h>
#include <so/item/so_item_manage_module_impl.h>

struct TaskBase { char pad[0x3c]; };
class Task : public TaskBase {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual int slot40();
};
struct Modules {
    char pad0[0x64];
    soWorkManageModule* work;
    char pad1[0x40];
    soItemManageModule* item;
};
struct Access {
    char pad0[8];
    Task* task;
    char pad1[0xcc];
    Modules* modules;
};
extern "C" void fn_27_3965C8(void* self, Access* accesser) {
    int var_r30 = 0;
    int var_r29 = 0;
    int var_r28 = 0;
    if (accesser->modules->work->isFlag(0x2200001a)) {
        switch (accesser->modules->work->getInt(0x20000007)) {
        case 1: var_r30 = 1; break;
        case 2: var_r28 = 1; break;
        }
    } else {
        soItemManageModule* item = accesser->modules->item;
        for (int i = 3; i < 7; i++) {
            if (item->isHaveItem(i)) {
                soItemInfo info;
                item->getHaveItemInfo(&info, i);
                if (item->getHaveItemSize(i) == 1) var_r30 = 1;
                if (info.m_trait.m_mask & 0x8000) var_r28 = 1;
                if (info.m_trait.m_mask & 0x2000) var_r29 = 1;
            }
        }
    }
    int kind = accesser->task->slot40();
    if (var_r28 != 0) {
        if (kind == 5) {
            accesser->modules->work->setInt(0x2c7, 0x20000000);
            accesser->modules->work->setInt(0x2d1, 0x20000001);
        } else {
            accesser->modules->work->setInt(0x1d4, 0x20000000);
            accesser->modules->work->setInt(0x1de, 0x20000001);
        }
    } else if (var_r30 != 0) {
        if (kind == 5) {
            accesser->modules->work->setInt(0x2c8, 0x20000000);
            accesser->modules->work->setInt(0x2d2, 0x20000001);
        } else {
            accesser->modules->work->setInt(0x1d5, 0x20000000);
            accesser->modules->work->setInt(0x1df, 0x20000001);
        }
    } else if (var_r29 != 0) {
        if (kind == 5) {
            accesser->modules->work->setInt(0x2c6, 0x20000000);
            accesser->modules->work->setInt(0x2d0, 0x20000001);
        } else {
            accesser->modules->work->setInt(0x1d3, 0x20000000);
            accesser->modules->work->setInt(0x1dd, 0x20000001);
        }
    } else if (kind == 5) {
        accesser->modules->work->setInt(0x2c9, 0x20000000);
        accesser->modules->work->setInt(0x2d3, 0x20000001);
    } else {
        accesser->modules->work->setInt(0x1d6, 0x20000000);
        accesser->modules->work->setInt(0x1e0, 0x20000001);
    }
}