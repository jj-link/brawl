#include <types.h>
#pragma force_active on

class Class_804863B0 {
public:
    virtual void fn_8027F128();
    virtual void fn_8027F188();
    virtual void fn_8027F1C0();
    virtual void fn_8027F24C();
    virtual void fn_8027F28C();
    virtual void fn_8027F9C8(void*, void*, void*, void*);
};

extern "C" void fn_8027F24C(Class_804863B0* self, char* p) {
    if (p != 0) {
        *(int*)(p - 0x10) = 0xDEADBEEF;
        self->fn_8027F9C8(p - *(int*)(p - 4), (void*)(*(int*)(p - 0xc) + 0x10), *(void**)(p - 8), p);
    }
}
