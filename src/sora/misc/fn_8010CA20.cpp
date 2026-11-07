#include <types.h>
#pragma force_active on

extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

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
    virtual void slot13(void* arg);
};

struct Owner {
    char pad[0x160];
    void* m_160;
};

extern "C" {
extern Object_vptr_0* lbl_805A033C;
extern char lbl_8059E688[6];
}

extern "C" void fn_8010CA20(Owner* self, int arg) {
    void* p = self->m_160;
    if (arg != 0) {
        lbl_805A033C->slot13(p);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A033C, p, lbl_8059E688);
    } else {
        lbl_805A033C->slot13(p);
    }
}
