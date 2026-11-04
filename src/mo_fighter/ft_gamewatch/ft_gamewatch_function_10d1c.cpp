#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class EnergyModule {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void* getEnergy(int);
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_38;
extern const char lbl_107_data_8CA4[], lbl_107_data_3B18[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __memcpy(void*, const void*, unsigned long);
float fn_107_10E54(float, float, float);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_107_10D1C(void*, int, const Vec2f* input, soModuleAccesser* accesser) {
    char* data = *reinterpret_cast<char**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x12)) + 0xb8);

    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));

    const float lim = *reinterpret_cast<const float*>(data + 0x10);
    speed.m_x = fn_107_10E54(speed.m_x, -lim, lim);

    Vec3f rotation;
    fn_27_89D08(3, accesser, 0x12, &speed, fn_107_B444(&rotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));

    EnergyModule* kinetic = *reinterpret_cast<EnergyModule**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    void* energy = kinetic->getEnergy(3);
    char* obj = static_cast<char*>(__dynamic_cast(
        energy, 0, lbl_107_data_8CA4, lbl_107_data_3B18, 1));

    float f31 = *reinterpret_cast<const float*>(data + 0xc);
    float v = f31 * soValueAccesser::getConstantFloat(accesser, 0xc38, 0);

    Vec2f a(v, lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x20), &a);

    Vec2f b(*reinterpret_cast<const float*>(data + 0x24), lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x28), &b);
}
