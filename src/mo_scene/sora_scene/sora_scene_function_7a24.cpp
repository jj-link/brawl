#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
}

struct UnkTaskSet {
    void* unk0;
    void* unk4;
    void* unk8;
};

struct UnkOwner {
    u8 pad[0x35c];
    UnkTaskSet* unk35C;
};

extern "C" {
s32 fn_1_7A24(UnkOwner* self) {
    s32 ret;
    if (self->unk35C == nullptr) {
        ret = 0;
    } else {
        exit__6gfTaskFv(self->unk35C->unk0);
        exit__6gfTaskFv(self->unk35C->unk4);
        exit__6gfTaskFv(self->unk35C->unk8);
        free__13gfHeapManagerFPv(self->unk35C);
        self->unk35C = nullptr;
        ret = 0;
    }
    return ret;
}
}
