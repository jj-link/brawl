#pragma force_active on
struct Entry {
    unsigned char pad[0x0C];
};

extern "C" Entry* fn_70_9088(Entry* base, int index) {
    return (Entry*)((char*)base + index * 0x38 + 0x0C);
}
