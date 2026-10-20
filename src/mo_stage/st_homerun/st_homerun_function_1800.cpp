#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

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
    u8 x38;
};

struct Obj {
    u8 p0[0x808];
    void* trigger;
    Data* data;
};

extern "C" const float lbl_88_rodata_0[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* g_stTriggerMng;
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void* self, int kind, int id);
extern "C" void setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(void* trigger, Data* data);
extern "C" void setAreaSleep__9stTriggerFb(void* trigger, bool sleep);

extern "C" void fn_88_1800(Obj* self) {
    self->data = (Data*)__nw__FUlQ25Heaps8HeapType(0x40, 0x11);
    if (self->data == 0)
        return;

    memset(self->data, 0, 0x40);

    float f = lbl_88_rodata_0[0];
    Data* d = self->data;
    d->x28 = f;
    d->x2c = f;
    d->x30 = f;
    self->data->x34 = f;
    self->data->x38 = 1;
    d = self->data;
    d->x18 = f;
    d->x1c = f;
    d->x20 = f;
    d->x24 = f;
    *(u32*)d = 0;

    self->trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 0xe, -1);
    setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(self->trigger, self->data);
    setAreaSleep__9stTriggerFb(self->trigger, true);
}
