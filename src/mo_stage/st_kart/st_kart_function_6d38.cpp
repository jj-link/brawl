#pragma force_active on
struct KartEntry {
    unsigned char data[0x68];
};

struct KartEntries {
    int header[2];
    int flags;
    KartEntry entries[1];
};

extern "C" KartEntry* fn_49_6D38(KartEntries* object, unsigned int index) {
    int adjusted = (object->flags >> 30) + index;
    if (adjusted >= 1) {
        --adjusted;
    }
    return &object->entries[adjusted];
}
