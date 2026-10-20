#include <types.h>
#pragma force_active on

class gfTask;

extern "C" {
extern void* lbl_27_bss_F8;
void __dt__6gfTaskFv(void* self, int flag);
void __dl__FPv(void* p);

void* fn_27_64AF0(gfTask* task, int flag) {
    if (task) {
        lbl_27_bss_F8 = 0;
        __dt__6gfTaskFv(task, 0);
        if (flag > 0) {
            __dl__FPv(task);
        }
    }
    return task;
}
}
