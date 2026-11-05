#include <types.h>
#pragma force_active on

struct AnimState {
    char pad0[0x1C];
    int first;
    char pad20[0x1C];
    int second;
    int value;
};

class soNullable {
public:
    virtual void isNull();
    virtual AnimState* slot1();
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
    virtual void slot14(int);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int*, int, int);
};

struct Resource {
    char pad[0xE8];
    int value;
};

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual Resource* fn_27_7ABD8();
};

struct Modules {
    char pad[4];
    Class_90D8* resource;
};
struct Accesser {
    char pad[0xD8];
    Modules* modules;
};
struct Owner {
    char pad0[0x3C];
    soNullable* first;
    char pad40[0x2C];
    soNullable* second;
    char pad70[0x1C];
    soNullable* state;
    char pad90[4];
    soNullable* effect;
    char pad98[0xD0];
    Accesser* accesser;
};

extern "C" void fn_27_170A8(Owner* self, int arg, unsigned int mode) {
    int a;
    int b;
    AnimState* state = self->state->slot1();
    if (state->first != -1 || state->second != -1) {
        if (self->effect)
            self->effect->slot14(arg + 2);
        if (mode == 1 && self->first) {
            Resource* resource = self->accesser->modules->resource->fn_27_7ABD8();
            a = resource->value;
            self->first->slot18(&a, state->value, 1);
            if (self->second) {
                b = resource->value;
                self->second->slot18(&b, state->value, 1);
            }
        }
    }
}
