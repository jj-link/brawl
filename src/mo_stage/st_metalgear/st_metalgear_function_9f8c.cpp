#pragma force_active on
struct Entry {
    unsigned char data[0x0C];
};

extern "C" void* fn_71_9F8C(Entry* base, int index) {
    return reinterpret_cast<unsigned char*>(base) + index * 0x38 + 0x0C;
}
