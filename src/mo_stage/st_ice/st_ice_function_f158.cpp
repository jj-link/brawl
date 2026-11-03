#pragma force_active on
struct Vec3f;
#include <snd/snd_3d_generator.h>
extern "C" void fn_62_2C84(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_62_data_5650[];
extern "C" const float lbl_62_rodata_1B0;

struct Flags { unsigned int pad, flags; };
class Class_1890 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_6134();
    virtual void fn_62_5E28(int, int);
    Flags* data;
    unsigned int state;
};
class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual void fn_62_BF04();
    virtual void fn_62_BF14();
    virtual void fn_62_A624();
    virtual void fn_62_A3AC(int, int);
};
class Class_4768 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_F038();
    virtual void fn_62_5E28(int, int);
};
struct Object {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Class_1890 task;
    char paddc[0x7c];
    unsigned int a158, a15c, a160, a164;
    unsigned char a168;
    char pad169[3];
    float a16c;
    unsigned char a170, a171;
    char pad172[2];
    unsigned int a174;
    float a178, a17c, a180;
    unsigned int a184;
    char gen[0x40];
    unsigned int a1c8, a1cc;
};
extern "C" Object* fn_62_F158(Object* self) {
    fn_62_2C84(self);
    self->vtable = lbl_62_data_5650;
    __ct__14snd3DGeneratorFv(self->gen);
    self->a1c8 = 0;
    self->a1cc = 0;
    self->a158 = 0;
    self->a15c = 0;
    self->a160 = 0;
    self->a164 = 0;
    self->a168 = 1;
    float zero = lbl_62_rodata_1B0;
    self->a16c = zero;
    self->a178 = zero;
    self->a17c = zero;
    self->a180 = zero;
    self->a184 = 0;
    self->a170 = 0;
    self->a171 = 0;
    self->a174 = 0;
    *(unsigned char*)(self->gen + 8) = 0;
    *(int*)(self->gen + 12) = -1;
    *(int*)(self->gen + 16) = 0;
    *(int*)(self->gen + 20) = 0;
    Class_1890* task = &self->task;
    if (!task)
        return self;
    task->state = 1;
    task->fn_62_5E28(0, 15);
    task->data->flags |= 1;
    return self;
}