#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <ft/ft_manager.h>
#include <em/em_manager.h>
#pragma force_active on
#pragma switch_tables off
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
u32 fn_41_D044(void*, u32);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern char lbl_41_data_1B48[];
extern char lbl_41_data_1630[];
}
extern "C" void fn_41_2A21C(void* self, u8* ref, void* arg2, void*)
{
    if (ref == 0) return;
    u32 id = *(u32*)(ref + 0x0C);
    if (id == 0xFFFFFFFF) return;
    ref = (u8*)gfTaskScheduler::getInstance()->getTaskById(
        (gfTask::Category)ref[0x22], id);
    if (ref == 0) return;
    u32 bits = *(u32*)(ref + 0x2C);
    gfTask::Category type =
        (gfTask::Category)((s32)((bits << 17) & 0xFF800000) >> 24);
    if (type == 6) return;
    if (type < 6) {
        if (type == 2) goto enemy_case;
        return;
    }
    if (type == 10) goto fighter_case;
    if (type < 10) return;
    return;

fighter_case: {
        ftManager* fighter = (ftManager*)__dynamic_cast(
            ref, 0x3C, lbl_41_data_1B48, lbl_41_data_1630, 1);
        s32 entry = *(s32*)((u8*)fighter + 0x10C);
        if (entry == g_ftManager->getEntryId(0)) {
            if ((void*)g_ftManager->getFighter(
                    *(s32*)((u8*)fighter + 0x10C), -1) == ref)
                *(u32*)((u8*)self + 0x30) |= 1;
            else
                *(u32*)((u8*)self + 0x30) |= 2;
            return;
        }
        entry = *(s32*)((u8*)fighter + 0x10C);
        if (entry == g_ftManager->getEntryId(1)) {
            if ((void*)g_ftManager->getFighter(
                    *(s32*)((u8*)fighter + 0x10C), -1) == ref)
                *(u32*)((u8*)self + 0x30) |= 4;
            else
                *(u32*)((u8*)self + 0x30) |= 8;
        }
        return;
    }
enemy_case: {
        void* obj = __dynamic_cast(
            *(void**)((u8*)arg2 + 8), 0x3C,
            __RTTI__5Enemy, __RTTI__11StageObject, 1);
        id = *(u32*)((u8*)obj + 0xB0);
        fn_41_D044(emManager::getInstance(), id);
        void* taskEnemy = __dynamic_cast(
            ref, 0x3C, __RTTI__5Enemy, lbl_41_data_1630, 1);
        if (id == *(u32*)((u8*)taskEnemy + 0xB0))
            *(u32*)((u8*)self + 0x30) |= 0x10;
        else
            *(u32*)((u8*)self + 0x30) |= 0x20;
        return;
    }
}
