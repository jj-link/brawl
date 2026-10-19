#pragma force_active on
typedef unsigned char u8;

struct Task {
    u8 pad000[0x100];
    u8 byte100;
    u8 pad101[3];
    int state104;
    u8 pad108[0x20];
};

struct Holder {
    u8 pad000[0x128];
    void* f128;
    u8 pad12C[0x140 - 0x12C];
    Task* task140;
};

extern "C" {
void exit__6gfTaskFv(void*);

int fn_6_B8A4(Holder* self) {
    Task* task = self->task140;
    int ret;
    if (task->state104 == 3) {
        u8 status = task->byte100;
        exit__6gfTaskFv(task);
        self->task140 = 0;
        ret = status ? 7 : 1;
    } else {
        ret = (int)self->f128;
    }
    return ret;
}
}
