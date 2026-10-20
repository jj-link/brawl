#pragma force_active on
struct Entry {
    unsigned char data[12];
};

struct Container {
    unsigned char padding[0x18];
    signed int start : 2;
    unsigned int remaining : 30;
    Entry entries[1];
};

extern "C" Entry* fn_27_1E510C(Container* self, int index)
{
    int adjusted = self->start + index;
    if (adjusted >= 1) {
        --adjusted;
    }
    return &self->entries[adjusted];
}
