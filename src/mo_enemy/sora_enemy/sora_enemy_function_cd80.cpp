#pragma force_active on
extern "C" void* fn_41_CD5C(void* obj, unsigned int index);

extern "C" void* fn_41_CD80(void* obj, unsigned int value) {
    if (value == 0xFFFFu) {
        return 0;
    }

    unsigned int i = 0;
    while (i < *static_cast<unsigned int*>(obj)) {
        void* entry = fn_41_CD5C(obj, i);
        if (entry != 0) {
            unsigned char* bytes = static_cast<unsigned char*>(entry);
            if (bytes[0] != 0 &&
                *reinterpret_cast<unsigned int*>(bytes + 0xC) == value) {
                return entry;
            }
        }
        ++i;
    }
    return 0;
}
