#pragma force_active on
extern "C" unsigned int fn_27_2331C4(void* p, unsigned short id) {
    unsigned int count = 0;
    unsigned int n = *(unsigned int*)((char*)p + 0x50);

    for (unsigned int i = 0; i < n; ++i) {
        void** entries = *(void***)((char*)p + 0x4c);
        void* entry = *(void**)((char*)entries + i * 4);
        void* obj = *(void**)((char*)entry + 0x90);
        unsigned short value = *(unsigned short*)((char*)obj + 0x7c);
        if (id == value)
            ++count;
    }

    return count;
}
