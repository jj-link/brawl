#pragma force_active on
extern "C" void fn_80162DF8(void*, void*, void*);
extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801EC1B8(void*, void*, void*);

extern "C" void fn_801AAA70(char* self, void* arg, unsigned int* flags) {
    if (flags && (*flags & 1)) {
        *flags &= ~1u;
        return;
    }
    if (arg) {
        if (*(unsigned int*)(self + 0xCC) & 0x80000000) {
            fn_801EC184(arg, self + 0x3C);
        } else {
            fn_801EC1B8(arg, self + 0xC, self + 0x3C);
        }
    } else {
        fn_801EC184(self + 0xC, self + 0x3C);
    }
    if (*(unsigned int*)(self + 0xCC) & 0x10000000) {
        fn_80162DF8(self + 0xB4, self + 0x9C, self + 0x3C);
    }
}
