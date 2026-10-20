#pragma force_active on
struct Entry {
    unsigned int value;
    unsigned char pad4;
    bool flag;
    unsigned char pad6[0x22];
};

struct State {
    unsigned char pad0[8];
    Entry entries[2];
};

extern "C" void fn_40_16D64(State* self, unsigned int value)
{
    for (int i = 0; i < 2; i++) {
        if (value == self->entries[i].value)
            self->entries[i].flag = true;
    }
}
