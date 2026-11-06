#include <types.h>
#pragma force_active on

extern "C" int fn_803FC7C8(const u16*);

class Class_804657A8 {
public:
    virtual void fn_80184E48();
    virtual void fn_801856B4();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_801850A4();
    virtual void fn_80183024();
    virtual void fn_801830B0();
    virtual void fn_80184FCC();
    virtual void fn_80185000();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80185074();
    virtual void fn_8018508C();
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
    virtual void fn_801852B8();
    virtual void fn_80185330();
    virtual void fn_80185378(const u16*, int);
    virtual void fn_801853E0(const u16*, int, u16);
};

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
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25(const u16*, int);
    virtual void slot26(const u16*, int, u16);
};

extern "C" void fn_80185378(Class_804657A8* self, const u16* text, int arg) {
    self->fn_801853E0(text, arg, (u16)fn_803FC7C8(text));
}
