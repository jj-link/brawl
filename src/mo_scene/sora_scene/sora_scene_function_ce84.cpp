#include <gf/gf_task.h>
#include <types.h>
#pragma force_active on

struct UnkTaskOwner {
    u8 pad[0x35C];
    gfTask* task;
};

extern "C" s32 fn_1_CE84(UnkTaskOwner* self) {
    if (self->task) {
        self->task->exit();
    }
    self->task = nullptr;
    return 0;
}
