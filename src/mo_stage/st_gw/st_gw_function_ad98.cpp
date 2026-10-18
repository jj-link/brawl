#pragma force_active on
struct Entry {
    unsigned char data[0xA0];
};

extern "C" void* fn_63_AD98(Entry* base, int index) {
    return base->data + index * 0xA0 + 0x0C;
}
