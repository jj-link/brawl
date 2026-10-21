#include <types.h>
#pragma force_active on

struct SeSeqElem {
    u32 unk0;
    u32 unk4;
    u8* data;
};

struct SeSeq {
    void* vtable;
    SeSeqElem* elems;
    u32 num;
};

extern "C" {
extern char lbl_27_data_4A1C4[];
void __dl__FPv(void*);
void __dla__FPv(void*);

SeSeq* __dt__Q28StSeUtil5SeSeqFv(SeSeq* self, s16 destroyFlag) {
    if (self) {
        self->vtable = lbl_27_data_4A1C4;
        for (u32 i = 0; i < self->num; ++i) {
            SeSeqElem* elem = &self->elems[i];
            if (elem->data) {
                __dla__FPv(elem->data);
                elem->data = 0;
            }
        }
        if (destroyFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
