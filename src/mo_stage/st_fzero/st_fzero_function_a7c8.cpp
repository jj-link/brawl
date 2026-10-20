#pragma force_active on
struct Entry {
    unsigned int a;
    unsigned int b;
};

extern "C" Entry* fn_61_A7C8(Entry* base, int index) {
    return (Entry*)((char*)base + index * 8 + 12);
}
