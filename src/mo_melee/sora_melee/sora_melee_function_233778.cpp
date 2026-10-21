#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct grGimmickBeltConveyorData;

struct TriggerAction {
    int value;
    virtual void unused();
    virtual ~TriggerAction();
};

extern "C" TriggerAction* fn_27_2356A4(
    void*, void*, grGimmickBeltConveyorData*);

struct stTrigger {
    char pad0[0x18];
    TriggerAction* action;
    char pad1[0x10];
};

extern "C" TriggerAction*
setBeltConveyorTrigger__9stTriggerFP25grGimmickBeltConveyorData(
    stTrigger* self, grGimmickBeltConveyorData* data)
{
    TriggerAction* result =
        (TriggerAction*)__nw__FUlQ25Heaps8HeapType(0x40, 0xF);

    if (result)
        result = fn_27_2356A4(result, (char*)self + 0x2C, data);

    if (self->action)
        delete self->action;

    self->action = result;
    return result;
}
