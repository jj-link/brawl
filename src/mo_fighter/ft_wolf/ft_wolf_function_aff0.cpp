#pragma force_active on
struct WolfEntry {
    unsigned int words[2];
};

extern "C" unsigned int* fn_125_AFF0(WolfEntry* entries, int index) {
    return &entries[index].words[1];
}
