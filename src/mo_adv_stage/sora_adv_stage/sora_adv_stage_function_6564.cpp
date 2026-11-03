#include <gf/gf_task_scheduler.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_40_data_0[];
extern char lbl_40_data_A70[];
extern char __RTTI__6gfTask[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_40_B48(const char*, ...);
}

extern "C" int fn_40_6564(void* self, unsigned long id) {
    char* base = lbl_40_data_0;
    gfTask* task = gfTaskScheduler::getInstance()->getTask(id);
    for (unsigned int i = 0; i < 5; i++) {
        if (task == 0) {
            fn_40_B48(base + 0x488, id);
            return -1;
        }
        switch (task->m_taskCategory) {
        case 10: {
            void* fighter = __dynamic_cast(task, 0x3c, lbl_40_data_A70, __RTTI__6gfTask, 0);
            int player = g_ftManager->getPlayerNo(*(int*)((char*)fighter + 0x10c));
            fn_40_B48(base + 0x4bc, player);
            return player;
        }
        case 2:
            fn_40_B48(base + 0x4f4, id);
            return -1;
        case 6:
            fn_40_B48(base + 0x52c, id);
            return -1;
        case 12:
            fn_40_B48(base + 0x568, id);
            return -1;
        case 11:
            fn_40_B48(base + 0x5a0, id);
            return -1;
        }
    }
    fn_40_B48(base + 0x5d8, id, 5);
    return -1;
}