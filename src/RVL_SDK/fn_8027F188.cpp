#include <types.h>

#pragma force_active on

class Class_804863B0 {
public:
    virtual void fn_8027F128();
    virtual void fn_8027F188();
    virtual void fn_8027F1C0();
    virtual void fn_8027F24C();
    virtual void fn_8027F28C();
    virtual void fn_8027F9C8(void*, void*, u32);
};

struct Hdr {
    u32 magic;
    u32 field1;
    u32 field2;
};

extern "C" {
void fn_8027F188(Class_804863B0* obj, u8* p) {
    if (p == 0) return;
    Hdr* hdr = (Hdr*)(p - 16);
    hdr->magic = 0xDEADBEEF;
    obj->fn_8027F9C8((void*)hdr, (void*)(hdr->field1 + 16), hdr->field2);
}
}