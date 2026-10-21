#pragma force_active on

typedef unsigned long u32;

struct Data {
    char pad[0x1c];
    char trigger[1];
};

struct Counts {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Data* get(u32);
    u32 pad;
    Counts* counts;
};

struct Callback {
    u32 field0;
    void* vtable;
    u32 field8;
    Data* data;
    unsigned char flag;
    float value;
    u32 field18;
};

extern "C" {
extern void* g_stTriggerMng;
extern char lbl_40_data_1F20[];
extern const float lbl_40_rodata_2C[];

void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
    void*, int, void*);
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void fn_27_233F58(void*, void*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);

void fn_40_92D0(void*, u32 kind, void* multi) {
    Data* data;
    void* trigger;
    Container* container;
    u32 n = 0;
    u32 i;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (i = 0; i < container->counts->count; i++) {
            data = container->get(i);
            trigger =
                createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
                    g_stTriggerMng, 0x1a, data->trigger);

            Callback* cb =
                (Callback*)__nw__FUlQ25Heaps8HeapType(0x1c, 15);
            if (cb) {
                cb->field0 = 0;
                cb->field8 = 0;
                cb->vtable = lbl_40_data_1F20;
                cb->data = data;
                cb->flag = 0;
                cb->value = lbl_40_rodata_2C[0];
                cb->field18 = 0;
            }
            fn_27_233F58(trigger, cb);
        }
    }
}
}
