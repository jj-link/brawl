#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(s32);
};

typedef struct Owner {
    char pad0[8];
    u32 inner;
    char pad1[4];
    u16 count;
} Owner;

extern "C" void* fn_8015C1EC(void*, u16);

extern "C" void fn_802796AC(Owner* arg0, s32 arg1) {
    u32 i;
    for (i = 0; i < arg0->count; i++) {
        u32* entry = (u32*)fn_8015C1EC(&arg0->inner, (u16)i);
        Object_vptr_0* obj = (Object_vptr_0*)entry[1];
        obj->slot18(arg1);
    }
}