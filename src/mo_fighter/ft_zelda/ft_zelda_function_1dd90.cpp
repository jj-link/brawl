#include <types.h>
#pragma force_active on
#pragma optimize_for_size on

struct Vec2 {
    f32 x, y;
};
struct Vec3 {
    f32 x, y, z;
};
struct Locals {
    Vec2 b;
    Vec2 a;
    Vec3 c;
    Vec3 d;
};

class Energy {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void* update(int);
};

extern "C" {
extern const f32 lbl_104_rodata_E8;
extern const char lbl_104_data_72B4[];
extern const char lbl_104_data_2404[];

Vec3* fn_104_121E8(Vec3*, f32, f32, f32);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_104_1DD90(void* unused, void* owner, const Vec2* source, void* accesser) {
    Locals locals;

    f32 sy = source->y;
    locals.a.x = lbl_104_rodata_E8;
    locals.a.y = sy;
    fn_27_89D08(1, accesser, 0, &locals.a,
        fn_104_121E8(&locals.d, lbl_104_rodata_E8,
                     lbl_104_rodata_E8, lbl_104_rodata_E8));

    locals.b.x = source->x;
    locals.b.y = lbl_104_rodata_E8;
    fn_27_89D08(3, accesser, 7, &locals.b,
        fn_104_121E8(&locals.c, lbl_104_rodata_E8,
                     lbl_104_rodata_E8, lbl_104_rodata_E8));

    f32 cv1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFB4, 0);
    f32 cv2 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFB5, 0);

    char* c = (char*)__dynamic_cast(
        ((Energy*)*(void**)((char*)*(void**)((char*)accesser + 0xD8) + 0x7C))->update(1),
        0, lbl_104_data_72B4, lbl_104_data_2404, 1);
    *(f32*)(c + 0x10) = -cv1;
    *(f32*)(c + 0x14) = cv2;
    *(f32*)(c + 0x1C) = cv2;
}
}