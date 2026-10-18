#pragma force_active on
extern "C" void* fn_40_3EDB0(void* a, int* b, int c) {
    if ((unsigned)(c - 27) <= 3) c = 27;
    if ((unsigned)(c - 14) <= 1) c = 14;
    if ((unsigned)(c - 3) <= 1) c = 3;
    
    char* p = (char*)a;
    int count = *(int*)(p + 0x6F8);
    char* q;
    int i = 0;
    while (i < count) {
        int inner_count = *(int*)(p + 0xE4);
        q = p;
        int j = 0;
        while (j < inner_count) {
            if (c == *(int*)(q + 0x44)) {
                *b = j;
                return *(void**)((char*)a + i * 0xAC + 0x40);
            }
            q += 4;
            j++;
        }
        p += 0xAC;
        i++;
    }
    return (void*)10;
}
