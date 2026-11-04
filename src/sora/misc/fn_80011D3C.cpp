#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>
extern "C" {
void fn_800132E8(void*);
void fn_8015C238(void*, int);
void __dt__6gfTaskFv(void*, int);
extern char lbl_8042084C[];
}
extern "C" void* fn_80011D3C(void* self, int flag) {
    char* s = (char*)self;
    if (self != 0) {
        *(void**)(s + 0x3C) = lbl_8042084C;

        if (!(((unsigned char)s[0x51] >> 7) & 1)) {
            void* c; unsigned int k; void* b; unsigned int j; unsigned int i; void* a; char* r; char* q; char* p;
            a = *(void**)(s + 0x58);
            p = s;
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

        if ((void*)(s + 0x40) != 0) {

        if (!(((unsigned char)s[0x51] >> 7) & 1)) {
            char* r; char* q; char* p; void* a; unsigned int i; unsigned int j; void* b; unsigned int k; void* c;
            a = *(void**)(s + 0x58);
            p = s;
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

            if ((void*)(s + 0x68) != 0)
                fn_8015C238(s + 0x68, 0);
        }
        __dt__6gfTaskFv(s, 0);
        if (flag > 0)
            operator delete(s);
    }
    return self;
}
