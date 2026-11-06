#pragma force_active on

extern "C" const float lbl_27_rodata_6330;

struct Entry {
    int first;
    int second;
    void* value;
};

struct State {
    int count;
    Entry entries[64];
    float amounts[96];
};

extern "C" void fn_27_2D7564(State* self)
{
    self->count = 0;
    Entry* entry = self->entries;
    for (int i = 0; i < 64; ++i, ++entry)
        entry->value = 0;
    for (int i = 0; i < 96; ++i)
        self->amounts[i] = lbl_27_rodata_6330;
}
