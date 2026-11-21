#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1(int, unsigned int);
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
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
};

class Class_80465740 {
public:
    virtual void fn_801846F8();
    virtual void fn_80184ADC();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_80184A00();
    virtual void fn_80183024();
    virtual void fn_801830B0();
    virtual void fn_80184978();
    virtual void fn_801849A4();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_801849D0();
    virtual void fn_801849E8();
    virtual void fn_80182B40();
    virtual void fn_80182BEC();
    virtual void fn_80183164();
    virtual void fn_80183180();
    virtual void fn_80183210();
    virtual void fn_80183228();
    virtual void fn_801832FC();
    virtual void fn_80183374();
    virtual void fn_80183618();
    virtual void fn_8018342C();

    char pad04[0x24];
    Object_vptr_0* obj;
    char pad2c[0x20];
    nw4r::math::VEC2 position;
    char pad54[0x61];
    u8 n;
    char padb6[0x1e];
    unsigned int data[4];
    char pade4;
    u8 flag;
    char pade6[2];
    int value;
};

extern "C" int fn_8018C3FC(unsigned int*, unsigned int);
extern "C" void fn_8018C4B8(int, int);
extern "C" u64 fn_8018352C(void*);
extern "C" void fn_8018CAFC(const nw4r::math::VEC2&, const nw4r::math::VEC2&, unsigned char, int, unsigned int*, unsigned int);

extern "C" void fn_80184A00(Class_80465740* self) {
    u8 flag;
    unsigned int* p;
    int value;
    u8 n;
    int v;
    if (self->obj) {
        self->fn_8018342C();
        n = self->n;
        v = self->obj->slot1(fn_8018C3FC(self->data, n), n);
        fn_8018C4B8(v, self->flag);
        if (v)
            p = self->data;
        else
            p = 0;
        value = self->value;
        flag = self->flag;
        u64 pos = fn_8018352C(self);
        fn_8018CAFC(*(nw4r::math::VEC2*)&pos, self->position, flag, value, p, self->n);
    }
}
