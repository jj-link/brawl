#pragma force_active on

struct stTriggerData {
    unsigned short id;
    unsigned char flags;
};

namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

void* operator new(unsigned long, Heaps::HeapType);
extern "C" char lbl_27_data_4C4F0[];

struct CallbackBase {
    unsigned long field0;
    void* vtable;
    unsigned long field8;

    CallbackBase() : field0(0), field8(0) {}
};

struct Callback : CallbackBase {
    bool valid;
    void* owner;

    Callback(void* self, bool value) {
        vtable = lbl_27_data_4C4F0;
        valid = value;
        owner = self;
    }
};

extern "C" {
extern void* g_stTriggerMng;
extern char lbl_27_data_4C4F0[];

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
    void*, int, stTriggerData*);
void fn_27_233F58(void*, void*);
void fn_27_233FCC(void*, void*);

void createIsValidTrigger__9grGimmickFP13stTriggerData(
    void* self, stTriggerData* data)
{
    if (data->id != 0) {
        void* trigger =
            createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
                g_stTriggerMng, 0, data);
        CallbackBase* valid =
            new (Heaps::StageInstance) Callback(self, true);
        CallbackBase* invalid =
            new (Heaps::StageInstance) Callback(self, false);

        if (data->flags & 1) {
            fn_27_233F58(trigger, valid);
            fn_27_233FCC(trigger, invalid);
        } else {
            fn_27_233F58(trigger, invalid);
            fn_27_233FCC(trigger, valid);
        }
    }
}
}
