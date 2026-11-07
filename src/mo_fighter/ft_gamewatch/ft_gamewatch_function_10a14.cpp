#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

extern "C" {
extern const float lbl_107_rodata_38, lbl_107_rodata_3C;
extern const char lbl_107_data_8E20[], lbl_107_data_3B18[];
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, const Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_107_10A14(void*, int, const Vec2f* speed, soModuleAccesser* accesser) {
    Vec3f rotation;
    fn_27_89D08(2, accesser, 10, speed, fn_107_B444(&rotation, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
    Object_vptr_0* kinetic = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    char* obj = static_cast<char*>(__dynamic_cast(kinetic->slot6(2), 0, lbl_107_data_8E20, lbl_107_data_3B18, 1));
    char* data = *reinterpret_cast<char**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0x12)) + 0xb8);
    Vec2f a(*reinterpret_cast<float*>(data + 8), lbl_107_rodata_3C);
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x18), &a);
    Vec2f b(*reinterpret_cast<float*>(data + 0x24), lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x28), &b);
    float v = soValueAccesser::getConstantFloat(accesser, 0xc38, 0);
    Vec2f c(*reinterpret_cast<float*>(data + 0xc) * v, lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x20), &c);
    *reinterpret_cast<float*>(obj + 0x3c) = *reinterpret_cast<float*>(data);
    *reinterpret_cast<float*>(obj + 0x40) = *reinterpret_cast<float*>(data + 4);
}