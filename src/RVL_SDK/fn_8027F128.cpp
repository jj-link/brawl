#include <types.h>
#pragma force_active on

class Class_804863B0 {
public:
    virtual void fn_8027F128();
    virtual void fn_8027F188();
    virtual void fn_8027F1C0();
    virtual void fn_8027F24C();
    virtual void* fn_8027F28C(int arg);
};

extern "C" void* fn_8027F128(Class_804863B0* self, int arg1, int arg2) {
    int* result = (int*)self->fn_8027F28C(arg1 + 0x10);
    result[0] = 0x02345656;
    result[1] = arg1;
    result[2] = arg2;
    return (char*)result + 0x10;
}
