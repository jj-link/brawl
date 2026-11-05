#pragma force_active on
extern "C" void* fn_8016E864(void*, const char*);
extern "C" void* fn_8015C1D0(void*, void*);

inline void* find(char* self, const char* name, void* start) {
    void* result;
    if (!*name)
        return 0;
    if (start) {
        result = fn_8016E864(start, name);
        if (result)
            return result;
    }
    void* item = fn_8015C1D0(self + 0x10, 0);
    while (item) {
        result = fn_8016E864(item, name);
        if (result)
            return result;
        item = fn_8015C1D0(self + 0x10, item);
    }
    return 0;
}

extern "C" void fn_8016EA70(void** out, char* self, const char* name, void* start) {
    *out = find(self, name, start);
}