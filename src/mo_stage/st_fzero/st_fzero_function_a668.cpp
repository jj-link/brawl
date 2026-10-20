#pragma force_active on
struct Entry {
    unsigned char data[0x78];
};

extern "C" void* fn_61_A668(Entry* base, int index) {
    return base[index].data + 0x0c;
}
