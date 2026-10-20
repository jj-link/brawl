#pragma force_active on
struct Entry {
    unsigned char data[0x68];
};

extern "C" void* fn_74_6AE8(Entry* entries, int index) {
    return &entries[index].data[0x0C];
}
