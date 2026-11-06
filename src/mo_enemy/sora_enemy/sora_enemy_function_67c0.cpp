#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_41_rodata_18;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int, int);
};

extern "C" void fn_41_67C0(void* self, float* fs, int arg2) {
    Object_vptr_0* target = *(Object_vptr_0**)((char*)*(void**)((char*)self + 0x1B4) + 0x64);
    int n = (int)fs[0];
    int m = (int)fs[2];
    float val = soValueAccesser::getValueFloat((soModuleAccesser*)((char*)self + 0xDC), 0x1100000C, 0);
    if (lbl_41_rodata_18 != fs[1]) {
        n = (int)((float)n + fs[1] * val);
    }
    if (lbl_41_rodata_18 != fs[3]) {
        m = (int)((float)m + fs[3] * val);
    }
    if (n > m) {
        m = n;
    }
    target->slot6(n, m, arg2);
}
