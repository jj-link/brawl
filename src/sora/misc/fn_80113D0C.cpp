#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0360;
void* fn_80112DAC(void* self, u8 index);
void* fn_80111BF0(void* self, s16 index);
void* fn_80111B60(void* self, s16 index);
}

struct Entry {
    u8 pad0[9];
    u8 unk9;
    u8 padA[2];
    s16 unkC;
};

struct Part4 {
    u8 pad0[0x54];
    u8 unk54;
};

struct Part8 {
    u8 pad0[0x2C];
    u8 unk2C;
};

struct Out {
    void* unk0;
    Part4* unk4;
    Part8* unk8;
};

extern "C" int fn_80113D0C(Entry** arg0, Out* arg1) {
    s16 idx;
    int result = 0;
    Entry* entry = *arg0;
    idx = entry->unkC;
    if (idx != -1) {
        Part8* p8 = (Part8*)fn_80112DAC(lbl_805A0360, entry->unk9);
        if (p8 != NULL) {
            Part4* p4 = (Part4*)fn_80111BF0(p8, idx);
            if (p4 != NULL) {
                void* p0 = fn_80111B60(p8, idx);
                int flag = 0;
                int ok;
                arg1->unk0 = p0;
                arg1->unk4 = p4;
                arg1->unk8 = p8;
                if (p0 != NULL && p4 != NULL && p8 != NULL) {
                    flag = 1;
                }
                if (flag != 0 && ((arg1->unk4->unk54 >> 4) & 1) && ((arg1->unk8->unk2C >> 7) & 1)) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    result = 1;
                }
            }
        }
    }
    return result;
}
