#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct Task {
    char pad[0x100];
    unsigned char flag;
    char pad101[3];
    int state;
};

struct Menu {
    char pad[0x9c];
    int result;
    char pada0[0x45c - 0xa0];
    Task* task;
};

extern "C" int fn_16_67A0(Menu* self) {
    int status;
    Task* task = self->task;

    if (task->state != 3) {
        status = 0;
    } else {
        status = 2;
        if (task->flag) {
            status = 1;
        }
        exit__6gfTaskFv(task);
        self->task = 0;
    }

    if (status == 0) {
        return self->result;
    }
    return 0x10;
}
