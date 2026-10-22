#include <types.h>
#pragma force_active on

extern "C" {
void fn_8006E7E0(void* p);
void fn_8006CE10(int*);
void* fn_8006CE1C(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern u8 lbl_80454360[];
}

extern "C" void* fn_8006CD8C(void* arg0) {
    fn_8006E7E0(arg0);
    *(void**)arg0 = lbl_80454360;
    __construct_array((char*)arg0 + 0xC, (void (*)(void*))fn_8006CE10,
                      (void (*)(void*))fn_8006CE1C, 0x10, 8);
    __construct_array((char*)arg0 + 0x90, (void (*)(void*))fn_8006CE10,
                      (void (*)(void*))fn_8006CE1C, 0x10, 8);
    return arg0;
}
