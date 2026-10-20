#pragma force_active on
struct Entry {
    unsigned int storage[2];
};

extern "C" unsigned int* fn_62_A6A8(Entry* entries, int index) {
    return entries[index].storage + 3;
}
