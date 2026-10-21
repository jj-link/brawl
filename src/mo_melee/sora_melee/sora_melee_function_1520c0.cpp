#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_1E64[];

class VT {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16();
    virtual unsigned int s17(unsigned int a);
};

extern "C" float fn_27_1520C0(void* unused, soModuleAccesser* accesser, char* arg) {
    float v = lbl_27_rodata_1E64[0];
    VT* obj = *(VT**)(*(char**)((char*)accesser + 0xd8) + 0x64);
    unsigned int r = obj->s17(0x12000012U);
    if (r == 1) {
        unsigned long op = *(unsigned long*)(arg + 0x30) & 0x1F;
        if (op != 0x9 && op != 0xA && op != 0xB && op != 0x16) {
            v = soValueAccesser::getConstantFloat(accesser, 0xd9e, 0);
        }
    }
    return v;
}
