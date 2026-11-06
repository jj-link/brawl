#pragma force_active on
extern "C" void fn_801ECF4C(void*, float, float, float, float, float, float);
extern "C" void fn_801ECDC4(void*, float, float, float, float, float, float);
extern "C" void fn_801ECE60(void*, float, float, float, float);
extern "C" void fn_80162C04(void*, void*);

inline bool hasCachedMatrix(const char* p) {
    return (*(const unsigned long*)(p + 0x70) & 0x80) != 0;
}

extern "C" void fn_801A7E1C(void** arg0, void* arg1) {
    if (arg1) {
        char* p = (char*)*arg0;
        if (p) {
            if (hasCachedMatrix(p))
                goto done;

            if (*(unsigned int*)(p + 0x70) & 0x40) {
                fn_801ECF4C(p + 0x30, *(float*)(p + 0xBC),
                            *(float*)(p + 0xC0), *(float*)(p + 0xC4),
                            *(float*)(p + 0xC8), *(float*)(p + 0xB4),
                            *(float*)(p + 0xB8));
            } else if (*(unsigned int*)(p + 0x70) & 0x10) {
                fn_801ECDC4(p + 0x30, *(float*)(p + 0xBC),
                            *(float*)(p + 0xC0), *(float*)(p + 0xC4),
                            *(float*)(p + 0xC8), *(float*)(p + 0xB4),
                            *(float*)(p + 0xB8));
            } else {
                fn_801ECE60(p + 0x30, *(float*)(p + 0xAC),
                            *(float*)(p + 0xB0), *(float*)(p + 0xB4),
                            *(float*)(p + 0xB8));
            }
            *(unsigned int*)(p + 0x70) |= 0x80;

        done:
            fn_80162C04(arg1, p + 0x30);
        }
    }
}
