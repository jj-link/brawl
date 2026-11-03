#include <so/so_external_value_accesser.h>
#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D58;
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void fn_41_534C(Vec3f*, const Vec3f*);
void* fn_41_245B8(void*, float*);
}
void* fn_41_245B8(void* self, float* p) {
    Vec3f a;
    fn_41_5AC4(&a, lbl_41_rodata_D58, lbl_41_rodata_D58, lbl_41_rodata_D58);
    StageObject* obj = (StageObject*)__dynamic_cast(*(void**)((char*)self + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    Vec3f b = soExternalValueAccesser::getPos(obj);
    fn_41_534C(&a, &b);
    if (a.m_x <= *p) return 0;
    return (void*)1;
}