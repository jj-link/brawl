#pragma force_active on
extern "C" void* fn_80111BF0(void* self, unsigned int value) {
    unsigned short count = *(unsigned short*)((char*)self + 6);
    unsigned short* entry;
    int offset;
    unsigned int val;
    void* result = 0;
    offset = 0;
    for (unsigned int i = 0; i < count; i++) {
        char* base = *(char**)((char*)self + 0x18);
        val = *(unsigned short*)(base + offset);
        entry = (unsigned short*)(base + offset);
        int found = 0;
        if (val <= value && value < val + entry[1]) {
            found = 1;
        }
        if (found) {
            result = entry;
            break;
        }
        offset += 0x60;
    }
    return result;
}