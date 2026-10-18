#pragma force_active on
struct Entry {
    unsigned int first;
    unsigned int second;
};

extern "C" unsigned int* fn_116_A5F0(Entry* entries, int index) {
    return &entries[index].second;
}
