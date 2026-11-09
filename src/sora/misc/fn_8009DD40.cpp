#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on
extern "C" {
void fn_8009D468(void*);
extern void* lbl_805A0280;
extern const float lbl_805A1DC8;
}
inline void clear(int* begin, int* end) {
    int* p = begin;
    do { *p = 0; ++p; } while (p < end);
}
inline char* getState() {
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
    return static_cast<char*>(lbl_805A0280);
}
extern "C" void cmRemoveQuake__Fi(int i) {
    char* base = getState();
    *reinterpret_cast<int*>(base + 0x14 + i * 4) = 0;
}
