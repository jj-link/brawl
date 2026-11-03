#pragma force_active on
struct Vec3f;
#include <snd/snd_3d_generator.h>
extern "C" void fn_47_1750(void*, const char*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_47_data_22A0[];
extern "C" const float lbl_47_rodata_A0;
extern "C" const float lbl_47_rodata_A4;
struct Flags { unsigned int pad; unsigned int flags; };
class Class_1640 {
public:
 virtual void fn_47_7394();
 virtual void fn_47_685C();
 virtual void fn_47_686C();
 virtual void fn_47_4D54();
 virtual void fn_47_499C(int, int);
 Flags* data;
 unsigned int state;
};
class Class_18E8 {
public:
 virtual void fn_47_8D88();
 virtual void fn_47_81A8();
 virtual void fn_47_81B8();
 virtual void fn_47_4EB4();
 virtual void fn_47_4968(int, int);
 Flags* data;
 unsigned int state;
};
struct Object {
 char pad0[0x3c];
 void* vtable;
 char pad40[0x90];
 Class_1640 task;
 char padDC[0x7c];
 unsigned int a158, a15c, a160, a164;
 float a168;
 unsigned char a16c, a16d, a16e, pad16f;
 unsigned int a170;
 unsigned char a174;
 char pad175[3];
 float a178;
 char gen[0x20];
};
extern "C" Object* fn_47_99A0(Object* self, const char* name) {
 fn_47_1750(self, name);
 self->vtable = lbl_47_data_22A0;
 __ct__14snd3DGeneratorFv(self->gen);
 self->a158 = 0;
 self->a15c = 0;
 self->a160 = 0;
 self->a164 = 0;
 self->a168 = lbl_47_rodata_A0;
 self->a16c = 0;
 self->a16d = 0;
 self->a16e = 2;
 self->a170 = 0;
 self->a174 = 1;
 self->a178 = lbl_47_rodata_A4;
 Class_1640* task = &self->task;
 if (!task) return self;
 task->state = 1;
 task->fn_47_499C(0, 15);
 task->data->flags |= 4;
 return self;
}