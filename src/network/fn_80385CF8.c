#include <stddef.h>
#pragma force_active on

extern void* fn_8035CF8C(void);
extern int fn_8035D140(void* arg);
extern unsigned long SOHtoNl(unsigned long hostlong);

unsigned int fn_80385CF8(void) {
    int offset;
    unsigned int val;
    void* ptr;
    unsigned int result;
    void* base;

    result = 0;
    base = fn_8035CF8C();
    if (base == NULL)
        return 0;
    offset = 0;
    while (1) {
        ptr = *(void**)((char*)*(void**)((char*)base + 0xc) + offset);
        if (ptr == NULL)
            break;
        val = *(unsigned int*)ptr;
        if (val != SOHtoNl(0x7F000001UL)) {
            result = val;
            if (fn_8035D140(ptr) != 0)
                return val;
        }
        offset += 4;
    }
    return result;
}
