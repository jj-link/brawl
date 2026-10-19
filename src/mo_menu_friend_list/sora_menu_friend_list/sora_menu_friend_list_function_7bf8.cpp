#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);

struct SelfFriendList {
    u8 pad0[0x24c4];
    s32 f24c4;
    u8 pad1[0x24ec - 0x24c8];
    void* f24ec;
};

struct TaskState {
    u8 pad0[0x104];
    s32 state;
};

extern "C" s32 fn_14_7BF8(SelfFriendList* self) {
    TaskState* task = (TaskState*)self->f24ec;
    if (task->state == 3) {
        exit__6gfTaskFv(task);
        self->f24ec = nullptr;
        return 0x12;
    }
    return self->f24c4;
}
