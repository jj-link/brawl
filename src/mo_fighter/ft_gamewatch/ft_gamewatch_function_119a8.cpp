#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class FtSlots {
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
extern char lbl_107_data_8CA4[], lbl_107_data_3B18[];
extern const float lbl_107_rodata_38;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __memcpy(void*, const void*, unsigned long);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
float fn_107_10E54(float, float, float);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
extern char g_ftCommonDataAccesser[];
}

extern "C" void fn_107_119A8(void*, int, Vec2f* speed, soModuleAccesser* accesser) {
    char* data = *reinterpret_cast<char**>(static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12)) + 0xb8);
    Vec2f sp;
    __memcpy(&sp, speed, sizeof(sp));
    float t = *reinterpret_cast<float*>(data + 0x10);
    sp.m_x = fn_107_10E54(sp.m_x, -t, t);
    Vec3f rot;
    fn_27_89D08(3, accesser, 0x10, &sp, fn_107_B444(&rot, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
    FtSlots* mod = *reinterpret_cast<FtSlots**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    void* ret = mod->slot6(3);
    char* obj = static_cast<char*>(__dynamic_cast(ret, 0, lbl_107_data_8CA4, lbl_107_data_3B18, 1));
    float f31 = *reinterpret_cast<float*>(data + 0xc);
    Vec2f a;
    a.m_x = f31 * soValueAccesser::getConstantFloat(accesser, 0xc38, 0);
    a.m_y = lbl_107_rodata_38;
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x20), &a);
    Vec2f b;
    b.m_x = *reinterpret_cast<float*>(data + 0x24);
    b.m_y = lbl_107_rodata_38;
    fn_107_EF04(reinterpret_cast<Vec2f*>(obj + 0x28), &b);
}
