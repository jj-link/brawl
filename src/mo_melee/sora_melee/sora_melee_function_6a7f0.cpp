#pragma force_active on
typedef unsigned int u32;

struct WorkData {
    unsigned char padding[0x30];
    u32 flags : 24;
    u32 other : 8;
};

struct Work {
    virtual void unused();
    virtual WorkData* get(u32);
};

struct Context {
    unsigned char padding[0x48];
    Work* work;
};

extern "C" void fn_27_6A7F0(Context* self, u32 index, u32 bit, u32 enabled) {
    Work* work = self->work;
    WorkData* data = work->get(index);
    if (enabled == 1) {
        data->flags |= 1 << bit;
    } else {
        data->flags &= ~(1 << bit);
    }
}
