#pragma force_active on

struct Vec3f;
#include <snd/snd_3d_generator.h>

extern "C" void fn_57_3980(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_57_data_2A38[];
extern "C" const float lbl_57_rodata_2C0;

struct Flags {
    unsigned int pad;
    unsigned int flags;
};

class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C(int, int);

    Flags* data;
    unsigned int state;
};

struct Object {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Class_2110 task;
    char padDC[0x84];
    unsigned int a160, a164, a168;
    float a16c, a170, a174, a178, a17c, a180;
    float a184, a188, a18c, a190, a194, a198;
    unsigned char a19c, a19d;
    char pad19e[2];
    float a1a0, a1a4;
    char gen[0x20];
};

extern "C" Object* fn_57_DC00(Object* self) {
    fn_57_3980(self);
    self->vtable = lbl_57_data_2A38;
    __ct__14snd3DGeneratorFv(self->gen);

    self->a160 = 0;
    self->a164 = 0;
    self->a168 = 0;
    float zero = lbl_57_rodata_2C0;
    self->a16c = zero;
    self->a170 = zero;
    self->a174 = zero;
    self->a178 = zero;
    self->a17c = zero;
    self->a180 = zero;
    self->a184 = zero;
    self->a188 = zero;
    self->a18c = zero;
    self->a190 = zero;
    self->a194 = zero;
    self->a198 = zero;
    self->a19d = 4;
    self->a1a0 = zero;
    self->a1a4 = zero;
    self->a19c = 0;

    Class_2110* task = &self->task;
    if (!task)
        return self;

    task->state = 1;
    task->fn_57_AB4C(0, 15);
    task->data->flags |= 8;
    return self;
}
