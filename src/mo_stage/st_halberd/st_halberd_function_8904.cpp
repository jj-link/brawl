#pragma force_active on
extern "C" const float lbl_57_rodata_260;
extern "C" unsigned char lbl_57_data_1CF0[];

struct TaskData {
    unsigned int unk0;
    unsigned int flags;
};

struct Task {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void setup(int, int);

    TaskData* data;
    unsigned int state;
};

struct Object {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x90];
    Task task;
    unsigned char padDC[0x84];
    unsigned int field160;
    unsigned int field164;
    unsigned char field168;
    unsigned char pad169[3];
    float field16C;
    float field170;
    unsigned char field174;
    unsigned char field175;
    unsigned char pad176[2];
    unsigned int field178;
    int field17C;
};

extern "C" void fn_57_3980(Object*);

extern "C" Object* fn_57_8904(Object* self) {
    fn_57_3980(self);
    self->vtable = lbl_57_data_1CF0;
    self->field160 = 0;
    self->field164 = 0;
    self->field168 = 3;
    self->field16C = lbl_57_rodata_260;
    self->field170 = lbl_57_rodata_260;
    self->field174 = 0;
    self->field175 = 0;
    self->field178 = 0;
    self->field17C = -1;

    Task* task = &self->task;
    if (!task)
        return self;

    task->state = 1;
    task->setup(0, 15);
    task->data->flags |= 8;
    return self;
}
