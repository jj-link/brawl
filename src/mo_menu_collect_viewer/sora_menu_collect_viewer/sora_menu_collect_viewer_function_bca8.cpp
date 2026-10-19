#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct gfTask {
    u8 pad[0x104];
    s32 type;
};

struct CollectViewer {
    u8 pad128[0x128];
    s32 state;
    u8 pad12C[0x140 - 0x12C];
    gfTask* task;
};

extern "C" void exit__6gfTaskFv(void*);

extern "C" s32 fn_6_BCA8(CollectViewer* self) {
    if (self->task->type == 3) {
        exit__6gfTaskFv(self->task);
        self->task = 0;
        return 0xc;
    }
    return self->state;
}
