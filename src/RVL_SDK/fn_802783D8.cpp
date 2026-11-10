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
    virtual Object_vptr_0* slot7();
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
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void* slot23();
};

struct Self {
    int pad0;
    Object_vptr_0* unk4;
    int unk8;
};

struct Param {
    char pad[0x10];
    u32 flags;
};

extern "C" {
void fn_80274AD0(int, void*, void*);
void fn_80275CB0(int);
void fn_80276770(int);

void fn_802783D8(Self* self, int unused, int mode, Param* arg3) {
    Object_vptr_0* obj = self->unk4;
    char* q = (char*)obj->slot7()->slot23() + 0xb8;
    int r5 = self->unk8;
    switch (mode) {
    case 1:
        fn_80274AD0(r5, q, arg3);
        break;
    case 2:
        fn_80275CB0(r5);
        break;
    case 0: {
        u32 f = arg3->flags;
        if ((f & 0x800) || (f & 0x01000000)) {
            fn_80276770(r5);
        }
        break;
    }
    }
}
}
