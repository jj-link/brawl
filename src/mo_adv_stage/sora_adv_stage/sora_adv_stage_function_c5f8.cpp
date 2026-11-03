#pragma force_active on
typedef unsigned long u32;

struct Count {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* get(u32);

    u32 pad;
    Count* data;
};

struct stDataMultiContainer;

extern "C" {
extern void* g_stTriggerMng;

void* __nw__FUlQ25Heaps8HeapType(u32, int);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void*, int, void*);
void* fn_40_E824(void*, void*, void*, u32);
void fn_27_233F58(void*, void*);
Container* searchContainer__20stDataMultiContainerFUlUl(stDataMultiContainer*, u32, u32);

void fn_40_C5F8(void* arg0, u32 arg1, stDataMultiContainer* arg2) {
    void* trigger;
    Container* container;
    u32 index = 0;
    u32 i;
    void* entry;
    void* obj;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(arg2, arg1, index++)) != 0) {
        for (i = 0; i < container->data->count; i++) {
            entry = container->get(i);
            trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0x15, (char*)entry + 0x10);
            obj = __nw__FUlQ25Heaps8HeapType(0x20, 0xF);
            if (obj) {
                obj = fn_40_E824(obj, arg0, entry, 1);
            }
            fn_27_233F58(trigger, obj);
        }
    }
}
}
