#pragma force_active on
struct Entry {
    unsigned char pad[12];
};

extern "C" Entry* fn_27_295688(Entry* p, int i) {
    return (Entry*)((char*)p + i * 4 + 12);
}
