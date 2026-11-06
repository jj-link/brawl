#include <types.h>
#include <gf/gf_task.h>
#include <gf/gf_task_scheduler.h>
#include <ft/ft_manager.h>
#pragma force_active on
extern "C" {
void* fn_40_16DD8(); void* fn_40_17398(void*); void* fn_40_16634(void*, int, int);
void* fn_40_173A8(void*); int fn_40_16C20(void*, int); void* fn_40_1693C(void*, int, int);
int fn_27_8CB9C(); void* fn_27_8CD18(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_40_data_14A8[]; extern const char lbl_40_data_A70[]; extern const char __RTTI__6gfTask[];
}
struct Fn40_62A4Out { char pad[0x14]; int taskId; int flag; char tail[0x10]; };
extern "C" void fn_40_62A4(int dummy, int arg1, u32 arg2, int arg3, int arg4)
{
    void* first = fn_40_16DD8();
    void* current = fn_40_17398(first);
    fn_40_16634(current, arg1, arg3);
    void* state = fn_40_173A8(fn_40_16DD8());
    if (fn_40_16C20(state, arg1) != 0) {
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)arg4, arg2);
        void* cast = __dynamic_cast(task, 0x3c, lbl_40_data_14A8, __RTTI__6gfTask, 0);
        if (cast != 0) {
            if (arg4 == 0xa) {
                void* fighter = __dynamic_cast(cast, 0x3c, lbl_40_data_A70, lbl_40_data_14A8, 0);
                if (fighter != 0) {
                    int player = g_ftManager->getPlayerNo(*(int*)((char*)fighter + 0x10c));
                    if (player != -1) { fn_40_1693C(state, arg1, player); *((u8*)state + 0x58) = 1; }
                    else *((u8*)state + 0x58) = 0;
                }
            } else if ((u32)(arg4 - 0xb) <= 1) {
                int player = g_ftManager->getPlayerNo(g_ftManager->getEntryIdFromTaskId(fn_27_8CB9C(), 0));
                if (player != -1) { fn_40_1693C(state, arg1, player); *((u8*)state + 0x58) = 1; }
                else *((u8*)state + 0x58) = 0;
            } else {
                Fn40_62A4Out out;
                fn_27_8CD18(cast, &out);
                if (out.flag == 0) {
                    gfTask* fighterTask = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category_Fighter, out.taskId);
                    void* fighter = __dynamic_cast(fighterTask, 0x3c, lbl_40_data_A70, __RTTI__6gfTask, 0);
                    if (fighter != 0) {
                        int player = g_ftManager->getPlayerNo(*(int*)((char*)fighter + 0x10c));
                        if (player != -1) { fn_40_1693C(state, arg1, player); *((u8*)state + 0x58) = 1; }
                        else *((u8*)state + 0x58) = 0;
                    }
                } else {
                    int entry = g_ftManager->getEntryIdFromTaskId(((int (*)(void*))fn_27_8CB9C)(cast), 0);
                    if (entry != -1) { fn_40_1693C(state, arg1, g_ftManager->getPlayerNo(entry)); *((u8*)state + 0x58) = 1; }
                    else *((u8*)state + 0x58) = 0;
                }
            }
        } else *((u8*)state + 0x58) = 0;
    }
}
