#include <nw4r/math/math_arithmetic.h>
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
    virtual float slot12(int);
    virtual void slot13(int, float);
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(void*);
};

struct Params {
    char pad0[0x44];
    float f44;
    float f48;
    float f4C;
    char pad50[0xc0 - 0x50];
    float fC0;
};
struct Owner { char pad[0x4870]; Params* params; };
struct Modules {
    char pad0[8];
    Object_vptr_0* obj8;
    char pad0c[0x58];
    Object_vptr_0* work;
    char pad68[8];
    Object_vptr_0* status;
};
struct Accesser { char pad0[8]; void* owner; char padc[0xcc]; Modules* modules; };
struct Blk { int id; float a; float b; unsigned char c[4]; };

extern "C" {
extern char lbl_27_data_48E80[];
extern char lbl_27_data_248[];
extern float lbl_27_rodata_74F0[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_31AF40(void*, Accesser* a) {
    Params* params = ((Owner*)__dynamic_cast(a->owner, 0x3c, lbl_27_data_48E80, lbl_27_data_248, 1))->params;
    if (a->modules->status->slot16() == 5) {
        Object_vptr_0* work = a->modules->work;
        float f31 = nw4r::math::FAbs(work->slot12(0x11000003));
        work->slot13(0x21000008, f31 * params->fC0);
        work->slot13(0x21000001, lbl_27_rodata_74F0[0]);
        int state;
        if (f31 >= params->f48) {
            state = 10;
        } else if (f31 >= params->f4C) {
            state = 9;
        } else {
            state = 8;
        }
        float f1 = work->slot12(0x21000006);
        Blk blk;
        blk.id = state;
        blk.a = f1;
        blk.b = lbl_27_rodata_74F0[0];
        blk.c[0] = 0;
        blk.c[1] = 0;
        blk.c[2] = 0;
        blk.c[3] = 0;
        a->modules->obj8->slot30(&blk);
    }
    a->modules->work->slot13(0x11000008, params->f44);
}
