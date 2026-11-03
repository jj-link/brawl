#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, u16 type, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_802BB34C {
public:
    virtual ~Class_802BB34C() = 0;
    virtual void fn_802D639C();
    virtual void fn_802D5E1C();
    virtual void fn_802D5F28();
    virtual void fn_802D0890();
    virtual void fn_802D6004();

    void operator delete(void* p) {
        Class_802BB34C* self = (Class_802BB34C*)p;
        lbl_805A0EB8->free(self, self->type, 0x25);
    }

    u16 type;
};

Class_802BB34C::~Class_802BB34C() {}
