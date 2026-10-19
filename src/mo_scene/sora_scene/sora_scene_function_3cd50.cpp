#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" u8 lbl_1_data_9A80[0x80];
extern "C" u8 lbl_1_data_9B00[0x14];

struct Sequence {
    void* unk0;
    void* unk4;
    int unk8;
};

extern "C" void* fn_1_3CD50() {
    Sequence* seq = (Sequence*)__nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (seq) {
        seq->unk0 = lbl_1_data_9A80;
        seq->unk4 = lbl_1_data_9B00;
        seq->unk8 = 0;
    }
    return seq;
}
