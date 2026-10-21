#pragma force_active on
extern "C" void* fn_68_2398(void* self, const char* name);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_68_data_3030[];
extern "C" const float lbl_68_rodata_1D8;

struct TaskData {
    unsigned int pad;
    unsigned int flags;
};

struct Task {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void setup(int, int);
    TaskData* data;
    unsigned int state;
};

struct Obj {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x90];
    Task task;
    unsigned char padDC[0x7C];
    unsigned int f158;
    unsigned int f15C;
    unsigned int f160;
    float f164;
    float f168;
    unsigned int f16C;
    unsigned char f170;
    float f174;
    unsigned char f178;
    unsigned char f179;
    unsigned int f17C;
    char gen[8];
    int f188;
    int f18C;
};

extern "C" Obj* fn_68_11930(Obj* self, const char* name) {
    fn_68_2398(self, name);
    self->vtable = lbl_68_data_3030;
    __ct__14snd3DGeneratorFv(self->gen);

    self->f158 = 0;
    self->f160 = 0;
    float zero = lbl_68_rodata_1D8;
    self->f164 = zero;
    self->f168 = zero;
    self->f16C = 0;
    self->f170 = 1;
    self->f174 = zero;
    self->f178 = 0;
    self->f179 = 0;
    self->f17C = 0;

    Task* task = &self->task;
    if (!task)
        return self;

    task->state = 1;
    task->setup(0, 0xF);
    task->data->flags |= 0x10;
    self->f188 = -1;
    self->f18C = -1;
    return self;
}
