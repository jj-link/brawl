#pragma force_active on
struct Entry {
    unsigned char data[0xA0];
};

struct Container {
    unsigned char header[8];
    int state;
    Entry entries[25];
};

extern "C" Entry* fn_48_BA6C(Container* self, int index)
{
    int position = (self->state >> 26) + index;
    if (position >= 25)
        position -= 25;
    return &self->entries[position];
}
