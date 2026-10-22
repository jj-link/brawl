#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Ft100Slots {
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
extern const char lbl_100_data_6250[], lbl_100_data_16D4[];
extern const float lbl_100_rodata_18;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_100_CC84(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_100_B818(float*, const float*);
}

extern "C" void fn_100_CADC(void*, int, Vec2f* speed, soModuleAccesser* accesser) {
    Vec2f pos;
    pos.m_x = lbl_100_rodata_18;
    pos.m_y = lbl_100_rodata_18;
    Vec3f rot0;
    fn_27_89D08(0, accesser, 4, &pos, fn_100_CC84(&rot0, lbl_100_rodata_18, lbl_100_rodata_18, lbl_100_rodata_18));

    Vec2f spd;
    spd.m_x = speed->m_x;
    spd.m_y = lbl_100_rodata_18;
    Vec3f rot1;
    fn_27_89D08(2, accesser, 0, &spd, fn_100_CC84(&rot1, lbl_100_rodata_18, lbl_100_rodata_18, lbl_100_rodata_18));

    Ft100Slots* mod = *(Ft100Slots**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
    void* ret = mod->slot6(2);
    char* obj = (char*)__dynamic_cast(ret, 0, lbl_100_data_6250, lbl_100_data_16D4, 1);

    float f31 = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
    float k = soValueAccesser::getConstantFloat(accesser, 0xbd5, 0);
    f31 = k * f31;
    Vec2f a;
    a.m_x = soValueAccesser::getConstantFloat(accesser, 0xc47, 0);
    a.m_y = lbl_100_rodata_18;
    fn_100_B818((float*)(obj + 0x20), (const float*)&a);

    Vec2f b;
    b.m_x = f31;
    b.m_y = lbl_100_rodata_18;
    fn_100_B818((float*)(obj + 0x18), (const float*)&b);

    Vec2f c;
    c.m_x = f31;
    c.m_y = lbl_100_rodata_18;
    fn_100_B818((float*)(obj + 0x28), (const float*)&c);

    Vec2f zero;
    zero.m_x = lbl_100_rodata_18;
    zero.m_y = lbl_100_rodata_18;
    Vec3f rot2;
    fn_27_89D08(3, accesser, 0x16, &zero, fn_100_CC84(&rot2, lbl_100_rodata_18, lbl_100_rodata_18, lbl_100_rodata_18));
}
