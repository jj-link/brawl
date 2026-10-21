#pragma force_active on
extern "C" void fn_57_3980(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_57_data_2EB0[];
extern "C" const float lbl_57_rodata_360;

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
    unsigned char field169;
    unsigned char pad16A[2];
    float field16C;
    float field170;
    unsigned char field174;
    unsigned char field175;
    unsigned char pad176[2];
    unsigned int field178;
    unsigned char gen[0x20];
};

extern "C" Object* fn_57_10474(Object* self) {
    fn_57_3980(self);
    self->vtable = lbl_57_data_2EB0;
    __ct__14snd3DGeneratorFv(self->gen);
    self->field160 = 0;
    self->field164 = 0;
    self->field168 = 3;
    self->field169 = 3;
    self->field16C = lbl_57_rodata_360;
    self->field170 = lbl_57_rodata_360;
    self->field174 = 0;
    self->field175 = 0;
    self->field178 = 0;

    Task* task = &self->task;
    if (!task) {
        return self;
    }

    task->state = 1;
    task->setup(0, 15);
    task->data->flags |= 8;
    return self;
}
