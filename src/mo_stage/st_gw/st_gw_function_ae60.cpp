#pragma force_active on
struct Entry {
    unsigned char data[0x38];
};

extern "C" void* fn_63_AE60(Entry* entries, int index) {
    return entries[index].data + 0x0C;
}
