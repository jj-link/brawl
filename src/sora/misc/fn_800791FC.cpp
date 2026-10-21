#pragma force_active on
extern "C" {
int fn_800791FC(void* obj, unsigned int value) {
    char* r3 = (char*)obj;
    unsigned int count = *(int*)(r3 + 0x198);
    int off = 0;
    for (unsigned int i = 0; i < count; i++) {
        int base = *(int*)(r3 + 0x194);
        int sum = base + off;
        if (*(unsigned int*)(sum) == value) return sum;
        off += 0x30;
    }
    return 0;
}
}
