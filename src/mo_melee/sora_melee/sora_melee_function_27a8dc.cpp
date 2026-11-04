#pragma force_active on
#include <gr/gr_yakumono.h>

struct Data {
    unsigned int value;
    unsigned int flags;
};

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual void fn_27_100CC();
    virtual void fn_27_10094();
    virtual void fn_27_100C8(int, int);
    Data* data;
    unsigned int state;
};

class Object : public grYakumono {
public:
    float f150;
    float f154;
    float f158;
};

extern "C" void __ct__10grYakumonoFPCc(grYakumono*, const char*);
extern "C" char lbl_27_data_5A250[];
extern "C" const float lbl_27_rodata_4548;

extern "C" Object* fn_27_27A8DC(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3C) = lbl_27_data_5A250;
    self->f150 = lbl_27_rodata_4548;
    self->f154 = lbl_27_rodata_4548;
    self->f158 = lbl_27_rodata_4548;
    Class_CF8* sub = (Class_CF8*)((char*)self + 0xD0);
    if (!sub) return self;
    sub->state = 1;
    sub->fn_27_100C8(0, 15);
    sub->data->value = 0;
    sub->data->flags |= 4;
    return self;
}
