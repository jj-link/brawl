#pragma force_active on
struct SoraMenuSnapshot {
    unsigned char prefix[0x1AC];
    void* entries;
};

struct SoraMenuSnapshotEntry {
    unsigned char prefix[0x1A8];
    void* value;
};

extern "C" void* fn_8_9D4(SoraMenuSnapshot* object, unsigned int index) {
    SoraMenuSnapshotEntry* entry =
        reinterpret_cast<SoraMenuSnapshotEntry*>(
            reinterpret_cast<unsigned char*>(object->entries) + index * 16);
    return entry->value;
}
