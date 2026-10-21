#include <types.h>
#pragma force_active on

struct Vec3 { float x, y, z; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D58;
Vec3* fn_41_5AC4(Vec3*, float, float, float);
void fn_41_534C(Vec3*, const Vec3*);
void getCenterPos__23emExternalValueAccesserFP5Enemy(Vec3*, void*);
void fn_41_243F4(Vec3*, void*);
void fn_41_244DC(void* self, void* p);
}

void fn_41_244DC(void* self, void* p) {
    Vec3 a;
    Vec3 b;
    fn_41_5AC4(&a, lbl_41_rodata_D58, lbl_41_rodata_D58, lbl_41_rodata_D58);
    void* enemy = __dynamic_cast(*(void**)((char*)self + 8), 0x3C, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    getCenterPos__23emExternalValueAccesserFP5Enemy(&b, enemy);
    fn_41_534C(&a, &b);
    fn_41_243F4(&a, p);
}
