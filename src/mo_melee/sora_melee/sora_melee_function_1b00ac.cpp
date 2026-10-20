#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad[8];
    s32 unk8;
};

struct Entry {
    u8 data[0x14];
};

extern "C" {
Entry* fn_27_1B00AC(Obj* self, s32 idx)
{
    s32 n = (self->unk8 >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (Entry*)((u8*)self + 0xC + n * 0x14);
}
}
