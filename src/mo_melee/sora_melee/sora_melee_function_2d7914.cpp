#pragma force_active on

extern "C" const float lbl_27_rodata_6330;

struct Value {
    char padding[0x2c];
    int index;
    float amount;
};

struct Entry {
    int first;
    int second;
    Value* value;
};

struct State {
    int count;
    Entry entries[64];
    float amounts[96];
};

static inline Entry* getEntry(State* self, int index)
{
    int i;
    Entry* entry;
    if (self->count > 0) {
        entry = self->entries;
        for (i = 0; i < 64; ++i, ++entry) {
            if (entry->value != 0) {
                if (index <= 0)
                    return entry;
                --index;
            }
        }
    }
    return 0;
}

extern "C" void fn_27_2D7914(State* self)
{
    for (int i = 0; i < 96; ++i)
        self->amounts[i] = lbl_27_rodata_6330;

    int index = 0;
    Entry* entry;
    for (;;) {
        entry = getEntry(self, index);
        if (entry == 0)
            return;
        Value* value = entry->value;
        if (self->amounts[value->index] < value->amount)
            self->amounts[value->index] = value->amount;
        ++index;
    }
}
