#include <so/so_value_accesser.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual int fn_27_14A28(int, int, float*, int, int, float);
};
class Class_1F90 {
public:
    virtual void fn_27_1EFD0();
    virtual void fn_27_E240();
    virtual void fn_27_E190();
    virtual void fn_27_E1A0();
    virtual void fn_27_1D2D0();
    virtual void fn_27_1D200(int, int);
    virtual void fn_27_1D240();
};
struct Modules {
    char pad[0x64];
    Class_1F90* second;
    char pad2[0x20];
    Class_1250* first;
};
struct Object {
    char pad[0xd8];
    Modules* modules;
};
extern const float lbl_27_rodata_2288;
extern "C" void fn_27_173BCC(void*, Object* object, int value) {
    float f = soValueAccesser::getConstantFloat((soModuleAccesser*)object, 0xbea, 0);
    float pos[3] = {lbl_27_rodata_2288, lbl_27_rodata_2288, lbl_27_rodata_2288};
    int result = object->modules->first->fn_27_14A28(0x62, value, pos, 0, -1, f);
    object->modules->second->fn_27_1D200(result, 0x20000003);
}