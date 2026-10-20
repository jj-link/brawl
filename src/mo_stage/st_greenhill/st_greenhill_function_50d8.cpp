#pragma force_active on
struct GreenHillEntry {
    unsigned char data[0x68];
};

extern "C" GreenHillEntry* fn_72_50D8(GreenHillEntry* entries, int index) {
    return reinterpret_cast<GreenHillEntry*>(
        reinterpret_cast<unsigned char*>(entries) + index * 0x68 + 0x0C);
}
