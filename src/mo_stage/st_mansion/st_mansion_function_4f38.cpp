#pragma force_active on
struct Entry {
    unsigned int fields[3];
};

extern "C" Entry* fn_47_4F38(Entry* entries, int index) {
    return reinterpret_cast<Entry*>(
        reinterpret_cast<char*>(entries) + index * 8 + 12);
}
