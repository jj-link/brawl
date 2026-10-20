#pragma force_active on
struct Entry {
    unsigned char data[0x38];
};

extern "C" void* fn_68_6348(Entry* entries, int index) {
    return entries[index].data + 0x0C;
}
