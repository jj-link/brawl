#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_107_data_8DD0[], lbl_107_data_3B18[];
extern const float lbl_107_rodata_38;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_107_EF04(Vec2f*, const Vec2f*);
extern char g_ftCommonDataAccesser[];
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

extern "C" void fn_107_115B4(void*, int, Vec2f* speed, soModuleAccesser* accesser) {
    char* common = static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12));
    char* data = *reinterpret_cast<char**>(common + 0xb8);
    Vec3f rotation;
    fn_27_89D08(0, accesser, 0, speed, fn_107_B444(&rotation,
        lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
    FtModNode* mod = *reinterpret_cast<FtModNode**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x7c);
    void* ret = mod->slot6(0);
    char* energy = static_cast<char*>(__dynamic_cast(ret, 0, lbl_107_data_8DD0, lbl_107_data_3B18, 1));
    Vec2f sp(*reinterpret_cast<float*>(data + 0xc), lbl_107_rodata_38);
    fn_107_EF04(reinterpret_cast<Vec2f*>(energy + 0x20), &sp);
}
