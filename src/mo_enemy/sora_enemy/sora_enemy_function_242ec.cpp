#pragma force_active on

struct Vec3 {
    float x, y, z;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D58;

Vec3* fn_41_5AC4(Vec3*, float, float, float);
void fn_41_534C(Vec3*, const Vec3*);
void getCenterPos__23emExternalValueAccesserFP5Enemy(Vec3*, void*);
float fn_41_243F4(Vec3*, void*);

int fn_41_242EC(char* self, void* input) {
    char* area = (char*)__dynamic_cast(
        *(void**)(*(char**)(self + 0xd8) + 0x90),
        0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);

    if (!*(float**)(area + 0x5c))
        return 3;

    Vec3 a;
    Vec3 b;
    fn_41_5AC4(&a, lbl_41_rodata_D58,
               lbl_41_rodata_D58, lbl_41_rodata_D58);
    getCenterPos__23emExternalValueAccesserFP5Enemy(
        &b, __dynamic_cast(*(void**)(self + 8), 0x3c,
                          __RTTI__5Enemy, __RTTI__11StageObject, 1));
    fn_41_534C(&a, &b);

    for (int i = 0; i < 3; ++i) {
        if (fn_41_243F4(&a, input) <= (*(float**)(area + 0x5c))[i])
            return i;
    }
    return 3;
}
}
