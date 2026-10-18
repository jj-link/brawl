#pragma force_active on
struct SoraReplayMenuEntry {
    unsigned char data[12];
    void* value;
};

struct SoraReplayMenuTable {
    unsigned char data[0x1AC];
    unsigned char* entries;
};

extern "C" void* fn_7_9E0(SoraReplayMenuTable* object, unsigned int index) {
    unsigned char* entry = object->entries + index * 16;
    return *reinterpret_cast<void**>(entry + 0x1A8);
}
