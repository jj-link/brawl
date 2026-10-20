#pragma force_active on
struct Entry {
    unsigned char type;
    unsigned char padding[0x3B];
};

struct State {
    unsigned char padding[0x174];
    unsigned char* indices;
    Entry* entries;
};

extern "C" bool fn_81_7824(State* self, int index) {
    Entry* entries = self->entries;
    if (!entries)
        return false;

    unsigned char* indices = self->indices;
    if (!indices)
        return false;

    switch (entries[indices[index]].type) {
    case 4:
    case 5:
    case 6:
    case 7:
        return true;
    }

    return false;
}
