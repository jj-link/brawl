#pragma force_active on
struct Entry {
    unsigned char padding[0x0C];
    unsigned char value[0x5C];
};

extern "C" unsigned char* fn_76_3F58(Entry* base, int index) {
    return base[index].value;
}
