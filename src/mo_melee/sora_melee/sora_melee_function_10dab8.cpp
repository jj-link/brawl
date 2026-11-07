#include <types.h>
#pragma force_active on

struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
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
    virtual void slot10(s32, s32);
};
class Source {
public:
    char pad[0x2c];
    void* input;
};
class List {
public:
    virtual void fn_27_7B274();
    virtual Source** fn_27_7AC18(s32);
    virtual void fn_27_7AC28();
    virtual s32 fn_27_7AB50();
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    List list;
};
class Owner {
public:
    char pad[0x154];
    Class_90D8* holder;
};
extern "C" Object_vptr_4* fn_27_1240B8(void*);
extern "C" void fn_27_10DAB8(Owner* self, s32 a, s32 b) {
    s32 count = self->holder->list.fn_27_7AB50();
    for (s32 i = 0; i < count; i++) {
        fn_27_1240B8((*self->holder->list.fn_27_7AC18(i))->input)->slot10(b, a);
    }
}