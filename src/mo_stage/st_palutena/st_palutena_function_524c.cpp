#pragma force_active on
struct Entry {
    unsigned int storage[2];
};

extern "C" Entry* fn_67_524C(char* base, int index) {
    return (Entry*)(base + 12) + index;
}
