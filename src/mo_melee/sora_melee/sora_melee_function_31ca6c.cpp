#include <so/posture/so_posture_module_simple.h>
#pragma force_active on
class Class_1250 { public:
virtual void fn_27_13C90(); virtual void fn_27_14068(); virtual void fn_27_140C0(); virtual void fn_27_1412C(); virtual void fn_27_14134(); virtual void fn_27_14370(); virtual void fn_27_14A28(); virtual void fn_27_14A30(); virtual void fn_27_14A38(); virtual void fn_27_14A48(); virtual void fn_27_14A68(); virtual void fn_27_14AD8(); virtual void fn_27_14A60(); virtual unsigned long long fn_27_14D08(short*);
};
class Class_20E8 { public:
virtual void fn_27_1F1B8(); virtual void fn_27_14068(); virtual void fn_27_140C0(); virtual void fn_27_1412C(); virtual void fn_27_14134(); virtual void fn_27_14370(); virtual void fn_27_14A28(); virtual void fn_27_14A30(); virtual void fn_27_14A38(); virtual void fn_27_14A48(); virtual void fn_27_14A68(float); virtual void fn_27_14AD8(); virtual float fn_27_14A60(); virtual void fn_27_14D08();
};
class Class_4328 { public:
virtual void fn_27_48BE8(); virtual void fn_27_48DA8(); virtual void fn_27_48E2C(); virtual void fn_27_48ED0(); virtual void fn_27_48F28(); virtual void fn_27_48D24(); virtual void fn_27_48F34(); virtual void fn_27_48FB0(); virtual void fn_27_4902C(); virtual void fn_27_49094(); virtual void fn_27_490DC(); virtual void fn_27_49190(); virtual void fn_27_49238(); virtual void fn_27_49290(unsigned int, void*, float);
};
struct Modules { char pad0[8]; Class_20E8* motion; soPostureModule* posture; char pad10[0x54]; Class_4328* work; char pad68[0x14]; Class_1250* kinetic; };
struct Object { char pad[0xd8]; Modules* modules; };
extern "C" const float lbl_27_rodata_74F0[];
extern "C" void fn_27_31CA6C(void*, Object* obj) {
const float* values = lbl_27_rodata_74F0;
Modules* modules = obj->modules;
Class_1250* kinetic = modules->kinetic;
Class_20E8* motion = modules->motion;
float lr = modules->posture->getLr();
short attr = -1;
union { unsigned long long value; float f[2]; } speedValue;
speedValue.value = kinetic->fn_27_14D08(&attr);
float speed = speedValue.f[0];
lr *= speed;
float frame = motion->fn_27_14A60();
frame += values[13] * lr;
while (frame >= values[14]) frame -= values[14];
while (frame < values[0]) frame += values[14];
motion->fn_27_14A68(frame);
obj->modules->work->fn_27_49290(0x21000006, obj->modules, frame);
}