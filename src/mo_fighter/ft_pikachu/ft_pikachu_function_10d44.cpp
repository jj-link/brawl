#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_98_data_769C[], lbl_98_data_24B0[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v5();
    virtual void v4();
    virtual void v6();
    virtual void* v8(int);
};

extern "C" void fn_98_10D44(void* moduleAccesser, void* valueAccesser) {
    VObj* check = *(VObj**)((unsigned char*)*(void**)((unsigned char*)valueAccesser + 0xD8) + 0x14);
    if (check->v5() == 2) {
        VObj* kinetic = *(VObj**)((unsigned char*)*(void**)((unsigned char*)valueAccesser + 0xD8) + 0x7C);
        void* energy = kinetic->v8(1);
        unsigned char* m = (unsigned char*)__dynamic_cast(energy, 0, lbl_98_data_769C, lbl_98_data_24B0, 1);
        float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(valueAccesser, 0xfb3, 0);
        *(float*)(m + 0x10) = -f;
        m[5] |= 0x80;
    }
}
