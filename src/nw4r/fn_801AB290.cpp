#pragma force_active on

extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801EC1B8(void*, void*, void*);
extern "C" void fn_80162DF8(void*, void*, void*);
extern "C" void fn_801628B4(void*, void*, void*);

extern "C" void fn_801AB290(void* object, void* arg1, unsigned int* arg2) {
    char* self = (char*)object;

    if (arg2 != 0) {
        unsigned int flags = *arg2;
        if (flags & 1) {
            *arg2 = flags & ~1U;
            return;
        }
    }

    if (arg2 != 0 && (*arg2 & 1)) {
        *arg2 &= ~1U;
    } else {
        if (arg1 != 0) {
            if (*(unsigned int*)(self + 0xCC) & 0x80000000) {
                fn_801EC184(arg1, self + 0x3C);
            } else {
                fn_801EC1B8(arg1, self + 0xC, self + 0x3C);
            }
        } else {
            fn_801EC184(self + 0xC, self + 0x3C);
        }

        if (*(unsigned int*)(self + 0xCC) & 0x10000000) {
            fn_80162DF8(self + 0xB4, self + 0x9C, self + 0x3C);
        }
    }

    fn_801628B4(self + 0x3C, self + 0x3C, self + 0xDC);

    if (*(unsigned int*)(self + 0xCC) & 0x10000000) {
        fn_80162DF8(self + 0xB4, self + 0x9C, self + 0x3C);
    }
}
