#include <types.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" {

extern char lbl_8059E3A0;

void fn_800F00AC() {
    gfTaskScheduler::getInstance()->getTask(&lbl_8059E3A0);
}

}
