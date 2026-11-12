#pragma force_active on

#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void fn_8009D468(void*);
extern void* lbl_805A0280;
extern const float lbl_805A1DC8;
}
inline void clear(int* begin, int* end) {
    int* p = begin;
    do { *p = 0; ++p; } while (p < end);
}

extern "C" void fn_8009DEE8() {
    if (lbl_805A0280 == 0) {
        char* p = static_cast<char*>(operator new(0x274, (Heaps::HeapType)1));
        if (p != 0) {
            *reinterpret_cast<int*>(p + 0x22C) = 0;
            clear(reinterpret_cast<int*>(p + 0x230), reinterpret_cast<int*>(p + 0x244));
            fn_8009D468(p);
            float* f = reinterpret_cast<float*>(p + 0x244);
            f[0] = lbl_805A1DC8;
            f[1] = lbl_805A1DC8;
            f[2] = lbl_805A1DC8;
            f[3] = lbl_805A1DC8;
            f[4] = lbl_805A1DC8;
        }
        lbl_805A0280 = p;
    }
    char* s = static_cast<char*>(lbl_805A0280);
    *reinterpret_cast<int*>(s + 0x14) = 0;
    *reinterpret_cast<int*>(s + 0x18) = 0;
    *reinterpret_cast<int*>(s + 0x1C) = 0;
    *reinterpret_cast<int*>(s + 0x20) = 0;
    *reinterpret_cast<int*>(s + 0x24) = 0;
    *reinterpret_cast<int*>(s + 0x28) = 0;
}
