#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Entry {
    u8 data[12];
};

struct Holder {
    u8 pad[8];
    s32 unk8;
};

extern "C" Entry* fn_27_1B1224(Holder* p, s32 idx)
{
    s32 i = (p->unk8 >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return (Entry*)((u8*)p + i * 12 + 12);
}
