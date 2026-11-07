#include <gf/gf_task_scheduler.h>
#include <it/it_manager.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern char lbl_41_data_1F84[];
extern char lbl_41_data_24AC[];
extern char lbl_41_data_2054[];
extern char lbl_41_data_1630[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern const float lbl_41_rodata_BE0;
extern const float lbl_41_rodata_BEC;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_5EE08(void*, float, void*, int, unsigned int, void*, void*);
unsigned int fn_27_2AC210(itManager*, unsigned int);
void fn_27_28FDEC(void*, bool);
bool fn_41_2B9D4(void*, unsigned int);
}

struct DamageModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual float damage(void*, unsigned int);
};

struct WorkModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned int);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void onFlag(unsigned int);
};

struct StatusModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void changeStatus(int, bool, bool, int);
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int isChanging();
    virtual void damageStatus(float, void*);
};

extern "C" void fn_41_12800(
    char* self, float amount, char* damage, int arg2, unsigned int arg3,
    char* arg4, char* log)
{
    if (*(unsigned char*)(log + 0x29) == 1) {
        fn_27_5EE08(self, amount, damage, arg2, arg3, arg4, log);
        return;
    }

    char* modules = *(char**)(*(char**)(self + 0x3c) + 0xd8);
    DamageModule* damageModule = (DamageModule*)__dynamic_cast(
        *(void**)(modules + 0x20), 0, lbl_41_data_1F84,
        lbl_41_data_24AC, 1);
    StatusModule* status = *(StatusModule**)(
        *(char**)(*(char**)(self + 0x3c) + 0xd8) + 0x50);
    float result = damageModule->damage(damage, arg3);

    bool stopped = false;
    if (amount <= lbl_41_rodata_BE0 && *(int*)damage > 0)
        stopped = true;

    if (result <= lbl_41_rodata_BE0 || stopped == 1) {
        if (*(int*)(self + 0xdc) != 0)
            *(int*)(self + 0xdc) = 1;
    } else {
        *(int*)(self + 0xdc) = 0;
    }

    WorkModule* work = *(WorkModule**)(
        *(char**)(*(char**)(self + 0x3c) + 0xd8) + 0x64);
    if (lbl_41_rodata_BEC == work->getFloat(0x11000001))
        amount = lbl_41_rodata_BE0;

    bool special = fn_41_2B9D4(damageModule, arg3);
    if (special == 1)
        work->onFlag(0x12000009);

    if ((*(unsigned int*)(damage + 0x30) & 0x1f) == 5)
        work->onFlag(0x1200000d);

    unsigned int id = *(unsigned int*)(log + 0x0c);
    if (id != 0xffffffff) {
        if (fn_27_2AC210(itManager::getInstance(), id) == 1) {
            work->onFlag(0x12000012);
            gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
                (gfTask::Category)*(unsigned char*)(log + 0x22), id);
            if (task != 0 &&
                ((int)((*(unsigned int*)((char*)task + 0x2c) << 17) & 0xff800000) >> 24) == 11) {
                void* item = __dynamic_cast(
                    task, 0x3c, lbl_41_data_2054, lbl_41_data_1630, 0);
                if (item != 0)
                    fn_27_28FDEC(item, true);
            }
        }

        if (*(unsigned int*)(log + 0x0c) ==
            *(unsigned int*)((char*)__dynamic_cast(
                *(void**)(arg4 + 8), 0x3c, __RTTI__5Enemy,
                __RTTI__11StageObject, 1) + 0x28))
            work->onFlag(0x12000013);
    }

    fn_27_5EE08(self, amount, damage, arg2, arg3, arg4, log);

    if (status->isChanging() == 0) {
        if (special == 0) {
            int value = soValueAccesser::getValueInt(
                *(soModuleAccesser**)(self + 0x3c), 0x59ec, 0);
            if ((unsigned int)value == 0xffffffff)
                status->damageStatus(amount, damage);
            else
                status->changeStatus(value, false, false, 0);
        } else {
            int value = soValueAccesser::getValueInt(
                *(soModuleAccesser**)(self + 0x3c), 0x59ed, 0);
            if ((unsigned int)value == 0xffffffff)
                status->damageStatus(amount, damage);
            else
                status->changeStatus(value, false, false, 0);
        }
    }
}
