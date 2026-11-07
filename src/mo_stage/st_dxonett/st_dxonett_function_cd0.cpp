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
    u8 p0[0x2f0];
    void* trigger0;
    void* trigger1;
    Data* data0;
    Data* data1;
};

extern "C" const float lbl_78_rodata_0[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* g_stTriggerMng;
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void* self, int kind, int id);
extern "C" void setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(void* trigger, Data* data);

extern "C" void fn_78_CD0(Obj* self) {
    const float* r = lbl_78_rodata_0;
    self->data0 = (Data*)__nw__FUlQ25Heaps8HeapType(0x40, 0x11);
    if (self->data0 == 0)
        return;
    memset(self->data0, 0, 0x40);
    Data* d = self->data0;
    d->x28 = r[2];
    d->x2c = r[0];
    d->x30 = r[0];
    self->data0->x34 = r[3];
    self->data0->x38 = 0;
    d = self->data0;
    d->x18 = r[0];
    d->x1c = r[0];
    d->x20 = r[4];
    d->x24 = r[5];
    *(u32*)d = 0;
    self->trigger0 = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 0xe, -1);
    setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(self->trigger0, self->data0);

    self->data1 = (Data*)__nw__FUlQ25Heaps8HeapType(0x40, 0x11);
    if (self->data1 == 0)
        return;
    memset(self->data1, 0, 0x40);
    d = self->data1;
    d->x28 = r[6];
    d->x2c = r[0];
    d->x30 = r[0];
    self->data1->x34 = r[3];
    self->data1->x38 = 1;
    d = self->data1;
    d->x18 = r[0];
    d->x1c = r[0];
    d->x20 = r[7];
    d->x24 = r[5];
    *(u32*)d = 0;
    self->trigger1 = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 0xe, -1);
    setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(self->trigger1, self->data1);
}
