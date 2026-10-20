#pragma force_active on
typedef int s32;

struct Entry {
    s32 unk0;
    s32 unk4;
};

struct Table {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Entry entries[4];
};

extern "C" void* fn_27_264A58(Table* t, s32 idx)
{
    s32 n = (t->unk8 >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return &t->entries[n];
}
