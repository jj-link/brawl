#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

extern "C" {
extern const float lbl_107_rodata_38, lbl_107_rodata_3C;
extern const char lbl_107_data_8E20[], lbl_107_data_3B18[];
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Frame {
    Vec2f v8;
    Vec2f v10;
    Vec2f v18;
    Vec2f v20;
    int sp28;
    int sp2c;
    Vec2f speed;
    Vec3f rotation;
    float pad0[2];
};

extern "C" void fn_107_1083C(void* context, int resetKind, const Vec2f* input, soModuleAccesser* accesser) {
    Frame f;

    f.speed.m_x = lbl_107_rodata_38;
    f.speed.m_y = lbl_107_rodata_38;
    fn_27_89D08(2, accesser, 5, &f.speed,
        fn_107_B444(&f.rotation, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    Object_vptr_0* kinetic = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    Object_vptr_0* obj = static_cast<Object_vptr_0*>(
        __dynamic_cast(kinetic->slot6(2), 0, lbl_107_data_8E20, lbl_107_data_3B18, 1));
    char* data = *reinterpret_cast<char**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0x12)) + 0xb8);
    char* objc = reinterpret_cast<char*>(obj);

    Object_vptr_0* modObj = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0xc);
    float f31 = modObj->slot9();
    float f30 = *reinterpret_cast<float*>(data + 0x10);

    unsigned long long ret = obj->slot2();
    f.sp2c = (int)ret;
    f.sp28 = (int)(ret >> 32);
    float f2 = *reinterpret_cast<float*>(&f.sp28);

    if (f2 * f31 >= lbl_107_rodata_38) {
        f2 = f31 * f30;
    } else {
        f2 = f2 + f31 * f30;
    }

    f.v20.m_x = f2;
    f.v20.m_y = lbl_107_rodata_38;
    fn_107_EF04(reinterpret_cast<Vec2f*>(objc + 0x08), &f.v20);

    f.v18.m_x = *reinterpret_cast<float*>(data + 0x1c);
    f.v18.m_y = lbl_107_rodata_3C;
    fn_107_EF04(reinterpret_cast<Vec2f*>(objc + 0x18), &f.v18);

    f.v10.m_x = *reinterpret_cast<float*>(data + 0x24);
    f.v10.m_y = lbl_107_rodata_38;
    fn_107_EF04(reinterpret_cast<Vec2f*>(objc + 0x28), &f.v10);

    float dc = *reinterpret_cast<float*>(data + 0xc);
    f.v8.m_x = dc * soValueAccesser::getConstantFloat(accesser, 0xc38, 0);
    f.v8.m_y = lbl_107_rodata_38;
    fn_107_EF04(reinterpret_cast<Vec2f*>(objc + 0x20), &f.v8);

    *reinterpret_cast<float*>(objc + 0x3c) = *reinterpret_cast<float*>(data + 0x14);
    *reinterpret_cast<float*>(objc + 0x40) = *reinterpret_cast<float*>(data + 0x18);
}
