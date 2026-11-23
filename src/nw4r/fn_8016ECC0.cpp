#pragma force_active on
extern "C" void* fn_8015C1D0(void*, int);
extern "C" void* fn_8016E658(void*, void*);
inline void* find_node(void* self, void* entry, void*& node) {
    node = fn_8015C1D0(self, 0);
    while (node) {
        void* result = fn_8016E658(node, entry);
        if (result) return result;
        node = fn_8015C1D0(self, (int)node);
    }
    return 0;
}
extern "C" int fn_8016ECC0(void* arg, unsigned char* data) {
    void* self = arg;
    void* node;
    void** out;
    int missing;
    unsigned char* base;
    unsigned char* entry;
    int i;
    unsigned short len;
    unsigned char* start = data + *(int*)(data + 0xc);
    start = (unsigned char*)((int)start + *(int*)(data + 0x10));
    start += *(int*)(data + 0x14);
    base = start + 0x20;
    start = base + *(unsigned short*)(start + 0x20) * 4;
    entry = start + 4;
    out = (void**)base;
    missing = 0;
    i = 0;
    for (; i < *(unsigned short*)base; ++i) {
        len = *(unsigned short*)entry;
        entry += 2;
        void* result = find_node(self, entry, node);
        out[1] = result;
        if (!result) ++missing;
        entry += len;
        ++out;
    }
    return missing;
}