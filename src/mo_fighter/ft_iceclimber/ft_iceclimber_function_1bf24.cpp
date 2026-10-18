#pragma force_active on
struct Accesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x10];
    int* row;
};

extern "C" int fn_105_1BF24(Accesser* self, void*, int index, int element) {
    Accesser* entry = reinterpret_cast<Accesser*>(
        reinterpret_cast<char*>(self) + (index - self->firstIndex) * 4
    );
    return entry->row[element];
}
