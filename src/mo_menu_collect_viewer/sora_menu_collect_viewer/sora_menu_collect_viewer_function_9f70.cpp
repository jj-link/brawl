#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct Task {
    unsigned char pad[0x100];
    unsigned char flag;
    unsigned char pad2[3];
    int state;
};

struct Viewer {
    unsigned char pad[0x124];
    int result;
    unsigned char pad2[0x628];
    Task* task;
};

extern "C" int fn_6_9F70(Viewer* self) {
    Task* task = self->task;
    if (task->state == 3) {
        unsigned char flag = task->flag;
        exit__6gfTaskFv(task);
        self->task = 0;
        return flag ? 0xB : 7;
    }
    return self->result;
}
