#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char __vt__7Message[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void* fn_8006CE5C(void*, int);
void* fn_80070B38(void*, int);
void* __dt__7MessageFv(char* self, int deleting) {
    if (self) {
        char* p = *(char**)(self + 0x1d4);
        *(void**)(self + 0xa0) = __vt__7Message;
        if (p) {
            __dla__FPv(*(void**)(p + 0x50));
            __dl__FPv(p);
        }
        if (*(char***)(self + 0x1d8)) {
            while (*(int*)(self + 0x1dc)) {
                --*(int*)(self + 0x1dc);
                char* q = (*(char***)(self + 0x1d8))[*(int*)(self + 0x1dc)];
                if (q) {
                    __dla__FPv(*(void**)(q + 0x50));
                    __dl__FPv(q);
                }
                (*(char***)(self + 0x1d8))[*(int*)(self + 0x1dc)] = 0;
            }
            gfHeapManager::free(*(void**)(self + 0x1d8));
            *(void**)(self + 0x1d8) = 0;
        }
        fn_8006CE5C(self + 0xa4, -1);
        fn_80070B38(self, 0);
        if (deleting > 0) __dl__FPv(self);
    }
    return self;
}
}