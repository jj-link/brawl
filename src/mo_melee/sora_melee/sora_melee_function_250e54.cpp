#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void exit__6gfTaskFv(void*);

struct gfTaskLike {
    char pad[0x40];
    s32 m_state;
};

struct OwnerObj {
    char pad[0xcc];
    gfTaskLike* m_task;
};

extern "C" u32 fn_27_250E54(OwnerObj* self) {
    gfTaskLike* task = self->m_task;
    if (task == 0) {
        return 0;
    }
    u32 isDone = (task->m_state - 12) == 0;
    if (isDone == 1 && task != 0) {
        exit__6gfTaskFv(task);
        self->m_task = 0;
    }
    return isDone;
}
