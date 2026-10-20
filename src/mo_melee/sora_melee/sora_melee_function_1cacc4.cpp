#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct Owner {
    u8 pad[0x18];
    s32 unk18;
    Entry entries[4];
};

extern "C" Entry* fn_27_1CACC4(Owner* self, s32 idx) {
    s32 i = (self->unk18 >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return &self->entries[i];
}
