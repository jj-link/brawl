#pragma force_active on
#include <types.h>

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
    virtual void slot18(s32 arg);

    s32 unk4;
    s32 unk8;
    s32 refcount;
};

extern Object_vptr_0* lbl_805A0EB8;

extern "C" {
void fn_8027E27C(Object_vptr_0* arg0) {
    Object_vptr_0* old;
    s32 rc;

    if (arg0 != 0) {
        arg0->refcount++;
    }
    old = lbl_805A0EB8;
    if (old != 0) {
        rc = old->refcount - 1;
        old->refcount = rc;
        if (rc == 0 && old != 0) {
            old->slot18(1);
        }
    }
    lbl_805A0EB8 = arg0;
}
}
