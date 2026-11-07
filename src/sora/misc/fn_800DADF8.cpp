#include <gf/gf_task.h>
#pragma force_active on
struct Task : gfTask {
    char pad[0xc0];
    unsigned char flag;
    char pad2[3];
    int mode;
};
struct State {
    char pad[0x48];
    int field48;
    char pad2[4];
    int result;
    char pad3[8];
    Task* task;
};
extern "C" int fn_800DADF8(State* self) {
    int result;
    int status;
    Task* task = self->task;
    if (task == 0) {
        status = 0;
    } else if (task->mode != 3) {
        status = 1;
    } else {
        status = 3;
        if (task->flag != 0) status = 2;
    }
    switch (status) {
    case 1:
        result = self->result;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 4;
        self->field48 = 1;
        break;
    }
    if (result != self->result) {
        if (self->task != 0) {
            self->task->exit();
            self->task = 0;
        }
    }
    return result;
}