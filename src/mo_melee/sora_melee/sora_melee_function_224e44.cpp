class Vec3f;
#include <st/se_util.h>
#pragma force_active on

struct Seq {
    void* vtable;
    StSeUtil::UnkStruct2* entries;
    unsigned long count;
    StSeUtil::UnkStruct3* items;
    unsigned long itemCount;
    snd3DGenerator* generator;
    int current;
    float value;
};

extern "C" {
extern char lbl_27_data_4A1C4[];
extern const float lbl_27_rodata_34B8[2] = { -1.0f, 0.0f };

Seq* __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
    Seq* self, StSeUtil::UnkStruct2* entries, unsigned long count,
    StSeUtil::UnkStruct3* items, unsigned long itemCount) {
    self->vtable = lbl_27_data_4A1C4;
    self->entries = entries;
    self->count = count;
    self->items = items;
    self->itemCount = itemCount;
    self->generator = 0;
    self->current = -1;
    self->value = lbl_27_rodata_34B8[0];
    for (unsigned long i = 0; i < count; i++) {
        self->entries[i].unk0 = 0;
        self->entries[i].unk4 = 0;
        self->entries[i].unk8 = 0;
    }
    for (unsigned long i = 0; i < self->itemCount; i++) {
        self->items[i].id = snd_se_invalid;
        self->items[i].unk4 = -1;
        self->items[i].unk8 = 0;
        self->items[i].unkC = 0;
    }
    return self;
}
}
