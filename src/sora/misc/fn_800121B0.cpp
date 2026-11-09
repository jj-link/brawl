#pragma force_active on
#include <gf/gf_heap_manager.h>
extern "C" {
void fn_800132E8(void*);
void fn_80012E18(void*);
extern const float lbl_805A13B0;
}

extern "C" void fn_800121B0(char* self, float f0, float f1) {
    unsigned int v = !((self[0x51] >> 7) & 1);
    if (v) {
        if (v) {
            void* c; unsigned int k; void* b; unsigned int j; unsigned int i; void* a; char* p; char* q; char* r;
            a = *(void**)(self + 0x58);
            p = self;
            i = 0;
            do {
                q = *(char**)(p + 0x58);
                if (!(((unsigned char)q[0x11] >> 7) & 1)) {
                    b = *(void**)(q + 0x18);
                    j = 0;
                    do {
                        r = *(char**)(q + 0x18);
                        if (!(((unsigned char)r[0x11] >> 7) & 1)) {
                            c = *(void**)(r + 0x18);
                            k = 0;
                            do {
                                fn_800132E8(*(void**)(r + 0x18));
                                ++k;
                                *(void**)(r + 0x18) = 0;
                                r += 4;
                            } while (k < 4);
                            gfHeapManager::free(c);
                        }
                        ++j;
                        *(void**)(q + 0x18) = 0;
                        q += 4;
                    } while (j < 4);
                    gfHeapManager::free(b);
                }
                ++i;
                *(void**)(p + 0x58) = 0;
                p += 4;
            } while (i < 4);
            gfHeapManager::free(a);
        }
    }

    *(float*)(self + 0x40) = lbl_805A13B0 * f0;
    *(float*)(self + 0x44) = lbl_805A13B0 * f1;
    *(float*)(self + 0x48) = lbl_805A13B0 * f0;
    *(float*)(self + 0x4c) = lbl_805A13B0 * f1;
    *(s32*)(self + 0x54) = 0;
    fn_80012E18((void*)(self + 0x40));
}
