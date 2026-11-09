#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Object_vptr_0* slot6();
    virtual void* slot7();
    virtual void* slot8();
};

extern "C" unsigned char* fn_80334BF8();
extern "C" int fn_80281AE8(void* a, unsigned char* b);
extern "C" int fn_80334C04(void* a, void* b, void* c, void* d, unsigned char* e);

extern "C" int fn_80334D24(Object_vptr_0* self, void* arg1) {
    unsigned char* temp_r31;
    void* temp_r30;
    Object_vptr_0* temp_r3;

    temp_r30 = self->slot8();
    if (fn_80281AE8(temp_r30, fn_80334BF8()) != 0) {
        temp_r3 = self->slot6();
        if (*(u32*)((u8*)temp_r3 + 4) != 0) {
            temp_r31 = fn_80334BF8();
            void* r4 = self->slot7();
            return fn_80334C04(temp_r3, r4, arg1, temp_r30, temp_r31);
        }
        return 1;
    }
    return 0;
}
