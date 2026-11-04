#include <ft/ft_common_data_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Class_9C3C {
public:
    virtual void fn_107_8720();
    virtual void fn_107_160EC();
    virtual void fn_107_166C8();
    virtual void fn_107_166C4();
    virtual void fn_107_166C0();
    virtual void fn_107_166BC();
    virtual void fn_107_166B4();
    virtual void fn_107_166FC();
    virtual void fn_107_166F4();
    virtual void fn_107_166EC();
    virtual void fn_107_166E4();
    virtual void fn_107_166DC();
    virtual float fn_107_16674(int);
    virtual void fn_107_166A8();
    virtual void fn_107_1669C();
    virtual void fn_107_16694();
    virtual void fn_107_16688(float, int);
};
class Class_9E14 {
public:
    virtual void fn_107_8720();
    virtual void fn_107_16090();
    virtual void fn_107_168B4();
    virtual void fn_107_168AC();
    virtual void fn_107_168A4();
    virtual void fn_107_1689C();
    virtual void fn_107_16894();
    virtual void fn_107_1688C();
    virtual void fn_107_16884();
    virtual void fn_107_1687C();
    virtual void fn_107_16874();
    virtual void fn_107_1686C();
    virtual float fn_107_16864(int);
    virtual void fn_107_1685C();
    virtual void fn_107_1680C();
    virtual void fn_107_16854();
    virtual void fn_107_16844(float, int);
};

extern "C" {
extern const float lbl_107_rodata_88;
extern const float lbl_107_rodata_8C;
void fn_27_165458(soModuleAccesser*, float, float, float, float, float, unsigned long, float);
void fn_107_130DC(void*, soModuleAccesser*);
void fn_107_14328(void*, soModuleAccesser*);
}

extern "C" void fn_107_12FC4(void* self, soModuleAccesser* accesser) {
    float* data = *reinterpret_cast<float**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)0x12)) + 0xb8);
    Class_9C3C* work = *reinterpret_cast<Class_9C3C**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x64);
    float value = soValueAccesser::getConstantFloat(accesser, 0xc37, 0);
    float f = work->fn_107_16674(0x21000005);
    fn_27_165458(accesser, f, data[7], data[5], data[6], value, 0x21000005, lbl_107_rodata_88);
    fn_107_130DC(self, accesser);
    if ((*reinterpret_cast<Class_9C3C**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x64))->fn_107_16674(0x21000004) > lbl_107_rodata_8C) {
        (*reinterpret_cast<Class_9C3C**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8) + 0x64))->fn_107_16688(lbl_107_rodata_88, 0x21000004);
    }
    fn_107_14328(self, accesser);
}