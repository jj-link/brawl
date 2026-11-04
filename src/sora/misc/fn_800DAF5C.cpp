#include <gf/gf_task.h>
#pragma force_active on

struct Data {
    char pad[0xa0];
    int mode;
    char pad2[0x4c];
    int busy;
};
struct State {
    char pad[0x50];
    int result;
    char pad2[8];
    gfTask* task;
    Data* data;
    int timer;
    int field68;
    unsigned char field6c;
};
extern "C" int fn_800DAF5C(State* self) {
    Data* data = self->data;
    int result = self->result;
    if (data->busy == 0) {
        if (--self->timer <= 0) {
            switch (data->mode) {
            case 0:
                result = 0;
                self->field6c = 1;
                break;
            case 1:
                result = 3;
                self->field68 = 0;
                break;
            case 2:
                result = 3;
                self->field68 = 1;
                break;
            }
            if (self->task != 0) {
                self->task->exit();
                self->task = 0;
            }
        }
    }
    return result;
}