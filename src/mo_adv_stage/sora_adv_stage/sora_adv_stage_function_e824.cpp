#include <types.h>
#include <st/st_trigger.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_40_EA7C(void*, int, void*);
void fn_27_233F58(void*, void*);
}

extern int lbl_40_data_2280;

struct Obj {
    int unk0;
    void* unk4;
    int unk8;
    int unkC;
    void* unk10;
    u8 unk14;
    u8 unk15;
    void* unk18;
    void* unk1C;
};

extern "C" Obj* fn_40_E824(Obj* self, int arg1, void* arg2, s8 arg3) {
    u8 kind;
    void* p;

    self->unk0 = 0;
    self->unk8 = 0x15;
    self->unk4 = &lbl_40_data_2280;
    self->unkC = arg1;
    self->unk10 = arg2;
    self->unk14 = 0;
    self->unk15 = arg3;
    self->unk18 = 0;
    kind = ((u8*)arg2)[7];
    if (kind == 0) {
        self->unk18 = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x15, -1);
    } else if (kind == 1) {
        self->unk18 = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x15, -1);
    } else {
        self->unk18 = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x15, (stTriggerData*)((u8*)arg2 + 0x14));
    }
    p = __nw__FUlQ25Heaps8HeapType(0x48, 0xF);
    if (p != 0) {
        p = fn_40_EA7C(p, self->unkC, self->unk10);
    }
    self->unk1C = p;
    fn_27_233F58(self->unk18, p);
    return self;
}
