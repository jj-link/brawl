#pragma force_active on
extern "C" void* fn_40_76F8(char* self, unsigned long key) {
    char* table = *(char**)(self + 0x1d0);
    if (table != 0) {
        unsigned long count = *(unsigned long*)(self + 0x1d4);
        char* p = table;
        unsigned long i;
        for (i = 0; i < count; i++) {
            if (key == *(unsigned long*)p) {
                return *(void**)(table + (i << 4) + 4);
            }
            p += 0x10;
        }
    }
    return (void*)-1;
}
