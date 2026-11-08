#include <st/st_trigger.h>
#pragma force_active on

typedef unsigned char u8;

struct Data {
    u8 p0[0x18];
    float x18;
    float x1c;
    float x20;
    float x24;
    float x28;
    float x2c;
    float x30;
    float x34;
    float x38;
    float x3c;
    float x40;
    u8 x44;
    u8 p45[7];
};

struct Obj {
    u8 p0[0x280];
    stTrigger* trigger;
    Data* data;
};

extern "C" const float lbl_66_rodata_0[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" void fn_27_233808(void*, void*);

extern "C" void fn_66_10CC(Obj* self) {
    const float* rodata = lbl_66_rodata_0;
    self->data = (Data*)__nw__FUlQ25Heaps8HeapType(0x4C, 0x11);
    if (self->data == 0)
        return;

    memset(self->data, 0, 0x4C);

    Data* d = self->data;
    d->x28 = rodata[4];
    d->x2c = rodata[5];

    d = self->data;
    d->x30 = rodata[4];
    d->x34 = rodata[6];

    d = self->data;
    d->x38 = rodata[7];
    d->x3c = rodata[6];

    self->data->x40 = rodata[0];
    self->data->x44 = 1;

    d = self->data;
    d->x18 = rodata[0];
    d->x1c = rodata[0];
    d->x20 = rodata[0];
    d->x24 = rodata[0];
    *(int*)d = 2;

    self->trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0xE, -1);
    fn_27_233808(self->trigger, self->data);
    self->trigger->setAreaSleep(true);
}
