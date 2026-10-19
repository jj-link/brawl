#pragma force_active on
struct gfTask {
    void exit();
};

struct TaskHolder {
    char pad[8];
    gfTask* task;
};

extern "C" int fn_1_B384(TaskHolder* self) {
    self->task->exit();
    self->task = 0;
    return 0;
}
