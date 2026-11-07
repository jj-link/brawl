#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_104_data_7138[], lbl_104_data_2404[];
extern const float lbl_104_rodata_E8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_104_121E8(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_104_CDE4(Vec2f*, const Vec2f*);
}

class FtModNode {
public:
    virtual void* slot0();
    virtual void* slot1();
    virtual void* slot2();
    virtual void* slot3();
    virtual void* slot4();
    virtual void* slot5();
    virtual void* slot6(int);
};

extern "C" void fn_104_1DCBC(void*, void*, Vec2f* speed, soModuleAccesser* accesser) {
    Vec3f rot;
    fn_27_89D08(3, accesser, 0x16, speed, fn_104_121E8(&rot, lbl_104_rodata_E8, lbl_104_rodata_E8, lbl_104_rodata_E8));
    FtModNode* mod = *reinterpret_cast<FtModNode**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    void* ret = mod->slot6(3);
    char* energy = static_cast<char*>(__dynamic_cast(ret, 0, lbl_104_data_7138, lbl_104_data_2404, 1));
    Vec2f zero(lbl_104_rodata_E8, lbl_104_rodata_E8);
    fn_104_CDE4(reinterpret_cast<Vec2f*>(energy + 0x10), &zero);
    fn_104_CDE4(reinterpret_cast<Vec2f*>(energy + 0x18), speed);
    fn_104_CDE4(reinterpret_cast<Vec2f*>(energy + 0x28), speed);
}
