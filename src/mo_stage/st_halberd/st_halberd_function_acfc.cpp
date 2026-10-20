#pragma force_active on
struct HalberdEntry {
    char data[0x78];
};

struct HalberdArray {
    char header[0xc];
    HalberdEntry entries[1];
};

extern "C" HalberdEntry* fn_57_ACFC(HalberdArray* array, int index) {
    return &array->entries[index];
}
