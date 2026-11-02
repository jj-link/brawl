#include <so/so_value_accesser.h>
#pragma force_active on

class Work {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int);
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
};

class Posture {
public:
    virtual void isNull();
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
    virtual void slot23(float);
};

struct Holder {
    char pad[0xc];
    Posture* posture;
    char pad2[0x54];
    Work* work;
};

struct Owner {
    char pad[8];
    void* obj;
    char pad2[0xcc];
    Holder* holder;
};

struct Link {
    char pad[0x60];
    Owner* owner;
};

struct Data {
    int max;
    char pad[0xc];
    int divisor;
    char pad2[4];
    float mul;
    float add;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
Data* fn_27_14954C(void*, int);
extern char g_ftCommonDataAccesser[];
extern char lbl_27_data_9B6C0[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_7E18;

void fn_27_39FAD4(Owner* self) {
    Work* work = self->holder->work;
    Link* link = (Link*)__dynamic_cast(
        self->obj, 0x3c, lbl_27_data_9B6C0, lbl_27_data_248, 1);
    Data* data = fn_27_14954C(
        g_ftCommonDataAccesser, work->slot4(0x10000009));
    float base = soValueAccesser::getConstantFloat(
        (soModuleAccesser*)self, 0xfa6, 0);
    Data* other = fn_27_14954C(
        g_ftCommonDataAccesser,
        link->owner->holder->work->slot4(0x10000009));
    int level =
        link->owner->holder->work->slot4(0x10000005) / other->divisor;
    if (level < 0)
        level = 0;
    else if (level >= other->max)
        level = other->max;
    float scale = soValueAccesser::getConstantFloat(
        (soModuleAccesser*)self, level + 0xfa7, 0);
    float f = work->slot12(0x1100000a);
    float g = work->slot12(0x11000009);
    self->holder->posture->slot23(
        f * ((lbl_27_rodata_7E18 / base) *
             (data->add + scale * (g * data->mul))));
}
}
