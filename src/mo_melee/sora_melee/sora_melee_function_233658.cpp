#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_2350AC(void* obj, void* p, void* arg);

struct grGimmickWindData;

struct TriggerAction {
    int value;
    virtual void unused();
    virtual void fn(int del);
};

struct stTrigger {
    char pad0[0x18];
    TriggerAction* action;
    char pad1[0x10];
};

extern "C" void* setWindTrigger__9stTriggerFP17grGimmickWindData(
    stTrigger* self, grGimmickWindData* data)
{
    void* obj = __nw__FUlQ25Heaps8HeapType(0x40, 0xF);

    if (obj)
        obj = fn_27_2350AC(obj, (char*)self + 0x2C, data);

    if (self->action && self->action)
        self->action->fn(1);

    self->action = (TriggerAction*)obj;
    return obj;
}
