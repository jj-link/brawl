#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_2578;

class VTx {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float s14(unsigned int a);
};

extern "C" float fn_27_18B520(soModuleAccesser* a, int b, int c) {
    float v = lbl_27_rodata_2578;
    switch (b) {
    case 3:
    case 4:
        switch (c) {
        case 1:
            if (soValueAccesser::getConstantFloat(a, 0xbe2, 0) > lbl_27_rodata_2578) v = soValueAccesser::getConstantFloat(a, 0xd90, 0);
            else v = soValueAccesser::getConstantFloat(a, 0xd91, 0);
            break;
        case 2:
            if (soValueAccesser::getConstantFloat(a, 0xbe2, 0) > lbl_27_rodata_2578) v = soValueAccesser::getConstantFloat(a, 0xd97, 0);
            else v = soValueAccesser::getConstantFloat(a, 0xd98, 0);
            break;
        }
        break;
    case 5:
    case 6:
        switch (c) {
        case 1:
            if (soValueAccesser::getConstantFloat(a, 0xbe2, 0) > lbl_27_rodata_2578) v = soValueAccesser::getConstantFloat(a, 0xd92, 0);
            else v = soValueAccesser::getConstantFloat(a, 0xd93, 0);
            break;
        case 2:
            if (soValueAccesser::getConstantFloat(a, 0xbe2, 0) > lbl_27_rodata_2578) v = soValueAccesser::getConstantFloat(a, 0xd99, 0);
            else v = soValueAccesser::getConstantFloat(a, 0xd9a, 0);
            break;
        }
        break;
    }
    VTx* obj = *(VTx**)(*(char**)((char*)a + 0xd8) + 0x64);
    return v * obj->s14(0x1100000B);
}
