#pragma force_active on
extern "C" bool fn_8018C0E8(const char* a, const char* b);

extern "C" void* fn_801838DC(char* list, const char* arg1) {
    char* node = *(char**)(list + 4);
    char* end = list + 4;
    while (node != end) {
        char* base = node - 4;
        if (fn_8018C0E8(base + 0x18, arg1)) {
            return base;
        }
        node = *(char**)node;
    }
    return 0;
}
