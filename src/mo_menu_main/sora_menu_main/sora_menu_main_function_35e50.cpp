#include <mu/mu_msg.h>
#pragma force_active on

extern char lbl_2_data_4518[];

struct Work {
    char pad0[0x40];
    unsigned long index;
    unsigned long timer;
    MuMsg* msg;
    float frame;
    char pad50[8];
    int state;
    char pad5c[0x10];
    MuObject* obj;
    char pad70[0x10];
    void* data;
};

extern "C" void fn_2_35E50(Work* self) {
    if (self->state != 0) {
        ++self->timer;
        switch (self->state) {
        case 1:
            if (self->timer >= 10) {
                self->msg->printIndex(0, self->index, self->data);
                self->obj->setFrameTex(self->frame);
                self->obj->setFrameMatCol(self->frame);
                self->state = 0;
            }
            break;
        case 2:
            if (self->timer >= 1) {
                self->msg->printIndex(0, self->index, self->data);
                self->obj->setFrameTex(self->frame);
                self->obj->setFrameMatCol(self->frame);
                self->state = 0;
            }
            break;
        case 3:
        case 4:
            if (self->timer >= 5) {
                if (self->state == 3) {
                    self->msg->printf(0, lbl_2_data_4518);
                } else {
                    self->msg->printIndex(0, self->index, self->data);
                }
                self->state = 0;
            }
            break;
        }
    }
}