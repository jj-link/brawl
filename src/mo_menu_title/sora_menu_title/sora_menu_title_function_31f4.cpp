#pragma force_active on
extern "C" unsigned int fn_24_3290(void* a, void* b);

extern "C" int fn_24_31F4(void* base) {
    char* p1 = (char*)base;
    char* p2 = (char*)base + 0x100;
    for (int i = 0; i < 4; i++) {
        if (fn_24_3290(base, (void*)p1) == 1) return 1;
        if (fn_24_3290(base, (void*)p2) == 1) return 1;
        p1 += 0x40;
        p2 += 0x40;
    }
    return 0;
}
