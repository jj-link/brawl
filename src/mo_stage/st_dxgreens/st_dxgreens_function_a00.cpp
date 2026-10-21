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
};

struct Obj {
    u8 p0[0x6F0];
    void* trigger;
    Data* data;
};

extern "C" const float lbl_79_rodata_0[];
extern "C" const float lbl_79_rodata_4;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* g_stTriggerMng;
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void*, int, int);
extern "C" void setWindTrigger__9stTriggerFP17grGimmickWindData(void*, Data*);
extern "C" void setAreaSleep__9stTriggerFb(void*, bool);

extern "C" void fn_79_A00(Obj* self) {
    self->data = (Data*)__nw__FUlQ25Heaps8HeapType(0x40, 0xF);
    if (self->data != 0) {
        memset(self->data, 0, 0x40);
        Data* d = self->data;
        float f = lbl_79_rodata_0[0];
        d->x28 = f;
        d->x2c = f;
        d->x30 = f;
        self->data->x34 = lbl_79_rodata_4;
        self->data->x38 = f;
        d = self->data;
        d->x18 = f;
        d->x1c = f;
        d->x20 = f;
        d->x24 = f;
        self->trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(
            g_stTriggerMng, 0xC, -1);
        setWindTrigger__9stTriggerFP17grGimmickWindData(self->trigger, self->data);
        setAreaSleep__9stTriggerFb(self->trigger, true);
    }
}
