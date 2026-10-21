#pragma force_active on

typedef unsigned char u8;

struct Data {
    u8 p0[0x18];
    float x18;
    float x1c;
    float x20;
    float x24;
    float x28;
    u8 x2c;
    u8 p30[3];
    float x30;
    u8 p34[4];
};

struct Obj {
    u8 p0[0x75c];
    void* trigger;
    Data* data;
};

extern "C" const float lbl_46_rodata_0[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* g_stTriggerMng;
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void* self, int kind, int id);
extern "C" void setWaterTrigger__9stTriggerFP18grGimmickWaterData(void* trigger, Data* data);
extern "C" void setAreaSleep__9stTriggerFb(void* trigger, bool arg0);

extern "C" void fn_46_F58(Obj* self) {
    const float* rodata = lbl_46_rodata_0;
    self->data = (Data*)__nw__FUlQ25Heaps8HeapType(0x38, 0xf);
    if (self->data == 0)
        return;

    memset(self->data, 0, 0x38);

    self->data->x28 = rodata[0];
    self->data->x2c = 1;
    self->data->x30 = rodata[1];
    Data* d = self->data;
    d->x18 = rodata[0];
    d->x1c = rodata[2];
    d->x20 = rodata[3];
    d->x24 = rodata[4];

    self->trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 0x11, -1);
    setWaterTrigger__9stTriggerFP18grGimmickWaterData(self->trigger, self->data);
    setAreaSleep__9stTriggerFb(self->trigger, 1);
}
