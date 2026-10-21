#pragma force_active on
extern "C" void* fn_801804C4(char* self) {
    unsigned short off;
    char* r5 = *(char**)(self + 0x3C);
    while (r5 != 0 && *(int*)(r5 + 0xC) != 1) {
        off = *(unsigned short*)(self + 0x42);
        r5 = *(char**)(r5 + off);
        while (r5 != 0 && *(int*)(r5 + 0xC) != 1) {
            r5 = *(char**)(r5 + off);
        }
    }
    return r5;
}
